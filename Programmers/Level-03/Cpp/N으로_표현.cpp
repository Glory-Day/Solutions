#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) 
{
    int answer = -1;

    if (N == number) 
    {
        return 1;
    }
    
    vector<unordered_set<int>> caches(8);
    
    int concatenated = 0;
    for (int i = 0; i < 8; i++) 
    {
        concatenated = concatenated * 10 + N;
        caches[i].insert(concatenated);
        
        for (int j = 0; j < i; j++) 
        {
            for (int a : caches[j]) 
            {
                for (int b : caches[i - j - 1]) 
                {
                    caches[i].insert(a + b);
                    caches[i].insert(a - b);
                    caches[i].insert(a * b);
                    
                    if (b != 0) 
                    {
                        caches[i].insert(a / b);
                    }
                }
            }
        }
        
        if (caches[i].find(number) != caches[i].end()) 
        {
            return i + 1;
        }
    }
    
    return answer;
}

int main()
{
    int N;
    cin >> N;

    int number;
    cin >> number;

    int answer = solution(N, number);

    cout << answer << '\n';

    return 0;
}