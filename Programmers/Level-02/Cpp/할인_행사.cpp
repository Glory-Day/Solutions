#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string, int> ump;
    for (int i = 0; i < (int)want.size(); i++)
    {
        ump[want[i]] = number[i];
    }
    
    for (int i = 0; i <= (int)discount.size() - 10; i++)
    {
        unordered_map<string, int> caches;
        for (int j = 0; j < 10; j++)
        {
            if (caches.find(discount[i + j]) == caches.end())
            {
                caches[discount[i + j]] = 1;
            }
            else
            {
                caches[discount[i + j]]++;
            }
        }
        
        int count = 0;
        for (const auto& j: caches)
        {
            if (ump.find(j.first) != ump.end() && ump[j.first] == j.second)
            {
                count += j.second;
            }
        }
        
        if (count == 10)
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

    vector<string> want(n);
    for (int i = 0; i < n; i++)
    {
        cin >> want[i];
    }

    vector<int> number(n);
    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
    }

    int m;
    cin >> m;

    vector<string> discount(m);
    for (int i = 0; i < m; i++)
    {
        cin >> discount[i];
    }

    int answer = solution(want, number, discount);

    cout << answer;

    return 0;
}