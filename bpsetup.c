/*
*
*	bpsetup.c*
*
*   This program creates a boilerplate.c file
*   customized for a user to create their own boilerplate
*   for new programs easily and efficiently
*
*	Firstname Lastname (Mar 16 2016)*
*/

/*	----------------------------------------------------	*/
/*  Pre-processor Directives    */
/*included libraries*/
	#include <stdlib.h>
	#include <stdio.h>

/*included constants*/
    #define REQSIZE 35

/*included functions*/
	void menu();
	void function2();
	void function3();

/*included external variables*/
/*included structures*/

/*	----------------------------------------------------	*/
/*main function: describe the main function here*/
int main() {
	/*initialize variables, files, and pointers below*/
	char firstName[REQSIZE], lastName[REQSIZE], choice;

    /*ask the user their information*/
    printf("\aHello user! What is your first and last name?\n");    scanf("%s %s", firstName, lastName);
    printf("\aHello %s. What would you like to do?\n");     menu();     scanf("%c", choice);


	return 0;
}

/*	----------------------------------------------------	*/

/*Precondition: user isn't like dead or anything
*Postcondition: prints menu for boilerplate options
*/
void menu(){
    printf("\tPress 'a' to use one of your files as boilerplate\n");
    printf("\tPress anything else to use the standard boilerplate\n");
}

/*	----------------------------------------------------	*/

/*Precondition:
*Postcondition:
*/
void function2(){
}

/*	----------------------------------------------------	*/

/*Precondition:
*Postcondition:
*/
void function3(){
}
