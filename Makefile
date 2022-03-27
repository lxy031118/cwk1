main:main.c
	gcc -c -O3 main.c
	gcc -o main main.o
find_book:find_book.c
	gcc -c -O3 find_book.c
	gcc -o find_book find_book.o
Informations:Informations.c
	gcc -c -O3 Informations.c
	gcc -o Informations Informations.o
interface:interface.c
	gcc -c -O3 interface.c
	gcc -o interface interface.o
manager:manager.c
	gcc -c -O3 manager.c
	gcc -o manager manager.o
password_functions:password_functions.c
	gcc -c -O3 password_functions.c
	gcc -o password_functions password_functions.o
student_page:student_page.c
	gcc -c -O3 student_page.c
	gcc -o student_page student_page.o
student_side:student_side.c
	gcc -c -O3 student_side.c
	gcc -o student_side student_side.o
all:main find_book Informations interface manager password_functions student_page student_side  

clean:
	rm -f main *.o find_book *.o Informations *.o interface *.o manager *.o password_functions *.o student_page *.o student_side *.o

