#ifndef HEAD_H_
#define HEAD_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>


#define CreateManNode(p) p = (Manager *) malloc (sizeof(Manager));
#define CreateStuNode(p) p = (Student *) malloc (sizeof(Student));


typedef struct stu{
    char *stu_name;				//student name
    char *stu_user;				//student username
    char *stu_pas;				//student password
	unsigned int *stu_bookid;		   //borrowed book id
	struct stu *next;		   //pointer
}Student;

typedef struct manager{
    char man_name[20];              //manager name
	char man_user[10];				//manager username
	char man_pas[15];				//manager password
	struct manager *next;			//pointer
}Manager;

Student *student_head; //head node
Manager *manager_head; //head node

void show_menu(); //main maue
void show_stu(); //show the student side.
void stu_enter(); //enter the student page.
void find_book_menu(); // many ways of finding books.
void show_manager(); // show the manager side.
void manager_enter(); //enter the student page.
void student_port(); //the link bwteen student page and student side.
void manager_port(); //the link bwteen manager page and manager side.
void student_login(); //for students to login.
void manager_login(void); //for manager to login.
int student_register(Student student); //for students to register.
void password_input(char *Password); //get the password they enter, for following test.
int password_text(char *Password_temp); //test two passwords match or not.
Student *find_name(char *Stu_acc); //using username to find the student exist.
Manager *find_nam(char *Man_acc);//using username to find the manager exist.
int password_find(char *Password); //test the password correct or not.
void stu_borrow(Student *Stu_num); //students borrow books.
void stu_return(Student *Stu_num); //return them.
void find_book(void); //find books by many ways.
void print_book(void); //print out the book list.
int ifborrow(Student *Stu_num,unsigned int Book_num); //Check if the student borrowed this book
void borrow_status(Student *Stu_num); //Print the borrowed book street

int student_load(FILE *file); //create linked list.
Manager *Manager_load(void);
int store_student(FILE *file); //Save the student list to a file
void massage_save(); //save all the information in the files.


#endif