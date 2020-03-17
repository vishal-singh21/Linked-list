#include<stdio.h>
struct List *memory(int);
struct List                //creating Structure fro data and next Pointer
{
    int data;
    struct List *next;        //next contain address for next node
};
struct List *start=NULL;       //contain address of starting node
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
struct List *memory(int data)           //create a node of structure type and also allocate memory
{
    struct List *ptr=(struct List *)malloc(sizeof(struct List));   //allocate dynamic memory to structure
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1. add node");
        printf("\n2.traverse");
        printf("\n3. exit");
        printf("\nenter your choice ");
        scanf("\n%d",&ch);
        switch(ch)
        {
            case 1:add();
            break;
            case 2:traverse();
            break;
            case 3:exit(0);
        }
    }
}


