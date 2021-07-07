#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> A;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		A.push_back(num);
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += A.at(j);
			if (sum == M) cnt++;
			else if (sum > M) break;
		}
	}
	cout << cnt << "\n";
	return 0;
}