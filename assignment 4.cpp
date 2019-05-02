#include<iostream>
using namespace std;

void create(int mat[][10], int v)
{
int v1,v2,cost;
int edges;
cout<< "\nEnter the total number of edges : ";
cin>> edges;

for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			mat[i][j] = 0;
		}
	}

for(int i=0;i<edges;i++)
    {
cout<< "\nEnter edge : ";
cin>> v1 >> v2;
cout<< "\nEnter the cost of that edge : ";
cin>> cost;
mat[v1][v2] = cost;
    }
}

void display_matrix(int mat[][10],int v)
{
cout<< "\nAdjacency matrix representation :- " <<endl;
for(int i=0;i<v;i++)
    {
for(int j=0;j<v;j++)
        {
cout<< mat[i][j] << "\t";
        }
cout<<endl;
    }
}

int min_dist(int dist[],int visited[],int v)
{
int min = 32767;
int min_index;
for(int i=0;i<v;i++)
    {
if(visited[i] == 0 &&dist[i] <= min)
        {
min = dist[i];
min_index = i;
        }
    }
cout<<min_index<<endl;
return min_index;
}

void print_dist(int mat[][10],int dist[],int v,int parent[])
{
int sum=0;
cout<<"\nPRIM'S MST OF THE GRAPH IS: ";
for(int i = 1; i<v; i++) 
    {
cout<<"\n"<<i<<"-"<<parent[i];
sum = sum + mat[parent[i]][i];
    }
cout<<endl;
cout<<"\nCOST OF MST IS: "<<sum<<endl;
}

void prims(int mat[][10],int s,int v)
{
int dist[v];
int visited[v];
int parent[v];
for(int i=0;i<v;i++)
    {
dist[i] = 32767;
visited[i] = 0;
    }
dist[s] = 0;
int p=0;
for(int j=0;j<v-1;j++)
    {
        p = min_dist (dist,visited,v);
visited[p] = 1;
for(int q=0;q<v;q++)
        {
if(mat[p][q] != 0)
            {
if(visited[q] == 0 && mat[p][q] <dist[q])
                {
dist[q] = mat[p][q];
parent[q] = p;
                }
            }
        }
    }
print_dist(mat,dist,v,parent);
}



int main()
{
int v;
int s;
cout<< "\nEnter the number of vertices : ";
cin>> v;
int mat[v][10];
	create(mat,v);
display_matrix(mat,v);
cout<< "\nEnter source vertex : ";
cin>> s;
prims(mat,s,v);
return 0;
}

