#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int sugar = -1;
	if (N != 4 && N != 7)
	{
		switch (N % 5)
		{
		case 0:
			sugar = N / 5;
			break;
		case 1:
			sugar = (N / 5) + 1;	// N/5 - 1 + 1 * 2
			break;
		case 2:
			sugar = (N / 5) + 2;	// N/5 - 2 + 1 * 4
			break;
		case 3:
			sugar = (N / 5) + 1;	
			break;
		case 4:
			sugar = (N / 5) + 2;	// N/5 - 1 + 1 * 3
			break;
		default:
			break;
		}
	}


	cout << sugar << endl;
}