//character haruko stack
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
typedef struct
{
	char item[MAX]; //stack structure sabai
	int tos;	
}stack;

int IsEmpty(stack *sp) // ya struct stack lekhiranu pareana matji ko tarikako karan lea
{
	if(sp->tos==-1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
int IsFull(stack *sp)
{
	if(sp->tos==MAX-1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
void pop(stack *sp)
{
	if(IsEmpty(sp))
	{
		printf("\nStack Underflow\n");
		exit(0);
	}
	sp->tos--;
}
void push (stack *sp,char ch) //to push character
{
	if(IsFull(sp))
	{
		printf("\nStack Is FUll\n");
	}
	sp->item[++sp->tos]=ch; //sp lai banaunea ra bhadeko thau ma push garnea //++sp pre increament
}
// we need one more operation
//top iteam herna cause pop lea remove gardinxa
char peek(stack *sp)
{
	if(IsEmpty(sp))
	return (char) NULL; //stack empty bho bhanea NULL
		else
		return sp->item[sp->tos]; //top iteam shows stack pointer lea point gareko item ko top dekhauxa
}

int main()
{
	stack s;
	int i,valid=TRUE,ch;
	char exp[MAX];
	s.tos=-1;// empty stack 
	printf("\nEnter Your CHaracter:\n");
	gets(exp);
	for(i=0;i<strlen(exp);i++)
	{
		
		if(exp[i]=='[' || exp[i]=='{' || exp[i]=='(') // if opner
		{
				push(&s,exp[i]);	
		}
		
		else if(exp[i]==']' || exp[i]=='}' || exp[i]==')') //if closing
		{
			if(IsEmpty(&s))
			{
				valid=FALSE;
				break;
			}
			else
			{
				ch=peek(&s);
				pop(&s);
				if((ch=='[' && exp[i]!=']')||(ch=='{' && exp[i]!='}')||(ch=='(' && exp[i]!=')'))
				{
					valid=FALSE;
					break;
				}
			}
		}
		if(IsEmpty(&s)==FALSE)
			valid=FALSE;
		if(valid=TRUE)
		printf("\nExpression is valid\n");
		else
		printf("\nExpression is invalid");
		getch();
	}
	
}
