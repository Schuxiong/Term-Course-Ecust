#include "stdafx.h"
#include <stdio.h>
#include <string.h>

enum WORD_TYPE_ENUM {
	INVALID_WORD,
	IDENTIFIER,
	NUMBER,
	CONST,
	VAR,
	PROCEDURE,
	BEGIN,
	END,
	IF,
	THEN,
	WHILE,
	DO,
	WRITE,
	READ,
	CALL,
	LEFT_PARENTHESIS,
	RIGHT_PARENTHESIS,
	COMMA,
	SEMICOLON,
	PERIOD,
	PLUS,
	MINUS,
	MULTIPLY,
	DIVIDE,
	ODD,
	EQL,
	NEQ,
	LES,
	LEQ,
	GTR,
	GEQ,
	ASSIGN
};

struct RESERVED_WORD_NAME_VS_TYPE_STRUCT {
	char szName[20];
	enum WORD_TYPE_ENUM eType;
};

#define MAX_LENGTH_OF_A_WORD 10
#define MAX_NUMBER_OF_WORDS 1000
#define NUMBER_OF_RESERVERD_WORDS 13

struct WORD_STRUCT {
	char szName[MAX_LENGTH_OF_A_WORD];
	enum WORD_TYPE_ENUM eType;
	int nNumberValue;
	int nLineNo;
};

RESERVED_WORD_NAME_VS_TYPE_STRUCT ReservedWordNameVsTypeTable[NUMBER_OF_RESERVERD_WORDS];
WORD_TYPE_ENUM SingleCharacterWordTypeTable[256];
WORD_STRUCT g_Words[MAX_NUMBER_OF_WORDS];
int g_nWordsIndex;
int g_nLineNo = 1;
extern FILE *fpSourceFile;

int WordTypeToString(char string[100], WORD_TYPE_ENUM eWordType);
void PrintInLexis(int nWordsIndex);
int GetAWord();

void InitializeReservedWordTable()
{
	strcpy(ReservedWordNameVsTypeTable[0].szName, "begin");
	ReservedWordNameVsTypeTable[0].eType = BEGIN;
	strcpy(ReservedWordNameVsTypeTable[1].szName, "call");
	ReservedWordNameVsTypeTable[1].eType = CALL;
	strcpy(ReservedWordNameVsTypeTable[2].szName, "const");
	ReservedWordNameVsTypeTable[2].eType = CONST;
	strcpy(ReservedWordNameVsTypeTable[3].szName, "do");
	ReservedWordNameVsTypeTable[3].eType = DO;
	strcpy(ReservedWordNameVsTypeTable[4].szName, "end");
	ReservedWordNameVsTypeTable[4].eType = END;
	strcpy(ReservedWordNameVsTypeTable[5].szName, "if");
	ReservedWordNameVsTypeTable[5].eType = IF;
	strcpy(ReservedWordNameVsTypeTable[6].szName, "odd");
	ReservedWordNameVsTypeTable[6].eType = ODD;
	strcpy(ReservedWordNameVsTypeTable[7].szName, "procedure");
	ReservedWordNameVsTypeTable[7].eType = PROCEDURE;
	strcpy(ReservedWordNameVsTypeTable[8].szName, "read");
	ReservedWordNameVsTypeTable[8].eType = READ;
	strcpy(ReservedWordNameVsTypeTable[9].szName, "then");
	ReservedWordNameVsTypeTable[9].eType = THEN;
	strcpy(ReservedWordNameVsTypeTable[10].szName, "var");
	ReservedWordNameVsTypeTable[10].eType = VAR;
	strcpy(ReservedWordNameVsTypeTable[11].szName, "while");
	ReservedWordNameVsTypeTable[11].eType = WHILE;
	strcpy(ReservedWordNameVsTypeTable[12].szName, "write");
	ReservedWordNameVsTypeTable[12].eType = WRITE;
}

void InitializeSingleCharacterTable()
{
	int i;
	for (i = 0; i <= 255; ++i)
		SingleCharacterWordTypeTable[i] = INVALID_WORD;
	SingleCharacterWordTypeTable['+'] = PLUS;
	SingleCharacterWordTypeTable['-'] = MINUS;
	SingleCharacterWordTypeTable['*'] = MULTIPLY;
	SingleCharacterWordTypeTable['/'] = DIVIDE;
	SingleCharacterWordTypeTable['('] = LEFT_PARENTHESIS;
	SingleCharacterWordTypeTable[')'] = RIGHT_PARENTHESIS;
	SingleCharacterWordTypeTable['='] = EQL;
	SingleCharacterWordTypeTable[','] = COMMA;
	SingleCharacterWordTypeTable['.'] = PERIOD;
	SingleCharacterWordTypeTable['#'] = NEQ;
	SingleCharacterWordTypeTable[';'] = SEMICOLON;
}

