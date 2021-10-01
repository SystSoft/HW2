/*
    Written by: Anjaly Davis, Jennifer Nguyen
     Fall 2021 COP 3402
     October 1, 2021
     
	This is the lex.c file for the UCF Fall 2021 Systems Software Project.
	For HW2, you must implement the function lexeme *lexanalyzer(char *input).
	You may add as many constants, global variables, and support functions
	as you desire.
	
	If you choose to alter the printing functions or delete list or lex_index, 
	you MUST make a note of that in you readme file, otherwise you will lose 
	5 points.
*/


#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "compiler.h"
#define MAX_NUMBER_TOKENS 500
#define MAX_IDENT_LEN 11
#define MAX_NUMBER_LEN 5

lexeme *list;
int lex_index;

void printlexerror(int type);
void printtokens();


lexeme *letterFirst(char *input , lexeme *list, int k)
{
    int i, j;
    char *identBuffer = malloc(sizeof(char) * MAX_IDENT_LEN);
    
    lex_index = 0;
    while (input[k] != '\0')
    {
        
        if (iscntrl(input[k]) || isspace(input[k]))
        {
            k++;
            continue;
        }
        
        // when i < 12
        if (lex_index + 1 % MAX_IDENT_LEN != 0)
        {
            
            if (isalpha(input[k]) || isdigit(input[k]))
            {
                identBuffer[lex_index] = input[k];
                lex_index++;
            }
            else
                break; // if neither letter or number, it is a symbol
        }
        else if (isalpha(input[i]) || isdigit(input[i]))
        {
            printlexerror(4);
            return NULL;
        }
        k++;
    }
    
    strncpy(list[lex_index].name, identBuffer, MAX_IDENT_LEN);
        
    if (strcmp(list[lex_index].name, "const") == 0)
    {
        list[lex_index].value = 1;
        list[lex_index].type = constsym;
    }
    if (strcmp(list[lex_index].name, "var") == 0)
    {
        list[lex_index].value = 2;
        list[lex_index].type = varsym;
    }
    if (strcmp(list[lex_index].name, "procedure") == 0)
    {
        list[lex_index].value = 3;
        list[lex_index].type = procsym;
    }
    if (strcmp(list[lex_index].name, "begin") == 0)
    {
        list[lex_index].value = 4;
        list[lex_index].type = beginsym;
    }
    if (strcmp(list[lex_index].name, "end") == 0)
    {
        list[lex_index].value = 5;
        list[lex_index].type = endsym;
    }
    if (strcmp(list[lex_index].name, "while") == 0)
    {
        list[lex_index].value = 6;
        list[lex_index].type = whilesym;
    }
    if (strcmp(list[lex_index].name, "do") == 0)
    {
        list[lex_index].value = 7;
        list[lex_index].type = dosym;
    }
    if (strcmp(list[lex_index].name, "if") == 0)
    {
        list[lex_index].value = 8;
        list[lex_index].type = ifsym;
    }
    if (strcmp(list[lex_index].name, "then") == 0)
    {
        list[lex_index].value = 9;
        list[lex_index].type = thensym;
    }
    if (strcmp(list[lex_index].name, "else") == 0)
    {
        list[lex_index].value = 10;
        list[lex_index].type = elsesym;
    }
    if (strcmp(list[lex_index].name, "call") == 0)
    {
        list[lex_index].value = 11;
        list[lex_index].type = callsym;
    }
    if (strcmp(list[lex_index].name, "write") == 0)
    {
        list[lex_index].value = 12;
        list[lex_index].type = writesym;
    }
    if (strcmp(list[lex_index].name, "read") == 0)
    {
        list[lex_index].value = 13;
        list[lex_index].type = readsym;
    }
    if (strcmp(list[lex_index].name, "identifiers") == 0)
    {
        list[lex_index].value = 14;
        list[lex_index].type = identsym;
    }
    if (strcmp(list[lex_index].name, "numbers") == 0)
    {
        list[lex_index].value = 15;
        list[lex_index].type = numbersym;
    }
    
    return NULL;
}

