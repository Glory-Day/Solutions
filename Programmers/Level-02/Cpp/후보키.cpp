#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    int n = (int)relation.front().size();
    vector<vector<int>> sets;
    for (int i = 1; i <= n; i++)
    {
        vector<bool> bits;
        for (int j = 0; j < i; j++)
        {
            bits.push_back(true);
        }
        
        for (int j = 0; j < n - i; j++)
        {
            bits.push_back(false);
        }
        
        do
        {
            set<string> st;
            for (int j = 0; j < (int)relation.size(); j++)
            {
                string cache = "";
                for (int k = 0; k < n; k++)
                {
                    if (bits[k])
                    {
                        cache.append(relation[j][k]);
                    }
                }
                
                if (cache.empty() == false)
                {
                    st.insert(cache);
                }
            }
            
            if (st.size() == relation.size())
            {
                vector<int> v;
                for (int i = 0; i < n; i++)
                {
                    if (bits[i])
                    {
                        v.push_back(i);
                    }
                }
                
                sets.push_back(v);
            }
        }
        while (prev_permutation(bits.begin(), bits.end()));
    }
    
    for (int i = 0; i < (int)sets.size() - 1; i++)
    {
        for (int j = i + 1; j < (int)sets.size(); j++)
        {
            int sum = 0;
            for (int k = 0; k < (int)sets[i].size(); k++)
            {
                sum += (int)(find(sets[j].begin(), sets[j].end(), sets[i][k]) != sets[j].end());
            }
            
            if (sum == (int)sets[i].size())
            {
                sets.erase(sets.begin() + j);
                j--;
            }
        }
    }

    answer = (int)sets.size();
    
    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<string>> relation(n, vector<string>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> relation[i][j];
        }
    }

    int answer = solution(relation);

    cout << answer;
}