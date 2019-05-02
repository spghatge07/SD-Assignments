#include<iostream>
#include<stdlib.h>
using namespace std;

int size=10;
void display(int hash[])
{
	int i;
	cout<<"\nHASH TABLE:\n";
	for(i=0;i<size;i++)
 	{
		cout<<""<<hash[i]<<"\t";
 	}
}
int main()
{
	int hash[size],val,i;
	char ch;
	for(i=0;i<size;i++)
	{
		hash[i]=-1;
	}
	do
	{
		cout<<"Enter the value:  ";
		cin>>val;
		int m=val%size;
		if(hash[m] == -1)
		{
			hash[m]=val;
			display(hash);
		}
	else
	{
		cout<<"\nCollision: ";
		cout<<""<<hash[m]<<"\n";
		if(hash[m]%10!=m)
 		{
			int h=hash[m];
			hash[m]=val;
			val=h;
 		}
		int x=1+(val%(size-1));
		for(i=1;i<size;i++)
 		{
			int y=(val+i*x);
			int z=y%size;
			if(hash[z]==-1)
   			{
				hash[z]=val;
				display(hash);
				break;
   			}
 		}
	}
	cout<<"\n\n Want to add more values?  ";
	cin>>ch;
	int ss=0;
	for(i=0;i<size;i++)
	{
		if(hash[i]!= -1)
		ss++;
	}
	if(ss==10)
	{
		cout<<"\n\nHast table is full";
		exit(1);
	}
}while(ch=='y' || ch=='Y');
display(hash);
return 0;
}