void LexicalAnalysis()
{
	int nResult;
	InitializeReservedWordTable();
	InitializeSingleCharacterTable();
	fseek(fpSourceFile, 0L, SEEK_SET);
	
	printf("\n ------------------Lexical Analysis Begin! ------------\n");
	
	g_nWordsIndex = 0;
	nResult = GetAWord();
	while(nResult == OK && g_nWordsIndex >= 1)
	{
		PrintInLexis(g_nWordsIndex - 1);
		nResult = GetAWord();
	}
	
	printf("-------------------Lexical Analysis Finished---------------\n");
}

char GetACharacterFromFile()
{
	char cACharacter;
	if(fscanf(fpSourceFile, "%c", &cACharacter) == EOF)
		cACharacter = EOF;
	if(cACharacter == RETURN)
		g_nLineNo++;
	return cACharacter;
}

int GetAWord()
{
	static char cACharacter = SPACE;
	int nAWordIndex;
	int nDigitNumber;
	int i;
	char szAWord[MAX_LENGTH_OF_A_WORD+1];
	int nNumberValue;
	
	while((cACharacter == SPACE || cACharacter == RETURN || cACharacter == TABLE) && cACharacter != EOF)
		cACharacter = GetACharacterFromFile();
	if(cACharacter != EOF)
	{
		if(cACharacter >= 'a' && cACharacter <= 'z')
		{
			nAWordIndex = 0;
			do {
				if(nAWordIndex < MAX_LENGTH_OF_A_WORD)
					szAWord[nAWordIndex++] = cACharacter;
				cACharacter = GetACharacterFromFile();
			}while((cACharacter>='a'&&cACharacter<='z' || cACharacter>='0'&&cACharacter<='9')&&cACharacter!=EOF);
			if(cACharacter != EOF)
			{
				szAWord[nAWordIndex] = 0;
				for(i = 0; i < NUMBER_OF_RESERVERD_WORDS; i++)
					if(strcmp(szAWord, ReservedWordNameVsTypeTable[i].szName) == 0)
					{
						g_Words[g_nWordsIndex].eType = ReservedWordNameVsTypeTable[i].eType;
						break;
					}
				if(i>=NUMBER_OF_RESERVERD_WORDS)
					g_Words[g_nWordsIndex].eType = IDENTIFIER;
				strcpy(g_Words[g_nWordsIndex].szName, szAWord);
				g_Words[g_nWordsIndex].nLineNo = g_nLineNo;
				g_nWordsIndex++;
				
				return OK;
			} else 
				return ERROR;
		} else
			if(cACharacter >= '0' && cACharacter <= '9')
			{
				nDigitNumber = 0;
				nNumberValue = 0;
				do {
					szAWord[nDigitNumber++] = cACharacter;
					nNumberValue = 10 * nNumberValue + cACharacter - '0';
					cACharacter = GetACharacterFromFile();
				}while(cACharacter >= '0' && cACharacter <= '9' && cACharacter != EOF);
				
				if(cACharacter != EOF)
				{
					szAWord[nDigitNumber] = 0;
					g_Words[g_nWordsIndex].eType = NUMBER;
					strcpy(g_Words[g_nWordsIndex].szName, szAWord);
					g_Words[g_nWordsIndex].nNumberValue = nNumberValue;
					g_Words[g_nWordsIndex].nLineNo = g_nLineNo;
					g_nWordsIndex++;
					
					return OK;
				} else
					return ERROR;
			} else 
				if(cACharacter == ':')
				{
					cACharacter = GetACharacterFromFile();
					if(cACharacter == '=')
					{
						g_Words[g_nWordsIndex].eType = ASSIGN;
						strcpy(g_Words[g_nWordsIndex].szName, ":=");
						g_Words[g_nWordsIndex].nLineNo = g_nLineNo;
						g_nWordsIndex++;
						cACharacter = GetACharacterFromFile();
						
						return OK;
					}
				} else
					if (cACharacter == '<')
					{
						cACharacter = GetACharacterFromFile();
						if(cACharacter == '=')
						{
							g_Words[g_nWordsIndex].eType = LEQ;
							strcpy(g_Words[g_nWordsIndex].szName, "<=");
							g_Words[g_nWordsIndex].nLineNo = g_nLineNo;
							g_nWordsIndex++;
							cACharacter = GetACharacterFromFile();
							
							return OK;
						} else {
							g_Words[g_nWordsIndex].eType = LES;
							strcpy(g_Words[g_nWordsIndex].szName, "<");
							g_Words[g_nWordsIndex].nLineNo = g_nLineNo;
							g_nWordsIndex++;
							return OK;
						}
					} else 
						if (cACharacter == '>')
						{
							cACharacter = GetACharacterFromFile();
							if(cACharacter == '=')
							{
								g_Words[g_nWordsIndex].eType = GEQ;
								strcpy(g_Words[g_nWordsIndex].szName, ">=");
								g_Words[g_nWordsIndex].nLineNo = g_nLineNo;
								g_nWordsIndex++;
								cACharacter = GetACharacterFromFile();
							} else {
								g_Words[g_nWordsIndex].eType = GTR;
								strcpy(g_Words[g_nWordsIndex].szName, ">");
								g_Words[g_nWordsIndex].nLineNo = g_nLineNo;
								g_nWordsIndex++;
							}
							return OK;
						} else {
							g_Words[g_nWordsIndex].eType = SingleCharacterWordTypeTable[cACharacter];
							g_Words[g_nWordsIndex].szName[0] = cACharacter;
							g_Words[g_nWordsIndex].szName[1] = 0;
							g_Words[g_nWordsIndex].nLineNo = g_nLineNo;
							
							g_nWordsIndex++;
							cACharacter = GetACharacterFromFile();
							return OK;
						}		
	}
	return ERROR;
}

