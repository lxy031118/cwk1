#include "head.h"

void password_input(char *Password)
{
    char ch;
    int i;
    int len = 4;
    while(len<6 || len>10)
    {
        for(i = 0; i < 20; i++)
        {
            ch = getch();
            if(ch == 8)
            {
                if((i-1)>=0)
                {
                    i-=2;
                    printf("\b \b");
                }
                else i--;
                continue;
            }
                if(ch=='\r') break;
            Password[i]=ch;
            printf("*");
        }
        Password[i] = '\0';
        len = strlen(Password);
        if(len<6 || len>10)
            printf("\n\t\tIncorrect input, please enter a password of correct length:");
    } 
}

int password_text(char *Password)
{
    char password_tem[20];
    int try = 0;
    int n = 0;    //Check input count
    while(n != 3){
        password_input(password_tem);
        if(strcmp(password_tem, Password) == 0)
        {
            try=1;
            break;
        }
        else{
            n++;
            if(n != 3){
                printf("\n\t\tThe two input passwords are inconsistent, please re-enter, "
                       "you still have %d times to enter:", 3-n);
            }
        }
    }
    return try;
}

//Password validation
int password_find(char *Password)
{
    char password_tem[20];
    int try = 0;
    int n = 0;    //Check input count
    while(n != 3)
    {
        password_input(password_tem);
        if(strcmp(password_tem, Password) == 0)
        {
            try = 1;
            break;
        }
        else
        {
            n++;
            printf("\n\t\tThe input passwords are inconsistent, please re-enter, "
                   "you still have %d times to enter:", 3-n);
        }
    }
    return try;
}