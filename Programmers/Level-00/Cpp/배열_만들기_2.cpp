#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for (int i = l; i <= r; i++)
    {
        string cache = to_string(i);
        int a = count(cache.begin(), cache.end(), '0');
        int b = count(cache.begin(), cache.end(), '5');
        if ((int)cache.size() == a + b)
        {
            answer.push_back(i);
        }
    }
    
    if (answer.empty())
    {
        answer.push_back(-1);
    }
    
    return answer;
}

int main()
{
    int l, r;
    cin >> l >> r;

    vector<int> answer = solution(l, r);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}