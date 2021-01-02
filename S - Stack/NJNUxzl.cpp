#include<stdio.h>
#include<stdlib.h>
void initial(struct Stack *stack);
void push(struct Stack *stack);
void pop(struct Stack *stack);
void output(struct Stack *stack);
void menu();
struct Link
{
	int data;
    struct Link* next;		
};
struct Stack
{	
	struct Link* head;
	int size;	
};
int main()
{
	struct Stack stack;
	int n,choice,flag=1;
	menu();
	while(flag)
	{   scanf("%d",&choice);
		switch(choice)
		{
			case 0:flag=0;
				    break;	
			case 1:output(&stack);
					break;
			case 2:initial(&stack);
					break;
			case 3:push(&stack);
					break;
			case 4:pop(&stack);
					break;
			 
		}
 
 
	}
return 0;		
} 
void menu()
{
	printf("             ����ջ����               \n");
	printf("--------------------------------------\n");	
	printf(">1.��ʾջ�и�Ԫ��\n");
	printf(">2.��ʼ��\n");
	printf(">3.����һ����\n");
	printf(">4.�Ƴ�ջ������\n");
	printf(">0.�˳�\n");
	printf("--------------------------------------\n");
	
}
void output(struct Stack *stack)
{
	struct Link *p=stack->head;
	if(stack->size==0)
	{
		printf("��ջ!\n");
		return ;	
		
	}
	else if(stack->size==1)
	{	printf("    ջ��Ԫ��\n");
		printf("----------------\n");
		printf("ջ�� "); 
		printf("ջ�� %d\n",p->data);	
		printf("----------------\n");
		return ;
		
	}
		printf("    ջ��Ԫ��\n");
		printf("----------------\n");
		printf("ջ�� ");	
	while(p->next!=NULL)
	{	printf("%d\n",p->data);
		printf("     ");
		p=p->next;	
	
	}	
		printf("\b\b\b\b\bջ�� %d\n",p->data);
		printf("----------------\n");
		
}
void initial(struct Stack *stack)
{
	stack->head=NULL;
	stack->size=0;
	printf("��ʼ���ɹ�!\n");
}
void push(struct Stack *stack)
{
	struct Link *p;
	p=(struct Link*)malloc(sizeof(struct Link));
	printf("��������Ҫ�����ֵ:");
	scanf("%d",&p->data);
	p->next=stack->head;
	stack->head=p;
	stack->size++;
	printf("����ɹ�!\n");		
}
void pop(struct Stack *stack)
{
	if(stack->size==0)
	{
		printf("��ջ!\n");	
		return ;
	 }	 
	struct Link *p=stack->head;
	stack->head=p->next;
	free(p);
	stack->size--;
    printf("�ɹ�!\n");		
}
