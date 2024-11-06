#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    
    vector<pair<int, int>> caches;
    for (int i = 0; i < (int)rank.size(); i++)
    {
        if (attendance[i])
        {
            caches.push_back({ rank[i],i });
        }
    }
    
    sort(caches.begin(), caches.end());
    
    answer = 10000 * caches[0].second + 100 * caches[1].second + caches[2].second;
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> rank(n);
    for (int i = 0; i < n; i++)
    {
        cin >> rank[i];
    }

    vector<bool> attendance(n);
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        attendance[i] = input;
    }

    int answer = solution(rank, attendance);
    
    cout << answer;

    return 0;
}