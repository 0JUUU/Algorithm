#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int N, M;
	int count = 1;
	int depth = 0;
	int sum = 0;
	int dir[4] = { (0,-1), (0,1),(-1,0),(1,0) };

	queue<int> q;

	cin >> N >> M;
	queue<pair<int, int>> sibling;
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

	cout << count << endl;
}