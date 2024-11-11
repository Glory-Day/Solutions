#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<string, int> mp;
    for (int i = 0; i < (int)players.size(); i++)
    {
        mp[players[i]] = i;
    }
    
    for (int i = 0; i < (int)callings.size(); i++)
    {
        int a = mp[callings[i]];
        int b = mp[players[a - 1]];
        swap(players[a], players[b]);
        swap(mp[players[a]], mp[players[b]]);
    }
    
    answer = players;
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> players(n);
    for (int i = 0; i < n; i++)
    {
        cin >> players[i];
    }

    int m;
    cin >> m;

    vector<string> callings(m);
    for (int i = 0; i < m; i++)
    {
        cin >> callings[i];
    }

    vector<string> answer = solution(players, callings);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}