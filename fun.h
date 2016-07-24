#ifndef _FUN_H
#define _FUN_H

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

/*Select add node type, by head or back.*/
extern int add_node_operation_select();

/*Add a node data to StuLink head.*/
extern StuLink* add_node_front(StuLink* p_head, StuLink* p_pnode);

/*Add a node data to StuLink back.*/
extern StuLink* add_node_back(StuLink* p_head, StuLink* p_pnode);

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

/*Delete a node*/
extern void delete_node(StuLink* p_phead, StuLink* p_pnode, StuLink* p_privew);

/*Remove a node*/
extern void remove_node(StuLink** p_phead, StuLink* p_pnode);

/*Modify a node by the student`s name in the StuLink.*/
extern StuLink* modify_node_by_name(StuLink* p_phead, char* p_pname);

/*Modify a node by the student`s number in the StuLink.*/
extern StuLink* modify_node_by_number(StuLink* p_phead, int p_number);

/*Modify a node data*/
extern void modify_node(StuLink* p_pnode, int p_chose);

/*This function show a menu that you can chose three function to opetate the student data.*/
extern int menu_search_delete_modify(const char* operation_array[], int);

/*This function which you can use to operate the student data in the set of [search, delete, modify].*/
extern StuLink* search_delete_modify_operation(StuLink* p_head, const char* operation_array[], Fun_By_Name p_fun_name, Fun_By_Number p_fun_number);

/*Init file name*/
extern void init_file(char* p_pfile_name);

/*Save a file that store the data that you input to the system.*/
extern void save_file(StuLink* p_head, char*);

/*Read a file that store the student data to the system.*/
extern StuLink* read_file(StuLink* p_head, char*);

/*This function can malloc a new node that can link to the StuLink.*/
extern StuLink* malloc_node();

/*Return a number that you select the part of the StuLink*/
extern int modify_select();

/*Init a node*/
extern void init_node(StuLink* pnode);

/*Sort StuLink by the student number.*/
extern int sort_by_number(StuLink* p_phead);


#endif // _FUN_H





