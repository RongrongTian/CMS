#include "fun.h"

/*operation set*/
const char* search[] = {"search by name", "search by number"};
const char* delete[] = {"delete by name", "delete by number"};
const char* modify[] = {"modify by name", "modify by number"};


/** \brief Init a new node data.
 *
 * \param	pnode :	the node that need to init.
 * \return	void.
 *
 * You can use this function to init a new node and the node->pnext = NULL.
 */
void init_node(StuLink* pnode) {

    puts("please input the number:");
    scanf("%d", &pnode->number);

    puts("please input the age:");
    scanf("%d", &pnode->age);

    puts("please input the score:");
    scanf("%f", &pnode->score);

    puts("please input the name[10]:");
    scanf("%s", pnode->name);

    pnode->pnext = NULL;

    puts("init node ok!");
}



/** \brief Malloc a new node.
 *
 * \param	void.
 * \return	void.
 *
 * This function can malloc a new node that can link to the StuLink.
 */
StuLink* malloc_node() {

    StuLink* ptemp = (StuLink*)malloc(sizeof(StuLink));
    assert(ptemp != NULL);

    return ptemp;
}


/** \brief Select add node type, by head or back.
 *
 * \return int Select number 0(Insert Head) or 1(Insert Back).
 *
 */
int add_node_operation_select() {
    puts("\tplease select insert node type");
    puts("\t1.Insert node to head.");
    puts("\t2.Insert node to back");

    int chose = 0;
    puts("please input you chose: ");
    scanf("%d", &chose);
    return chose;
}




/** \brief Add a node data to StuLink head.
 *
 * \param	phead : The head of the StuLink.
 * \param	p_ptemp : The node that you want to add to the head.
 * \return	StuLink*. The head of the StuLink.
 */
StuLink* add_node_front(StuLink* phead, StuLink* p_ptemp) {
    //StuLink* ptemp = malloc_node();

    //init node data
    //init_node(ptemp);

    if (NULL == phead) {
        p_ptemp->pnext = NULL;
        phead = p_ptemp;
    } else {
        p_ptemp->pnext = phead;
        phead = p_ptemp;
    }

    return phead;
}



/** \brief  Add a node data to StuLink back.
 *
 * \param   p_head  The head of the StuLink
 * \param   p_ptemp The node will be insert to StuLink back
 * \return  StuLink* head
 *
 */
StuLink* add_node_back(StuLink* p_head, StuLink* p_pnode) {

    p_pnode->pnext = NULL;

    //StuLink is empty
    if (NULL == p_head)
        return p_pnode;

    StuLink* ptemp = p_head;

    while (ptemp->pnext)
        ptemp = ptemp->pnext;

    ptemp->pnext = p_pnode;

    return p_head;
}




/** \brief Show one node data from StuLink.
 *
 * \param	phead : The head of the StuLink.
 * \return	void.
 */
void show_node(StuLink* phead) {
    if (NULL == phead) {
        printf("\tThe StuLink is NULL\n");
        return;
    }

    StuLink* ptemp = phead;
    while (ptemp) {
        printf("\t%d %d %6.2f %s\n", ptemp->number, ptemp->age, ptemp->score, ptemp->name);
        ptemp = ptemp->pnext;
    }

}

/** \brief Search a node by the student`s name in the StuLink.
 *
 * \param	phead : The head of the StuLink.
 * \param	pname : The student name of the search.
 * \return	StuLink* : The student node which name is equal to pname
 */
StuLink* search_node_by_name(StuLink* phead, char* pname) {
    assert(phead != NULL);
    assert(pname != NULL);

    StuLink* ptemp = phead;
    while (ptemp) {
        if (!strcmp(ptemp->name, pname)) {
            return ptemp;
        }
        ptemp = ptemp->pnext;
    }
    return NULL;
}

/** \brief Search a node by the student`s number in the StuLink.
 *
 * \param	phead : The head of the StuLink.
 * \param	number : The student number of the search.
 * \return	StuLink* : The student node which number is equal to number
 */
StuLink* search_node_by_number(StuLink* phead, int number) {
    assert(phead != NULL);

    StuLink* ptemp = phead;
    while (ptemp) {
        if (number == ptemp->number) {
            return ptemp;
        }
        ptemp = ptemp->pnext;
    }
    return NULL;

}



/** \brief Free all node memory when exit system.
 *
 * \param	phead : The head of the StuLink.
 * \return	void.
 */
void free_all_node(StuLink* phead) {
    //assert(phead != NULL);

    if (NULL == phead) {
        return;
    }

    StuLink* ptemp = phead;

    while (ptemp) {
        phead = phead->pnext;
        free(ptemp);
        ptemp = phead;
    }

}


/** \brief Show one node data from StuLink.
 *
 * \param	phead : The head of the StuLink.
 * \return	void.
 */
