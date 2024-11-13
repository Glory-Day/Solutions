#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const bool compare(const vector<int>& a, const vector<int>& b)
{
    if (a[1] == b[1])
    {
        return a[0] < b[0];
    }
    
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), compare);
    
    int cache = targets[0][1];
    answer++;
    
    for (int i = 1; i < (int)targets.size(); i++)
    {
        if (targets[i][0] < cache)
        {
            continue;
        }
        
        cache = targets[i][1];
        
        answer++;
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> targets(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> targets[i][0] >> targets[i][1];
    }

    int answer = solution(targets);

    cout << answer;

    return 0;
}