#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    bool able = true;
    int count = 0;
    while (able)
    {
        for (int i = 0; i < stones.size(); i++)
        {
            if (stones[i] == 0)
            {
                count += 1;
            }
            else
            {
                stones[i] -= 1;
                count = 0;
            }
            if (count == k)
            {
                able = false;
                break;
            }
            if (i == stones.size() - 1) answer++;
        }
    }

    return answer;
}

int main()
{
    //vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
    //int k = 3;

    vector<int> stones = {2,1,4,5,10,3,2,8};
    int k = 4;

    cout << solution(stones, k) << endl;
}