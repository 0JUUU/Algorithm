#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> set;
    vector<int> push;
    int num = 0;
    int count = 0;
    // s를 집합별로 나눔

    int i = s.size() - 1;
    while (1)
    {
        num = 0;
        count = 0;
        while (i != -1 && s[i] != ',')
        {
            if (s[i] != '{' && s[i] != '}')
            {
                num += pow(10, count) * (s[i] - '0');
                count++;
            }
            i--;

        }
        push.push_back(num);
        if (i == -1)break;

        if (s[i] == ',')
        {
            if (s[i - 1] == '}')
            {
                set.push_back(push);
                push.clear();
                i--;
            }
            else
            {
                i--;
            }
        }
       
    }
    set.push_back(push);
    push.clear();

 //   set.pop_back();
    
    for (int i = 1; i <= set.size(); i++)
    {
        for (auto j : set)
        {
            if (i == j.size())
            {
                if (answer.empty())
                {
                    answer.push_back(j[0]);
                    break;
                }
                
                else
                {
                    for (auto a : answer)
                    {
                        for (int b = 0; b < j.size(); b++)
                        {
                            if (a == j[b]) j[b] = 0;
                       }
                    }
                    for (auto b : j)
                    {
                        if (b != 0) {
                            answer.push_back(b);
                            break;
                        }
                       

                    }
                }
            }
        }
    }

    return answer;
}

int main()
{
 //   string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
    string s = "{{111,20},{111}}";

    vector<int> sol= solution(s);
    for (auto i : sol) cout << i << " ";
    cout << endl;
}

/*   while (!p.empty())
   {

       while (p.top() != ',')
       {
           if (p.top() == '}' || p.top() == '{') p.pop();
           num = p.top() - '0';
           p.pop();
           num += count * p.top();
           count += 1;
           p.pop();
       }

   }*/