#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int b = 0;
    int e = 0;
    int sum = sequence[0];
    int cache = INT_MAX;
    while (b <= e && e < (int)sequence.size())
    {
        if (sum < k)
        {
            sum += sequence[++e];
        }
        else if (sum > k)
        {
            sum -= sequence[b++];
        }
        else
        {
            if (e - b < cache)
            {
                cache = e - b;
                
                answer.clear();
                answer.push_back(b);
                answer.push_back(e);
            }
            
            sum -= sequence[b++];
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sequence[i];
    }

    int k;
    cin >> k;

    vector<int> answer = solution(sequence, k);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}