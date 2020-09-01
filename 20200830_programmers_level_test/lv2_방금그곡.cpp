#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    string time;
    map<string, string> music;
    int hour = 0, minute = 0;
    for (int i = 0; i < musicinfos.size(); i++)
    {
        if (i % 4 == 0)
        {
            for (stringstream sts(musicinfos[i]); (sts >> time);)
            {
                cout << time << endl;
                cout << stoi(time) << endl;
                time.erase(1);
                cout << time << endl;
            }
            
        }
    }
   
    return answer;
}

int main()
{
    // HELLO
    string m = "ABCDEFG";
    vector<string> musicinfos = {"12:01","12:14","HELLO","CDEFGAB", "13:00","13:05","WORLD","ABCDEF"};
    cout << solution(m, musicinfos) << endl;

    // FOO
    m = "CC#BCC#BCC#BCC#B";
    musicinfos = { "03:00", "03:30", "FOO", "CC#B", "04:00", "04:08", "BAR", "CC#BCC#BCC#B" };
    cout << solution(m, musicinfos) << endl;

    // WORLD
    m = "ABC";
    musicinfos = { "12:00", "12:14", "HELLO", "C#DEFGAB", "13:00", "13:05", "WORLD", "ABCDEF" };
    cout << solution(m, musicinfos) << endl;
}