#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    return answer;
}

int main()
{
    vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
    vector<string> banned_id = { "fr*d*", "abc1**" };

    cout << solution(user_id, banned_id) << endl;
}