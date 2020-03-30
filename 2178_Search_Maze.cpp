#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	int N, M;
	int vertex = 0;
	int count = 0;
	queue<int> queueshort;

	cin >> N >> M;
	int* visited = new int[N * M];
	
	int** maze = new int*[M];
	int** edge = new int*[M * N];

	for (int i = 0; i < N * M; i++)
	{
		visited[i] = 0;
	}

	string input;
	for (int i = 0; i < M; i++)
	{
		maze[i] = new int[N];
		memset(maze[i], 0, sizeof(int) * N);
	}

	for (int i = 0; i < M * N; i++)
	{
		edge[i] = new int[N * M];
		memset(edge[i], 0, sizeof(int) * (M * N));
	}

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		for (int j = 0; j < M; j++) 
		{
			maze[i][j] = input[j] - '0';
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (maze[i][j] != 0)
			{
				if (i == 0)
				{
					if (j == 0)
					{
						if (maze[i][j + 1] == 1)
						{
							edge[6 * i + j][6 * i + (j + 1)] = 1;
							edge[6 * i + j + 1][6 * i + j] = 1;
						}
						if (maze[i + 1][j] == 1)
						{
							edge[6 * i + j][6 * (i + 1) + j] = 1;
							edge[6 * (i + 1) + j][6 * i + j] = 1;
						}
					}
					else if (j == M - 1)
					{
						if (maze[i][j - 1] == 1)
						{
							edge[6 * i + j][6 * i + (j - 1)] = 1;
							edge[6 * i + j - 1][6 * i + j] = 1;
						}
						if (maze[i + 1][j] == 1)
						{
							edge[6 * i + j][6 * (i + 1) + j] = 1;
							edge[6 * (i + 1) + j][6 * i + j] = 1;
						}
					}
					else
					{
						if (maze[i][j - 1] == 1)
						{
							edge[6 * i + j][6 * i + (j - 1)] = 1;
							edge[6 * i + j - 1][6 * i + j] = 1;
						}
						if (maze[i][j + 1] == 1)
						{
							edge[6 * i + j][6 * i + (j + 1)] = 1;
							edge[6 * i + j + 1][6 * i + j] = 1;
						}
						if (maze[i + 1][j] == 1)
						{
							edge[6 * i + j][6 * (i + 1) + j] = 1;
							edge[6 * (i + 1) + j][6 * i + j] = 1;
						}
					}
				}
				else if (i == N - 1)
				{
					if (j == 0)
					{
						if (maze[i][j + 1] == 1)
						{
							edge[6 * i + j][6 * i + (j + 1)] = 1;
							edge[6 * i + j + 1][6 * i + j] = 1;
						}
						if (maze[i - 1][j] == 1)
						{
							edge[6 * i + j][6 * (i - 1) + j] = 1;
							edge[6 * (i - 1) + j][6 * i + j] = 1;
						}
					}
					else if (j == M - 1)
					{
						if (maze[i][j - 1] == 1)
						{
							edge[6 * i + j][6 * i + (j - 1)] = 1;
							edge[6 * i + j - 1][6 * i + j] = 1;
						}
						if (maze[i - 1][j] == 1)
						{
							edge[6 * i + j][6 * (i - 1) + j] = 1;
							edge[6 * (i - 1) + j][6 * i + j] = 1;
						}
					}
					else
					{
						if (maze[i - 1][j] == 1)
						{
							edge[6 * i + j][6 * (i - 1) + j] = 1;
							edge[6 * (i - 1) + j][6 * i + j] = 1;
						}
						if (maze[i][j - 1] == 1)
						{
							edge[6 * i + j][6 * i + (j - 1)] = 1;
							edge[6 * i + j - 1][6 * i + j] = 1;
						}
						if (maze[i][j + 1] == 1)
						{
							edge[6 * i + j][6 * i + (j + 1)] = 1;
							edge[6 * i + j + 1][6 * i + j] = 1;
						}
					}
				}
				else
				{
					if (j == 0)
					{
						if (maze[i][j + 1] == 1)
						{
							edge[6 * i + j][6 * i + (j + 1)] = 1;
							edge[6 * i + j + 1][6 * i + j] = 1;
						}
						if (maze[i + 1][j] == 1)
						{
							edge[6 * i + j][6 * (i + 1) + j] = 1;
							edge[6 * (i + 1) + j][6 * i + j] = 1;
						}
						if (maze[i - 1][j] == 1)
						{
							edge[6 * i + j][6 * (i - 1) + j] = 1;
							edge[6 * (i - 1) + j][6 * i + j] = 1;
						}
					}
					else if (j == M - 1)
					{
						if (maze[i][j - 1] == 1)
						{
							edge[6 * i + j][6 * i + (j - 1)] = 1;
							edge[6 * i + j - 1][6 * i + j] = 1;
						}
						if (maze[i + 1][j] == 1)
						{
							edge[6 * i + j][6 * (i + 1) + j] = 1;
							edge[6 * (i + 1) + j][6 * i + j] = 1;
						}
						if (maze[i - 1][j] == 1)
						{
							edge[6 * i + j][6 * (i - 1) + j] = 1;
							edge[6 * (i - 1) + j][6 * i + j] = 1;
						}
					}
					else
					{
						if (maze[i - 1][j] == 1)
						{
							edge[6 * i + j][6 * (i - 1) + j] = 1;
							edge[6 * (i - 1) + j][6 * i + j] = 1;
						}
						if (maze[i][j - 1] == 1)
						{
							edge[6 * i + j][6 * i + (j - 1)] = 1;
							edge[6 * i + j - 1][6 * i + j] = 1;
						}
						if (maze[i][j + 1] == 1)
						{
							edge[6 * i + j][6 * i + (j + 1)] = 1;
							edge[6 * i + j + 1][6 * i + j] = 1;
						}
						if (maze[i + 1][j] == 1)
						{
							edge[6 * i + j][6 * (i + 1) + j] = 1;
							edge[6 * (i + 1) + j][6 * i + j] = 1;
						}
					}
					
			
				}
			}
		}
	}

	queueshort.push(0);
	while (!queueshort.empty())			// ť�� �� ������ �ݺ�
	{
		int search = queueshort.front();

		if (search == (N - 1) * (M - 1))
		{
			break;
		}
		// ť�� FRONT�� �湮 ���̶�� ��� �� POP / �湮�ߴٸ� �׳� POP
		if (visited[search] != 1)
		{
			count++;
			cout << search << " ";
	
		}
		else
		{
		//	count -= 1;

		}
		queueshort.pop();

		// �湮 ���� ��� 1�� 
		visited[search] = 1;

		// ť�� FRONT�� ����Ǿ� �ְ�, �湮 �� ����� QUEUE�� �־���
		for (int i = 0; i < N * M; i++)
		{
			if (edge[search][i] == 1 && visited[i] != 1)
			{
				queueshort.push(i);
			}
		}
	}
				
	cout << endl;
	cout << count << endl;

	return 0;
}