void PrintInLexis(int nIndex)
{
	char szWordName[100];
	char szWordType[100];
	
	strcpy(szWordName, g_Words[nIndex].szName);
	WordTypeToString(szWordType, g_Words[nIndex].eType);
	
	switch(g_Words[nIndex].eType)
	{
		case IDENTIFIER:
			printf("%-4d%-15s%-20s\n", nIndex, szWordName, szWordType); break;
		case NUMBER:
			printf("%-4d%-15s%-20s%-10d\n", nIndex, szWordName, szWordType, g_Words[nIndex].nNumberValue); break;
		case CONST:
		case VAR:
		case PROCEDURE:
		case BEGIN:
		case END:
		case IF:
		case THEN:
		case WHILE:
		case DO:
		case WRITE:
		case READ:
		case CALL:
		case LEFT_PARENTHESIS:
		case RIGHT_PARENTHESIS:
		case COMMA:
		case SEMICOLON:
		case PERIOD:
		case PLUS:
		case MINUS:
		case MULTIPLY:
		case DIVIDE:
		case ODD:
		case EQL:
		case NEQ:
		case LES:
		case LEQ:
		case GTR:
		case GEQ:
		case ASSIGN:
			printf("%-4d%-15s%-20s\n", nIndex, szWordName, szWordType); break;
		default:
		printf("%-4d%-15s%-20s\n", nIndex, szWordName, szWordType);
	}
}

int WordTypeToString(char strString[100], WORD_TYPE_ENUM eWordType)
{
	switch(eWordType)
	{
		case IDENTIFIER: strcpy(strString, "IDENTIFIER"); break;
		case NUMBER: strcpy(strString, "NUMBER"); break;
		case PLUS: strcpy(strString, "PLUS"); break;
		case MULTIPLY: strcpy(strString, "MULTIPLY"); break;
		case MINUS: strcpy(strString, "MINUS"); break;
		case DIVIDE: strcpy(strString, "DIVIDE"); break;
		case LES: strcpy(strString, "LES"); break;
		case LEQ: strcpy(strString, "LEQ"); break;
		case GTR: strcpy(strString, "GTR"); break;
		case GEQ: strcpy(strString, "GEQ"); break;
		case EQL: strcpy(strString, "EQL"); break;
		case NEQ: strcpy(strString, "NEQ"); break;
		case LEFT_PARENTHESIS: strcpy(strString, "LEFT_PARENTHESIS"); break;
		case RIGHT_PARENTHESIS: strcpy(strString, "RIGHT_PARENTHESIS"); break;
		case COMMA: strcpy(strString, "COMMA"); break;
		case SEMICOLON: strcpy(strString, "SEMICOLON"); break;
		case PERIOD: strcpy(strString, "PERIOD"); break;
		case ASSIGN: strcpy(strString, "ASSIGN"); break;
		case CONST: strcpy(strString, "CONST"); break;
		case VAR: strcpy(strString, "VAR"); break;
		case PROCEDURE: strcpy(strString, "PROCEDURE"); break;
		case BEGIN: strcpy(strString, "BEGIN"); break;
		case END: strcpy(strString, "END"); break;
		case IF: strcpy(strString, "IF"); break;
		case THEN: strcpy(strString, "THEN"); break;
		case ODD: strcpy(strString, "ODD"); break;
		case WHILE: strcpy(strString, "WHILE"); break;
		case DO: strcpy(strString, "DO"); break;
		case CALL: strcpy(strString, "CALL"); break;
		case READ: strcpy(strString, "READ"); break;
		case WRITE: strcpy(strString, "WRITE"); break;
		case INVALID_WORD: strcpy(strString, "INVALID_WORD"); break;
	}
	return NULL;
}