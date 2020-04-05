#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;

	int** s = new int* [N];
	for (int i = 0; i < N; i++)
	{
		s[i] = new int[M];
	}
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };
	bool visited[1000][1000] = { false, };
	int** day = new int* [N];
	for (int i = 0; i < N; i++)
	{
		day[i] = new int[M];
		memset(day[i], 0, sizeof(int) * M);
	}
	queue<pair<int, int>> q;


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> s[i][j];
			if (s[i][j] == 1)
			{
				day[i][j] = 1;
				q.push(make_pair(i, j));
				visited[i][j] = true;
			}
			else if (s[i][j] == -1) day[i][j] = -1;
		}
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int newX = x + dx[i];
			int newY = y + dy[i];

			if (0 <= newX && newX < N && 0 <= newY && newY < M && !visited[newX][newY] && s[newX][newY] != -1 && day[newX][newY] == 0)
			{
				day[newX][newY] = day[x][y] + 1;
				visited[newX][newY] = true;
				q.push(make_pair(newX, newY));
			}
		}
	}

	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (day[i][j] == 0)
			{
				answer = -1;
				break;
			}
			else
			{
				if (answer < day[i][j]) answer = day[i][j];
			}
		}
		if (answer == -1) break;
	}
	if (answer == -1) cout << "-1" << endl;
	else cout << answer - 1 << endl;

}