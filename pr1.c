#include<stdio.h>
int main()
	{
	int state=0,i=0;
	char c ;
	char input_string[100];
	printf("Enter input string \n");
	scanf("%s",input_string);
	while(1)
		{
		c = input_string[i++];
		if(c=='\0')
		break;
		switch(state)
		{
		case 0:
			if(c=='0')
				state=1;
			else if (c=='1')
				state=2;
			else
			{
				printf("Invalid input");
				return 0;
			}
			break;

		case 1:
			if(c=='0'||c=='1')
			state=1;
			else
			{
				printf("Invalid");
				return 0;
			}
			break;
		case 2:
			if(c=='0'||c=='1')
			state=2;
			else
			{
				printf("Invalid");
				return 0;
			}
			break;
		default:;
			}
			}
		if(state==1)
			printf("Valid input");
		else
			printf("Input Not accepted");
}
