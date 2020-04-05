#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int N, M;
	int count = 1;

	stack<int> dep;
	int depth = 0;
	int dir[4] = { (0,-1), (0,1),(-1,0),(1,0) };

	queue<int> q;

	cin >> N >> M;
	vector<int> sibling(N * M);
	vector<int> visited(N * M);
	int** maze = new int* [M];

	string input;
	for (int i = 0; i < M; i++)
	{
		maze[i] = new int[N];
//		memset(maze[i], 0, sizeof(int) * N);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		for (int j = 0; j < M; j++)
		{
			maze[i][j] = input[j] - '0';
		}
	}
	int push = 0;
	int parent;
	q.push(0);
	sibling[0] = 0;
	dep.push(0);
	while (1)
	{
		push = q.front();
		depth = 0;
		if (dep.top() == q.front()) count++;
		int i = push / M, j = push % M;
		if (maze[i][j] != 0 && visited[push] != 1)
		{
			if (i == 0)
			{
				if (j == 0)
				{
					if (maze[i][j + 1] == 1 && visited[M * i + j + 1] != 1)
					{
						q.push(M * i + j + 1);
						dep.push(M * i + j + 1);
						depth++;
						if (q.back() == N * M - 1) break;
					}
					if (maze[i + 1][j] == 1 && visited[M * (i+1) + j] != 1)
					{
						q.push(M * (i + 1) + j);
						dep.push(M * (i + 1) + j);
						depth++;
						if (q.back() == N * M - 1) break;
					}
				}
				else if (j == M - 1)
				{
					if (maze[i][j - 1] == 1 && visited[M * i + j - 1] != 1)
					{
						q.push(M * (i) + j - 1);
						dep.push(M * (i)+j - 1);
						depth++;
						if (q.back() == N * M - 1) break;
					}
					if (maze[i + 1][j] == 1 && visited[M * (i + 1) + j] != 1)
					{
						q.push(M * (i + 1) + j);
						dep.push(M * (i + 1) + j);
						depth++;
						if (q.back() == N * M - 1) break;
					}
				}
				else
				{
					if (maze[i][j - 1] == 1 && visited[M * i + j - 1] != 1)
					{
						q.push(M * (i) + j - 1);
						dep.push(M * (i)+j - 1);
						depth++;
						if (q.back() == N * M - 1) break;
					}
					if (maze[i][j + 1] == 1 && visited[M * i + j + 1] != 1)
					{
						q.push(M * (i) + j + 1);
						dep.push(M * i + j + 1);
						depth++;
						if (q.back() == N * M - 1) break;
					}
					if (maze[i + 1][j] == 1 && visited[M * (i + 1) + j] != 1)
					{
						q.push(M * (i + 1) + j);
						dep.push(M * (i + 1) + j);
						depth++;
						if (q.back() == N * M - 1) break;
					}
				}
				//if(q.back() != push) count++;
			
			}
			else if (i == N - 1)
			{
				if (j == 0)
				{
					if (maze[i][j + 1] == 1 && visited[M * i + j + 1] != 1 )
					{
						q.push(M * (i)+j + 1);
						dep.push(M * i + j + 1);
						depth++;
						if (q.back() == N * M - 1) break;

					}
					if (maze[i - 1][j] == 1 && visited[M * (i - 1) + j] != 1)
					{
						q.push(M * (i - 1)+j);
						dep.push(M* (i - 1) + j);
						depth++;
						if (q.back() == N * M - 1) break;

					}
				}
				else if (j == M - 1)
				{
					if (maze[i][j - 1] == 1 && visited[M * i + j - 1] != 1)
					{
						q.push(M * (i)+j - 1);
						dep.push(M * (i)+j - 1);
						depth++;
						if (q.back() == N * M - 1) break;
					}
					if (maze[i - 1][j] == 1 && visited[M * (i - 1) + j] != 1)
					{
						q.push(M * (i - 1) + j);
						dep.push(M * (i - 1) + j);
						depth++;
						if (q.back() == N * M - 1) break;
					}
				}
				else
				{
					if (maze[i - 1][j] == 1 && visited[M * (i - 1) + j] != 1)
					{
						q.push(M * (i - 1) + j);
						dep.push(M* (i - 1) + j);
						depth++;
						if (q.back() == N * M - 1) break;
					}
					if (maze[i][j - 1] == 1 && visited[M * i + j - 1] != 1)
					{
						q.push(M * (i)+j - 1);
						dep.push(M* (i)+j - 1);
						depth++;
						if (q.back() == N * M - 1) break;
					}
					if (maze[i][j + 1] == 1 && visited[M * i + j + 1] != 1)
					{
						q.push(M* (i)+j + 1);
						dep.push(M* i + j + 1);
						depth++;
						if (q.back() == N * M - 1) break;
					}
				}
//				if (q.back() != push) count++;
			}
			else
			{
				if (j == 0)
				{
					if (maze[i][j + 1] == 1 && visited[M * i + j + 1] != 1)
					{
						q.push(M * (i)+j + 1);
						dep.push(M* i + j + 1);
						depth++;
						if (q.back() == N * M - 1) break;
					}
					if (maze[i + 1][j] == 1 && visited[M * (i + 1) + j] != 1)
					{
						q.push(M * (i + 1) + j);
						dep.push(M* (i + 1) + j);
						depth++;
						if (q.back() == N * M - 1) break;
					}
					if (maze[i - 1][j] == 1 && visited[M * (i - 1) + j] != 1)
					{
						q.push(M * (i - 1) + j);
						dep.push(M* (i - 1) + j);
						depth++;
						if (q.back() == N * M - 1) break;
					}
				}
				else if (j == M - 1)
				{
					if (maze[i][j - 1] == 1 && visited[M * i + j - 1] != 1)
					{
						q.push(M* (i)+j - 1);
						dep.push(M* (i)+j - 1);
						depth++;
						if (q.back() == N * M - 1) break;
					}
					if (maze[i + 1][j] == 1 && visited[M * (i + 1) + j] != 1)
					{
						q.push(M* (i + 1) + j);
						dep.push(M* (i + 1) + j);
						depth++;
						if (q.back() == N * M - 1) break;
					}
					if (maze[i - 1][j] == 1 && visited[M * (i - 1) + j] != 1)
					{
						q.push(M* (i - 1) + j);
						dep.push(M* (i - 1) + j);
						depth++;
						if (q.back() == N * M - 1) break;
					}
				}
				else
				{
					if (maze[i - 1][j] == 1 && visited[M * (i - 1) + j] != 1)
					{
						q.push(M* (i - 1) + j);
						dep.push(M* (i - 1) + j);
						depth++;
						if (q.back() == N * M - 1) break;
					}
					if (maze[i][j - 1] == 1 && visited[M * i + j - 1] != 1)
					{
						q.push(M* (i)+j - 1);
						dep.push(M* (i)+j - 1);
						depth++;
						if (q.back() == N * M - 1) break;
					}
					if (maze[i][j + 1] == 1 && visited[M * i + j + 1] != 1)
					{
						q.push(M* (i)+j + 1);
						dep.push(M* i + j + 1);
						depth++;
						if (q.back() == N * M - 1) break;
					}
					if (maze[i + 1][j] == 1 && visited[M * (i + 1) + j] != 1)
					{
						q.push(M* (i + 1) + j);
						dep.push(M* (i + 1) + j);
						depth++;
						if (q.back() == N * M - 1) break;
					}
				}
//				if (q.back() != push) count++;
			}

		}
		visited[push] = 1;
		q.pop();
		parent = push;
		if (push != 0) sibling[parent] = depth;

	}

	cout << count + 1 << endl;
}