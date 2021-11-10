
/*PAGE REPLACEMENT LRU */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int fsize,ssize,f,frame[10],arrive[30],rstring[30];
int main()
{
int i,lfi,idx,cs=0,f,ls=0,pf=0,j=0,y,k,z=0,time=0;
int pagefound (int x);
void display();
int leastused();
int pagelocation(int x);
clrscr();
printf("\n\n\t\t LRU PAGE REPLACEMENT");
printf("\n\t\t --------------------");
printf("\n\n\t Enter the frame size:");
scanf("%d",&fsize);
printf("\n\t Enter the reference string size:");
scanf("%d",&ssize);
printf("\n\t Enter the reference string:");
for(i=0;i<ssize;i++)
scanf("%d",&rstring[i]);
for(k=0;k<fsize;k++)
{
frame[k]=-3;
arrive[k]=0;
}
for(i=0;i<ssize;i++)
{
y=pagefound(rstring[i]);
if(y==0)
{
pf++;
if(cs>=fsize)

\newpage{
lfi=leastused();
frame [lfi]=rstring[i];
arrive [lfi]=++time;
}
else if (cs<fsize)
{
frame[cs]=rstring[i];
arrive [cs]=++time;
}
}
else
{
idx=pagelocation(rstring[i]);
arrive [idx]=++time;
}
cs++;
display();
}
printf("\n Page fault=%d",pf);
}
int pagefound(int x)
{
int i,val=0;
for(i=0;i<fsize;i++)
{
if(x==frame[i])
{
val=1;
break;
}
}
return(val);
}
void display()
{
int i;

\newpageprintf("\n");
for(i=0;i<fsize;i++)
{
if(frame[i]>=0)
{
printf("%d",frame[i]);
}
else
printf("\t");
}
}
int leastused()
{
int i,min=0,n=0;
for(i=1;i<fsize;i++)
{
if(arrive[i]<arrive[min])
{
min=i;
n++;
}
}
if(n==0)
return(0);
else
return(min);
}
int pagelocation(int pageno)
{
int i,flag=0;
for(i=0;i<fsize;i++)
{
if(frame[i]==pageno)
{
flag=1;
break;
}

\newpage}
return(i);
getch();
}