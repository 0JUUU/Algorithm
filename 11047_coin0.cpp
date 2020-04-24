#include <iostream>
using namespace std;

int main()
{
	int N, K, A[11], count = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = N - 1; i >= 0; i--)
	{
		if (A[i] > K) continue;
		else if (A[i] == K) 
		{
			count += 1;
			break;
		}
		else
		{
			int num = K / A[i];
			K -= num * A[i];
			count += num;
		}
	}
	cout<<count<<endl;
}