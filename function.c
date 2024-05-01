#include<stdio.h>
#include<string.h>
char str[100];
void main()
	{
	printf("Enter string");
	scanf("%s",str);
	stateq0(0);
	}

void stateq0(int i)
{
char c=str[i];
switch(c)
	{
	case 'a':stateq1(++i);break;
	case 'b':stateq2(++i);break;
	case '\0':printf("Not Accepted");
	default:printf("Error i/p");
	}
}

void stateq1(int i)
{
char c=str[i];
switch(c)
	{
	case 'a':stateq1(++i);break;
	case 'b':stateq1(++i);break;
	case '\0':printf("Acceptet");
	default:printf("Error i/p");
	}
}
void stateq2(int i)
{
char c=str[i];
switch(c)
	{
	case 'a':stateq2(++i);break;
	case 'b':stateq2(++i);break;
	case '\0':printf("Rejected");
	
char c=str[i];
switch(c)
	{
	case 'a'=stateq1(++i);
	case 'b'=stateq1(++i);
	default: printf("Accept\n");
	}
}
