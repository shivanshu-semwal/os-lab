
#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedefstruct node
{
charprss[3];
int burst;
int priority;
struct node *next;
}node;
node *front=NULL;
node *rear=NULL;
void insert();
void display(int);
void main()
{
int i,n;
printf("\nEnter number of processes : ");
scanf("%d",&n);
for(i=0;i<n;i++)
insert();
printf("\n\nExecuting processes : \n");
display(n);
printf("\n");
}

//HEADER FILES

//STRUCTURE

//GLOBAL VARIABLES
//FUNCTION DECLARATION
//MAIN FUNCTION

//LOOP
//FUNCTION CALL
//FUNCTION CALL
//END OF MAIN

\newpagevoid insert()
//FUNCTION DEFINITION
{
node *p,*temp;
int b,pri;
p=(node*)malloc(sizeof(node)); //DYNAMIC MEMORY ALLOCATION
printf("\n\tEnter the process name : ");
scanf("%s",p->prss);
printf("\tEnter Burst time : ");
scanf("%d",&b); printf("\tEnter
Priority : "); scanf("%d",&pri); p>burst=b;
p->priority=pri;
p->next=NULL;
if(front==NULL)
{
front=p;
rear=p;
}
else if(p->priority < front->priority)
{
p->next=front;
front=p;
}
else if(p->priority > rear->priority)
{
rear->next=p;
rear=p;
}
else
{
temp=front;
while( p->priority > (temp->next)->priority )
temp=temp->next;
p->next=temp->next;
temp->next=p;
}
}
void display(int n)
{
node *temp=front;
int c=0;
float turn=0.0,wttime=0.0;
if(front!=NULL)
{

//FUNCTION DEFINITION

\newpageprintf("\n-------------------------------------------------------\n\t");
while(temp!=NULL)
{
printf("|\t%s\t",temp->prss);
temp=temp->next;
}
printf("\n-------------------------------------------------------------------\n");
temp=front;
while(temp!=NULL)
{
printf("\t%d\t ",temp->burst);
temp=temp->next;
}
printf("\n------------------------------------------------------------------\n\t");
temp=front;
printf("0\t");
while(temp!=NULL)
{
wttime+=c;
turn+=c+temp->burst;
c=c+temp->burst;
printf(" \t%d\t ",c);
temp=temp->next;
}
printf("\n------------------------------------------------------------\n");
printf("\n\nAveragewt time = %f ",wttime/n);
printf("\nTurn around time = %f\n",turn/n);
}
}