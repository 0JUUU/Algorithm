#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> arr;
    for (int i = 0; i < s.size(); i++)
    {
        string str = "";
        if (s[i] == ' ') continue;
        else if (s[i] == '-')
        {
            str = s[i];
            str += s[i + 1];
            i += 1;
        }
        else str = s[i];

        int a = atoi(str.c_str());
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    answer = to_string(arr.front()) + ' ' + to_string(arr.back());

    return answer;
}

int main()
{
    string s = "-1 2 3 4";
    cout << solution(s) << endl;;

    s = "-1 -2 -3 -4";
    cout << solution(s) << endl;
    s = "-1 -1 -2 2";
    cout << solution(s) << endl;
}