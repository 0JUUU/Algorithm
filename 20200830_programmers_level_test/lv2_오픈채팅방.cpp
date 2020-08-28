#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    string uid;
    string nickname; 
    string sentence;
    map<string, string> pair_name;

    for (int i = 0; i < record.size(); i++)
    {
        if (record[i].at(0) != 'L')
        {
            uid = "";
            nickname = "";
            uid = record[i].substr(record[i].find(' ') + 1);
            nickname = uid.substr(uid.find(' ') + 1);
            uid.erase(uid.find(' '));

            if (pair_name[uid] == "")  pair_name[uid] = nickname;
            else
            {
                pair_name[uid].erase();
                pair_name[uid] = nickname;
            }
        }
    }

    for (int i = 0; i < record.size(); i++)
    {
        sentence = "";
        switch (record[i].at(0))
        {
        case 'E':
            uid = "";
            uid = record[i].substr(record[i].find(' ') + 1);
            uid.erase(uid.find(' '));
            sentence = pair_name[uid] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
            answer.push_back(sentence);
            break;
        case 'L':
            uid = "";
            uid = record[i].substr(record[i].find(' ') + 1);
            sentence = pair_name[uid] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
            answer.push_back(sentence);
            break;
        default:
            break;
        }
    }
    return answer;
}

int main()
{
    vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };

    vector<string> answer = solution(record);

    for (auto i : answer)
        cout << i << endl;
}