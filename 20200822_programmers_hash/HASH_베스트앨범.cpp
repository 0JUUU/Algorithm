#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<string, int>> albums;
    unordered_map<string, vector<int>> play;
    unordered_map<string, int> total_plays;

    for (int i = 0; i < genres.size(); i++)
    {
        if (total_plays[genres[i]] <= 0) total_plays[genres[i]] = plays[i];
        else total_plays[genres[i]] += plays[i];

        play[genres[i]].push_back(plays[i]);
        albums.push_back(pair<string, int>(genres[i], plays[i]));
        cout << genres[i] << "  " << plays[i] << endl;
    }
    for (auto i : play)
    {
        sort(i.second.begin(), i.second.end(), greater<int>());
    }

    for (auto i : play)
    {
        cout << i.second.begin() << " ";
    }
    cout << endl;

    vector<pair<string, int>> tmp;
    for (auto it = total_plays.begin(); it != total_plays.end(); it++) tmp.push_back(*it);

    sort(tmp.begin(), tmp.end(), compare);

    for (auto i : tmp)
    {
        cout << i.first << "  " << i.second << endl;
    }

    int count = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        count = 0;
        for (int j = 0; j < albums[tmp[i].first].size(); i++)
        {
            answer.push_back(albums[tmp[i].first][j]);
            count++;
            if (count == 2) break;
        }

    }

    return answer;
}

int main()
{
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};

    vector<int> answer = solution(genres, plays);
    for (auto i : answer) cout << i << endl;
}