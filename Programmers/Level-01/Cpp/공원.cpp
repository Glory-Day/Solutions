#include <iostream>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    
    int a = (int)park.size();
    int b = (int)park[0].size();
    
    for (int i = 0; i < (int)mats.size(); i++)
    {
        for (int j = 0; j < a - mats[i] + 1; j++)
        {
            for (int k = 0; k < b - mats[i] + 1; k++)
            {
                int cache = 0;
                for (int l = 0; l < mats[i]; l++)
                {
                    for (int m = 0; m < mats[i]; m++)
                    {
                        if (park[j + l][k + m] == "-1")
                        {
                            cache++;
                        }
                    }
                }
                
                if (cache == mats[i] * mats[i])
                {
                    answer = max(answer, mats[i]);
                }
            }
        }
    }
    
    if (answer == 0)
    {
        answer = -1;
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> mats(n);
    for (int i = 0; i < n; i++)
    {
        cin >> mats[i];
    }

    int m, k;
    cin >> m >> k;

    vector<vector<string>> park(m, vector<string>(k));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> park[i][j];
        }
    }

    int answer = solution(mats, park);

    cout << answer;

    return 0;
}