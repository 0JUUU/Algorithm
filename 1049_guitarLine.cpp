#include <iostream>
using namespace std;

int main()
{
	int N, M, pack[50], one[50], packmin = 1001, onemin = 1001, money;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> pack[i] >> one[i];
		if (packmin > pack[i]) packmin = pack[i];
		if (onemin > one[i]) onemin = one[i];
	}
	if (N <= 6)
	{
		if (packmin > onemin* N) money = onemin * N;
		else money = packmin;
	}
	else
	{
		if (packmin > onemin * 6)
		{
			money = onemin * N;
		}
		else
		{
			if (N % 6 == 0)
			{
				money = packmin * (N / 6);
				 
			}
			else
			{
				if (packmin * (N / 6 + 1) > packmin * (N/6) + onemin * (N - 6*(N/6))) money = packmin * (N / 6) + onemin * (N - 6 * (N / 6));
				else money = packmin * (N / 6 + 1);
			}
		}
	}

	cout << money << endl;
	return 0;
}