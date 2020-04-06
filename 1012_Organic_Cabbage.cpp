#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int T, N, M, K;
	queue<pair<int, int> > q;
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };
	int count;

	cin >> T;
	while (T != 0)
	{
		cin >> N >> M >> K;
		int land[50][50] = { 0, };
		bool visited[50][50] = { false, };
		count = 0;
		for (int i = 0; i < K; i++)
		{
			int a, b;
			cin >> a >> b;
			land[a][b] = 1;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (land[i][j] == 1 && !visited[i][j] )
				{
					q.push(make_pair(i, j));
					visited[i][j] = true;

					while (!q.empty())
					{
						int x = q.front().first;
						int y = q.front().second;

						q.pop();
						for (int k = 0; k < 4; k++)
						{
							int newX = x + dx[k];
							int newY = y + dy[k];

							if (0 <= newX && newX < N && 0 <= newY && newY < M && land[newX][newY] == 1 && !visited[newX][newY])
							{
								q.push(make_pair(newX, newY));
								visited[newX][newY] = true;
							}
						}
					}

					count++;
				}
			}
		}
		cout << count << endl;
		T--;
	}
}