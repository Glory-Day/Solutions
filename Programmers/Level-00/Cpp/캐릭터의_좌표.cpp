#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer(2, 0);
    
    unordered_map<string, pair<int, int>> ump = {
        { "left",{ -1,0 } },{ "right",{ 1,0 } },{ "down",{ 0,-1 } },{ "up",{ 0,1 } }
    };
    
    for (int i = 0; i < (int)keyinput.size(); i++)
    {
        int n = board[0] / 2;
        int m = board[1] / 2;
        int x = answer[0] + ump[keyinput[i]].first;
        int y = answer[1] + ump[keyinput[i]].second;
        if (-n <= x && x <= n && -m <= y && y <= m)
        {
            answer[0] = x;
            answer[1] = y;
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> keyinput(n);
    for (int i = 0; i < n; i++)
    {
        cin >> keyinput[i];
    }

    vector<int> board(2);
    cin >> board[0] >> board[1];

    vector<int> answer = solution(keyinput, board);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}