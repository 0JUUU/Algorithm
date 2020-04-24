#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int p[1001] = { 0, };
	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> p[i];
	}

	sort(p, p + N);
	
	int count = N;
	for (int i = 0; i < N; i++)
	{
		sum += count * p[i];
		count--;
	}
	cout << sum << endl;
}