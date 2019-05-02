#include<iostream>
#include<fstream>
using namespace std;
class student
{
	int roll_num;
	char div;
	string name;
	string address;
	public:
	void getdata()
	{
		cout<<"\n Enter the Roll Number: ";
		cin>>roll_num;
		cout<<"Enter the division: ";
		cin>>div;
		cout<<"Enter the Name: ";
		fflush(stdin);
		getline(cin,name);
		cout<<"Enter the Address: ";
		fflush(stdin);
		getline(cin,address);
	}
	void putdata(int n)
	{
		student st[n];
		ifstream infile;
		infile.open("student.dat",ios::binary|ios::in);
		for(int i=0;i<n;i++)
	    {
			infile.read((char *)&st[i],sizeof(st[i]));
			cout<<"\n Roll Number: "<<st[i].roll_num;
			cout<<"\n Division:  "<<st[i].div;
			fflush(stdin);
			cout<<"\n Name:  "<<st[i].name;
			fflush(stdin);
			cout<<"\n Address:  "<<st[i].address;
			cout<<"\n ____________________________________________________ \n";
	    }
		infile.close();
    }


	void search_(int n)
	{
		student st[n];
		ifstream infile;
		cout<<"\n Enter the Roll Number to be searched: ";
		int r;
		cin>>r;
		infile.open("student.dat",ios::in|ios::binary);
		for(int i=0;i<n;i++)
		{
			infile.read((char *)&st[i],sizeof(st[i]));
			if(st[i].roll_num==r)
			{
				cout<<"\n Found";
				cout<<"\n Details:  "<<endl;
				cout<<"\n Roll Number: "<<st[i].roll_num;
				cout<<"\n Division:  "<<st[i].div;
				fflush(stdin);
				cout<<"\n Name:  "<<st[i].name;
				fflush(stdin);
				cout<<"\n Address:  "<<st[i].address;
				cout<<"\n ____________________________________________________ \n";
				infile.close();
				return;
		    }
		}
		cout<<"\n Not Found";
		infile.close();
	}
	
	void del(int n)
	{
		student st[n];
		int r;
		cout<<"\n Enter the roll number to be deleted ";
		cin>>r;
		ifstream infile;
		ofstream outfile;
		infile.open("student.dat",ios::binary|ios::in);
		outfile.open("temp.dat",ios::binary|ios::out);
		for(int i=0;i<n;i++)
		{
			infile.read((char *)&st[i],sizeof(st[i]));
			if(st[i].roll_num==r)
			{
				continue;
			}
			else
			{
				outfile.write((char *)&st[i],sizeof(st[i]));
			}
		}
		outfile.close();
		infile.close();
		remove("student.dat");
		int re=rename("temp.dat","student.dat");
		cout<<"Data deleted";
	
	}
};
int main()
{
	int n;
	cout<<"\nEnter the Number of Students:   ";
	cin>>n;
	student s[n];
	ofstream outfile;
	outfile.open("student.dat",ios::out|ios::binary);
	for(int i=0;i<n;i++)
	{
		cout<<"\n Enter the information of Students: ";
		s[i].getdata();
		outfile.write((char *)&s[i],sizeof(s[i]));
	}
	outfile.close();
	
	int c;
	student d;
	do
	{
		cout<<"\n 1.Search";
		cout<<"\n 2.Delete";
		cout<<"\n 3.Display";
		cout<<"\n 4.Exit";
		cout<<"\n Enter Your Choice";
		cin>>c;
		switch(c)
		{
			case 1:d.search_(n);break;
			case 2:d.del(n);n=n-1;break;
			case 3:d.putdata(n);break;
			case 4:break;
		}
	}
	while(c!=4);
	
}

