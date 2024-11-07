#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    vector<string> tokens = { "aya","ye","woo","ma" };
    for (int i = 0; i < (int)babbling.size(); i++)
    {
        string cache = "";
        for (int j = 0; j < (int)babbling[i].size(); j++)
        {
            cache.push_back(babbling[i][j]);
            
            if (find(tokens.begin(), tokens.end(), cache) != tokens.end())
            {
                cache.clear();
            }
        }
        
        if (cache.empty())
        {
            answer++;
        }
    }
    
    
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> babbling(n);
    for (int i = 0; i < n; i++)
    {
        cin >> babbling[i];
    }

    int answer = solution(babbling);
    
    cout << answer;

    return 0;
}