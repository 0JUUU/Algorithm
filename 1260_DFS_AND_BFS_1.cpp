#include <iostream>
#include <stack>
#include <queue>
using namespace std;

stack<int> stackDFS;
queue<int> queueBFS;

void DFS(int V, int N, int* visited, int* edge[]) {
//	stackDFS.push(V);					// stack ������ �ذ� �غ���

	// �湮���� ��, �湮���ι迭�� 1��
	visited[V] = 1;						
	cout << V << " ";							// �ش� ��� ���

	for (int i = 1; i <= N; i++)
	{
		if (edge[V][i] == 1 && visited[i] != 1)			// ��尡 ����Ǿ� �ְ�, �湮 �� ����� 
		{
		//	stackDFS.pop();
			DFS(i, N, visited, edge);					// DFS(i) --> i �湮�ϰ� �� ������ i�� ����� ��� -> ...
		}
	}
}

void BFS(int V, int N, int* visited, int* edge[]) {
	queueBFS.push(V);					// FIFO ������ ť�� �̿� --> �湮�ϴ� ��� ť�� �ֱ�
	
	while (!queueBFS.empty())			// ť�� �� ������ �ݺ�
	{
		int search = queueBFS.front();		

		// ť�� FRONT�� �湮 ���̶�� ��� �� POP / �湮�ߴٸ� �׳� POP
		if (visited[search] != 1)		
		{
			cout << search << " ";
		}
		queueBFS.pop();			

		// �湮 ���� ��� 1�� 
		visited[search] = 1;

		// ť�� FRONT�� ����Ǿ� �ְ�, �湮 �� ����� QUEUE�� �־���
		for (int i = 1; i <= N; i++)
		{
			if (edge[search][i] == 1 && visited[i] != 1)
			{
				queueBFS.push(i);
			}
		}
	}
}

int main() {
	// ��� ����, ���� ����, ���� ���
	int N, M, V;

	int a, b;

	// �湮 ���θ� �˷��ִ� �迭(0 : �湮 ��/ 1 : �湮 ��)
	int* visited;

	// ���� ���� ���θ� �˷��ִ� 2���� �迭( ���� O : 1/ ���� X: 0)
	int** edge;

	cin >> N >> M >> V;


	visited = new int[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		visited[i] = 0;
	}

	edge = new int* [N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		edge[i] = new int[N + 1];
	}

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		edge[a][b] = 1;
		edge[b][a] = 1;
	}

	DFS(V, N, visited, edge);
	cout << endl;

	for (int i = 0; i < N + 1; i++)
	{
		visited[i] = 0;
	}

	BFS(V, N, visited, edge);
	cout << endl;

}