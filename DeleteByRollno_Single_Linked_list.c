#include<stdio.h>
struct list
{
	int age;
	int rollno;
	struct list *next;
};
struct list *start=NULL;
struct list *nn(int age,int rollno);
void add()
{
	int age,rollno;
	struct list *ptr1,*ptr2;
	char ch;
	do
	{
		printf("\nenter age : ");
		scanf("%d",&age);
		printf("\nenter rollno : ");
		scanf("%d",&rollno);
		ptr1=nn(age,rollno);
		if(start==NULL)
		{
			start=ptr1;
		}
		else
		{
			ptr2=start;
			while(ptr2->next!=NULL)
			{
		   		ptr2=ptr2->next;
			}
			ptr2->next=ptr1;
		}
		printf("\ndo you want to continue(y/n)?: ");
		fflush(stdin);
		ch=getchar();
	}while(ch=='y'||ch=='Y');
}
struct list *nn(int age,int rollno)
{
	struct list *ptr;
ptr=(struct list*)malloc(
                   sizeof(struct list));
	ptr->age=age;
	ptr->rollno=rollno;
	ptr->next=NULL;
	return ptr;
}
void traverse()
{
	struct list *ptr;
	if(start==NULL)
	{
		printf("\nlist is empty");
	}
	else
	{
		ptr=start;
		while(ptr!=NULL)
		{
			printf("\n%d--->%d",ptr->age,ptr->rollno);
			ptr=ptr->next;
		}
	}
}
int countNodes()
{
	int count=0;
	struct list *ptr=start;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next;
	}
	return count;
}
void deleteByRollNo()
{
	int rollno;
	struct list *ptr=start,*ptr1;
	printf("\nenter rollno: ");
	scanf("%d",&rollno);
	while(ptr!=NULL&&ptr->rollno!=rollno)
	{
		ptr1=ptr;
		ptr=ptr->next;
	}
	if(ptr==NULL)
	  printf("\nrollno not found");
	else
	{
		if(ptr==start)
			start=start->next;
		else
			ptr1->next=ptr->next;
		free(ptr);
		ptr=NULL;
	}
}
void main()
{
	 int ch;
	 while(1)
	 {
     	printf("\n1. add node");
     	printf("\n2. traverse");
     	printf("\n3. countNode");
     	printf("\n4. deleteByRollNo");
     	printf("\n5. exit");
     	printf("\nenter your choice: ");
     	scanf("%d",&ch);
     	switch(ch)
     	{
     		case 1: add();
     	        break;
     		case 2: traverse();
     	        break;
     		case 3: printf("\n%d",countNodes());
     		        break;
     		case 4: deleteByRollNo();
     		    break;
     		case 5: return 0;

	 	}
	 }
}
