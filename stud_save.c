#include "header.h"

void save_file(SLL *ptr)
{
if(ptr == 0)
{
printf("No records found\n");
return;
}
FILE *fp = fopen("std.txt", "r+");
while(ptr)
{
fprintf(fp, "%d %s %f\n", ptr->roll_no, ptr->name, ptr->marks);
ptr = ptr->next;
}
printf("\033[38mData saved in file successfully\n\033[0m");
fclose(fp);

}

