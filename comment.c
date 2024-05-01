#include<stdio.h>
#include<string.h>

FILE *fp;
char nextChar(){ return fgetc(fp);}
int main(){
	fp=fopen("pr1.c","r");
	stateQ0(nextChar());
	return 0;
}

void stateQ0(char c){
	switch(c){
	case EOF:
		break;
	case '/':
		stateQ1(nextChar());
		break;
	default:
		printf("%c",c);
		stateQ0(nextChar());
	}
}

void stateQ1(char c){
	switch(c){
	case EOF;
	break;
	case'/':
		stateQ2(nextChar());
	break;
	case '*':
		stateQ3(nextChar());
	break;
	default:
		printf("%c",c);
		stateQ0(nextChar());
	}
}

void stateQ2(char c){
	switch(c){
	case EOF:
		break;
	case '\n':
		stateQ0(nextChar());
		break;
	default:
		stateQ2(nextChar());
	}
}

void stateQ3(char c){
	switch(c){
	case EOF:
		break;
	case '*':
		stateQ4(nextChar());
		break;
	default:
		stateQ3(nextChar());
	}
}

void stateQ4(char c){
	switch(c){
	case EOF:
		break;
	case '/':
		stateQ0(nextChar());
		break;
	default:
		printf("%c",c);
		stateQ3(nextChar());
	}
}
