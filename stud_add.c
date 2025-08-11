#include "header.h"
void add_begin(SLL ** ptr)
{
 SLL *new;
 new = malloc(sizeof(SLL)); // Creating node
 printf("\033[36m My dear! Enter rollno name and marks \033[0m\n");
 scanf("%d %s %f", &new->roll_no, new->name, &new->marks);
new->next = *ptr;       // update next address
 *ptr = new;     // update headptr
  
}

