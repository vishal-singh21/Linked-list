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
void insert()
{
	struct list *ptr,*ptr1;
	int pos,n,rollno,age,count;
	printf("\nenter position: ");
	scanf("%d",&pos);
	n=countNodes();
	if(pos<=0 || pos>n+1 )
	{
		printf("\ninvalid position");
	}
	else
	{
		printf("\nenter rollno: ");
		scanf("%d",&rollno);
		printf("\nenter age: ");
		scanf("%d",&age);
		ptr=nn(age,rollno);
		if(pos==1)
		{
			ptr->next=start;
			start=ptr;
		}
		else
		{
		   ptr1=start;
		   count=0;
		   while(pos-2>count)
		   {
		   	ptr1=ptr1->next;
		   	count++;
		   }
		   ptr->next=ptr1->next;
		   ptr1->next=ptr;

		}
	}
}
void deleteNode()
{
	int pos,n,count;
	struct list *ptr,*ptr1;
	printf("\nenter position: ");
	scanf("%d",&pos);
	n=countNodes();
	if(pos<1 || pos>n)
	{
		printf("\ninvalid position");
	}
	else
	{
	    if(pos==1)
		{
			ptr=start;
			start=start->next;
			free(ptr);
			ptr=NULL;
		}
		else
		{
			ptr=start;
			count=0;
			while(pos-2>count)
			{
				ptr=ptr->next;
				count++;
			}
			ptr1=ptr->next;
			ptr->next=ptr->next->next;
			free(ptr1);
			ptr1=NULL;
		}
	}
}
void update()
{
	int pos,n,count;
	struct list *ptr;
	printf("\nenter position: ");
	scanf("%d",&pos);
	n=countNodes();
	if(pos<=0 || pos>n)
	{
		printf("\ninvalid position");

	}
	else
	{
		ptr=start;
		count=0;
		while(pos-1>count)
		{
			ptr=ptr->next;
			count++;
		}
		printf("\nenter new age: ");
		scanf("%d",&ptr->age);
		printf("\nenter new rollno: ");
		scanf("%d",&ptr->rollno);
	}
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
void addInAscendingOrder()
{
	int age,rollno;
	struct list *ptr,*ptr1,*ptr2;
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
		    ptr=start;
			while(ptr!=NULL && ptr->rollno<ptr1->rollno )
            {
                ptr2=ptr;
                ptr=ptr->next;
            }
            ptr1->next=ptr2->next;
            ptr2->next=ptr1;
		}
		printf("\ndo you want to continue(y/n)?: ");
		fflush(stdin);
		ch=getchar();
	}while(ch=='y'||ch=='Y');
}
void reverse()
{
     struct list *ptr,*pre,*next;

     if(start->next==NULL)
        printf("cant reverse");
     else
     {
         ptr=start;
         pre=start;
         next=start->next;
         while(ptr!=NULL)
         {
             next=ptr->next;
             ptr->next=pre;
             pre=ptr;
             ptr=next;
         }
         start->next=NULL;
         start=pre;
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
     	printf("\n4. insert");
     	printf("\n5. delete");
     	printf("\n6. update");
     	printf("\n7. deleteByRollNo");
     	printf("\n8. add in ascending");
     	printf("\n9. reverse");
     	printf("\n10. exit");
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
     		case 4: insert();
     	        break;
     		case 5: deleteNode();
     	        break;
     		case 6: update();
     	        break;
     		case 7: deleteByRollNo();
     		    break;
     		case 8: addInAscendingOrder();
     		    break;
     		case 9: reverse();
     		    break;
     		case 10: return 0;

	 	}
	 }
}














