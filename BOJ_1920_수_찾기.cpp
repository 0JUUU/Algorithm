#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �ð� �ʰ� --> �̺� Ž������ ����
int main() {
	int N, M;
	cin >> N;
	string s;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		s += to_string(num) + " ";
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		if (s.find(to_string(num)) != -1) {
			cout << "1\n";
		}
		else cout << "0\n";
	}

	return 0;
}
