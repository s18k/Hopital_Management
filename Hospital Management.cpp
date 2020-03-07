#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
ofstream outfile("Details");
 typedef struct patient
{
char name[50];
char reason[50];
int age;
int p;

struct patient *nxt;
}node;
node *front=NULL;
node *rear=NULL;
void enqueue(int p)
{
node *a;
a=new node;
cout<<"\n Enter the name of patient";
fflush(stdin);
gets(a->name);
cout<<"\n Enter the age";
cin>>a->age;
cout<<"\n Enter the Reason of Visit";
fflush(stdin);
gets(a->reason);
a->p=p;
a->nxt=NULL;
if((front==NULL)||(p<front->p))
{
a->nxt=front;
front=a;
}
else
{ node *t;
node *pr;
t=front;

while((t->nxt!=NULL)&&((t->nxt)->p<=p))
{
t=t->nxt;

}
a->nxt=t->nxt;
t->nxt=a;
}
}
void display()
{
node *t=front;
if(front==NULL)
{

cout<<"\n Empty list!!!!!";

}
else
{
while(t!=NULL)
{
cout<<"\n Name: ";
puts(t->name);
cout<<"\n Age:  ";
cout<<t->age;
cout<<"\n Reason of Visit: ";
puts(t->reason);
cout<<"\n ___________________________________________________\n";
t=t->nxt;
}

}

}
void dequeue()
{

if(front!=NULL)
{

node *t=front;
 outfile<<"\n Name :  ";
    outfile<<t->name;
    outfile<<"\n Age: ";
    outfile<<t->age;
    outfile<<"\n Reason Of Visit:  ";
    outfile<<t->reason;
    outfile<<"\n ________________________________________________";
cout<<"\n Sending  "<<t->name<<"  To the Doctor";
front=front->nxt;

}
else
{
cout<<"\n List is empty";
}
}
int main()
{
cout<<"\n ****************************** WELCOME TO NOBLE CLINIC ************************************";
outfile<<"\n Details of Patients Visited By the Doctor \n";
int c;
do
{
cout<<"\n You can do the following things";
cout<<"\n 1.Enqueue new patient";
cout<<"\n 2.Send Current Patient to the Doctor";
cout<<"\n 3.Display Current  Waiting list";
cout<<"\n 4.Exit";
cin>>c;
switch(c)
{
case 1:
{
int p;
cout<<"\n Under which category does the Patient belong";
cout<<"\n 1.Heart Attack/Serious Symptoms/Accident ";
cout<<"\n 2.Severe Pain/Injury";
cout<<"\n 3.Fever/Cold/Cough";
cout<<"\n Enter the priority";
cin>>p;
enqueue(p);
break;
}
case 2:
{
dequeue();

break;

}
case 3:
{
display();
break;

}
case 4:
    {

outfile.close();
break;
    }

}
}while(c!=4);

return 0;
}

