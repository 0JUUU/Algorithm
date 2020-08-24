#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> hash;
    for (auto i : participant)
    {
        if(hash[i] == 0) hash[i] = 1;
        else hash[i]++;
    }

    for (auto i : completion)
    {
        if (hash[i] != 0)
        {
            hash[i] -= 1;
        }
        
    }
    
    for (auto i : participant)
    {
        if (hash[i] == 1)
            answer = i;
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