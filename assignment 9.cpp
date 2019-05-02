#include<iostream>
#include<fstream>
using namespace std;
typedef struct emp_records
{
    int emp_id;
    string name;
    long int sal;

}rec;
typedef struct index_file
{
    int id;
    int pos;
}index;

class employee
{
    rec record;
    index index_record;
public:
    void getdata()
    {
    ofstream seqfile;
    ofstream indexfile;
    int i=0;
    indexfile.open("index.dat",ios::out|ios::binary);
    seqfile.open("seq.dat",ios::out|ios::binary);
    char ch;
    do
    {
        cout<<"\n Enter the Employee ID"<<endl;
        cin>>record.emp_id;
        cout<<"\n Enter the Name"<<endl;
        cin>>record.name;
        cout<<"\n Enter the Salary"<<endl;
        cin>>record.sal;
        seqfile.write((char*)&record,sizeof(record));
        index_record.id=record.emp_id;
        index_record.pos=i;
        indexfile.write((char*)&index_record,sizeof(index_record));
        i++;
        cout<<"\n Continue? (y/n)"<<endl;
        cin>>ch;

    }while(ch=='y'|| ch=='Y');
    indexfile.close();
    seqfile.close();
    }
    void display()
    {
        ifstream seqfile;
        ifstream indexfile;
        seqfile.open("seq.dat",ios::in|ios::binary);
        indexfile.open("index.dat",ios::in|ios::binary);
        int i=0;
        while(indexfile.read((char*)&index_record,sizeof(index_record)))
        {
            i=index_record.pos*sizeof(record);
            seqfile.seekg(i,ios::beg);
            seqfile.read((char*)&record,sizeof(record));
            if(record.emp_id!=-1)
            {
                cout<<"\n Name:  "<<record.name;
                cout<<"\n EMP ID:  "<<record.emp_id;
                cout<<"\n Salary:  "<<record.sal;
                cout<<endl;
            }


        }
        seqfile.close();
        indexfile.close();

    }
    int Search()
    {
        ifstream seqfile;
        ifstream indexfile;
        int pos=-1;
        int offset;
        int x;
        cout<<"\n Enter the ID";
        cin>>x;
        indexfile.open("index.dat",ios::in|ios::binary);
        seqfile.open("seq.dat",ios::in|ios::binary);
        while(indexfile.read((char*)&index_record,sizeof(index_record)))
        {
            if(index_record.id==x)
            {
                pos=index_record.pos;
                break;
            }
        }
        if(pos==-1)
        {
            cout<<"\n Not Present in the File";
            return 0;
        }
      //  cout<<pos<<endl;
        offset=pos*sizeof(record);
        seqfile.seekg(offset,ios::beg);
        seqfile.read((char*)&record,sizeof(record));
        if(record.emp_id==-1)
        {
            cout<<"\n Data was deleted"<<endl;
        }
        else
        {
            cout<<"\n Name:  "<<record.name;
                cout<<"\n EMP ID:  "<<record.emp_id;
                cout<<"\n Salary:  "<<record.sal;
                cout<<endl;
            return(offset);
        }

    }
    void del()
    {
        int offset=Search();
        cout<<offset<<endl;
        fstream seqfile;
        seqfile.open("seq.dat",ios::binary|ios::in|ios::out);
        seqfile.seekg(offset,ios::beg);
        seqfile.read((char*)&record,sizeof(record));
        cout<<offset<<endl;
        record.emp_id=-1;
        cout<<"\n Name:  "<<record.name;
                cout<<"\n EMP ID:  "<<record.emp_id;
                cout<<"\n Salary:  "<<record.sal;
                cout<<endl;
        //offset=offset-(sizeof(record));
        //cout<<offset<<endl;
        seqfile.seekp(offset,ios::beg);
        seqfile.write((char*)&record,sizeof(record));
        cout<<"\n Deleted Successfully"<<endl;
        seqfile.close();
    }

};
int main()
{
employee e;
e.getdata();
e.display();
e.Search();
e.del();
e.display();
}
