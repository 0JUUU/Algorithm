#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    vector<long long> full(k);

    for (int i = 0; i < room_number.size(); i++)
    {
        if (full[room_number[i]] == 0)
        {
            answer.push_back(room_number[i]);
            full[room_number[i]] = 1;
        }
        else
        {
            long long number = room_number[i];
            while (full[number] != 0)
            {
                number++;
            }
            answer.push_back(number);
            full[number] = 1;
        }
    }
    return answer;
}

int main()
{
    long long k = 10;
    vector<long long> room_number = { 1,3,4,1,3,1 };

    vector<long long> sol = solution(k, room_number);

    for (auto i : sol)
        cout << i << " ";
    cout << endl;
}