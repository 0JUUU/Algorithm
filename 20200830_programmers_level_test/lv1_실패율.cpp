#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(pair<int, double> a, pair<int, double> b)
{
    return a.second > b.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, float>> count;
    int fail = 0, clear = 0;
    for (int i = 1; i <= N; i++)
    {
        fail = 0, clear = 0;
        for (auto j : stages)
        {
            if (i == j)
            {
                fail += 1;
                clear += 1;
            }
            else if (i < j)
                clear += 1;
            else continue;
        }
        double ratio = double(fail) / double(clear);
        count.push_back(make_pair(i, ratio));
    }

    sort(count.begin(), count.end(), compare);
    for (auto i : count)
        answer.push_back(i.first);
    return answer;
}

int main()
{
    int N = 5;
    vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };

    vector<int> answer = solution(N, stages);
    for (auto i : answer) cout << i << endl;

    N = 4;
    stages = { 4,4,4,4,4 };
    answer = solution(N, stages);
    for (auto i : answer) cout << i << endl;
}