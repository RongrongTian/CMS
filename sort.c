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
        printf("node_array[%d] = 0x%X, ptemp = 0x%X\n", i, node_array[i], ptemp);
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

    printf("length = %d\n", length);

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
    //show_node_array(p_pnode_array, p_length, p_size);
}


/** \brief Sort the StuLink by then number.
 *
 * \param p_plhs const void*
 * \param p_prhs const void*
 * \return int
 *
 */
int sort_by_number(const void* p_plhs,const void* p_prhs) {
    return (*((StuLink**)p_plhs))->number > (*((StuLink**)p_prhs))->number;
}

/** \brief Sort the StuLink by then age.
 *
 * \param p_plhs const void*
 * \param p_prhs const void*
 * \return int
 *
 */
int sort_by_age(const void* p_plhs,const void* p_prhs) {
    return (*((StuLink**)p_plhs))->age > (*((StuLink**)p_prhs))->age;
}



/** \brief Show the sort node array.
 *
 * \param p_pnode_array StuLink**
 * \param p_length size_t
 * \param p_size size_t
 * \return void
 *
 */
void show_node_array(StuLink** p_pnode_array, size_t p_length, size_t p_size) {
    for (int i = 0; i < p_length; i++)
        show_one_node(p_pnode_array[i]);
}

