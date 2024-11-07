#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    
    if (common[1] - common[0] == common[2] - common[1])
    {
        answer = common.back() + common[1] - common[0];
    }
    else
    {
        answer = common.back() * (common[1] / common[0]);
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> common(n);
    for (int i = 0; i < n; i++)
    {
        cin >> common[i];
    }

    int answer = solution(common);

    cout << answer;

    return 0;
}