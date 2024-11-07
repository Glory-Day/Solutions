#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    
    for (int i = 0; i < (int)numlist.size(); i++)
    {
        if (numlist[i] % n == 0)
        {
            answer.push_back(numlist[i]);
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<int> numlist(m);
    for (int i = 0; i < m; i++)
    {
        cin >> numlist[i];
    }

    vector<int> answer = solution(n, numlist);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}