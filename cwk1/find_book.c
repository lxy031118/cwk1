#include "head.h"
#include "book_management.h"

void find_book(void)
{
    char fb = '1';
    char *title, *author;
    int year;
    while(fb != '0')
    {
        find_book_menu();
        printf("\t\t\tOption:");
        scanf("%s", &fb);
        while(getchar() != '\n');
        switch(fb)
        {
            case '1':
                title = (char *) malloc(200*sizeof (char));
                printf("Please enter the book title: \n");
                fflush(stdin);
                gets(title);
                find_book_by_title(title);
                break;
            case '2':
                author = (char *) malloc(200*sizeof (char));
                printf("Please enter the book's author: \n");
                fflush(stdin);
                gets(author);
                find_book_by_author(author);
                break;
            case '3':
                printf("Please enter the book's publish year: \n");
                scanf("%d",&year);
                find_book_by_year(year);
                break;
            case '0':
                break;
            default:
                printf("\t\tInput errors, please re-enter.\n");
                break;
        }
    }
}

BookList find_book_by_title (const char *title)
{
    Book *p;
    p = list_head->list;
    p = p->next;
    while(strcmp(title, p->title) != 0)
    {
        if(p->next == NULL)
        {
            printf("\t\tNot found, press any key to return.");
            getch();
            break;
        }
        p = p->next;
    }
    while(p != NULL)
    {
        if(strcmp(title, p->title) == 0)
        {
            printf("\t %s - %s - %s - %s\n\n", "book id","book name","author","year");
            printf("\t %d - %s - %s - %d\n", p->id, p->title, p->authors, p->year);
        }
        p = p->next;
    }
    printf("\n\t**************************************");
    printf("****************************\n\n\n");
    printf("\n\t\tPress any key to exit.");
    getch();
}

BookList find_book_by_author (const char *author)
{
    Book *q;
    q = list_head->list;
    q = q->next;
    while(strcmp(author, q->authors) != 0)
    {
        if(q->next == NULL)
        {
            printf("\t\tNot found, press any key to return.");
            getch();
            break;
        }
        q = q->next;
    }
    printf("3");
    while(q != NULL)
    {
        if(strcmp(author, q->authors) == 0)
        {
            printf("\t %s - %s - %s - %s\n\n", "book id","book name","author","year");
            printf("\t %d - %s - %s - %d\n", q->id, q->title, q->authors, q->year);
        }
        q = q->next;
    }
    printf("\n\t**************************************");
    printf("****************************\n\n\n");
    printf("\n\t\tPress any key to exit.");
    getch();
}

BookList find_book_by_year (unsigned int year)
{
    Book *p;
    p = list_head->list;
    p = p->next;
    while(year != p->year)
    {
        if(p->next==NULL)
        {
            printf("\t\tNot found, press any key to return.");
            getch();
            break;
        }
        p = p->next;
    }
    while(p != NULL)
    {
        if(year == p->year)
        {
            printf("\t %s - %s - %s - %s\n\n", "book id","book name","author","year");
            printf("\t %d - %s - %s - %d\n", p->id, p->title, p->authors, p->year);
        }
        p = p->next;
    }
    printf("\n\t**************************************");
    printf("****************************\n\n\n");
    printf("\n\t\tPress any key to exit.");
    getch();
}

