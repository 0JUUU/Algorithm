#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

bool compare2(pair<int, string> a, pair<int, string> b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> total;
    multimap<int, string, greater<int>> info;

    for (int i = 0; i < genres.size(); i++)
    {
        if (total[genres[i]] == 0) total[genres[i]] = plays[i];
        else total[genres[i]] += plays[i];

        info.insert(pair<int, string>(plays[i], genres[i]));
    }
    vector<pair<string, int>> total_sort;
    for (auto it = total.begin(); it != total.end(); it++) total_sort.push_back(*it);

    sort(total_sort.begin(), total_sort.end(), compare);

 /*   for (auto i : total_sort) cout << i.first << "  " << i.second << endl;

    for (auto i : info) cout << i.first << "  " << i.second << endl;*/

    vector<pair<int, string>> info_sort;
    for (auto it = info.begin(); it != info.end(); it++) info_sort.push_back(*it);

    sort(info_sort.begin(), info_sort.end(), compare2);
 //   for (auto i : info_sort) cout << i.first << "  " << i.second << endl;

    int count = 0;
    for (int i = 0; i < total_sort.size(); i++)
    {
        count = 0;

        for (int j = 0; j < info_sort.size() || count == 2; j++)
        {
            if (count == 2) break;
            if (total_sort[i].first == info_sort[j].second)
            {
                vector<int>:: iterator it;
                if (find(plays.begin(), plays.end(), info_sort[j].first) != plays.end())
                {
                    it = find(plays.begin(), plays.end(), info_sort[j].first);
                    *it = 0;
 //                   for (auto b : plays) cout << b << endl;
                }
                    
                int index = distance(plays.begin(), it);
                answer.push_back(index);
                count++;
            }
            
        }

    }

    return answer;
}

int main()
{
    /*
    vector<string> genres = { "a", "a", "b", "b", "c", "c", "d", "d" };
    vector<int> plays = { 1, 1, 1, 1, 1, 1, 1, 1 };
    */

    /*
    vector<string> genres = { "a", "a", "b", "c", "a", "a" };
    vector<int> plays = { 1, 2, 2, 2, 2, 2 };
    */

    //vector<string> genres = { "a", "a", "d", "d", "c", "b" };
    //vector<int> plays = { 5, 5, 3, 3, 5, 6 };

    // บาล๋
    vector<string> genres = { "a", "a", "d", "d", "c", "b" };
    vector<int> plays = { 5, 5, 3, 3, 500, 6 };
  
    vector<int> answer = solution(genres, plays);
    for (auto i : answer) cout << i << endl;
}