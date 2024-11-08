#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    set<int> caches;
    
    int p = 2;
    while (n != 1)
    {
        if (n % p == 0)
        {
            caches.insert(p);
            
            n /= p;
            
            continue;
        }
        
        p++;
    }
    
    for (auto iter = caches.begin(); iter != caches.end(); iter++)
    {
        answer.push_back(*iter);
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> answer = solution(n);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}