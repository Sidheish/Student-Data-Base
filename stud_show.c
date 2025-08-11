#include "header.h"
void print_node(SLL *ptr)
{
if(ptr==0)
{
printf("\033[37mNo records found\033[0m\n");
return;
}

printf("%-10s %-20s %-10s", "RollNo", "Name", "Marks");
printf("----------------------------------------------\n");
while(ptr)
{
printf("%d %s %f\n",ptr->roll_no, ptr->name, ptr->marks );
ptr= ptr->next;
}
}