void show_one_node(StuLink* pnode) {
    if (pnode != NULL) {
        printf("\t%d %d %6.2f %s\n", pnode->number, pnode->age, pnode->score, pnode->name);
    } else {
        printf("\tshow_one_node: pnode = NULL\n");
    }
}


/** \brief This function show a menu that you can chose three function to opetate the student data.
 *
 * \param	pstring : The array of the string that contain search[] or delete[] and modify[].
 * \return	int : The number of you chose 1 or 0, 0 is the first of the ppstring(array), and 1 is the next and the last.
 */
int menu_search_delete_modify(const char** pstring, int num) {
    //int i = 0;
    for (int i = 0; i < num; i++) {
        printf("\t%d. %s\n", i + 1, pstring[i]);
    }

    int chose = 0;
    printf("\t\nplease input your chose: ");
    scanf("%d", &chose);

    return chose;
}

/** \brief Delete a node by the student`s name in the StuLink.
 *
 * \param	phead : The head of the StuLink.
 * \param	pname : The student name of the delete.
 * \return	StuLink* : The head of the StuLink that has delete the node that name is equal to pname
 */
StuLink* delete_node_by_name(StuLink* phead, char* pname) {
    assert(phead != NULL);
    assert(pname != NULL);

    //StuLink* ptemp = phead;
    StuLink* pr = phead;
    StuLink* pn = phead;//This pointer is point to the delete node
//    char isDelete = 0;

    while (pn) {
        if (!strcmp(pn->name, pname)) {
            //delete_node(phead, pn, pr);
            remove_node(&phead, pn);
            break;
        }

        pr = pn;
        pn = pn->pnext;

    }
    return phead;
}



/** \brief	This function can delete a student data node by the number.
 * \param	phead :	 the pointer of the phead.
 * \param   number : the number of the student.
 * \return	StuLink* : The head of the StuLink that has delete the node that number is equal to number.
 */
StuLink* delete_node_by_number(StuLink* phead, int number) {
    assert(phead != NULL);

    //StuLink* ptemp = phead;
    StuLink* pr = phead;
    //This pointer is point to the delete node
    StuLink* pn = phead;
    //char isDelete = 0;

    while (pn) {
        if (number == pn->number) {
            //delete_node(phead, pn, pr);
            remove_node(&phead, pn);
            break;
        }

        pr = pn;
        pn = pn->pnext;

    }
    return phead;
}

/** \brief Delete a node.
 *
 * \param p_phead: The head of the StuLink.
 * \param p_pnode: The node that you want to delete.
 * \param p_privew:The point that point to the node pre.
 * \return void.
 */
void delete_node(StuLink* p_phead, StuLink* p_pnode, StuLink* p_privew) {
    char _isDelete = 0;

    printf("Sure to delete the node?\n");
    show_one_node(p_pnode);
    printf("y or n: ");
    while ((_isDelete = getchar()) == '\n');

    if ('Y' == _isDelete || 'y' == _isDelete) {
        if (p_pnode == p_phead) {

            //delete head node
            p_phead = p_phead->pnext;
        } else {

            //if pn->pnext = NULL, then we can delete the last	node.

            p_privew->pnext = p_pnode->pnext;
        }
        free(p_pnode);
        p_pnode = NULL;
    }
}

/** \brief Delete a node.
 *
 * \param p_phead: The address of the StuLink head.
 * \param p_pnode: The node that you want to delete.
 * \return void.
 */
void remove_node(StuLink** p_phead, StuLink* p_pnode) {
    char isDelete = 0;

    printf("Sure to delete the node?\n");
    show_one_node(p_pnode);
    printf("y or n: ");
    while ((isDelete = getchar()) == '\n');

    if ('Y' == isDelete || 'y' == isDelete) {

        StuLink** indirect = p_phead;

        //Find p_pnode
        while (*indirect != p_pnode)
            indirect = &(*indirect)->pnext;

        //Remove p_pnode
        *indirect = p_pnode->pnext;
    }

}



/** \brief This function can save student data to local file.
 *
 * \param	phead : the pointer of the phead.
 * \param   pfilename : the name of the save file.
 * \return	void.
 */
void save_file(StuLink* phead, char* pfilename) {
    assert(phead != NULL);

    FILE* pfw = fopen(pfilename, "ab");
    assert(pfw != NULL);

    StuLink* ptemp = phead;
    int write_count = 0;
    while (ptemp) {
        if (1 == fwrite(ptemp, sizeof(StuLink), 1, pfw)) {
            write_count++;
            fflush(pfw);
        }

        ptemp = ptemp->pnext;
    }
    fclose(pfw);
    printf("\tsave to file success, write count = %d\n", write_count);
}

/** \brief This function can read student data from local file.
 *
 * \param	phead : the pointer of the phead.
 * \param   pfilename : the name of the local file.
 * \return	StuLink* : The head of the read StuLink data.
 */
