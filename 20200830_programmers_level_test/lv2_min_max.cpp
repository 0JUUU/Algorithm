#include <string>
#include <vector>
#include <iostream>
#include <sstream>  //stringstream
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    string token = "";
    vector<int> arr;
    
    // ���ڿ��� ��ū���� �߶� int������ ��ȯ�� �� arr ���Ϳ� ����
    for (stringstream sts(s); (sts >> token);)
    {
        arr.push_back(stoi(token));
    }

    /*  
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
    */

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