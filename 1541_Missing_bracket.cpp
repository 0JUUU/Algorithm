#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	int sum = 0, num = 0, count = 0;
	string s;
	vector<char> transNum;
	vector<string> storage;
	cin >> s;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		while (s[i] != '+' && s[i] != '-' )
		{
			transNum.push_back(s[i]);
			i--;
			if (i == -1)
			{
				break;
			}
		}
		num = 0;
		count = 0;
		for (int j = 0; j < transNum.size(); j++)
		{
			num += (transNum[j] - '0') * pow(10, count);
			count++;
		}
		transNum.clear();
		if (i != -1)
		{
			if (s[i] == '-')
			{
				storage.push_back(to_string(num));
				for (auto a : storage)
				{
					int tmp = stoi(a);
					sum -= tmp;
				}
				storage.clear();
			}
			else
			{
				storage.push_back(to_string(num));
			}

		}
		else
		{
			if (!storage.empty())
			{
				for (auto a : storage)
				{
					int tmp = stoi(a);
					sum += tmp;
				}
			}
			sum += num;
		}

	}
	cout << sum << endl;
	return 0;
}