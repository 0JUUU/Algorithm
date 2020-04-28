#include <iostream>
using namespace std;

int main()
{
	int N, M, K, team = 0;
	cin >> N >> M >> K;
	if (N == 0 || M == 0) cout << team << endl;
	else
	{
		while (N > M * 2 && K != 0)
		{
			N -= 1;
			K -= 1;
		}
		while (N / 2 < M && K != 0)
		{
			M -= 1;
			K -= 1;
		}
		if (K == 0)
		{
			if (N >= M * 2) team = M;
			else team = N / 2;
		}
		else
		{
			int count = 1;
			while (K != 0 && N != 0 && M != 0)
			{
				switch (count % 3)
				{
				case 0:
					N--;
					K--;
					count++;
					break;
				case 1:
					N--;
					K--;
					count++;
					break;
				case 2:
					M--;
					K--;
					count++;
					break;
				default:
					break;
				}
			}
			if (K == 0)
			{
				if (N >= M * 2) team = M;
				else team = N / 2;
			}
			if (N == 0 || M == 0) team = 0;
		}

		cout << team << endl;
	}
}