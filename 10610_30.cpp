#include <iostream>
#include <algorithm>
using namespace std;

bool desc(int a, int b) { return a > b; }

int main()
{
	string N;
	int sum = 0, answer = -1;
	cin >> N;

	if (N.find('0') > N.length()) cout << answer << endl;
	else
	{
		for (int i = 0; i < N.size(); i++)
		{
			sum += N[i] - '0';
		}
		if (sum % 3 != 0) cout << answer << endl;
		else
		{
			sort(N.begin(), N.end(), desc);
			cout << N << endl;
		}
	}
}