#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int MAX = 99999;
int prev1 = 99999;

int get_path(int graph[][6], bool visited[], int n, string path, int s, int d, int length)
{
	//cout<<"Inside function";
	if (s == d)
	{
		cout<<"Found a path:"<<endl;
		cout<<path<<endl;

		cout<<"Length:"<<length<<endl;
		return length;
	}
	else
	{
		//cout<<"Got s="<<s<<endl;
		for(int j=0; j<n; j++)
		{
			if (graph[s][j] != MAX && visited[j]==false)
			{
				int temp = graph[s][j];
				graph[s][j] = 0;
				visited[j] = true;

				prev1 = min(prev1, get_path(graph, visited, n, path+" "+to_string(j), j, d, length+temp));

				graph[s][j] = temp;
				visited[j] = false;
			}
		}
	}
	return prev1;
}

void display_graph(int graph[][6], int n)
{
	cout<<"Graph Matrix is "<<endl;
	for (int i=0; i<n; i++)
	{
		cout<<endl;
		for(int j=0; j<n; j++)
			cout<<graph[i][j]<<" ";
	}
}

int main()
{
	const int n = 6;
	int graph[6][6] = {
		{MAX, 1, 2, MAX, MAX, MAX},
		{MAX, MAX, 3, 1, MAX, MAX},
		{MAX, MAX, MAX, MAX, 3, MAX},
		{MAX, MAX, 2, MAX, MAX, 4},
		{MAX, MAX, MAX, 1, MAX, 2},
		{MAX, MAX, MAX, MAX, MAX, MAX}
	};

	int s = 0, d = 5;

	bool visited[] = {false, false, false, false, false, false};
	string path = " "+to_string(s);

	display_graph(graph, n);
	prev1 = get_path(graph, visited, n, path, s, d, 0);

	cout<<"MIN Length:"<<prev1<<endl;

	return 0;
}
