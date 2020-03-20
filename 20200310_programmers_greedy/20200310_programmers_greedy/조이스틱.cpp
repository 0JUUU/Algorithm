#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    int nameLen = name.length();
    string A(nameLen, 'A');
    cout << A << endl;
    return answer;
}

int main()
{
    cout << solution("JEROEN") << endl;
    cout << solution("JAN") << endl;
}