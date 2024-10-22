#include <string>
#include <vector>
#include <map>

using namespace std;

const bool check(const char a, const char b, const char c)
{
    return (a == b && a == c) ? true : false;
}

int solution(vector<string> board) {
    int answer = 0;
    
    int a = 0, b = 0;
    for (int i = 0; i < (int)board.size(); i++)
    {
        for (int j = 0; j < (int)board[0].size(); j++)
        {
            if (board[i][j] == 'O')
            {
                a++;
            }
            else if (board[i][j] == 'X')
            {
                b++;
            }
        }
    }

    if (a - b < 0 || a - b > 1)
    {
        return answer;
    }
    
    map<char, int> mp;
    mp['O'] = 0;
    mp['X'] = 0;
    mp['.'] = -30;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 1 && check(board[i][j], board[i][j-1], board[i][j+1]))
            {
                mp[board[i][j]]++;
            }
                
            if (i == 1 && check(board[i][j], board[i-1][j], board[i+1][j]))
            {
                mp[board[i][j]]++;
            }
            
            if (i == 1 && j == 1 && (check(board[i-1][j-1], board[i][j], board[i+1][j+1]) ||
                                     check(board[i-1][j+1], board[i][j], board[i+1][j-1])))
            {
                mp[board[i][j]]++ ;
            }
            
            if (mp[board[i][j]] > 2)
            {
                return answer;
            }
        }
    }
    
    if (mp['O'] > 0 && mp['X'] > 0)
    {
        return answer;
    }
    
    if (mp['O'] > 0 && a == b)
    {
        return answer;
    }
    
    if (mp['X'] > 0 && a > b)
    {
        return answer;
    }

    answer = 1;

    return answer;
}