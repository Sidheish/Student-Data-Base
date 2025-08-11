/* mini project 2*/

#include "header.h"
void main()
{
SLL *headptr = 0;
int c;
char op;
while(1)
{
printf("\033***********Student Record Menu***************\n");
printf("a/A  :add_new record\nd/D : delete a record\ns/S : show the list\nm/M : modify a record\nv/V : save\ne/E :exit\nt/T : sort the list\nl/L : delete all the records\nr/R : reverse the list \033[0m\n");

scanf(" %c", &op);
char sub_op;
char m;
char s,t;
switch(op)
{
case 'a' :
case 'A' : add_begin(&headptr); break;
//case 2: add_end(&headptr); break;
case 'd':
case 'D': printf("R/r : enter roll to del\nN/n : enter name to del\n");
	scanf(" %c", &sub_op);
	switch(sub_op){
	case 'r':

	case 'R': delete_node_rollno(&headptr); break;
	case 'n':
	case 'N': delete_node_name(&headptr); break;

	}
case 's':
case 'S': print_node(headptr); break;
case 'm':
case 'M':	printf("Enter which record to search for modification\nR/r : to search a rollno\nN/n : to search a name\nP/p: percentage based\n");
		scanf(" %c", &m);
		//printf("R/r : to search a rollno\nN/n : to search a name\nP/p : percentage based\n");
		switch(m){
		case 'R':
		case 'r': modify_rollno(headptr);break;
		case 'N':
		case 'n': modify_name(headptr);break;
		case 'p':
		case 'P': modify_marks(headptr); break;

		}
//case 5: c = count_node(headptr);
//	printf("Total Count=%d\n", c);
//	break;
case 'V':
case 'v': save_file(headptr); break;
//case 8: reverse_print(headptr); break;
//case 9: print_rec(headptr); break;
//case 10: reverse_rec(headptr); break;
case 'e':
case 'E': printf("Enter\nS/s : save and exit\nE/e : exit without saving\n");
	scanf(" %c", &s);
	switch(s){
	case 'S':
	case 's': save_file(headptr);
		exit(0);
	case 'E':
	case 'e': exit(0);

	}
//case 16: exit(0);
case 't':
case 'T': printf("Enter\nN/n : sort with name\nP/p : sort with percentage\n");
	scanf(" %c", &t);
	switch(t){
	case 'N':
	case 'n': sort_name(headptr); break;
	case 'P':
	case 'p': sort_marks(headptr); break;
	}
case 'l':
case 'L': delete_all(&headptr); break;
case 'r':
case 'R': reverse_data(&headptr); break;
default : printf("My Dear! Invalid\n");


}
}


}
void sort_name(SLL *ptr){
if(ptr == NULL){
printf("No records found\n");
return;
}
int i,j,c = count_node(ptr);
SLL *p1, *p2, temp;
p1 = ptr; // Starts from first node
for(i=0; i<c-1; i++){
p2 = p1->next;	// Always starts from p1
for(j = 0; j<c-1-i; j++){
// Copying p1 data into temp
if(strcmp(p1->name, p2->name)>0){
temp.roll_no = p1->roll_no;
strcpy(temp.name, p1->name);
temp.marks = p1->marks;
// Copying p2 data into p1
p1->roll_no = p2->roll_no;
strcpy(p1->name, p2->name);
p1->marks = p2->marks;
// Copying temp data int p2
p2->roll_no = temp.roll_no;
strcpy(p2->name, temp.name);
p2->marks = temp.marks;


}
p2= p2->next;

}
p1 = p1->next;

}
}
void reverse_data(SLL **ptr){
if(*ptr == NULL){
printf("No records found\n");
return;
}
int i, c = count_node(*ptr);

if(c>1){
SLL **arr;
SLL *temp = *ptr;	// Start from the first node
arr = malloc(sizeof(SLL *)*c);

// Storing all address in array

for(i=0; i<c; i++){
arr[i] = temp;
temp = temp->next;
}
// update the link positions
for(i=1; i<c; i++){
arr[i] ->next = arr[i-1];
arr[0]->next = 0;
*ptr = arr[c-1];
}

}
}
void delete_all(SLL **ptr){
if(*ptr == 0){
printf("No records found\n");
return;
}
int c=0;
SLL *del = *ptr;	// Start from first node
while(del){

*ptr = del->next;
printf("Node num deleted : %d\n", ++c);
sleep(1);
free(del);
del = *ptr;
}
printf("All nodes deleted successfully\n");

}

