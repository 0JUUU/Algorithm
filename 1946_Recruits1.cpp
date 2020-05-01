#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	int T, N, minInterview = 0, count = 0;;
	cin >> T;
	while (T != 0)
	{
		count = 0;
		cin >> N;
		vector<pair<int, int>> recruits;

		for (int i = 0; i < N; i++)
		{
			int a, b;
			cin >> a >> b;
			recruits.push_back(make_pair(a, b));
		}
		sort(recruits.begin(), recruits.end());

		minInterview = recruits[0].second;
		for (auto i : recruits)
		{
			if (minInterview >= i.second)
			{
				count++;
				minInterview = i.second;
			}

		}
		cout << count << endl;
		T--;
	}
	return 0;
}