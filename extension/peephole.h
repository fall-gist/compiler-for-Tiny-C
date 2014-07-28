#include "emit.h"

extern struct code *list_head;
extern struct code *list_tail;

#define MAX 64
#define OPLEN 32

void delete_disuse_code();
void optimize();