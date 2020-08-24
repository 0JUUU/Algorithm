#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> num;
    for (int i = 0; i < clothes.size(); i++)
    {
        if (num[clothes[i][1]] == 0) num[clothes[i][1]] = 1;
        else num[clothes[i][1]]++;
    }

    for (auto i : num)
    {
        answer *= (i.second + 1);
    }
    answer -= 1;
    return answer;
}

int main()
{
    vector<vector<string>> clothes;
    clothes = { {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} };
    cout << solution(clothes) << endl;

    clothes = { {"crow_mask", "face"}, {"blue_sunglasses", "face"},{"smoky_makeup","face"} };
    cout << solution(clothes) << endl;
}