lexeme *lexanalyzer(char *input)
{
    int i = 0, j = 0; // i = input counter  j = initial i
    char numBuffer[MAX_NUMBER_LEN];
    lex_index = 0;
    lexeme *list = malloc(MAX_NUMBER_TOKENS * sizeof(struct lexeme));
    
    while (input[i] != '\0')
    {
       if (iscntrl(input[i]) || isspace(input[i]))
        {
            i++;
            continue;
        }
        
        if (isalpha(input[i]))
        {
            letterFirst(input, list, i); // i is index of the first letter, j is index of list
            lex_index++;
        }
        
        i++;
    }
    printtokens();

	return NULL;
    
}


void printtokens()
{
	int i;
	printf("Lexeme Table:\n");
	printf("lexeme\t\ttoken type\n");
	for (i = 0; i < lex_index; i++)
	{
		switch (list[i].type)
		{
			case oddsym:
				printf("%11s\t%d", "odd", oddsym);
				break;
			case eqlsym:
				printf("%11s\t%d", "==", eqlsym);
				break;
			case neqsym:
				printf("%11s\t%d", "!=", neqsym);
				break;
			case lsssym:
				printf("%11s\t%d", "<", lsssym);
				break;
			case leqsym:
				printf("%11s\t%d", "<=", leqsym);
				break;
			case gtrsym:
				printf("%11s\t%d", ">", gtrsym);
				break;
			case geqsym:
				printf("%11s\t%d", ">=", geqsym);
				break;
			case modsym:
				printf("%11s\t%d", "%", modsym);
				break;
			case multsym:
				printf("%11s\t%d", "*", multsym);
				break;
			case divsym:
				printf("%11s\t%d", "/", divsym);
				break;
			case addsym:
				printf("%11s\t%d", "+", addsym);
				break;
			case subsym:
				printf("%11s\t%d", "-", subsym);
				break;
			case lparensym:
				printf("%11s\t%d", "(", lparensym);
				break;
			case rparensym:
				printf("%11s\t%d", ")", rparensym);
				break;
			case commasym:
				printf("%11s\t%d", ",", commasym);
				break;
			case periodsym:
				printf("%11s\t%d", ".", periodsym);
				break;
			case semicolonsym:
				printf("%11s\t%d", ";", semicolonsym);
				break;
			case assignsym:
				printf("%11s\t%d", ":=", assignsym);
				break;
			case beginsym:
				printf("%11s\t%d", "begin", beginsym);
				break;
			case endsym:
				printf("%11s\t%d", "end", endsym);
				break;
			case ifsym:
				printf("%11s\t%d", "if", ifsym);
				break;
			case thensym:
				printf("%11s\t%d", "then", thensym);
				break;
			case elsesym:
				printf("%11s\t%d", "else", elsesym);
				break;
			case whilesym:
				printf("%11s\t%d", "while", whilesym);
				break;
			case dosym:
				printf("%11s\t%d", "do", dosym);
				break;
			case callsym:
				printf("%11s\t%d", "call", callsym);
				break;
			case writesym:
				printf("%11s\t%d", "write", writesym);
				break;
			case readsym:
				printf("%11s\t%d", "read", readsym);
				break;
			case constsym:
				printf("%11s\t%d", "const", constsym);
				break;
			case varsym:
				printf("%11s\t%d", "var", varsym);
				break;
			case procsym:
				printf("%11s\t%d", "procedure", procsym);
				break;
			case identsym:
				printf("%11s\t%d", list[i].name, identsym);
				break;
			case numbersym:
				printf("%11d\t%d", list[i].value, numbersym);
				break;
		}
		printf("\n");
	}
	printf("\n");
	printf("Token List:\n");
	for (i = 0; i < lex_index; i++)
	{
		if (list[i].type == numbersym)
			printf("%d %d ", numbersym, list[i].value);
		else if (list[i].type == identsym)
			printf("%d %s ", identsym, list[i].name);
		else
			printf("%d ", list[i].type);
	}
	printf("\n");
	list[lex_index++].type = -1;
}

void printlexerror(int type)
{
	if (type == 1)
		printf("Lexical Analyzer Error: Invalid Symbol\n");
	else if (type == 2)
		printf("Lexical Analyzer Error: Invalid Identifier\n");
	else if (type == 3)
		printf("Lexical Analyzer Error: Excessive Number Length\n");
	else if (type == 4)
		printf("Lexical Analyzer Error: Excessive Identifier Length\n");
	else
		printf("Implementation Error: Unrecognized Error Type\n");
	
	free(list);
	return;
}
