#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include "fun.h"
#include "sort.h"
#include "CMS_Utils.h"

#define IS_HEAD_NULL(phead) if (!is_head_NULL(phead)) {\
                printf("The System don`t has data now, if you want to add a node, please input 1.\n");\
                return phead;\
		    }

/*Show menu to user*/
void show_menu(int* pchose) {

	printf("\n");
	printf("--------Welocme to C Manage System--------\n\n");
	printf("\t1.Add a node to System\n");
	printf("\t2.Delete a node from System\n");
	printf("\t3.Search a node from System\n");
	printf("\t4.Modify a node from System\n");
	printf("\t5.Show all node from System\n");
	printf("\t6.Free all node from System\n");
	printf("\t7.Save data to local file\n");
	printf("\t8.Read data from local file\n");
	printf("\t9.Sort all data.\n");
	printf("\t0.Exit System\n");

	printf("\nplease chose the number[0, 9]:");
	scanf("%d", pchose);

	putchar('\n');
}

/*Chose function from chose*/
StuLink* menu_fun(StuLink* phead, int chose) {
	StuLink* pret_node = NULL;
	char file_name[50];

	switch (chose) {
		case 1:
			puts("\nAdd Node:");
			StuLink* ptemp = malloc_node();
			init_node(ptemp);
			if (1 == add_node_operation_select())
                phead = add_node_front(phead, ptemp);
            else
                phead = add_node_back(phead, ptemp);
			break;
		case 2:
		    IS_HEAD_NULL(phead);
			puts("\nDelete Node:");
			phead = search_delete_modify_operation(phead, delete, delete_node_by_name, delete_node_by_number);
			break;
		case 3:
            IS_HEAD_NULL(phead);
			puts("\nSearch Node:");
			pret_node = search_delete_modify_operation(phead, search, search_node_by_name, search_node_by_number);
			show_one_node(pret_node);
			break;
		case 4:
		    IS_HEAD_NULL(phead);
			puts("\nModify Node:");
			pret_node = search_delete_modify_operation(phead, modify, modify_node_by_name, modify_node_by_number);
			show_one_node(pret_node);
			break;
		case 5:
		    IS_HEAD_NULL(phead);
			puts("\nShow Node:");
			show_node(phead);
			break;
		case 6:
		    IS_HEAD_NULL(phead);
			puts("\nFree Node:");
			free_all_node(phead);
			phead = NULL;
			break;
		case 7:
		    IS_HEAD_NULL(phead);
			puts("\nSave file:");
			init_file(file_name);

			save_file(phead, file_name);

			//save_text_file(phead, file_name);
			break;
		case 8:
			puts("\nRead file:");
			init_file(file_name);
			free_all_node(phead);
			phead = NULL;
			phead = read_file(phead, file_name);
			//phead = read_text_file(phead, file_name);
			break;
        case 9:
            IS_HEAD_NULL(phead);
            puts("Sort node:");
            size_t _length = get_length(phead);

            StuLink** pnode_array = sort_init(phead);

            //sort function pointer array, define in sort.h
            sort_pointer sort_fun_array[] = {
            sort_by_number_less, sort_by_age_less, sort_by_score_less, sort_by_name_less,
            sort_by_number_greater, sort_by_age_greater, sort_by_score_greater, sort_by_name_less};

            //start qsort.
            qsort_stulink(pnode_array, _length, sizeof(pnode_array[0]), sort_fun_array[sort_operation() - 1]);

            //print node array that has been qsort.
            show_node_array(pnode_array, _length);

            //保存排序之后的文本
            init_file(file_name);
            save_sort_text_file(pnode_array, file_name, _length);

            free(pnode_array);
            pnode_array = NULL;
            break;
		case 0:
			puts("\nExit System!");
			free_all_node(phead);
			phead = NULL;
			exit(0);
			break;
		default:
			break;
	}
	return phead;
}

int main() {

	int chose = 0;
	StuLink* phead = NULL;

	while (1) {
        //Show operation menu and select.
		show_menu(&chose);

        //Execute menu operation.
		phead = menu_fun(phead, chose);
	}

	return 0;
}



int main2() {

    int x[2][2] = {1, 2, 3, 4};
    printf("%x", &x[1]);

    return 0;
}


