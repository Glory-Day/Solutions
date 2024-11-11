#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    
    int a = 0;
    int b = 0;
    for (int i = 0; i < attacks.back()[0] + 1 && 0 < answer; i++, a++, answer += bandage[1])
    {
        if (i == attacks[b][0])
        {
            answer -= (attacks[b][1] + bandage[1]);
            
            a = 0;
            b++;
            
            continue;
        }
        
        if (a == bandage[0])
        {
            answer += bandage[2];
            a = 0;
        }
        
        if (answer > health)
        {
            answer = health;
        }
    }
    
    answer -= bandage[1];
    
    if (answer <= 0)
    {
        answer = -1;
    }
        
    return answer;
}

int main()
{
    vector<int> bandage(3);
    cin >> bandage[0] >> bandage[1] >> bandage[2];

    int health;
    cin >> health;

    int n;
    cin >> n;

    vector<vector<int>> attacks(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> attacks[i][0] >> attacks[i][1];
    }

    int answer = solution(bandage, health, attacks);

    cout << answer;

    return 0;
}