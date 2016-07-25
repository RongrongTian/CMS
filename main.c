#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include "fun.h"
#include "sort.h"


/*Show menu to user*/
void show_menu(int* pchose) {

	printf("\n");
	printf("--------Welocme to C Manage System--------\n");
	printf("\t1.Add a node to System\n");
	printf("\t2.Delete a node from System\n");
	printf("\t3.Search a node from System\n");
	printf("\t4.Modify a node from System\n");
	printf("\t5.Show all node from System\n");
	printf("\t6.Free all node from System\n");
	printf("\t7.Save data to local file\n");
	printf("\t8.Read data from local file\n");
	printf("\t9.Sort all node.\n");
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
			puts("\nDelete Node:");
			phead = search_delete_modify_operation(phead, delete, delete_node_by_name, delete_node_by_number);
			break;
		case 3:
			puts("\nSearch Node:");
			pret_node = search_delete_modify_operation(phead, search, search_node_by_name, search_node_by_number);
			show_one_node(pret_node);
			break;
		case 4:
			puts("\nModify Node:");
			pret_node = search_delete_modify_operation(phead, modify, modify_node_by_name, modify_node_by_number);
			show_one_node(pret_node);
			break;
		case 5:
			puts("\nShow Node:");
			show_node(phead);
			break;
		case 6:
			puts("\nFree Node:");
			free_all_node(phead);
			phead = NULL;
			break;
		case 7:
			puts("\nSave file:");
			init_file(file_name);
			save_file(phead, file_name);
			break;
		case 8:
			puts("\nRead file:");
			init_file(file_name);
			phead = read_file(phead, file_name);
			break;
        case 9:
            puts("Sort node:");
            //get_length(phead);
            StuLink** pnode_array = sort_init(phead);
            qsort_stulink(pnode_array, get_length(phead), sizeof(pnode_array[0]), sort_by_number);
            show_node_array(pnode_array, get_length(phead), sizeof(pnode_array[0]));
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
		show_menu(&chose);
		phead = menu_fun(phead, chose);
	}

	return 0;
}
