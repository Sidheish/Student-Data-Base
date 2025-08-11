#include "header.h"

void delete_node_rollno(SLL **ptr){
if(*ptr == 0){
printf("No records found\n");
return;
}
SLL *del = *ptr;	// holding first node
SLL *prev;
int num;
printf("Enter Roll_no to  Delete\n");
scanf("%d", &num);
while(del){
if(del->roll_no == num){	// If rollno found
if(*ptr == del)	// If found at first position
*ptr = del->next;	// update headptr
else
// if middle / last position
prev->next = del->next;
free(del);	// delete node
return;
}
prev= del;	// follow del one step back
del = del->next;	// visit new node
}
printf("Roll_no not found\n");
}


void delete_node_name(SLL **ptr){

if(*ptr == NULL){
printf("No records found\n");
return;
}
SLL *del = *ptr;	// holding first node
SLL *prev;
char name[20];
printf("Enter name to  Delete\n");
scanf("%s", name);
while(del){
if(strcmp(del->name , name)==0){	// If name found
if(*ptr == del)			// If found at first position
*ptr = del->next;		// update headptr
else
// if middle / last position
prev->next = del->next;
free(del);	// delete node
return;
}
prev= del;	// follow del one step back
del = del->next;	// visit new node
}
printf("Name not found\n");
}




