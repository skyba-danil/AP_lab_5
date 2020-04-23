#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void PrintWords1(int, char, char*, ...);
void PrintWords2(char,char*, ...);
void PrintWords3(char, char*, ...);
void FindPrintPowtor(char*, char);
char* FindRozdil(char*, char);

int main()
{
	puts("First:");
	PrintWords1(3, 'p', "pkvppd kkkppp pp","1pp","2pppp");
	puts("Second:");
	PrintWords2('p', "sids", "pkvppd kkkppp pp", 1, 4., "ppp");
	puts("therd:");
	PrintWords3('p', "sids", "pkvppd kkkppp pp", 1, 4., "ppp");
}

void PrintWords1(int kilkel, char bukva, char* pershrech, ...)
{
	for (char** elem = &pershrech; kilkel > 0; kilkel--, elem++)
	{
		FindPrintPowtor(*elem, bukva);
	}
}

void FindPrintPowtor(char* elem,char bukva)
{
	int count = 0;
	char* endword = elem;
	for (char* p = elem;*endword != '\0';p = endword + 1, count = 0)
	{
		endword = FindRozdil(p, ' ');
		char* chek = p;
		while (chek != endword)
		{
			if (*chek == bukva) count++;
			if (count == 3)
			{
				while (p != endword)
				{
					printf("%c", *p);
					p++;
				}
				printf("\n");
				break;
			}
			chek++;
		}
	}
}

void PrintWords2(char bukva, char* types, ...)
{
	char** elem = &types;
	elem++;
	while (*types != '\0')
	{
		if (*types == 's')
		{
			FindPrintPowtor(*elem, bukva);
		}
		if (*types == 'd')
		{
			elem++;
		}
		elem++;
		types++;
	}
}

void PrintWords3(char bukva, char* types, ...)
{
	char* pt = types;
	char* elem;
	va_list parg;
	va_start(parg, types);
	while (*pt!='\0')
	{
		switch(*pt)
		{
			case 's': elem = va_arg(parg, char*);
				FindPrintPowtor(elem, bukva);
				break;
			case 'i' : va_arg(parg, int);
				break;
			case 'd': va_arg(parg, double);
				break;
		}
		pt++;
	}
}

char* FindRozdil(char* str, char znak)
{
	while (*str != znak && *str !='\0')
		str++;
	return str;
}