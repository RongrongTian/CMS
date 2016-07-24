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







