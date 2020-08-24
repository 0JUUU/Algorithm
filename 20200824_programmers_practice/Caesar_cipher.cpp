#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.size(); i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z')
        {
            if (s[i] + n <= 'Z') s[i] += n;
            else
                s[i] = 'A' + s[i] + n - 'Z' - 1;
        }
        else if ('a' <= s[i] && s[i] <= 'z')
        {
            if (s[i] + n <= 'z') s[i] += n;
            else
                s[i] = 'a' + s[i] + n - 'z' - 1;
        }
        else if (s[i] == ' ') continue;
        else {}
    }
    answer = s;
    return answer;
}

int main()
{
    string s;
    int n = 1;
    s = "AB";
    cout << solution(s, n) << endl;

    s = "Z";
    n = 25;
    cout << solution(s, n) << endl;

    s = "a B z";
    n = 4;
    cout << solution(s, n) << endl;
}