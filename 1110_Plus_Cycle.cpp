#include <iostream>
using namespace std;

int main()
{
	int N;
	int count = 1;
	cin >> N;

	int original = N;
	int newN = (original%10) * 10 + (original / 10 + original % 10) % 10;
	while (original != newN)
	{
		newN = (newN % 10) * 10 + (newN / 10 + newN % 10) % 10;

		count++;
	}

	cout << count << endl;
}