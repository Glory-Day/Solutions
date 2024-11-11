#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int a = 0;
    int b = 0;
    for (int i = 0; i < (int)goal.size(); i++)
    {
        if (a < (int)cards1.size() && cards1[a] == goal[i])
        {
            a++;
            
            continue;
        }
        
        if (b < (int)cards2.size() && cards2[b] == goal[i])
        {
            b++;
        }
    }
    
    answer = (a + b == (int)goal.size() ? "Yes" : "No");
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> card1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> card1[i];
    }

    int m;
    cin >> m;

    vector<string> card2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> card2[i];
    }

    int k;
    cin >> k;

    vector<string> goal(k);
    for (int i = 0; i < k; i++)
    {
        cin >> goal[i];
    }

    string answer = solution(card1, card2, goal);

    cout << answer;

    return 0;
}