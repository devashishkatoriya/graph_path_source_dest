#include <iostream>
#include <vector>

using namespace std;
void get_path(int graph[][6], bool visited[], int n, string path, int s, int d, int MAX)
{
	//cout<<"Inside function";
	if (s==d)
	{
		cout<<"Found a path:"<<endl;
		cout<<path<<endl;
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

				get_path(graph, visited, n, path+" "+to_string(j), j, d, MAX);

				graph[s][j] = temp;
				visited[j] = false;
			}
		}
	}
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
	const int MAX = 99999;

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
	get_path(graph, visited, n, path, s, d, MAX);

	return 0;
}
