#include<stdio.h>
#include<string.h>
#include<stdio.h>

char *str="a123";
int i=0;

int isNo(int a){
	if(a>=48 && a<57)
	return 1;
	return 0;
}

void main(){

stateQ0(str[i]);
}

void stateQ0(char c){
	if(isNo(c))
		stateQ2(str[++i]);
	else if(c=='+'||c=='-')
		stateQ1(str[++i]);
	else stateQ3(str[++i]);
}


void stateQ1(char c){
	if(isNo(c))
		stateQ2(str[++i]);
	else stateQ3(str[++i]);
}

void stateQ2(char c){
	if(c=='\0'){printf("valid int");
	}
	else if(isNo(c))
		stateQ2(str[++i]);
	else stateQ3(str[++i]);
}

void stateQ3(char c){
	if(c=='\0')
		printf("Invalid int");
	else stateQ3(str[++i]);
}

