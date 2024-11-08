#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string before, string after) {
    int answer = 1;
    
    vector<int> caches(26, 0);
    for (int i = 0; i < (int)before.size(); i++)
    {
        caches[before[i] - 'a']++;
    }
    
    for (int i = 0; i < (int)after.size(); i++)
    {
        caches[after[i] - 'a']--;
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (caches[i] != 0)
        {
            answer = 0;
        }
    }
    
    return answer;
}

int main()
{
    string before, after;
    cin >> before >> after;

    int answer = solution(before, after);

    cout << answer;

    return 0;
}