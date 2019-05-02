#include<iostream>
#define MAX 20
using namespace std;
class dijkstra
{
int city;
int distance[MAX][MAX];
int d[MAX];
int visited[MAX];
public:
void city_no();
int minvertex();
void matrix_fill();
void dijkstra_code();
void display();
};
void dijkstra::city_no()
{
cout<<"\n enter the number of cities (including cities A and B) : ";
cin>>city;
}
int dijkstra::minvertex()
{
int mvertex=-1;
for(int i=0;i<city;i++)
{
if(visited[i]==0 && (mvertex==-1 || d[i]<d[mvertex]))
mvertex=i;
}
return mvertex;
}
void dijkstra::matrix_fill()
{
cout<<"\n enter the distances between the cities : ";
for(int i=0;i<city;i++)
{
cout<<"\n For city "<<i<<endl;
for(int j=0;j<city;j++)
{
if(i==j)
distance[i][j]=0;
cin>>distance[i][j];
}
d[i]=INT_MAX;
visited[i]=0;
}
}
void dijkstra::dijkstra_code()
{
d[0]=0;
for(int i=0;i<city-1;i++)
{
int mvertex=minvertex();
visited[mvertex]=1;
for(int j=0;j<city;j++)
{
if((distance[mvertex][j]!=0)&&(visited[j]==0))
{
int dist=d[mvertex]+distance[mvertex][j];
if(dist<d[j])
d[j]=dist;
}
}
}
}
void dijkstra::display()
{
cout<<"\n distance of cities from city 0 \n";
cout<<"city Distance\n";
for(int i=0;i<city;i++)
cout<<i<<"\t"<<d[i]<<endl;
}
int main()
{
dijkstra sp;
sp.city_no();
sp.matrix_fill();
sp.dijkstra_code();
sp.display();
return 0;
}

