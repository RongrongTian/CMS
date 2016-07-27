#ifndef _CMSUTILS_H
#define _CMSUTILS_H

#include "fun.h"
#include "sort.h"


/*Judgment the head whether is NULL.*/
extern int is_head_NULL(StuLink* p_phead);

/*Save memory data to text file.*/
extern void save_text_file(StuLink* phead, char* pfilename);

/*Save memory data that have sort to text file.*/
extern void save_sort_text_file(StuLink** p_node_array, char* p_filename, size_t p_length);

/*Read data from text file.*/
extern StuLink* read_text_file(StuLink* phead, char* pfilename);


#endif
