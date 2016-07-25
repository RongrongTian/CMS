#ifndef _SORT_H
#define _SORT_H

#include "fun.h"

/*Get Stulink length.*/
extern size_t get_length(StuLink* p_head);


/*Sort StuLink by the student number.*/
extern StuLink** sort_init(StuLink* p_phead);

/*Qsort use to sort StuLink*/
extern void qsort_stulink(StuLink** p_pnode_array, size_t p_length, size_t p_size, int(*sort_fun)(const void*,const void*));

/*Sort the StuLink by then number.*/
extern int sort_by_number(const void* p_plhs,const void* p_prhs);

/*Sort the StuLink by then age.*/
extern int sort_by_age(const void* p_plhs,const void* p_prhs);

/*Sort the StuLink by then score.*/
extern int sort_by_score(const void* p_plhs,const void* p_prhs);

/*Sort the StuLink by then name.*/
extern int sort_by_name(const void* p_plhs,const void* p_prhs);

/*Show the sort node array.*/
extern void show_node_array(StuLink** p_pnode_array, size_t p_length, size_t p_size);

#endif //_SORT_H
