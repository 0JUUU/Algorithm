#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int main()
{
	int N, M, a, b;
	queue<int> q;
	cin >> N >> M;

	int** graph = new int* [N+1];
	bool* visited = new bool[N + 1];

	for (int i = 0; i < N+1; i++)
	{
		graph[i] = new int[N + 1];
		visited[i] = false;
	}


	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	
	int count = 0;
	for (int i = 1; i <= N/2; i++)
	{
		if(!visited[i])
		{
			for (int j = i; j <= N; j++)
			{
				if (graph[i][j] == 1)
				{
					q.push(i);
					while (!q.empty())
					{
						int q_front = q.front();
						visited[q_front] = true;
						q.pop();
						for (int k = q_front; k <= N; k++)
						{
							if (graph[q_front][k] == 1 && !visited[k])
							{
								q.push(k);
							}
						}

					}
					count++;
					break;
				}
			}
		}

	}
	
	cout << count << endl;
}