#include "sort.h"

/** \brief Init sort node array.
 *
 * \param p_phead StuLink*
 * \return StuLink**
 *
 */
StuLink** sort_init(StuLink* p_phead) {
    //Get StuLink length.
    size_t length = get_length(p_phead);

    StuLink** node_array = (StuLink**)malloc(length * sizeof(StuLink*));
    if (NULL == node_array) {
        printf("Malloc node array fail!\n");
        return NULL;
    }

    StuLink* ptemp = p_phead;
    for (int i = 0; i < length; i++) {
        node_array[i] = ptemp;
#if _DEBUG_
        printf("node_array[%d] = 0x%X, ptemp = 0x%X\n", i, node_array[i], ptemp);
#endif // _DEBUG_
        ptemp = ptemp->pnext;
    }

    return node_array;
}



/** \brief Get Stulink length.
 *
 * \param p_head StuLink
 * \return size_t Length
 *
 */
size_t get_length(StuLink* p_head) {
    size_t length = 0;

    while (p_head) {
        p_head = p_head->pnext;
        length++;
    }
#if _DEBUG_
    printf("length = %d\n", length);
#endif // _DEBUG_
    return length;
}


/** \brief Qsort use to sort StuLink.
 *
 * \param StuLink** The array of the StuLink node.
 * \param size_t The length of the array
 * \param size_t The size the one of array element.
 * \param sort_fun The function that use to sort.
 * \return void.
 *
 */
void qsort_stulink(StuLink** p_pnode_array, size_t p_length, size_t p_size, int(*sort_fun)(const void*,const void*)) {
    qsort((void*)p_pnode_array, p_length, p_size, sort_fun);
#if _DEBUG_
    show_node_array(p_pnode_array, p_length, p_size);
#endif // _DEBUG_
}


/** \brief Sort the StuLink by then number.
 *
 * \param p_plhs const void*
 * \param p_prhs const void*
 * \return int
 *
 */
int sort_by_number_less(const void* p_plhs,const void* p_prhs) {
    return (*((StuLink**)p_plhs))->number >= (*((StuLink**)p_prhs))->number;
}

/** \brief Sort the StuLink by then age.
 *
 * \param p_plhs const void*
 * \param p_prhs const void*
 * \return int
 *
 */
int sort_by_age_less(const void* p_plhs,const void* p_prhs) {
    return (*((StuLink**)p_plhs))->age >= (*((StuLink**)p_prhs))->age;
}

/** \brief Sort the StuLink by then score.
 *
 * \param p_plhs const void*
 * \param p_prhs const void*
 * \return int
 *
 */
int sort_by_score_less(const void* p_plhs,const void* p_prhs) {
    return (*((StuLink**)p_plhs))->score >= (*((StuLink**)p_prhs))->score;
}


/** \brief Sort the StuLink by then name.
 *
 * \param p_plhs const void*
 * \param p_prhs const void*
 * \return int
 *
 */
int sort_by_name_less(const void* p_plhs,const void* p_prhs) {
    if (strcmp((*((StuLink**)p_plhs))->name, (*((StuLink**)p_prhs))->name) >= 0)
        return 1;
}



/** \brief Sort the StuLink by then number by greater.
 *
 * \param p_plhs const void*
 * \param p_prhs const void*
 * \return int
 *
 */
int sort_by_number_greater(const void* p_plhs,const void* p_prhs) {
    return (*((StuLink**)p_plhs))->number < (*((StuLink**)p_prhs))->number;
}

/** \brief Sort the StuLink by then age by greater.
 *
 * \param p_plhs const void*
 * \param p_prhs const void*
 * \return int
 *
 */
int sort_by_age_greater(const void* p_plhs,const void* p_prhs) {
    return (*((StuLink**)p_plhs))->age < (*((StuLink**)p_prhs))->age;
}

/** \brief Sort the StuLink by then score by greater.
 *
 * \param p_plhs const void*
 * \param p_prhs const void*
 * \return int
 *
 */
int sort_by_score_greater(const void* p_plhs,const void* p_prhs) {
    return (*((StuLink**)p_plhs))->score < (*((StuLink**)p_prhs))->score;
}


/** \brief Sort the StuLink by then name by greater.
 *
 * \param p_plhs const void*
 * \param p_prhs const void*
 * \return int
 *
 */
int sort_by_name_greater(const void* p_plhs,const void* p_prhs) {
    if (strcmp((*((StuLink**)p_plhs))->name, (*((StuLink**)p_prhs))->name) < 0)
        return 1;
}


/** \brief Select a sort operation
 *
 * \return int
 *
 */
int sort_operation() {
    puts("please select sort operation:");

    puts("\nless to greater:");
    puts("\t1.Sort_by_number_less");
    puts("\t2.Sort_by_age_less");
    puts("\t3.Sort_by_score_less");
    puts("\t4.Sort_by_name_less");

    puts("\ngreater to less:");
    puts("\t5.Sort_by_number_greater");
    puts("\t6.Sort_by_age_greater");
    puts("\t7.Sort_by_score_greater");
    puts("\t8.Sort_by_name_greater");

    int chose = 0;
    printf("\nplease input your chose[1,8]: ");
    scanf("%d", &chose);

    return chose;
}




/** \brief Show the sort node array.
 *
 * \param p_pnode_array StuLink**
 * \param p_length size_t
 * \param p_size size_t
 * \return void
 *
 */
void show_node_array(StuLink** p_pnode_array, size_t p_length) {
    for (int i = 0; i < p_length; i++)
        show_one_node(p_pnode_array[i]);
}

