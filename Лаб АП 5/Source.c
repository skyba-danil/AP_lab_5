#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define MAXLEN 100

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
	PrintWords2('p', "ss", "pkvppd kkkppp pp", "ppp");
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

//strtok
void FindPrintPowtor(const char* elem,char bukva)
{
	char tempEl[MAXLEN] = { 0 };
	strcpy(tempEl, elem);
	
	char* next = NULL;
	char* rozd = " ,.-_/";
	char* ptemp;
	ptemp = strtok_s(tempEl, rozd,&next);
	while (ptemp != NULL)
	{
		int count = 0;
		for(char* point = ptemp; *point != '\0';point++)
		{
			if (*point == bukva)
			{
				count++;
			}
			if(count > 2)
			{
				puts(ptemp);
				break;
			}
		}
		ptemp = strtok_s(NULL, rozd,&next);
	}
}

void PrintWords2(char bukva, char* types, ...)
{
	void** elem = &types;
	elem++;
	while (*types != '\0')
	{
		if (*types == 's')
		{
			FindPrintPowtor(*elem, bukva);
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