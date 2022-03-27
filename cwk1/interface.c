#include "head.h"
void show_menu(void)
{
	printf("\n\n\n\n\t\t\t\tLeeds library");
	printf("\n\t\t\t*************************\n\n");
	printf("\t\t\t\t1)Student side\n");
	printf("\t\t\t\t2)Manager side\n");
	printf("\t\t\t\t0)exit\n");
	printf("\n\t\t\t*************************\n\n");
}
void show_stu(void)
{
	printf("\n\n\n\t\t\t\t Student side");
	printf("\n\t\t\t*************************\n\n");
	printf("\t\t\t\t1)loge in\n");
	printf("\t\t\t\t2)register\n");
	printf("\t\t\t\t0)return\n");
	printf("\n\t\t\t*************************\n\n");
}
void stu_enter(void)
{
	printf("\n\n\n\t\t\t\t Student page");
	printf("\n\t\t\t*************************\n\n");
	printf("\t\t\t\t1)Borrow books\n");
	printf("\t\t\t\t2)Return book\n");
	printf("\t\t\t\t3)Find book\n");
	printf("\t\t\t\t0)return\n");
	printf("\n\t\t\t*************************\n\n");
}
void find_book_menu()
{
    printf("\n\n\n\t\t\t\t Student page - Search book");
    printf("\n\t\t\t*************************************\n\n");
    printf("\t\t\t\t1)Find books by title\n");
    printf("\t\t\t\t2)Find books by author\n");
    printf("\t\t\t\t3)Find books by year\n");
    printf("\t\t\t\t0)return\n");
    printf("\n\t\t\t*************************************\n\n");
}
void show_manager(void)
{
	printf("\n\n\n\t\t\t\t Manager side");
	printf("\n\t\t\t*************************\n\n");
	printf("\t\t\t\t1)loge in\n");
	printf("\t\t\t\t         \n");
	printf("\t\t\t\t0)return\n");
	printf("\n\t\t\t*************************\n\n");
}
void manager_enter(void)
{
	printf("\n\n\n\t\t\t\t Manager page");
	printf("\n\t\t\t*************************\n\n");
	printf("\t\t\t\t1)add book\n");
	printf("\t\t\t\t2)delete book\n");
	printf("\t\t\t\t3)display all books\n");
	printf("\t\t\t\t0)exit\n");
	printf("\n\t\t\t*************************\n\n");
}