StuLink* read_file(StuLink* phead, char* pfilename) {

    FILE* pfr = fopen(pfilename, "rb");
    assert(pfr != NULL);

    StuLink* ptemp = malloc_node();
    int read_count = 0;

    while (1 == fread(ptemp, sizeof(StuLink), 1, pfr)) {
        //fflush(pfr);
        read_count++;
        phead = add_node_front(phead, ptemp);
        ptemp = malloc_node();
    }

    //Don`t foget to free the last malloc node
    free(ptemp);
    fclose(pfr);

    printf("\n\tRead file success, read count = %d\n", read_count);
    return phead;
}

/** \brief Init file name
 * \param p_pfile_name: The file name you want to init
 * \return void.
 */
void init_file(char* p_pfile_name) {
    printf("please input the file name: ");
    scanf("%s", p_pfile_name);
}

/** \brief	This function which you can use to operate the student data in the set of [search, delete, modify].
 *
 * \param	p_head : the pointer of the phead.
 * \param   operation_array : the array of the operation string.
 * \param	p_fun_name : The function point that type id define in the fun.h
 * \param	p_fun_number : The function point that type id define in the fun.h
 * \return	StuLink* : The node point that type is StuLink*.
 *
 * You can use this function to search or delete or modify a node data in function:menu_fun
 */
StuLink* search_delete_modify_operation(StuLink* p_head, const char* operation_array[], Fun_By_Name p_fun_name, Fun_By_Number p_fun_number) {

    //Get select number
    int temp_menu_chose = menu_search_delete_modify(operation_array, 2);

    int node_number = 0;
    char node_name[20];

    char temp_op_str[7] = {0};
    strncpy(temp_op_str, operation_array[0], 6);
    //ptemp = operation_array[0];
    //*(ptemp + 6) = '\0';

    if (1 == temp_menu_chose) {
        printf("please input %s node name: ", temp_op_str);
        scanf("%s", node_name);
        return p_fun_name(p_head, node_name);
    } else {
        printf("please input %s node number: ", temp_op_str);
        scanf("%d", &node_number);
        return  p_fun_number(p_head, node_number);
    }
}


/** \brief Modify a node by the student`s name in the StuLink.
 *
 * \param	p_phead : The head of the StuLink.
 * \param	p_pname : The student name of the delete.
 * \return	StuLink* : The head of the StuLink that has modify the node that name is equal to p_pname
 */
StuLink* modify_node_by_name(StuLink* p_phead, char* p_pname) {
    int _chose = modify_select();

    StuLink* _ptemp = p_phead;

    while (_ptemp) {
        //Find the node that need to modify.
        if (!strcmp(p_pname, _ptemp->name)) {
            modify_node(_ptemp, _chose);
            break;
        }
        _ptemp = _ptemp->pnext;
    }

    return _ptemp;
}

/** \brief Modify a node by the student`s number in the StuLink.
 *
 * \param	p_phead : The head of the StuLink.
 * \param	p_number : The student number of the delete.
 * \return	StuLink* : The head of the StuLink that has modify the node that name is equal to p_pname
 */
StuLink* modify_node_by_number(StuLink* p_phead, int p_number) {
    int _chose = modify_select();

    StuLink* _ptemp = p_phead;

    while (_ptemp) {
        //Find the node that need to modify.
        if (p_number == _ptemp->number) {
            modify_node(_ptemp, _chose);
            break;
        }
        _ptemp = _ptemp->pnext;
    }

    return _ptemp;
}

/** \brief  Modify a node data
 *
 * \param	p_pnode : The node that you want to modify.
 * \param	p_chose : The part that you want to modify in the p_pnode.
 * \return	void.
 */
void modify_node(StuLink* p_pnode, int p_chose) {
    int _temp_number = 0;
    int _temp_age = 0;
    float _temp_score = 0;
    char _temp_name[10] = {0};

    switch (p_chose) {
    case 1:
        printf("please input the new number: ");
        scanf("%d", &_temp_number);
        p_pnode->number = _temp_number;
        break;

    case 2:
        printf("please input the new age: ");
        scanf("%d", &_temp_age);
        p_pnode->age = _temp_age;
        break;

    case 3:
        printf("please input the new score: ");
        scanf("%f", &_temp_score);
        p_pnode->score = _temp_score;
        break;

    case 4:
        printf("please input the new name: ");
        scanf("%s", _temp_name);
        strcpy(p_pnode->name,_temp_name);
        break;

    default:
        break;

    }

}


/** \brief Return a number that you select the part of the StuLink
 *
 * \param	void.
 * \param	void.
 * \return	int : The number of your chose.
 */
int modify_select() {
    puts("\t1.modify number");
    puts("\t2.modify age");
    puts("\t3.modify score");
    puts("\t4.modify name");
    puts("please input your modify chose[1,4]: ");

    int _chose = 0;
    scanf("%d", &_chose);
    return _chose;
}








