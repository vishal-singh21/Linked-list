#include<stdio.h>
struct List *memory(int);
struct List
{
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
void delete()
{
    int pos,n,count=0;
    struct List *ptr,*ptr1;
    printf("enter position to delete");
    scanf("%d",&pos);
    n=countNodes();
    if(pos<1 || pos > n){
        printf("invalid position");
    }
    else{
        ptr=start;
        if(pos==1){
            free(start);
            start=ptr;
        }
        else{
            while(pos-2>count)
            {
                count++;
                ptr=ptr->next;
            }
            ptr1=ptr->next;
            ptr->next=ptr->next->next;
            free(ptr1);
            ptr1=NULL;
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
        printf("\n4.delete node");
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
            case 4:delete();
            break;
            case 5:exit(0);
        }
    }
}


