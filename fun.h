#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



/*The LinkList of the student*/
typedef struct student {
	int number;
	int age;
	float score;
	char name[10];
	struct student* pnext;
}StuLink;

/*******************Function Interface***************/

extern StuLink* add_node(StuLink*);

extern void show_node(StuLink*);

extern void free_all_node(StuLink*);

extern StuLink* search_node_by_name(StuLink*, char*);

extern StuLink* search_node_by_number(StuLink*, int);

extern StuLink* delete_node_by_name(StuLink*, char*);

extern StuLink* delete_node_by_number(StuLink*, int);

extern void show_one_node(StuLink*);

extern int menu_search_delete_modify(char**, int);

extern void save_file(StuLink*, char*);

extern StuLink* read_file(StuLink*, char*);

extern StuLink* malloc_node();







