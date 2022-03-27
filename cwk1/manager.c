#include "head.h"
#include "book_management.h"

//Manager port - used to connect functions
void manager_port(void)
{
	char choose = '1';
	while(choose != '0')
	{
		show_manager();
		printf("\t\t\tOption:");
		scanf("%c", &choose);
		while(getchar() != '\n');
		switch(choose)
		{
			case '1':
			    manager_login();
			    break;
			case '0':
			    break;
			default:printf("\t\tInput errors, please re-enter.\n");break;
		}
	}
}

Manager *find_nam(char *Man_acc)
{
    Manager *t = manager_head->next;
    while(t){
        if (strcmp(t->man_user, Man_acc) == 0)
        {
            break;
        }
        t = t->next;
    }
    return t;
}

void manager_login(void)
{
	char Manager_num[50];
	char ml = '1';
	int l = 1;
	Manager *enter_man;
	Book book;
	while(l != 6){
	    printf("\n\t\tUsername Accounts(6 digits):");
	    gets(Manager_num);
	    l = strlen(Manager_num);
	    if(l != 6)
	        printf("\t\tThe account number is incorrect, please enter the correct length of the account number\n");
	}
	Manager_num[6] = '\0';
	enter_man = find_nam(Manager_num);
	if(enter_man == NULL){
		printf("\t\tSorry, the manager is not exist.\n");
		printf("\t\tPress any key to exit.");
		getch();
		return;
	}
	printf("\t\tpassword: ");
	if(password_find(enter_man->man_pas)==0){
	    printf("\n\t\tThe password has been entered incorrectly three times, "
               "and the login system will be logged out...\n");
		return;
	}
	printf("\t\tlogin successful!\n");

	while(ml!='0')
	{
	    manager_enter();
	    printf("\t\tOption:");
	    scanf("%c",&ml);
	    while(getchar() != '\n');
	    switch(ml)
	    {
	        case '1':add_book(book);break;
	        case '2':remove_book(book);break;
	        case '3':print_book();break;
	        case '0':break;
	        default:printf("\t\tInput errors, please re-enter.\n");break;
	    }
	}
}

int add_book(Book book)
{
    unsigned int id = 0;
    Book *t,*p,*q;
    t = list_head->list;
    q = t;
    p = t->next;
    char *n  = (char *) malloc(200*sizeof (char));
    printf("\t\tPlease enter these information: \n");

    for(;;)
    {
        if(p == NULL)
        {
            p = (Book *) malloc(sizeof (Book));
            p->id = id + 1;
            printf("\t\tbook title:");
            fflush(stdin);
            gets(n);
            book.title = (char *) malloc(200*sizeof (char));
            strcpy(book.title,n);
            p->title = book.title;
            printf("\t\tauthors:");
            fflush(stdin);
            gets(n);
            book.authors = (char *) malloc(200*sizeof (char));
            strcpy(book.authors,n);
            p->authors = book.authors;
            printf("Please enter the publication date of the new book:");
            fflush(stdin);
            gets(n);
            book.year = atoi(n);
            p->year = book.year;
            printf("Please enter the copies of the new book:");
            fflush(stdin);
            gets(n);
            book.copies = atoi(n);
            p->copies = book.copies;

            p->next = NULL;
            q->next = p;
            break;
        }
        id = p->id;
        q = p;
        p = p->next;
    }
    free(n);
    printf("\t\tLaunched successfully!\n");
    printf("\t\tPress any key to exit.");
    getch();
    return 0;
}


int remove_book(Book book)
{
    unsigned int id;
    int i;
	Book *p = list_head->list;
	Book *q;
	Student *h;
	h = student_head;
	h = h->next;
	if(!p)
	{
	    printf("\t\tNo books yet.");
	    exit(1);
	}
	print_book();
	printf("\t\tPlease enter the number of the book to be removed:");
    scanf("%d", &id);
	book_exit(id);
	book.id = id;
	while(p->id != id)
	{
	    if(p->next==NULL)
	    {
	        printf("\t\tNo this book, press any key to return.\n");
	        getch();
	        return 0;
	    }
	    q = p;
	    p = p->next;				//point to the next node
	}
	for(;;)
	{
        if(h == NULL) break;
	    for(i = 0; i < 10; i++)
	    {
	        if(h->stu_bookid[i] == book.id)
	        {
	            printf("\t\tSorry, this book is still borrowed, fail to remove.\n");
                exit(1);
	        }
	    }
	    h = h->next;
	}
	if(p == list_head->list) //The deleted book is at the head of the linked list.
	{
	    list_head->list = p->next;
	    free(p);
	}
	else if(p->next == NULL) //The deleted book is at the end of the linked list.
	{
	    q->next = NULL;
	    free(p);
	}
	else
	{
	    q->next = p->next;
	    free(p);
	}
	printf("\t\tTaken down successfully!\n");
	printf("\t\tPress any key to exit.");
	getch();
	return 0;
}
