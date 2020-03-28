#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    queue<int> move;
    for (auto i : moves)
    {
        move.push(i);
    }
    int answer = 0;
    stack<int> basket;
    while (!move.empty())
    {
        int dest = move.front() - 1;
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][dest] != 0)
            {
                if (basket.empty() || board[i][dest] != basket.top())
                {
                    basket.push(board[i][dest]);
                    board[i][dest] = 0;
                }
                else
                {
                    board[i][dest] = 0;
                    answer += 2;
                    basket.pop();
                }
                    
                break;
            }
        }
        move.pop();
    }
    
    return answer;
}

int main()
{
    vector<vector<int>> board = { {0, 0, 0, 0, 0} ,{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
    vector<int> moves = { 1,5,3,5,1,2,1,4 };

    cout << solution(board, moves) << endl;
}