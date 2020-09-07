#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool compare(string a, string b)
{
    if(a.c_str > 9)
}
vector<string> solution(vector<string> files) {
    vector<string> answer;

    // 모두 대문자로 변경
    for (int i = 0; i < files.size(); i++)
    {
        for (int j = 0; j < files[i].size(); i++)
        {
            files[i][j] = toupper(files[i][j]);
        }
    }

    return answer;
}

int main()
{
    vector<string> files = {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};

    vector<string> answer = solution(files);

    for (auto i : answer)
        cout << i << endl;

    files = {"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"};
    answer = solution(files);
    for (auto i : answer)
        cout << i << endl;
}