#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0LL;
    
    unordered_map<int, int> caches;
    for (int i = 0; i < (int)weights.size(); i++)
    {
        caches[weights[i]]++;
    }
    
    for (const auto& i: caches)
    {
        long long a = i.first;
        long long b = i.second;
        
        if (1 < b)
        {
            answer += b * (b - 1) / 2;
        }
        
        long long n = a * 3 / 2;
        if (a * 3 % 2 == 0 && caches.find(n) != caches.end())
        {
            answer += caches[n] * b;
        }
        
        n = a * 4 / 2;
        if (a * 4 % 2 == 0 && caches.find(n) != caches.end())
        {
            answer += caches[n] * b;
        }
        
        n = a * 4 / 3;
        if (a * 4 % 3 == 0 && caches.find(n) != caches.end())
        {
            answer += caches[n] * b;
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    long long answer = solution(weights);

    cout << answer;

    return 0;
}