#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include "fun.h"

/*Show menu to user*/
void show_menu(int* pchose) {
	
	printf("\n");	
	printf("\t-----Welocme to LinkList System-----\n");
	printf("\t------1.Add a node to LinkList------\n");
	printf("\t------2.Delete a node from LinkList-\n");
	printf("\t------3.Search a node from LinkList-\n");
	printf("\t------4.Modify a node from LinkList-\n");
	printf("\t------5.Show all node from LinkList-\n");
	printf("\t------6.Free all node from LinkList-\n");
	printf("\t------7.Save data to local file-----\n");
	printf("\t------8.Read data from local file---\n");
	printf("\t------0.Exit System-----------------\n");
	
	printf("\nplease chose the number[0, 8]:");
	scanf("%d", pchose);
	
	putchar('\n');
}

/*Chose function from chose*/
StuLink* menu_fun(StuLink* phead, int chose) {

	char* search[] = {"search by name", "search by number"};
	char* delete[] = {"delete by name", "delete by number"};
	char* modify[] = {"modify by name", "modify by number"};

	int temp_menu_chose = 0;
	int node_number = 0;
	char node_name[20];
	StuLink* pret_node = NULL;
	char file_name[50];
	
	switch (chose) {
		case 1:
			puts("\nAdd Node:");
			phead = add_node(phead);
			break;
		case 2:
			puts("\nDelete Node:");
			temp_menu_chose = menu_search_delete_modify(delete, 2);
			
			if (1 == temp_menu_chose) {
				printf("please input delete node name: ");
				scanf("%s", node_name);
				phead = delete_node_by_name(phead, node_name);
		
			} else {
				printf("please input delete node number: ");
				scanf("%d", &node_number);
				phead = delete_node_by_number(phead, node_number);
			}
			break;
		case 3:
			puts("\nSearch Node:");
			temp_menu_chose = menu_search_delete_modify(search, 2);
			
			if (1 == temp_menu_chose) {
				printf("please input search node name: ");
				scanf("%s", node_name);
				pret_node = search_node_by_name(phead, node_name);
				
				show_one_node(pret_node);
		
			} else {
				printf("please input search node number: ");
				scanf("%d", &node_number);
				pret_node = search_node_by_number(phead, node_number);
			
				show_one_node(pret_node);
			}
			break;
		case 4:
			puts("\nModify Node:");
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
			printf("please input the save file name: ");
			scanf("%s", file_name);
		//	getchar();
			save_file(phead, file_name);
			break;
		case 8:
			puts("\nRead file:");
			printf("Please input the read file name: ");
			scanf("%s", file_name);
			getchar();
			phead = read_file(phead, file_name);
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