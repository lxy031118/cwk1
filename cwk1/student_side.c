#include "head.h"
#include "book_management.h"

//Student port - used to connect functions
void student_port()
{
    Student student;
    char sp = '1';
    while(sp != '0')
    {
        show_stu();
        printf("\t\t\tOption:");
        scanf("%c", &sp);
        while(getchar() != '\n');
        switch(sp)
        {
            case '1':student_login();break;
            case '2':student_register(student);break;
            case '0':break;
            default:printf("\t\tInput errors, please re-enter.\n");break;
        }
    }
}

//Student register page
int student_register(Student student)
{
	int l = 1;
	int i;
	Student *check_stu;
	Student *new, *q, *t;
	t = student_head;
	q = t;
	new = t->next;
    char *n  = (char *) malloc(200*sizeof (char));
	printf("\n\t\tWelcome to the registration system!\n");
	printf("\t\tPlease enter the following information.\n");
	for(;;)
	{
	    if(new == NULL)
	    {
	        CreateStuNode(new);
	        printf("\t\tname(No space): ");
	        fflush(stdin);
            gets(n);
            student.stu_name = (char *) malloc(200*sizeof (char));
            strcpy(student.stu_name, n);
            new->stu_name = student.stu_name;

            while(l != 6)
            {
                printf("\t\tUsername Accounts(6 digits):");
                fflush(stdin);
                gets(n);
                l = strlen(n);
                if(l != 6)
                    printf("\t\tThe account number is incorrect, please enter the correct length of the account number\n");
            }
            n[6] = '\0';
            check_stu = find_name(n);
            if(check_stu != NULL)
            {
                printf("\n\t\tSorry, student's username already exist. try again.");
                exit(0);
            }
            student.stu_user = (char *) malloc(200*sizeof (char));
            strcpy(student.stu_user, n);
            new->stu_user = student.stu_user;

            printf("\t\tpassword: ");
            fflush(stdin);
            password_input(n);
            printf("\n\t\tenter password again:");
            if(password_text(n) == 0)
            {
                printf("\n\t\tYou have entered the wrong input 3 times in a row, "
                       "and you will be logged out of the registration system...");
                exit(0);
            }
            student.stu_pas = (char *) malloc(200*sizeof (char));
            strcpy(student.stu_pas, n);
            new->stu_pas = student.stu_pas;

            new->stu_bookid = (int *) malloc(50*sizeof (int ));
            for(i = 0; i < 10; i++)
            {
                new->stu_bookid[i] = 0;
            }
            new->next = NULL;
            q->next = new;
            break;
	    }
	    q = new;
	    new = new->next;
	}
    free(n);

	printf("\n\t\tregistering...\n");
	printf("\t\t...\n");
	printf("\t\tregistration success!\n");
	printf("\t\tYour account is: %s\n", new->stu_user);
	printf("\t\tBe sure to remember the account password!\n");
	getch();
	return 0;
}

Student *find_name(char *Stu_acc)
{
	Student *t = student_head->next;
	while(t){
	    if (strcmp(t->stu_user, Stu_acc) == 0)
	    {
	        break;
	    }
	    t = t->next;
	}
	return t;
}

//Student login page
void student_login()
{
	char sl = '1';
	char enter_num[50];
	int l = 1;
	Student *enter_stu;
	while(l != 6){
	    printf("\n\t\tUsername Accounts(6 digits):");
		gets(enter_num);
		l = strlen(enter_num);
		if(l != 6)
		    printf("\t\tThe account number is incorrect, please enter the correct length of the account number\n");
	}
	enter_num[6] = '\0';
	enter_stu = find_name(enter_num);
	if(enter_stu == NULL){
	    printf("\n\t\tSorry, student's username does not exist.");
	    printf("\n\t\tPress any key to exit.");
	    getch();
        return;
	}
	printf("\t\tpassword:");
	if(password_find(enter_stu->stu_pas) == 0){
	    printf("\n\t\tThe password has been entered incorrectly three times, "
               "and the login system will be logged out...");
        return;
	}
	printf("\n\t\tlogin successful!\n");

	while(sl != '0')
	{
		stu_enter();
		printf("\t\tOption:");
		scanf("%c", &sl);
		while(getchar() != '\n');
		switch(sl)
		{
			case '1':stu_borrow(enter_stu); break;
			case '2':stu_return(enter_stu); break;
			case '3':find_book(); break;
			case '0':break;
			default:printf("\t\tInput errors, please re-enter.\n");break;
		}
	}
}