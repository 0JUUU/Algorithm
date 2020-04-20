#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int Solution(string p, string s)
{
	int answer = 0;
	int length = p.length();
	for (int i = 0; i < length; i++)
	{
		if (p[i] > s[i])
		{
			if (p[i] - s[i] > s[i] + 10 - p[i]) answer += s[i] + 10 - p[i];
			else answer += p[i] - s[i];
		}
		else if (p[i] < s[i])
		{
			if (s[i] - p[i] > p[i] + 10 - s[i]) answer += p[i] + 10 - s[i];
			else answer += s[i] - p[i];
		}
		else answer += 0;
	}
	return answer;
}

int main()
{
	string p, s;
	p = "82195";
	s = "64723";
	cout << Solution(p, s) << endl;
	p = "00000000000000000000";
	s = "91919191919191919191";
	cout << Solution(p, s) << endl;

	return 0;
}
