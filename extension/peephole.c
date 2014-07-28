#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "peephole.h"

void delete_disuse_code(){
	struct code *current = list_head, *prev = NULL;
	while(current->next != NULL){
		char code[MAX];
		char op[4][OPLEN] = { '\0', '\0', '\0', '\0' }, *tp;
		strcpy(code, current->cd);
		tp = strtok(code, ",\t\n ");
		sprintf(op[0], "%s", tp);
		int i=1;
		while(tp != NULL){
			tp = strtok(NULL, ",\t\n ");
			if(tp != NULL)
				sprintf(op[i], "%s", tp);
			i++;
		}
		// 関数定義のGLOBAL宣言から次（最低）2つはお決まりなので飛ばす
		if(!strcmp(op[0], "GLOBAL")){
			prev = current->next->next;
			current = prev->next;
		// 関数ラベルおよびリターンラベル以外（つまりラベル単独）の場合
		}else if(strstr(op[0], "L") && strstr(op[0], ":")){
			// 次の命令もジャンプ先ラベルの場合
			if(strstr(current->next->cd, "L") && strstr(current->next->cd, ":")){
				char nextcode[MAX];
				strcpy(nextcode, current->next->cd);
				char nextop[4][OPLEN] = { '\0', '\0', '\0', '\0' }, *tp;
				tp = strtok(nextcode, ",\t\n ");
				sprintf(nextop[0], "%s", tp);
				i = 1;
				while(tp != NULL){
					tp = strtok(NULL, ",\t\n ");
					if(tp != NULL)
						sprintf(nextop[i], "%s", tp);
					i++;
				}
				// そのラベルを削除
				current->next = current->next->next;
				strtok(op[0], ":");
				strtok(nextop[0], ":");
				struct code *temp = list_head;
				// 2つ目のラベルにジャンプする命令を、1つ目のラベルにジャンプする命令に変更
				while(temp->next != NULL){
					if(strstr(temp->cd, nextop[0]) && (temp != current->next)){
						char tempcode[MAX];
						strcpy(tempcode, temp->cd);
						char tempop[4][OPLEN] = { '\0', '\0', '\0', '\0' }, *tp;
						tp = strtok(tempcode, ",\t\n ");
						sprintf(tempop[0], "%s", tp);
						i = 1;
						while(tp != NULL){
							tp = strtok(NULL, ",\t\n ");
							if(tp != NULL)
								sprintf(tempop[i], "%s", tp);
							i++;
						}
						sprintf(temp->cd, "\t%s\t%s\n", tempop[0], op[0]);
					}
					temp = temp->next;
				}
				prev = current;
				current = prev->next;
			}else{
				int flag = 0;
				strtok(op[0], ":");
				struct code *temp = list_head;
				// このラベルを参照しているジャンプ命令があるか探す
				while(temp->next != NULL){
					if(strstr(temp->cd, op[0]) && (temp != current)){
						flag = 1;
						break;	
					}
					temp = temp->next;
				}
				// ない場合、削除
				if(!flag){
					prev->next = current->next;
					current = prev->next;
				}else{
					prev = current;
					current = prev->next;	
				}
			}
		// mov命令の場合
		}else if(!strcmp(op[0], "mov")){
			char nextcode[MAX];
			strcpy(nextcode, current->next->cd);
			char nextop[4][OPLEN] = { '\0', '\0', '\0', '\0' };
			tp = strtok(nextcode, ",\t\n ");
			sprintf(nextop[0], "%s", tp);
			i=1;
			while(tp != NULL){
				tp = strtok(NULL, ",\t\n ");
				if(tp != NULL)
					sprintf(nextop[i], "%s", tp);
				i++;
			}
			// 次がmov命令でないなら飛ばす
			if(strcmp(nextop[0], "mov")){
				prev = current;
				current = prev->next;
				continue;
			}
			// mov命令の移動先が同じ場合、先の方は削除
			// 変数宣言時によく出てくる
			if(!strcmp(op[1], nextop[1])){
				current = current->next;
				prev->next = current;
			// mov a,b と mov b,a が連続する場合、後者を削除
			}else if(!strcmp(op[1], nextop[2]) && !strcmp(op[2], nextop[1])){
				current->next = current->next->next;
				prev = current;
				current = prev->next;
			}else{
				prev = current;
				current = prev->next;
			}
		// jmp命令の場合
		}else if(!strcmp(op[0], "jmp")){
			struct code *temp = current->next;
			// jmp命令の次がラベルでない（＝Lから始まってない）なら飛ばす
			while(strstr(temp->cd, "L") != temp->cd)
				temp = temp->next;
			char nextcode[MAX];
			strcpy(nextcode, temp->cd);
			char nextop[4][OPLEN] = { '\0', '\0', '\0', '\0' };
			tp = strtok(nextcode, ",\t\n ");
			sprintf(nextop[0], "%s", tp);
			i=1;
			while (tp != NULL){
				tp = strtok(NULL, ",\t\n ");
				if(tp != NULL)
					sprintf(nextop[i], "%s", tp);
				i++;
			}
			// jmp命令の次のラベルがそのジャンプ先なら、
			if(!strcmp(op[1], nextop[0])){
				// jmp命令からラベルの直前まで削除
				current = temp;
				prev->next = current;
			// jmp命令の次のラベルがそのジャンプ先でないなら、
			}else{
				// jmp命令直後からラベル直前まで削除
				current->next = temp;
				prev = current;
				current = prev->next;
			}
		}else{
			prev = current;
			current = prev->next;	
		}
	}
}

void optimize(){
	int i;
	for(i=0; i<5; i++){
		delete_disuse_code();
	}
}