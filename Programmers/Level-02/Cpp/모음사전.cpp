#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string word) {
    int answer = 0;
    
    vector<char> v = { 'A','E','I','O','U' };
    
    int index = 1;
    string cache = "";
    unordered_map<string, int> mp;
    for (int i = 0; i < 5; i++)
    {
        cache.push_back(v[i]);
        mp[cache] = index++;
        for (int j = 0; j < 5; j++)
        {
            cache.push_back(v[j]);
            mp[cache] = index++;
            for (int k = 0; k < 5; k++)
            {
                cache.push_back(v[k]);
                mp[cache] = index++;
                for (int l = 0; l < 5; l++)
                {
                    cache.push_back(v[l]);
                    mp[cache] = index++;
                    for (int m = 0; m < 5; m++)
                    {
                        cache.push_back(v[m]);
                        mp[cache] = index++;
                        cache.pop_back();
                    }
                    
                    cache.pop_back();
                }
                
                cache.pop_back();
            }
            
            cache.pop_back();
        }
        
        cache.pop_back();
    }
    
    answer = mp[word];
    
    return answer;
}

int main()
{
    string word;
    cin >> word;

    int answer = solution(word);

    cout << answer;

    return 0;
}