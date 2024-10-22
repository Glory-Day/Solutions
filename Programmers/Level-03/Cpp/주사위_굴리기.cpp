#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& v, vector<int>& caches, const int n, const int depth, const int lv){
    if((int)caches.size() == depth){
        v.push_back(caches);
        
        return;
    }

    for(int i = lv; i < n; i++){
        caches.push_back(i + 1);

        dfs(v, caches, n, depth, i + 1);
        
        caches.pop_back();
    }
}

void dfs(vector<int>& out, vector<vector<int>> dice, vector<int>& indexes, int sum, const int lv){
    if(lv == (int)indexes.size()){
        out.push_back(sum);

        return;
    }

    for(int i = 0; i < (int)dice[indexes[lv] - 1].size(); i++){
        sum += dice[indexes[lv] - 1][i];

        dfs(out, dice, indexes, sum, lv + 1);
        
        sum -= dice[indexes[lv] - 1][i];
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    
    
    int n = (int)dice.size();
    vector<vector<int>> v;
    vector<int> caches;

    dfs(v, caches, n, n / 2, 0);

    int b = 0, e = (int)v.size() - 1;
    int mx = 0;

    while(b < e)
    {
        int sum1 = 0, sum2 = 0;
        vector<int> l, r;
        dfs(l, dice, v[b], sum1, 0);
        dfs(r, dice, v[e], sum2, 0);

        sort(l.begin(), l.end());
        sort(r.begin(), r.end());

        int count1= 0, count2 = 0;
        for (auto i : l){
            int j = lower_bound(r.begin(), r.end(), i) - r.begin();
            if (j >= 0)
            {
                count1 += j;
            }
        }
        for (auto i : r){
            int j = lower_bound(l.begin(), l.end(), i) - l.begin();
            if (j >= 0)
            {
                count2 += j;
            }
        }

        if (count1 > count2 && count1 > mx){
            answer = v[b];
            mx = count1;
        }
        else if (count2 > count1 && count2 > mx){
            answer = v[e];
            mx = count2;
        }

        l.clear();
        r.clear();
        
        b++;
        e--;

    }

    return answer;
}