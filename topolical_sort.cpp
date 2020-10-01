// Topological Sort

#include<bits/stdc++.h>
#include"stack.cpp"
using namespace std;

int check_visited(bool* visited,int n)
{
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
			return i;
	}
	return -1;
}

void Topological_Sort(int **edges,int sv,int n,bool *visited,int *stack)
{
	
	visited[sv]=true;
	for(int i=0;i<n;i++)
	{
		if(edges[sv][i]==0)
			continue;
		if(visited[i])
			continue;
			
		Topological_Sort(edges,i,n,visited,stack);

	}
	push(stack,sv,n);
}

int main()
{
	int n,e;
	int a,b;
	int sv;
	cout<<"Enter no. of nodes and no.of edges in the graph\n";
	cout<<"Remember! node values should range from 0 to n-1\n";
	cin>>n>>e;
	int stack[n];
	int **edges=new int *[n];
	for(int i=0;i<n;i++)
	{
		edges[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			edges[i][j]=0;
		}
	}
	cout<<"Enter start node and end node of the edges\n";
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		edges[a][b]=1;
	}
	cout<<"Enter starting vertexof graph\n";
	cin>>sv;
	bool *visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	Topological_Sort(edges,sv,n,visited,stack);
	while(1)
	{
		int p=check_visited(visited,n);
		if(p==-1)
			break;
		Topological_Sort(edges,p,n,visited,stack);
	}
	cout<<"Result\n";
	for(int i=0;i<n;i++)
	{
		cout<<pop(stack)<<" ";
	}
}









//sample input
//
//6 6
//
//0 1
//0 3
//1 2
//2 4
//2 3
//3 4
//
//output
//
//5 0 1 2 3 4
