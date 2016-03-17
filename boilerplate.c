/*
*
*   Boiler Plate
*
*   This program will create and
*   write the boilerplate code for
*   said c program
*
*   Coded by Sebastian Giovannini (2016)
*
*/

/*  ----------------------------------------------------    */

/*  Pre-processor Directives    */
/*included libraries*/
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

/*included constants*/
	#define REQSIZE 35

/*included structures*/
/*included function*/
    void printstar(int numstar, FILE *ofp);
    void newline(int numline, FILE *ofp);
    void linespace(FILE *ofp);
    void declarefunc(FILE *ofp, int numfunct);
    void definefunc(FILE *ofp, int numfunct);
    void printprogram(FILE *ofp, const char * programname, char * first, char * last, int numfunct);

/*  ----------------------------------------------------    */

/*main function: this is where most things happen*/
int main() {
	/*initialize variables, files, and pointers below*/
    int numfunct;    FILE* ofp;
    char *programname = malloc(REQSIZE);
    char first[REQSIZE], last[REQSIZE];

    /*ask the user to name the program*/
    printf("\aHello user! What is your name?\n");   scanf("%s", first);
    printf("\aHello %s! What is your last name?\n", first);    scanf("%s", last);
    printf("\aWhat would you like to name the program?\n"); scanf("%s", programname);
    printf("\aHow many functions would you like to set up, %s?\n", first);	scanf("%d", &numfunct);

    /*initialize the file, using a char pointer*/
    ofp = fopen(programname, "w");
    /*This is all the information needed to boilerplate, for now*/

    /*Printing in progress*/
	printprogram(ofp, programname, first, last, numfunct);

    /*pointer closure and garbage collection*/
    fclose(ofp);    free(programname);
	return 0;
}

/*  ----------------------------------------------------    */

/*Precondition: User gives number of stars desired
*Postcondition: Prints the number of stars desired
*/
void printstar(int numstar, FILE *ofp){
    int k;
    for(k=0;k<numstar;k++)fprintf(ofp,"*\n");
}


/*  ----------------------------------------------------    */

/*Precondition: User gives number of newlines desired
*Postcondition: Prints the number of newlines desired
*/
void newline(int numline, FILE *ofp){
    int k;
    for(k=0;k<numline;k++)fprintf(ofp, "\n");
}

/*  ----------------------------------------------------    */

/*Precondition: User demands a line to separate sections of code
*Postcondition: Prints a separator
*/
void linespace(FILE *ofp){
    fprintf(ofp, "\n/*\t----------------------------------------------------\t*/\n\n");
}

/*  ----------------------------------------------------    */

/*Precondition: User demands functions
*Postcondition: Prints the declaractions for functions
*/
void declarefunc(FILE *ofp, int numfunct){
    int k;
    for(k=0;k<numfunct;k++)fprintf(ofp, "\tvoid function%d();\n", k+1);
    fprintf(ofp, "\n");
}

/*  ----------------------------------------------------    */

/*Precondition: User demands functions
*Postcondition: Sets up spaces where functions can be printed and then defined
*/
void definefunc(FILE *ofp, int numfunct){
    int k;
    for(k=0;k<numfunct;k++){
    	fprintf(ofp, "\n/*\t----------------------------------------------------\t*/\n\n");
    	fprintf(ofp, "/*Precondition:\n*Postcondition:\n*/\n");
    	fprintf(ofp, "void function%d()%c\n%c\n",k+1,123,125);
	}
}

/*  ----------------------------------------------------    */

/*Precondition: I wanted the program to not be completely unsightly
*Postcondition: Literally calls every function and prints the program to the c file
*/
void printprogram(FILE *ofp, const char * programname, char * first, char * last, int numfunct){
	fprintf(ofp, "/*\n");   printstar(1, ofp);  fprintf(ofp, "*\t%s", programname);
    printstar(5, ofp);  fprintf(ofp, "*\t%s %s (%s)", first, last, __DATE__);
    printstar(1, ofp);  fprintf(ofp, "*/\n"); linespace(ofp);
    fprintf(ofp, "/*  Pre-processor Directives    */\n");
    fprintf(ofp, "/*included libraries*/\n");   fprintf(ofp, "\t%cinclude %cstdlib.h%c\n", 35, 60, 62);
    fprintf(ofp, "\t%cinclude %cstdio.h%c\n", 35, 60, 62);  newline(1,ofp);	fprintf(ofp, "/*included constants*/\n");
    fprintf(ofp, "/*included functions*/\n");	declarefunc(ofp, numfunct);		fprintf(ofp, "/*included external variables*/\n");
	fprintf(ofp, "/*included structures*/\n"); linespace(ofp);
    fprintf(ofp, "/*main function: describe the main function here*/\n");
    fprintf(ofp, "int main%c%c %c\n", 40,41,123);   fprintf(ofp, "\t/*initialize variables, files, and pointers below*/\n\n\n\n");
    fprintf(ofp, "\treturn 0%c\n", 59); fprintf(ofp, "%c", 125);    newline(1,ofp);	definefunc(ofp, numfunct);
}