void sort_marks(SLL *ptr){
if(ptr == NULL){
printf("No records found\n");
return;
}
int i,j,c = count_node(ptr);
SLL *p1, *p2, temp;
p1 = ptr; // Starts from first node
for(i=0; i<c-1; i++){
p2 = p1->next;	// Always starts from p1
for(j = 0; j<c-1-i; j++){
// Copying p1 data into temp
if(p1->marks>p2->marks){
temp.roll_no = p1->roll_no;
strcpy(temp.name, p1->name);
temp.marks = p1->marks;
// Copying p2 data into p1
p1->roll_no = p2->roll_no;
strcpy(p1->name, p2->name);
p1->marks = p2->marks;
// Copying temp data int p2
p2->roll_no = temp.roll_no;
strcpy(p2->name, temp.name);
p2->marks = temp.marks;


}
p2= p2->next;

}
p1 = p1->next;

} 
}
void modify_marks(SLL *ptr){
if(ptr == NULL){
printf("File not present\n");
return;
}
int rollno;
printf("Enter Rollno to modify marks: \n");
scanf("%d", &rollno);

SLL *start = ptr;
while(start){
if(start->roll_no == rollno){
printf("Current marks: %f\n", start->marks);
printf("Enter new marks: ");
scanf("%f", &start->marks);
printf("Marks updated successfully\n");
return;
}
start = start->next;

}

}
/*void add_begin(SLL ** ptr)
{
SLL *new;
new = malloc(sizeof(SLL)); // Creating node
printf("\033[36m My dear! Enter rollno name and marks \033[0m\n");
scanf("%d %s %f", &new->roll_no, new->name, &new->marks);
new->next = *ptr;	// update next address
*ptr = new;	// update headptr


}*/

/*void print_node(SLL *ptr)
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
}*/

void modify_rollno(SLL *ptr){
if(ptr == NULL){
printf("No records found\n");
return;
}

int old_rollno;
printf("Enter current rollno: \n");
scanf("%d", &old_rollno);
SLL *temp =ptr;		// Starting from first node
while(temp){
	if(temp->roll_no == old_rollno){
	printf("Enter new rollno: \n");
	scanf("%d", &temp->roll_no);
	printf("Roll number updated\n");
	return;
	}
	temp = temp->next;
}
printf("Rollno not found\n");

}
void modify_name(SLL *ptr){
if(ptr == NULL){
printf("No records found\n");
return;
} 
int rollno;
printf("Enter Rollno to modify name\n");
scanf("%d", &rollno);
SLL *temp = ptr;
while(temp){
if(temp->roll_no == rollno){
printf("Current name : %s\n", temp->name);
printf("Enter new name: \n");
scanf("%s", temp->name);
printf("Name updated successfully\n");
return;
}

temp = temp->next;
}

}

int count_node(SLL *ptr)
{

int c=0;
while(ptr)
{
c++;
ptr = ptr->next;

}
return c;

}
/*void save_file(SLL *ptr)
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
void reverse_print(SLL *ptr)
{
if(ptr == 0)
{
printf("No records found\n");
return;
}
int i,j;
SLL *temp ; //Taking temp variable to travel till last node
int c = count_node(ptr);	// finding node count
for(i = 0; i<c; i++)
{

temp = ptr; 	// Temp starts from first node
for(j=0; j<c-1-i; j++)
temp = temp->next;
printf("%d %s %f\n", temp->roll_no, temp->name, temp->marks);


}



}
void print_rec(SLL *ptr)
{
if(ptr ==0)
{
printf("No records found\n");
return;
}
else if(ptr)
{
printf("%d %s %f\n", ptr->roll_no, ptr->name, ptr->marks);
if(ptr->next)
print_rec(ptr->next);
}

}
void reverse_rec(SLL *ptr)
{
if(ptr)
{
if(ptr->next)
reverse_rec(ptr->next);
printf("%d %s %f\n", ptr->roll_no, ptr->name, ptr->marks);

}
else
printf("No records found\n");


}
void add_end(SLL **ptr)
{
SLL *new, *last;
new = malloc(sizeof(SLL));	// Create Node
printf("\033[31mEnter roll_no name marks\033[0m\n");
scanf("%d %s %f", &new->roll_no, new->name, &new->marks);

new->next = 0;	// new next is always zero
if(*ptr==0)	// If no records found
*ptr = new;	// update headptr
else
{
// If records found
last = *ptr;	// always start from first
while(last->next)	
last = last->next;	// finding last node
last->next = new;	// update last node next add as new
}
}

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




*/





