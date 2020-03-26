#include <iostream>
using namespace std;

int main()
{
	int N, number;
	cin >> N;

	int count = N;
	for (int i = 0; i < N; i++)
	{
		cin >> number;
		if (number == 1) count--;
		else if(number == 2) {}
		else
		{
			for (int j = 2; j < number; j++)
			{
				if (number % j == 0)
				{
					count--;
					break;
				}
			}
		}
	}
	cout << count << endl;
}