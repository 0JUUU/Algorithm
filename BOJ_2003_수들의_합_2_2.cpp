#include <iostream>
#include <vector>
using namespace std;

int A[10001];

// 투포인터
int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int start = 0;
	int end = 0;
	int sum = 0;
	int ans = 0;
	while (end <= N) {
		if (sum >= M) {
			sum -= A[start++];
		}
		else {
			sum += A[end++];
		}

		if (sum == M) {
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}