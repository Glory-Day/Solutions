#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    map<string, int> mp;
    for (int i = 0; i < (int)name.size(); i++)
    {
        mp[name[i]] = yearning[i];
    }
    
    for (int i = 0; i < (int)photo.size(); i++)
    {
        int cache = 0;
        for (int j = 0; j < (int)photo[i].size(); j++)
        {
            if (mp.find(photo[i][j]) != mp.end())
            {
                cache += mp[photo[i][j]];
            }
        }
        
        answer.push_back(cache);
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> name(n);
    for (int i = 0; i < n; i++)
    {
        cin >> name[i];
    }

    int m;
    cin >> m;

    vector<int> yearning(m);
    for (int i = 0; i < m; i++)
    {
        cin >> yearning[i];
    }

    int k;
    cin >> k;

    vector<vector<string>> photo(k);
    for (int i = 0; i < k; i++)
    {
        int l;
        cin >> l;

        vector<string> caches(l);
        for (int j = 0; j < l; j++)
        {
            cin >> caches[j];
        }
        
        photo[i] = caches;
    }

    vector<int> answer = solution(name, yearning, photo);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}