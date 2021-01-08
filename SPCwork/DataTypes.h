#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "malloc.h"
#include <string>
#include "stdlib.h"
#include "ctype.h"

#define MAX_LEXEMS 1000
#define MAX_IDENT 100
#define MAX_BUF_SIZE 100
#define STACK_SIZE 200
#define MAX_LENGTH_TYPES 20

enum TypeOfLex
{
	LBegProg,		// #
	LProgram,		// program
	LProgramName,		// ProgramName
	LStart,			// start
	LData,			// variable
	LVarType,		// int16
	LIdentifier,		// NameVar
	LEnd,			// stop
	
	LScan,			// scan
	LPrint,			// print

	LDo,			// do
	LWhile,			// while

	LNewValue,		// ::
	LAdd,			// +
	LSub,			// -
	LMul,			// Mul
	LDiv,			// Div
	LMod,			// Mod
	LEqu,			// =
	LNotEqu,		// <>
	LGreate,		// lt
	LLess,			// gt
	LNot,			// !!
	LAnd,			// &&
	LOr,			// ||

	LLBraket,		// (
	LRBraket,		// )
	LNumber,		// number
	LSeparator,		// ;
	LComma,			// ,
	LEOF,			// EndFile
	LUnknown
};

//DATA
typedef struct Lexem
{
	char name[50];
	int value;
	int line;
	TypeOfLex type;
}Lexema;

typedef struct ID
{
	char name[50];
	int value;
}Identificator;

typedef struct L
{
	Lexema LexTable[MAX_LEXEMS];			//token table
	int LexNum;							

	Identificator IdTable[MAX_IDENT];		//table of identifiers
	int IdNum;							

	bool IsPresentInput,				//Signs of the presence of operators
	IsPresentOutput,
	IsPresentMod,
	IsPresentAnd,
	IsPresentOr,
	IsPresentNot,
	IsPresentEqu,
	IsPresentGreate,
	IsPresentLess,
	IsPresentDiv;

	int numberErrors;

	std::string InputFileName;
	char OutputFileName[50];

	int bufExprPostfixForm[MAX_BUF_SIZE];	//Buffer for expression in postfix form
}DataType;

typedef struct Stacks
{
	int st[STACK_SIZE];
	int top;
}StackType;

typedef class stack
{
public:
	StackType S;
	void Init(StackType* s)
	{
		s->top = -1;
	}

	void Push(int i, StackType* s)
	{
		if (IsFull(s))
		{
			puts("Stack error (is full)");
			exit(0);
		}
		else
		{
			++s->top;
			s->st[s->top] = i;
		}
	}
	int Pop(StackType* s)
	{
		int i;
		if (IsEmpty(s))
		{
			puts("Stack error (is empty)");
			exit(0);
		}
		else
		{
			i = s->st[s->top];
			--s->top;
		}
		return i;
	}
	bool IsEmpty(StackType* s)
	{
		if (s->top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool IsFull(StackType* s)
	{
		if (s->top == 199)return true;
		else return false;
	}
	void prints(StackType s)
	{
		int i = 0;
		for (; i < 10; ++i)
		{
			printf("%d_", s.st[i]);
		}
	}
}StackT;

StackT Stack;						//Stack
StackT startStack;
StackT forStack;

DataType Data;						//The structure-register in which all data of the program are stored

FILE* InF, * OutF, * ErrorF;
