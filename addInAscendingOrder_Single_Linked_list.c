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
void main()
{
	 int ch;
	 while(1)
	 {
     	printf("\n1. add node");
     	printf("\n2. traverse");
     	printf("\n3. addInAscendingOrder");
     	printf("\n4. exit");
     	printf("\nenter your choice: ");
     	scanf("%d",&ch);
     	switch(ch)
     	{
     		case 1: add();
     	        break;
     		case 2: traverse();
     	        break;
            case 3: addInAscendingOrder();
     	        break;
     		case 4: return 0;

	 	}
	 }
}
