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


typedef StuLink* (*Fun_By_Name)(StuLink*, char*);
typedef StuLink* (*Fun_By_Number)(StuLink*, int);


extern const char* search[];
extern const char* delete[];
extern const char* modify[];

/*******************Function Interface***************/

/*Add a node data to StuLink head*/
extern StuLink* add_node(StuLink* p_head);

/*Show one node data from StuLink*/
extern void show_one_node(StuLink* p_head);

extern void show_node(StuLink* p_head);

extern void free_all_node(StuLink* p_head);

extern StuLink* search_node_by_name(StuLink* p_head, char*);

extern StuLink* search_node_by_number(StuLink* p_head, int);

extern StuLink* delete_node_by_name(StuLink* p_head, char*);

extern StuLink* delete_node_by_number(StuLink* p_head, int);

extern int menu_search_delete_modify(const char* operation_array[], int);

extern StuLink* search_delete_modify_operation(StuLink* p_head, const char* operation_array[], Fun_By_Name p_fun_name, Fun_By_Number p_fun_number);

extern void save_file(StuLink* p_head, char*);

extern StuLink* read_file(StuLink* p_head, char*);

extern StuLink* malloc_node();







