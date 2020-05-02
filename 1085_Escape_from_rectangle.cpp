#include <iostream>
using namespace std;

int main()
{
	int x, y, w, h, minZero = 1001, minWH = 1001;
	cin >> x >> y >> w >> h;

	if (x > y) minZero = y;
	else minZero = x;

	if (w - x > h - y) minWH = h - y;
	else minWH = w - x;

	if (minWH > minZero) cout << minZero << endl;
	else cout << minWH << endl;

	return 0;

}