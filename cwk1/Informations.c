#include "head.h"
#include "book_management.h"

int load_books(FILE *file){
    list_head->list = (Book *) malloc(sizeof (Book));
    char *buff = (char *) malloc(sizeof (char));
    Book *h = (Book *) malloc(sizeof (Book));
    Book *t, *p;
    list_head->list = h;
    t = list_head->list;
    for(;;)
    {
        if(fgets(buff, 1024, file) == NULL) break;
        CreateBookNode(p);
        p->id = atoi(buff);

        fgets(buff, 100, file);
        p->title = (char *)malloc(sizeof(buff));
        buff[strlen(buff)-1] = '\0';
        strcpy(p->title, buff);

        fgets(buff, 100, file);
        p->authors = (char *)malloc(sizeof(buff));
        buff[strlen(buff)-1] = '\0';
        strcpy(p->authors, buff);

        fgets(buff,50,file);
        buff[strlen(buff)-1] = '\0';
        p->year = atoi(buff);

        fgets(buff,50,file);
        buff[strlen(buff)-1] = '\0';
        p->copies = atoi(buff);

        t->next = p;
        t = p;
    }
    t->next = NULL;
    return 0;
}

int store_books(FILE *file)
{
    Book *t;
    t = list_head->list;
    t = t->next;
    if(file == NULL) return -1;
    if(!t) return 0;
    while(t)
    {
        fprintf(file,"%d\n", t->id);
        fprintf(file,"%s\n", t->title);
        fprintf(file,"%s\n", t->authors);
        fprintf(file,"%d\n", t->year);
        fprintf(file,"%d\n", t->copies);
        t = t->next;
    }
    return 0;
}

int student_load(FILE *file)
{
    int i;
    student_head = (Student *) malloc (sizeof(Student));
    Student *h, *p, *t;
    CreateStuNode(h);
    student_head = h;
    t = student_head;
    char *buff;
    buff = (char *) malloc(500*sizeof(char));
    for(;;)
    {
        if (fgets(buff,500,file) == NULL) break;
        CreateStuNode(p);
        p->stu_name = (char *) malloc(500*sizeof (buff));
        buff[strlen(buff)-1] = '\0';
        strcpy(p->stu_name, buff);

        fgets(buff, 500, file);
        p->stu_user = (char *) malloc(500*sizeof (buff));
        buff[strlen(buff)-1] = '\0';
        strcpy(p->stu_user, buff);

        fgets(buff, 500, file);
        p->stu_pas = (char *) malloc(500*sizeof (buff));
        buff[strlen(buff)-1] = '\0';
        strcpy(p->stu_pas, buff);

        p->stu_bookid = (int *) malloc(250*sizeof (buff));
        for(i = 0; i < 10; i++)
        {
            fgets(buff, 50, file);
            buff[strlen(buff)-1] = '\0';
            p->stu_bookid[i] = atoi(buff);
        }

        t->next = p;
        t = p;
    }
    t->next = NULL;
    return 0;
}

int store_student(FILE *file)
{
    int i;
    Student *p;
    p = student_head;
    p = p->next;
    if(file == NULL) return -1;
    if(!p) return 0;
    while(p) {
        fprintf(file,"%s\n", p->stu_name);
        fprintf(file,"%s\n", p->stu_user);
        fprintf(file,"%s\n", p->stu_pas);
        for(i = 0; i < 10; i++)
        {
            fprintf(file,"%d\n", p->stu_bookid[i]);
        }
        p = p->next;
    }
    return 0;
}
/*Save all the information to a file*/

Manager *Manager_load(void)
{
    FILE *fp;
    Manager *h=NULL, *t=h, *p;
    if((fp=fopen("Manager.txt","r"))==NULL){
        exit(1);
    }
    getc(fp);
    if(feof(fp)){
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    while(!feof(fp)){
        p=(Manager *)malloc(sizeof(Manager));
        p->next=NULL;
        fscanf(fp,"%s",p->man_name);
        fscanf(fp,"%s",p->man_user);
        fscanf(fp,"%s",p->man_pas);

        if(h==NULL)
            h=p;
        else
            t->next=p;
        t=p;
    }
    fclose(fp);
    return h;
}

// void massage_save()
// {
//
// }