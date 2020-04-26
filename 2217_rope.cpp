#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, max = 0;
	cin >> N;
	int* rope = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> rope[i];
	}
	sort(rope, rope + N);

	int count = N;
	for (int i = 0; i < N; i++)
	{
		if (max < rope[i] * count) max = rope[i] * count;
		count--;
	}
	
	cout << max << endl;
}