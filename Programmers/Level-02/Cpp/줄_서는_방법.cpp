#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    
    if (k == 1LL)
    {
        answer = v;
    }
    else
    {
        long long cache = 1;
        for (int i = 1; i <= n; i++)
        {
            cache *= i;
        }
        
        k--;
        long long d, m;
        while ((int)v.size() > 1)
        {
            cache /= n;
            d = k / cache;
            m = k % cache;
            
            answer.push_back(v[d]);
            v.erase(v.begin() + d);
            
            k = m;
            n--;
        }
        answer.push_back(v[0]);
        
        return answer;
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    long long k;
    cin >> k;

    vector<int> answer = solution(n, k);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}