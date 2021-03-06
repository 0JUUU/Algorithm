#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

bool compare_play(pair<string, string> a, pair<string, string> b) {
    if (a.second.size() == b.second.size())
    {

        return a.first.size() > b.first.size();
    }
    return a.second.size() > b.second.size();
}

string solution(string m, vector<string> musicinfos) {
    string answer = "'(None)";

    vector<pair<string, string>> music;
    int hour = 0, minute = 0, time = 0;
    for (int i = 0; i < musicinfos.size(); i++)
    {
        if (i % 4 == 0)
        {
            musicinfos[i].replace(2, 1, " ");
            stringstream sts(musicinfos[i]);
            while (!sts.eof())
            {
                sts >> hour;
                sts >> minute;
                time = -hour * 60 - minute;
            }

        }
        else if (i % 4 == 1)
        {
            musicinfos[i].replace(2, 1, " ");
            stringstream sts(musicinfos[i]);
            while (!sts.eof())
            {
                sts >> hour;
                sts >> minute;
                time += (hour * 60 + minute);
            }
        }
        else if (i % 4 == 3)
        {
            string play = "";
            for (int j = 0; j < time; j++)
            {
                if (j < musicinfos[i].size())
                {
                    if (musicinfos[i][j] == '#')
                    {
                        play += musicinfos[i][j];
                        time += 1;
                    }
                    else
                    {
                        play += musicinfos[i][j];
                    }
                }
                else
                {
                    if (musicinfos[i][j % musicinfos[i].size()] == '#')
                    {
                        play += musicinfos[i][j % musicinfos[i].size()];
                        time += 1;
                    }
                    else
                    {
                        play += musicinfos[i][j % musicinfos[i].size()];
                    }
                }
            }
            time = 0;
            if(play.find(m) != string::npos && play[play.find(m) + m.size()] != '#')  music.push_back(make_pair(musicinfos[i - 1], play));
           
        }
            
    }

    vector<pair<string, string>> sort_play = music;
    sort(sort_play.begin(), sort_play.end(), compare_play);
   
    if(!sort_play.empty()) answer = sort_play.front().first;
    
    return answer;
}

int main()
{
    // HELLO
    string m = "ABCDEFG";
    vector<string> musicinfos = {"12:00","12:14","HELLO","CDEFGAB", "13:00","13:05","WORLD","ABCDEF"};
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