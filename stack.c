#include<stdio.h>
#include<stdlib.h>
#define size 3
void push(int);
void pop();
void display();
int stack[size];
int top=-1;
int main()
{
	int value, choice;
	while(1)
	{
		printf("\n1.push \n2.pop \n3.Display \nExit");
		printf("\nEnter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value to be inserted");
				scanf("%d",&value);
				push(value);
				break;
			case 2:
			    pop();
				break;
			case 3:
			    display();
				break;
			case 4:
			    exit(0);
				break;
			default:
				printf("wrong choice");
		}
	}
	return 0;
}
void push(int value)
{
	if(top==size -1)
	{
		printf("Stack is full");
	}
	else
	{
		top++;
		stack[top]=value;
		printf("inseration successful");
	}
}
void pop()
{
	if(top==-1)
	{
		printf("stack is empty");
	}
	else
	{
		int value;
		stack[top]=value;
		printf("item deleted%d",stack[top]);
		top--;
	}
}
void display()
{
	if(top==-1)
	{
		printf("Stack is empty");
	}
	else
	{
		int i;
		printf("Stack elements are :");
		for(i=top;i>=0;i--)
		{
			printf("%d",stack[i]);
		}
	}
}
 
