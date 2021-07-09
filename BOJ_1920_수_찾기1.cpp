#include <iostream>
#include <algorithm>
using namespace std;

int num[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int find;
		cin >> find;
		int left = 0;
		int right = N - 1;
		int mid = (left + right) / 2;
		bool isFind = false;
		while (left < right) {
			mid = (left + right) / 2;	// 이거 계속 안넣어줘서 mid 이상한 값 됨 
			if (num[mid] > find) {
				right = mid - 1;
			}
			else if (num[mid] < find) {
				left = mid + 1;
			}
			else {
				break;
			}
		}
		if (find == num[(left + right)/ 2]) {
			cout << "1\n";
		}
		else cout << "0\n";
	}
	return 0;
}