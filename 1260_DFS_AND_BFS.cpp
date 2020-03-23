#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Graph {

public:
	int vertex;
	int* visited;
	int** edgeDFS;
	int** edgeBFS;
	stack<int> stackDFS;
	queue<int> queueBFS;

	Graph() {

	}
	Graph(int N) {
		vertex = N;
		visited = new int[vertex + 1];
		visited = { 0, };

		edgeDFS = new int* [vertex + 1];
		for (int i = 0; i < vertex + 1; i++) {
			edgeDFS[i] = new int[vertex + 1];
		}

		for (int i = 1; i <= vertex; i++) {
			for (int j = 1; j <= vertex; j++) {
				edgeDFS[i][j] = 0;
			}
		}

		edgeBFS = new int* [vertex + 1];
		for (int i = 0; i < vertex + 1; i++) {
			edgeBFS[i] = new int[vertex + 1];
		}

		for (int i = 1; i <= vertex; i++) {
			for (int j = 1; j <= vertex; j++) {
				edgeBFS[i][j] = 0;
			}
		}
	}

	void DFS(int V) {
		stackDFS.push(V);

		int top;
		int size = 0;
		while (!stackDFS.empty() && size != vertex)
		{
			top = stackDFS.top();
			
			size++;
			for (int i = 1; i <= vertex; i++)
			{
				if (edgeDFS[top][i] == 1)
				{
					stackDFS.pop();
					cout << top << " ";
					stackDFS.push(i);
					edgeDFS[top][i] = 0;
					edgeDFS[i][top] = 0;
					DFS(i);
				}
			}
		}

	}

	void BFS(int V) {
		queueBFS.push(V);
		int front;
		int size = 0;

		while (!queueBFS.empty() && size != vertex)
		{
			front = queueBFS.front();
			size++;
			cout << front << " ";
			queueBFS.pop();

			for (int i = 1; i <= vertex; i++)
			{
				if (edgeBFS[front][i] == 1)
				{
					queueBFS.push(i);
					edgeBFS[front][i] = 0;
					edgeBFS[i][front] = 0;
				}
			}
		}
	}
};

int main() {
	int N, M, V;
	cin >> N >> M >> V;
	Graph graph = Graph(N);
	stack<int> stackDFS;
	queue<int> queueBFS;
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph.edgeDFS[a][b] = 1;
		graph.edgeDFS[b][a] = 1;
		graph.edgeBFS[a][b] = 1;
		graph.edgeBFS[b][a] = 1;
	}
	graph.DFS(V);
	cout << endl;
	graph.BFS(V);
	cout << endl;
}