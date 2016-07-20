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

/*Add a node data to StuLink head.*/
extern StuLink* add_node(StuLink* p_head);

/*Show one node data from StuLink.*/
extern void show_one_node(StuLink* p_head);

/*Show all node data in the StuLink.*/
extern void show_node(StuLink* p_head);

/*Free all node memory when exit system.*/
extern void free_all_node(StuLink* p_head);

/*Search a node by the student`s name in the StuLink.*/
extern StuLink* search_node_by_name(StuLink* p_head, char*);

/*Search a node by the student`s number in the StuLink.*/
extern StuLink* search_node_by_number(StuLink* p_head, int);

/*Delete a node by the student`s name in the StuLink.*/
extern StuLink* delete_node_by_name(StuLink* p_head, char*);

/*Delete a node by the student`s number in the StuLink.*/
extern StuLink* delete_node_by_number(StuLink* p_head, int);

/*Modify a node by the student`s name in the StuLink.*/
extern StuLink* modify_node_by_name(StuLink* p_phead, char* p_pname);

/*This function show a menu that you can chose three function to opetate the student data.*/
extern int menu_search_delete_modify(const char* operation_array[], int);

/*This function which you can use to operate the student data in the set of [search, delete, modify].*/
extern StuLink* search_delete_modify_operation(StuLink* p_head, const char* operation_array[], Fun_By_Name p_fun_name, Fun_By_Number p_fun_number);

/*Save a file that store the data that you input to the system.*/
extern void save_file(StuLink* p_head, char*);

/*Read a file that store the student data to the system.*/
extern StuLink* read_file(StuLink* p_head, char*);

/*This function can malloc a new node that can link to the StuLink.*/
extern StuLink* malloc_node();







