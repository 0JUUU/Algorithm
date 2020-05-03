#include <iostream>
using namespace std;

int main()
{
	long A, B, C, BREAK = -1;
	cin >> A >> B >> C;
	int i = 1;
	if (C > B)
	{
		BREAK = A / (C-B) + 1;
	}

	cout << BREAK << endl;
	return 0;
}