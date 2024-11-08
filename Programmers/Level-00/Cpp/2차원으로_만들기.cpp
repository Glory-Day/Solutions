#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    
    for (int i = 0; i < (int)num_list.size(); i += n)
    {
        vector<int> caches;
        for (int j = 0; j < n; j++)
        {
            caches.push_back(num_list[i + j]);
        }
        
        answer.push_back(caches);
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> numlist(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numlist[i];
    }

    cin >> n;

    vector<vector<int>> answer = solution(numlist, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << answer[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}