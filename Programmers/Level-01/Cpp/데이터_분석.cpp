#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    vector<vector<int>> caches;
    for (int i = 0; i < (int)data.size(); i++)
    {
        int index;
        switch (ext[0])
        {
            case 'c': index = 0; break;
            case 'd': index = 1; break;
            case 'm': index = 2; break;
            case 'r': index = 3; break;
        }
        
        if (data[i][index] < val_ext)
        {
            caches.push_back(data[i]);
        }
    }
    
    sort(caches.begin(), caches.end(), [&](const vector<int>& a, const vector<int>& b)
    {
        int index;
        switch (sort_by[0])
        {
            case 'c': index = 0; break;
            case 'd': index = 1; break;
            case 'm': index = 2; break;
            case 'r': index = 3; break;
        }
        
        return a[index] < b[index];
    });
    
    answer = caches;
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> data(n, vector<int>(4));
    for (int i = 0; i < n; i++)
    {
        cin >> data[i][0] >> data[i][1] >> data[i][2] >> data[i][3];
    }

    string ext;
    cin >> ext;

    int val_ext;
    cin >> val_ext;

    string sort_by;
    cin >> sort_by;

    vector<vector<int>> answer = solution(data, ext, val_ext, sort_by);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i][0] << ' ' << answer[i][1] << ' ' << answer[i][2] << ' ' << answer[i][3] << '\n';
    }

    return 0;
}