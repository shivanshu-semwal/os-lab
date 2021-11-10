
#include<stdio.h>
#include<conio.h>
#include<process.h>
void main()
{
char p[10][5],temp[5];
int c=0,pt[10],pr[i],i,j,n,temp1;
float bst=0.0,turn=0.0;

\newpageclrscr();
printf("enter no of processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter process%d name:\n",i+1);
scanf("%s",&p[i]);
printf("enter process time");
scanf("%d",&pt[i]);
printf(“\nenter the priority of process”);
scanf(“%d”,&pr[i]);
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(pr[i]>pr[j])
{
temp1=pt[i];
pt[i]=pt[j];
pt[j]=temp1;
t=pr[i];
pr[i]=pr[j];
pr[j]=t;
strcpy(temp,p[i]);
strcpy(p[i],p[j]);
strcpy(p[j],temp);
}
}
}
printf("\n.....................................................\n");
for(i=0;i<n;i++)
{
printf("|\t %s\t",p[i]);
}
printf("|\n.....................................................\n");
for(i=0;i<n;i++)
{
printf("\t\t%d",pt[i]);
}
printf("\n.....................................................\n");
printf("0");
for(i=0;i<n;i++)
{
bst+=c;
turn+=c+pt[i];

\newpagec=c+pt[i];
printf("\t\t%d",c);
}
printf("\nAverage time is %f: ",bst/n);
printf("\nTurn around time is %f", turn/n);
getch();
}