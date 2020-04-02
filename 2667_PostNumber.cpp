#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int N;
	cin >> N;

	string arr[25];
	vector<int> building;
	queue<pair<int, int>> q;

	bool visited[25][25] = { false, };
	int sum = 0;
	int count[25][25] = { 0, };
	int dx[4] = { 0,-1,0,1 };
	int dy[4] = { -1,0,1,0 };

	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == '1' && !visited[i][j])
			{
				int x, y;
				sum = 0;
				q.push(make_pair(i, j));
				visited[i][j] = true;
				count[i][j] = 1;
				while (!q.empty())
				{
					x = q.front().first;
					y = q.front().second;

					q.pop();
					sum++;
					for (int k = 0; k < 4; k++)
					{
						int newX = x + dx[k];
						int newY = y + dy[k];
						if (0 <= newX && newX < N && 0 <= newY && newY < N && arr[newX][newY] == '1' && !visited[newX][newY]/* && count[newX][newY] == 0*/)
						{
							visited[newX][newY] = true;
						//	count[newX][newY] = count[x][y] + 1;
							q.push(make_pair(newX, newY));
						}
					}
				}
				building.push_back(sum);
			}	
		}
	}
	sort(building.begin(), building.end());
	cout << building.size() << endl;
	for (auto i : building) cout << i << endl;
}