#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one, two, three;
    vector<pair<int, int>> math;
    int a = 1, b = 1, c = 1, count = 0;
    // 첫번쨰 수포자
    for (int i = 0; i < answers.size(); i++)
    {
        if (a == 6) a = 1;
        one.push_back(a);
        a++;
       
    }

    // 두번쨰 수포자
    for (int i = 0; i < answers.size(); i++)
    {
        if (i % 2 == 0) two.push_back(2);
        else
        {
            if (b == 5)
            {
                two.push_back(b);
                b = 1;
            }
            else if (b == 2)
            {
                b++; two.push_back(b);
                b++;
            }
            else
            {
                two.push_back(b);
                b++;
            }
            
        }
    }

    // 세번째 수포자
    for (int i = 0; i < answers.size(); i++)
    {
        if (count == 2)
        {
            count = 0;
            c++;
            if (c == 6) c = 1;
        }
        if (c == 3) c++;
        if (i % 10 == 0 || i % 10 == 1) three.push_back(3);
        else
        {
            count++;
            three.push_back(c);
        }
    }

    int same[3] = { 0, 0,0 };

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == one[i]) same[0]++;
        if (answers[i] == two[i]) same[1]++;
        if (answers[i] == three[i]) same[2]++;
    }
    int temp = 0;
    for (int i = 0; i < 3; i++)
    {
        if (temp < same[i]) temp = same[i];
    }
    
    for (int i = 0; i < 3; i++)
    {
        if (temp == same[i]) answer.push_back(i+1);
    }
    
    
    return answer;
}

int main()
{
    vector<int> answers = { 1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4 };
    vector<int> answer = solution(answers);

    for (auto i : answer)
        cout << i << endl;

    cout << endl;
    answers = { 1,3,2,4,2 };
    answer = solution(answers);

    for (auto i : answer)
        cout << i << endl;
}