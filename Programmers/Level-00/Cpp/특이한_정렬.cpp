#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    
    sort(numlist.begin(), numlist.end(), [&](const int a, const int b) {
        if (abs(n - a) == abs(n - b))
        {
            return a > b;
        }
        
        return abs(n - a) < abs(n - b);
    });
    
    answer = numlist;
    
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

    vector<int> answer = solution(numlist, n);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}