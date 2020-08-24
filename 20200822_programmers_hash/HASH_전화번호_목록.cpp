#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = i + 1; j < phone_book.size(); j++)
        {
            if (phone_book[j].find(phone_book[i]) == 0)
            {
                answer = false;
                break;
            }
            if (!answer) break;
        }
    }
    return answer;
}

int main()
{
    vector<string> list = { "119", "97674223", "5521194421" };
    cout << solution(list) << endl;

    list = { "123" ,"456", "789" };
    cout << solution(list) << endl;

    list = { "12", "123", "1235", "567","88" };
    cout << solution(list) << endl;
}