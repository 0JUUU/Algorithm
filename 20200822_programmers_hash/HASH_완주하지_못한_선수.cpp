#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    vector<string>::iterator it;
    for (int i = 0; i < completion.size(); i++)
    {
        it = find(participant.begin(), participant.end(), completion[i]);
        if (it != participant.end())
        {
            *it = "";
        }
    }
    for (int i = 0; i < participant.size(); i++)
    {
        if (participant[i] != "")
        {
            answer = participant[i];
            break;
        }
    }
    return answer;
}

int main()
{
    vector<string> participant = { "marina", "josipa", "nikola", "vinko", "filipa" };
    vector<string> completion = { "marina", "josipa", "nikola", "filipa" };

    cout << solution(participant, completion) << endl;

    participant = { "mislav", "stanko", "mislav", "ana" };
    completion = { "mislav", "stanko", "ana" };

    cout << solution(participant, completion) << endl;
}