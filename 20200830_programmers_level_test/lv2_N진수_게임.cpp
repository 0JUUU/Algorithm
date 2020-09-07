#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string line = "";
    int count = t * m;
    int number = 0, remain;
    for (int a = 0; a < count; a++)
    {
        int copy = number;
        int sum = 0;
        char out[10];
        int i = 0;
        while (copy > 0) {
            if (n > 9) {
                switch (copy) {
                case 10: line += 'A'; break;
                case 11: line += 'B'; break;
                case 12: line += 'C'; break;
                case 13: line += 'D'; break;
                case 14: line += 'E'; break;
                case 15: line += 'F'; break;
                default:  line += copy % n + 48;
                }
          
                copy = copy / n;
            }
            else {
                line += copy % n + 48;
                copy = copy / n;
             
            }
        }
        cout << line << endl;
        number++;

    }


    // 자리수 구하기
    if (p != m) remain = p;
    else remain = 0;


    return answer;
}

int main()
{
    int n, t, m, p;
    n = 2, t = 4, m = 2, p = 1;
    cout << solution(n, t, m, p) << endl;

    n = 16, t = 16, m = 2, p = 1;
    cout << solution(n, t, m, p) << endl;

    n = 16, t = 16, m = 2, p = 2;
    cout << solution(n, t, m, p) << endl;
}