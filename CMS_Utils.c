#include "CMS_Utils.h"



/** \brief Judgment the head whether is NULL.
 *
 * \param p_phead StuLink*
 * \return bool If p_phead = NULL then return 0, otherwise return 1.
 *
 */
int is_head_NULL(StuLink* p_phead) {
    return NULL != p_phead;
}


/** \brief Save memory data to text file.
 *
 * \param phead StuLink*
 * \param pfilename char*
 * \return void
 *
 */
void save_text_file(StuLink* phead, char* pfilename) {
    FILE* pfw = fopen(pfilename, "w");

    if (NULL == pfw) {
        puts("Open file fail, please check the file name and path.");
        return;
    }

    StuLink* ptemp = phead;
    char node_buf[100] = {0};
    fputs("ID\tName\tAge\t Score\n\n", pfw);
    while (ptemp) {
        sprintf(node_buf, "%d\t%s\t%d\t%6.2f\n", ptemp->number, ptemp->name, ptemp->age, ptemp->score);
        fputs(node_buf, pfw);
        ptemp = ptemp->pnext;
    }

    //fclose , no close
    fclose(pfw);

    printf("Save to text file success.");
}





/** \brief Read data from text file.
 *
 * \param phead StuLink*
 * \param pfilename char*
 * \return StuLink*
 *
 */
StuLink* read_text_file(StuLink* phead, char* pfilename) {
    FILE* pfr = fopen(pfilename, "r");

    if (NULL ==  pfr) {
        puts("Open file fail, please check the file name and path.");
        return phead;
    }

    StuLink* ptemp = malloc_node();
    char node_buf[100] = {0};
    fgets(node_buf, pfr);
    fgets(node_buf, pfr);
    memset(node_buf, 0, 100);



}





