#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    int num[3] = {4,1,2};
    string answer = "";
    while(n > 0) {
        int remain = n % 3;
        answer += to_string(num[remain]);
        if(n % 3 == 0) n = n/3-1;
        else n /=3;
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}