#include "head.h"
#include "book_management.h"

int main(void)
{
    CreateBookNode(book_head);
    CreateListNode(list_head);
	CreateStuNode(student_head);
    CreateManNode(manager_head);

	FILE *file;
	file = fopen("Book.txt","r");
	if(file == NULL) file = fopen("Book.txt","w+");
	load_books(file);
	fclose(file);

	FILE *fp;
	fp = fopen("Student.txt","r");
	if(fp == NULL) fp = fopen("Student.txt","w+");
	student_load(fp);
	fclose(fp);

	manager_head->next=Manager_load();

	char choose = '1';

	while(choose != '0')
	{
	    show_menu();
	    printf("\t\t\tOption:");
	    scanf("%c", &choose);
	    while(getchar() != '\n');
	    switch(choose)
	    {
	        case '1':student_port();break;
	        case '2':manager_port();break;
	        case '0':break;
	        default:printf("\t\tInput errors, please re-enter.\n");break;
	    }
	}
	FILE *fp1;
	fp1 = fopen("Book.txt","w+");
	store_books(fp1);
	fclose(fp1);
	FILE *fp2;
	fp2 = fopen("Student.txt","w+");
	store_student(fp2);
	fclose(fp2);
	return 0;
}