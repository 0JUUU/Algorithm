#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(pair<int, double> a, pair<int, double> b)
{
    if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, float>> count;
    int fail = 0, clear = 0;

    sort(stages.begin(), stages.end());
    for (int i = 1; i <= N; i++)
    {
        fail = 0;
        double stages_size = stages.size();
        for (int j = 0; j< stages.size();j++)
        {
            if (i == stages[j]) fail = j + 1;
            if (i < stages[j]) break;
        }
        double ratio  = double(fail) / stages_size;
        
        stages.erase(stages.begin(), stages.begin() + fail);

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

    N = 8;
    stages = { 1,2,3,4,5,6,7 };
    answer = solution(N, stages);
    for (auto i : answer) cout << i << endl;
}