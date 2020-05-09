#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    bool hand_right;
    vector<string> right_dis = { "#" };
    vector<string> left_dis = { "*" };
    int dir[4] = { -3,1,3,-1 };
    if (hand == "right") hand_right = 1;
    else hand_right = 0;
    vector<int>::iterator i = numbers.begin();
    while (i != numbers.end())
    {
        if (*i == 1 || *i == 4 || *i == 7)
        {
            int a = *i;
            answer.push_back('L');
            left_dis.push_back(to_string(a));
        }
        else if (*i == 3 || *i == 6 || *i == 9)
        {
            int a = *i;
            answer.push_back('R');
            right_dis.push_back(to_string(a));
        }

        else
        {
           
                if (hand_right == 1)
                {
                    int a = 0;
                    for (int j = 0; j < 4; j++)
                    {
                        if (right_dis[right_dis.size() - 1] == to_string(*i + dir[j]))
                        {
                            a = j;
                            break;
                        }
                    }
                   
                    if (right_dis[right_dis.size() - 1] == to_string(*i + dir[a]))
                    {
                        int b = *i;
                        answer.push_back('R');
                        right_dis.push_back(to_string(a));
                    }

                    else
                    {
                        int b = *i;
                        answer.push_back('L');
                        left_dis.push_back(to_string(a));
                    }
                }
                else
                {
                    int a = 0;
                    for (int j = 0; j < 4; j++)
                    {
                        if (left_dis[left_dis.size() - 1] == to_string(*i + dir[j]))
                        {
                            a = j;
                        }
                    }

                    if (left_dis[left_dis.size() - 1] == to_string(*i + dir[a]))
                    {
                        int b = *i;
                        answer.push_back('L');
                        left_dis.push_back(to_string(b));
                    }
                    else
                    {
                        int b = *i;
                        answer.push_back('R');
                        right_dis.push_back(to_string(b));
                    }
                }
               
        }
        i++;
    }
    return answer;
}

int main()
{
    vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string hand = "right";

    cout << solution(numbers, hand) << endl;

    numbers = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };
    hand = "left";

    cout << solution(numbers, hand) << endl;

    numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    hand = "right";

    cout << solution(numbers, hand) << endl;
}