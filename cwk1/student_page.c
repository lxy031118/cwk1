#include "head.h"
#include "book_management.h"

void stu_borrow(Student *Stu_num)
{
	int n = 0;
	int i;
	Book *p;
    if(p == NULL) exit(1);
	int numb;
	for(i = 0; i < 10; i++)
	{
	    if(Stu_num->stu_bookid[i] != 0) n++;
	}
	printf("\n\t\tWelcome to the borrowing system\n");
	if(n == 10){
	    printf("\t\tHello, you have borrowed 10 books and have reached the maximum borrowing limit");
	    printf("\t\tPlease return the borrowed books first\n\n");
		printf("\t\tPress any key to exit.");
		getch();
		return;
	}
	printf("\t\tYou have borrowed %d books, and you can borrow %d books\n", n, 10-n);
	printf("\n\t\tThe book list is as follows");
	print_book();
	printf("\n\t\tPlease select the number of the book you want to borrow:");
    scanf("%d", &numb);
	p = book_exit(numb);
	printf("\t\tin progress...\n");
	if(p == NULL)
	{
	    printf("\t\tSorry, no books yet, failed to borrow books\n");
	    printf("\t\tPress any key to exit.");
	    getch();
	    return;
	}
	if(ifborrow(Stu_num, numb) == 1)
	{
	    printf("\t\tSorry, you have already borrowed this book, please do not borrow it again\n");
	    printf("\t\tPress any key to exit.");
	    getch();
	    return;
	}

	if(p->copies == 0)
	{
	    printf("\t\tSorry, insufficient stock, failed to borrow books\n");
		printf("\t\tPress any key to exit.");
		getch();
		return;
	}
	for(i = 0; i < 10; i++)
	{
	    if(Stu_num->stu_bookid[i] == 0)
	    {
	        Stu_num->stu_bookid[i] = numb;
			p->copies--;
			break;
		}
	}
	printf("\t\tCongratulations on your success!\n");
	printf("\t\tPress any key to exit.");
	getch();
}

void print_book(void)
{
    int n = 0;
    BookList *p1;
    p1 = list_head;
	Book *p = list_head->list;
	p = p->next;
	if(p == NULL){
	    printf("\t\tSorry, no books yet.\n");
		Sleep(2000);
		return;
	}
	printf("\n\n\t**********************************");
	printf("********************************\n\n");
	printf("\t %s - %s - %s - %s\n\n", "book id","book name","author","year");
	while(p){
	    printf("\t %d - %s - %s - %d\n", p->id, p->title, p->authors, p->year);
	    n++;
		p = p->next;
	}
	p1->length = n;
	printf("\n\t**************************************");
	printf("****************************\n\n\n");
	printf("\n\t\tHave a total of %d books.", n);
	printf("\n\t\tPress any key to exit the book list.");
	getch();
}

Book *book_exit(unsigned int Book_id)
{
	Book *t = list_head->list;
	t = t->next;
	while (1)
	{
	    if(t == NULL)
	    {
	        printf("\t\tSorry, no such book.");
            exit(1);
	    }
	    if(t->id == Book_id)
	    {
            break;
	    }
	    t = t->next;
	}
    return t;
}

int ifborrow(Student *Stu_num, unsigned int Book_id)
{
	int n = 0;
	int i;
	for(i = 0; i < 10; i++){
	    if(Stu_num->stu_bookid[i] == Book_id){
			n = 1;
			break;
		}
	}
	return n;
}

void borrow_status(Student *Stu_num)
{
    int i;
    Book *t;
    printf("\n\n\t*************************");
    printf("********************************\n\n");
    printf("\t %s - %s - %s - %s\n\n", "book id", "book name", "author", "year");
    for(i = 0; i < 10; i++){
        if(Stu_num->stu_bookid[i] != 0){
            t = borrowed_book_id(Stu_num->stu_bookid[i]);
            printf("\t %d - %s - %s - %d\n", t->id, t->title, t->authors, t->year);
        }
    }
    printf("\n\t*****************************");
    printf("****************************\n\n\n");
}

Book *borrowed_book_id(unsigned int Book_id)
{
    Book *t = list_head->list;
    t = t->next;
    while(t){
        if(Book_id == t->id)
            return t;
        t = t->next;
    }
    return t;
}

void stu_return(Student *Stu_num)
{
	unsigned int book_num;
	int n = 0;
	int i;
	printf("\n\t\tWelcome to the book return system\n");
	printf("\n\t\tLooking for borrowed books...\n");
	for(i = 0; i < 10; i++)
	{
	    if(Stu_num->stu_bookid[i] != 0){
			n = 1;
			break;
		}
	}
	if(n == 0){
	    printf("\n\t\tNo borrowing records\n");
		printf("\n\t\tPress any key to exit.");
		getch();
		return;
	}
	printf("\n\t\tThis is the list of your borrowed books...\n");
	borrow_status(Stu_num);
	printf("\n\t\tPlease enter the number of the book to return:");
    scanf("%d", &book_num);
	n = 0;
	for(i = 0; i < 10; i++){
	    if(Stu_num->stu_bookid[i] == book_num){
			n = 1;
			break;
		}
	}
	if(n == 0){
	    printf("\t\tTyping error, you have not borrowed this book\n");
		printf("\t\tPress any key to exit.");
		getch();
		return;
	}
	Book *t;
	t = borrowed_book_id(book_num);
	for(i = 0; i < 10; i++){
	    if(Stu_num->stu_bookid[i] == book_num){
	        Stu_num->stu_bookid[i] = 0;
	        t->copies++;
	        break;
	    }
	}
	printf("\t\tThe return was successful!\n");
	printf("\t\tPress any key to exit.");
	getch();
}
