#ifndef _SORT_H
#define _SORT_H

#include "fun.h"

typedef int (*sort_pointer)(const void*, const void*);

/*Get Stulink length.*/
extern size_t get_length(StuLink* p_head);

/*Sort StuLink by the student number.*/
extern StuLink** sort_init(StuLink* p_phead);

/*Qsort use to sort StuLink*/
extern void qsort_stulink(StuLink** p_pnode_array, size_t p_length, size_t p_size, int(*sort_fun)(const void*,const void*));

/*Sort the StuLink by then number by less.*/
extern int sort_by_number_less(const void* p_plhs,const void* p_prhs);

/*Sort the StuLink by then age by less.*/
extern int sort_by_age_less(const void* p_plhs,const void* p_prhs);

/*Sort the StuLink by then score by less.*/
extern int sort_by_score_less(const void* p_plhs,const void* p_prhs);

/*Sort the StuLink by then name by less.*/
extern int sort_by_name_less(const void* p_plhs,const void* p_prhs);

/*Sort the StuLink by then number by greater.*/
extern int sort_by_number_greater(const void* p_plhs,const void* p_prhs);

/*Sort the StuLink by then age by greater.*/
extern int sort_by_age_greater(const void* p_plhs,const void* p_prhs);

/*Sort the StuLink by then score by greater.*/
extern int sort_by_score_greater(const void* p_plhs,const void* p_prhs);

/*Sort the StuLink by then name by greater.*/
extern int sort_by_name_greater(const void* p_plhs,const void* p_prhs);

/*Select a sort operation.*/
extern int sort_operation();

/*Show the sort node array.*/
extern void show_node_array(StuLink** p_pnode_array, size_t p_length);

#endif //_SORT_H
