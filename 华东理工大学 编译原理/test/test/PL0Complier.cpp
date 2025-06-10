// PL0Complier.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "stdio.h"
#include "string.h"

enum WORD_TYPE_ENUM;

void InitializeSingleCharacterTable();
void InitializeReservedWordTable();
void PrintSourceFile();
int Initialization();
void LexicalAnalysis();
//int ParsingAnalysis();
//int GenerateAnalysis();
//void Interpreter();

#define SOURCE_FILE_NAME "SourceFile1.pl0"

FILE* fpSourceFile;

int main()
{
	Initialization();
	PrintSourceFile();
	
	LexicalAnalysis();
	getchar();

	/*
	ParsingAnalysis();
	getchar();

	GenerateAnalysis();
	getchar();

	interpreter();
	getchar();
	*/

    return 0;
}

int Initialization()
{
	char szFileName[100];

	strcpy(szFileName, SOURCE_FILE_NAME);
	if ((fpSourceFile = fopen(szFileName, "r")) == NULL)
	{
		printf("Can not open source file %s\n", szFileName);
		return ERROR;
	}
	return OK;
}

void PrintSourceFile()
{
	char cACharacter;
	fseek(fpSourceFile, 0L, SEEK_SET);

	while (fscanf(fpSourceFile, "%c", &cACharacter) != EOF)
		printf("%c", cACharacter);
}
