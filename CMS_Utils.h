#ifndef _CMSUTILS_H
#define _CMSUTILS_H

#include "fun.h"
#include "sort.h"


/*Judgment the head whether is NULL.*/
extern int is_head_NULL(StuLink* p_phead);

/*Save memory data to text file.*/
extern void save_text_file(StuLink* phead, char* pfilename);

/*Read data from text file.*/
extern StuLink* read_text_file(StuLink* phead, char* pfilename);


#endif
