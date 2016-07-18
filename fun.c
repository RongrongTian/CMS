#include "fun.h"

/*Init a new node data*/
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


/*Malloc a new node*/
StuLink* malloc_node() {

	StuLink* ptemp = (StuLink*)malloc(sizeof(StuLink));
	assert(ptemp != NULL);

	return ptemp;
}


/*Add a node to the head of the LinkList*/
StuLink* add_node(StuLink* phead) {
	
	StuLink* ptemp = malloc_node();

	//init node data
	init_node(ptemp);
	
	if (NULL == phead) {
		ptemp->pnext = NULL;
		phead = ptemp;
	} else {
		ptemp->pnext = phead;
		phead = ptemp;
	}

	return phead;
}

/*Show all node*/
void show_node(StuLink* phead) {
	if (NULL == phead) {
		printf("The StuLink is NULL\n");
		return;
	}

	StuLink* ptemp = phead;
	while (ptemp) {
		printf("%d %d %6.2f %s\n", ptemp->number, ptemp->age, ptemp->score, ptemp->name);
		ptemp = ptemp->pnext;
	}
	
}

/*Search a node by the name*/
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

/*Search a node by the number*/
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



/*Free all node*/
void free_all_node(StuLink* phead) {
	assert(phead != NULL);
	StuLink* ptemp = phead;
	
	while (ptemp) {
		phead = phead->pnext;
		free(ptemp);
		ptemp = phead;
	}

}


/*Only show one node*/
void show_one_node(StuLink* pnode) {
	if (pnode != NULL) {
		printf("\t%d %d %6.2f %s\n", pnode->number, pnode->age, pnode->score, pnode->name);
	} else {
		printf("\tshow_one_node: pnode = NULL\n");
	}
} 


/*This function can show menu by different operator*/
int menu_search_delete_modify(char** pstring, int num) {
	
	for (int i = 0; i < num; i++) {
		printf("\t%d. %s\n", i + 1, pstring[i]);
	}

	int chose = 0;
	printf("\t\nplease input your chose: ");
	scanf("%d", &chose);

	return chose;
}


/*Delete a node by name*/
StuLink* delete_node_by_name(StuLink* phead, char* pname) {
	assert(phead != NULL);
	assert(pname != NULL);

	//StuLink* ptemp = phead;
	StuLink* pr = phead;
	StuLink* pn = phead;//This pointer is point to the delete node
	char isDelete = 0;

	while (pn) {
		if (!strcmp(pn->name, pname)) {
			
			printf("Sure to delete the node?\n");
			show_one_node(pn);
			printf("y or n: ");
			while ((isDelete = getchar()) == '\n');
			
			if ('Y' == isDelete || 'y' == isDelete) {
				if (pn == phead) {

					//delete head node
					phead = phead->pnext;
				} else {
					/*
						if pn->pnext = NULL, then we can delete the last						node.
					*/
					pr->pnext = pn->pnext;
				}
				free(pn);
				pn = NULL;
				break;
			}
		}
		pr = pn;
		pn = pn->pnext;
	
	}
	return phead;
}



/*Delete a node by number*/
StuLink* delete_node_by_number(StuLink* phead, int number) {
	assert(phead != NULL);

	//StuLink* ptemp = phead;
	StuLink* pr = phead;
	StuLink* pn = phead;//This pointer is point to the delete node
	char isDelete = 0;

	while (pn) {
		if (number == pn->number) {
			
			printf("Sure to delete the node?\n");
			show_one_node(pn);
			printf("y or n: ");
			while ((isDelete = getchar()) == '\n');
			
			if ('Y' == isDelete || 'y' == isDelete) {
				if (pn == phead) {

					//delete head node
					phead = phead->pnext;
				} else {
					/*
						if pn->pnext = NULL, then we can delete the last						node.
					*/
					pr->pnext = pn->pnext;
				}
				free(pn);
				pn = NULL;
				break;
			}
		}
		pr = pn;
		pn = pn->pnext;
	
	}
	return phead;
}

void save_file(StuLink* phead, char* pfilename) {
	assert(phead != NULL);
	
	FILE* pfw = fopen(pfilename, "wb");
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

/*Read Stu data from file to memory*/
StuLink* read_file(StuLink* phead, char* pfilename) {

	FILE* pfr = fopen(pfilename, "rb");
	assert(pfr != NULL);
	
	StuLink* ptemp = malloc_node();
	int read_count = 0;

	while (1 == fread(ptemp, sizeof(StuLink), 1, pfr)) {
		fflush(pfr);
		read_count++;
		phead = add_node(ptemp);
		ptemp = malloc_node();
	}

	free(ptemp);//Don`t foget to free the last malloc node
	fclose(pfr);

	printf("\n\tRead file success, read count = %d\n", read_count);
	return phead;
}



