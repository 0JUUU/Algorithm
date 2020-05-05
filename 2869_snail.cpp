#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	double A, B, V;
	int count = 0;
	cin >> A >> B >> V;
	if (A >= V) count = 1;
	else
	{
		count = ceil((V - A)/ (A - B)) + 1;
	}
	

	cout << count << endl;
	return 0;
}
