#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
typedef struct student
{
int roll_no;
char name[20];
float marks;
struct student *next;

}SLL;

void add_begin(SLL ** ptr);
void print_node(SLL *ptr);
int count_node(SLL *ptr);
void save_file(SLL *ptr);
void reverse_print(SLL *ptr);
void print_rec(SLL *ptr);
void reverse_rec(SLL *ptr);
void add_end(SLL **ptr);
void delete_node_rollno(SLL **ptr);
void delete_node_name(SLL **ptr);
void modify_rollno(SLL *ptr);
void modify_name(SLL *ptr);
void modify_marks(SLL *ptr);
void sort_name(SLL *ptr);
void sort_marks(SLL *ptr);
void delete_all(SLL **ptr);
void reverse_data(SLL **ptr);
