#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int N, M;
	bool visited[100][100] = { false, };
	int count[100][100] = { 1, };
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };
	string s[100];

	queue<pair<int, int>> q;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> s[i];			// s[i]에 M만큼의 문자열이 들어감
	}

	visited[0][0] = true;
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dirx = x + dx[i];
			int diry = y + dy[i];
			if (0 <= dirx && dirx < N && 0 <= diry && diry < M && s[dirx][diry] == '1' && !visited[dirx][diry] && count[dirx][diry] == 0)
			{
				count[dirx][diry] = count[x][y] + 1;
				visited[dirx][diry] = true;
				q.push(make_pair(dirx,diry));
			}

		}
	}

	cout << count[N - 1][M - 1] << endl;


}