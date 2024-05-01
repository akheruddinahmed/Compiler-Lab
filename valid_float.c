#include<stdio.h>
#include<string.h>
char *str = "+123.59";
int i=0;
char nextChar(){return str[i++];}

int isNo(char c){
	if(c>=48 && c<=57)
		return 1;
	return 0;
}

int main(){
	stateQ0(nextChar());
	return 0;
}


void stateQ0(char c){ 
	if(c=='+'||c=='-'){
		stateQ1(nextChar());
	}else if (c=='.'){
		stateQ2(nextChar());
	}else if(isNo(c)){
		stateQ3(nextChar());
	}else{
		printf("ERROR\n");
	}
}

void stateQ1(char c){
	if(c=='.'){
		stateQ2(nextChar());
	}else if(isNo(c)){
		stateQ3(nextChar());
	}else{
		printf("ERROR\n");
	}
}

void stateQ2(char c){
	if(isNo(c)){
		stateQ4(nextChar());
	}else{
		printf("ERROR\n");
	}
}

void stateQ3(char c){
	if(isNo(c)){
		stateQ3(nextChar());
	}else if(c=='.'){
		stateQ4(nextChar());
	}else{
		printf("ERROR\n");
	}
}

void stateQ4(char c){
	if(isNo(c)){
		stateQ4(nextChar());
	}else if (c=='\0'){
		printf("Valid float\n");
	}else{
		printf("ERROR\n");
	}
}
