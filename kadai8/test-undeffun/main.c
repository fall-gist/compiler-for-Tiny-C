#include <stdio.h>

int g(int);

int main(void){
	printf("%d\n", f(2));
}

int g(int y){
	return y+2;	
}