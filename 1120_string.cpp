#include <iostream>
using namespace std;

int main()
{
	string A, B, front, back;
	int count = 0, minFront, minBack;

	cin >> A >> B;

	while (A.length() != B.length())
	{
		front = A, back = A;
		minFront = 0, minBack = 0;
		front.insert(0,1,B[0]);
		back.insert(A.length(), 1, B[A.length()]);

		for (int i = 0; i < front.length(); i++)
		{
			if (front[i] != B[i]) minFront++;
			if (back[i] != B[i]) minBack++;
	
		}
		A = minFront >= minBack ? back : front;
	}

	for (int i = 0; i < A.length(); i++)
	{
		if (A[i] != B[i]) count++;
	}
	cout << count << endl;
	return 0;
}