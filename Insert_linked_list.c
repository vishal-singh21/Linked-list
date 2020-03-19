#include<stdio.h>
struct List *memory(int);
struct List{
    int data;
    struct List *next;
};
struct List *start=NULL;
struct List *memory(int data)
{
    struct List *ptr=(struct List *)malloc(sizeof(struct List));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}
void add()
{
    int data;
    struct List *ptr,*prt1;
    char ch;
    do
    {
        printf("enter data ");
        scanf("%d",&data);
        ptr=memory(data);
        if(start==NULL)
        {
            start=ptr;
        }
        else
        {
            prt1=start;
            while(prt1->next!=NULL)
            {
                prt1=prt1->next;
            }
            prt1->next=ptr;
        }
        printf("\ndo you want to add more (y/n)? ");
        fflush(stdin);
        ch=getchar();
        }while(ch=='y'|| ch=='Y');
}

void traverse()
{
    struct List *ptr;
    if(start==NULL)
	{
		printf("\nlist is empty");
	}
	else
	{
		ptr=start;
		while(ptr!=NULL)
		{
			printf("\n%d",ptr->data);
			ptr=ptr->next;
		}
	}
}
int countNodes()
{
    struct List *ptr=start;
    int count =0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    return count;
}
void insert()
{
    struct List *ptr,*ptr1;
    int pos,n,data,count=0;
    printf("enter position to insert");
    scanf("%d",&pos);
    n=countNodes();
    if(pos<=0 || pos >n+1)
    {
        printf("invalid position");
    }
    else
    {
        ptr1=start;
        printf("enter data to insert");
        scanf("%d",&data);
        ptr=memory(data);
        if(pos==1)
        {
            ptr->next=start;
            start=ptr;
        }
        else
        {
            while(count<pos-2)
            {
                count++;
                ptr1=ptr1->next;
            }
            ptr->next=ptr1->next;
            ptr1->next=ptr;
        }
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1. add node");
        printf("\n2.traverse");
        printf("\n3.countNodes");
        printf("\n4.insert");
        printf("\n5. exit");
        printf("\nenter your choice ");
        scanf("\n%d",&ch);
        switch(ch)
        {
            case 1:add();
            break;
            case 2:traverse();
            break;
            case 3:printf("\n%d",countNodes());
            break;
            case 4:insert();
            break;
            case 5:exit(0);
        }
    }
}


