#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    vector<int> v;
    for (int i = 0; i < (int)dungeons.size(); i++)
    {
        v.push_back(i);
    }
    
    do
    {
        int count = 0;
        int cache = k;
        for (int i = 0; i < (int)v.size(); i++)
        {
            if (cache < dungeons[v[i]][0])
            {
                break;
            }
            
            cache -= dungeons[v[i]][1];
            count++;
        }
        
        answer = max(answer, count);
    }
    while (next_permutation(v.begin(), v.end()));
    
    return answer;
}

int main()
{
    int k;
    cin >> k;

    int n;
    cin >> n;

    vector<vector<int>> dungeons(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> dungeons[i][0] >> dungeons[i][1];
    }

    int answer = solution(k, dungeons);

    cout << answer;

    return 0;
}