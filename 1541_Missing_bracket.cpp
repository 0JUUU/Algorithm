#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
using namespace std;

// 입력된 식의 값을 최소로 만들기 위해서 
// '+' 기호가 나오면 '-'가 나오기 전까지 모든 수를 저장한 후, '-' 기호가 나오면 모아진 수들을 빼준다.
// '-' 기호가 끝날 때까지 등장하지 않는다면 저장된 수들을 모두 더해준다.
int main()
{
	// sum : 최솟값, num : 입력한 하나의 수 값 저장, count : 자리수
	int sum = 0, num = 0, count = 0;		
	string s;			// 입력받을 문자열
	// 입력받은 문자열 중 하나의 숫자를 뽑아내기 위해 사용하는 벡터
	vector<char> transNum;
	// '-'가 나오기 전까지 입력된 숫자들의 모음
	vector<string> storage;
	cin >> s;

	// 입력받은 문자열을 뒤에서부터 탐색
	for (int i = s.length() - 1; i >= 0; i--)
	{
		// 문자열에서 하나의 숫자를 골라내기 위한 작업
		// '+'나 '-' 기호가 나온다면 하나의 숫자가 끝난 것임
		while (s[i] != '+' && s[i] != '-' )
		{
			// 문자열로 입력된 숫자이므로 숫자를 만들어내기 위해 사용되는 벡터 trannNum에 넣어준다.
			// 만약 "50-40"이 입력된다면 transNum에 '0', '4'의 순서로 들어간다.
			transNum.push_back(s[i]);
			i--;
			// i가 -1이라면 문자열의 범위를 벗어나므로 -1일 경우를 예외로 둔다. 
			if (i == -1)
			{
				break;
			}
		}

		// 하나의 숫자를 나타내는 num과 자릿수를 나타내는 count를 초기화시켜준다.
		num = 0;
		count = 0;

		// 자리수와 transNum에 저장된 문자들을 바탕으로 int형 자료형을 만들어낸다. 
		for (int j = 0; j < transNum.size(); j++)
		{
			num += (transNum[j] - '0') * pow(10, count);
			count++;
		}

		// 다른 숫자가 들어올 것을 대비하여 지워준다.
		transNum.clear();

		// 입력된 문자열의 처음은 무조건 숫자이므로 구분하기 위해 i가 -1일 때와 아닐 때를 구분
		if (i != -1)
		{
			// 식의 값을 최소로 만들기위해
			if (s[i] == '-')
			{
				// 현재 저장된 수도 모아진 수들의 저장공간에 넣어준다
				storage.push_back(to_string(num));

				// 모아진 수들을 모두 빼준다
				for (auto a : storage)
				{
					int tmp = stoi(a);
					sum -= tmp;
				}
				// 다음 값들을 위해 정리
				storage.clear();
			}

			// + 기호가 나온다면 -기호 나오기 전까지 수를 저장
			else
			{
				storage.push_back(to_string(num));
			}

		}

		// i가 -1이라면 모든 기호와 관련된 식들은 정리가 끝났다는 의미
		else
		{
			// 50+55-60+49 처럼 - 기호가 나오기 전에 +가 입력되어 정리되지 않은 숫자들이 있기 때문에 확인해줌
			// 비어있지않다면 storage에 저장된 값은 모두 더해야한다는 의미이므로 더해준다. 
			if (!storage.empty())
			{
				for (auto a : storage)
				{
					int tmp = stoi(a);
					sum += tmp;
				}
			}
			// 가장 처음 입력된 숫자를 더해준다.
			sum += num;
		}

	}
	cout << sum << endl;
	return 0;
}