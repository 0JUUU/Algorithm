#include <iostream>
using namespace std;

struct Recruits
{
	int doc, interview;
};
int main()
{
	int T, N, maxDoc = 0, maxInterview = 0, count = 0;;
	cin >> T;
	while (T != 0)
	{
		count = 0;
		cin >> N;
		Recruits* recruits = new Recruits[N];
		for (int i = 0; i < N; i++)
		{
			cin >> recruits[i].doc >> recruits[i].interview;
			if (recruits[i].doc == 1) maxInterview = recruits[i].interview;
			if (recruits[i].interview == 1) maxDoc = recruits[i].doc;
		}
		for (int i = 0; i < N; i++)
		{
			if (recruits[i].doc <= maxDoc && recruits[i].interview <= maxInterview) count++;
		}
		cout << count << endl;
		T--;
	}
	return 0;
}