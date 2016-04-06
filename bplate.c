/*
*
*	bplate.c*
*
*   This program will be the template for the Boilerplate file
*   that will be created in order to generate boilerplate
*   by way of bpsetup.c
*
*	Sebastian Giovannini (Feb 23 2016)*
*/

/*	----------------------------------------------------	*/

/*  Pre-processor Directives    */
/*included libraries*/
	#include <stdlib.h>
	#include <stdio.h>

/*included constants*/
    #define REQSIZE 35

/*included functions*/
	char** allocate_Functions(int numfunc);
	void printStar(int n, FILE* fp);
	void newLine(FILE* fp);
	void lineSpace(FILE* fp);
	void print_Preprocessors(FILE* fp, int numfunct, char* programname, char** funcs);
	void print_Function_Prototypes(FILE* fp, int numfunc, char** funcs);
	void print_Main(FILE* fp);
	void print_Functions(FILE* fp, int numfunc, char* programname, char** funcs);
	void print_Program(FILE* fp, int numfunc, char* programname ,char** funcs);
	void free_Memory(char** funcs, char* programname, int numfunc);

/*included external variables*/
/*included structures*/

/*	----------------------------------------------------	*/

/*main function: describe the main function here*/
int main() {
	/*initialize variables, files, and pointers below*/
    FILE* fp;   char *programname = malloc(REQSIZE);    int numfunc, i;

    /*Ask the user some questions*/
    printf("\aHello Sebastian! What is the name of the program you want to make?\n");
    scanf("%s", programname);   fp = fopen(programname, "w");   /*get program name from user*/
    printf("\aHow many functions would you like to create?\n");  scanf("%d", &numfunc);
    char** funcs = allocate_Functions(numfunc);
    if(0 == numfunc)    goto nofunctions;
    else if(numfunc > 0){
            printf("\aWrite the function type for each function (i.e int, char*, etc)\n");
            for(i=0;i<numfunc;i++){
                    scanf(" %s", funcs[i]);  /*scanning function types*/
    }
    }   /*thus we depart from the demanding user*/

    /*	----------------------------------------------------	*/
    /* now we can begin to print the file */
    nofunctions:
    print_Program(fp, numfunc, programname, funcs);

    /*garbage collection*/
    free_Memory(funcs, programname, numfunc);
    fclose(fp);
	return 0;
}

/*	----------------------------------------------------	*/

/*Precondition: function is called
*Postcondition: allocates memory for the functions
*/
char** allocate_Functions(int numfunc){
    char** functions = (char**)malloc(numfunc*sizeof(char*));
    int indx;
    for(indx = 0;indx < numfunc; indx++){
        functions[indx] = (char*)malloc(REQSIZE*sizeof(char));
    }
    return functions;
}

/*	----------------------------------------------------	*/

/*Precondition: we use the program correctly
*Postcondition: prints however many stars we wish into another program (for the comments in boilerplate)
*/
void printStar(int n, FILE* fp){
    while(n > 0){
        fprintf(fp, "*\n");
        n--;    /*why make a local index variable when we can avoid it?*/
    }
}

/*	----------------------------------------------------	*/

/*Precondition: user knows how to use the program
*Postcondition: prints one line in the boilerplate program
*/
void newLine(FILE* fp){
    fprintf(fp, "\n");
}

/*	----------------------------------------------------	*/

/*Precondition:
*Postcondition: prints the line-space for a clean boilerplate with functions
*/
void lineSpace(FILE* fp){
    newLine(fp);
    fprintf(fp, "/*	----------------------------------------------------	*/");
    newLine(fp);
}

/*	----------------------------------------------------	*/

/*Precondition: we have all the data on the program
*Postcondition: we want to print the preprocessors (including function prototypes)
*/
void print_Preprocessors(FILE* fp, int numfunct, char* programname, char** funcs){
    fprintf(fp, "/*\n");   printStar(1,fp);    fprintf(fp, "*\t%s", programname);   /*printing the header*/
    printStar(5,fp);    fprintf(fp, "*\tSebastian Giovannini (%s)", __DATE__);
    printStar(1,fp);    fprintf(fp, "*/\n");    lineSpace(fp);
    fprintf(fp, "/*  Pre-processor Directives    */\n");    /*printing the pre-processors*/
    fprintf(fp, "/*included libraries*/\n");   fprintf(fp, "\t%cinclude %cstdlib.h%c\n", 35, 60, 62);
    fprintf(fp, "\t%cinclude %cstdio.h%c\n", 35, 60, 62);  newLine(fp);	fprintf(fp, "/*included constants*/\n");
    fprintf(fp, "/*included structures*/\n");   fprintf(fp, "/*included functions*/\n");
    print_Function_Prototypes(fp, numfunct, funcs);     fprintf(fp, "/*included external variables*/\n");
    lineSpace(fp);
}

/*	----------------------------------------------------	*/

/*Precondition: if the user wants functions
*Postcondition: prints the function prototypes for every function needed
*/
void print_Function_Prototypes(FILE* fp, int numfunc, char** funcs){
    int indx;
    for(indx=0;indx<numfunc;indx++){
        fprintf(fp, "\t%s function%d();\n", funcs[indx] ,indx+1);
    }
    newLine(fp);
}

/*	----------------------------------------------------	*/

/*Precondition: we are done printing pre-processors and want to make the main function
*Postcondition: we print the main function
*/
void print_Main(FILE* fp){
    fprintf(fp, "/*main function: describe the main function here*/\n");
    fprintf(fp, "int main%c%c %c\n", 40,41,123);   fprintf(fp, "\t/*initialize variables, files, and pointers below*/\n\n\n\n");
    fprintf(fp, "\t/*garbage collection*/\n\treturn 0%c\n", 59); fprintf(fp, "%c", 125);
}

/*	----------------------------------------------------	*/

/*Precondition: we have finished the main
*Postcondition: prints the functions with their types
*/
void print_Functions(FILE* fp, int numfunc, char* programname, char** funcs){
    int indx;
    newLine(fp);
    for(indx=0;indx<numfunc;indx++){
    	lineSpace(fp);  newLine(fp);
    	fprintf(fp, "/*Precondition:\n*Postcondition:\n*/\n");
    	fprintf(fp, "%s function%d()%c\n%c\n",funcs[indx],indx+1,123,125);
    }
}

/*	----------------------------------------------------	*/

/*Precondition: we want to be modular
*Postcondition: i think, therefore I am or some shit like that
*/
void print_Program(FILE* fp, int numfunc, char* programname ,char** funcs){
    print_Preprocessors(fp, numfunc, programname ,funcs);
    print_Main(fp);
    print_Functions(fp, numfunc, programname, funcs);
}

/*	----------------------------------------------------	*/

/*Precondition: we are done
*Postcondition: we want to free dynamically-allocated memory
*/
void free_Memory(char** funcs, char* programname, int numfunc){
    int indx;
    for(indx=0;indx<numfunc;indx++) free(funcs[indx]);
    free(funcs);    free(programname);
}
