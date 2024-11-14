#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end(),greater<int>());
    while(answer < citations.size()) {
        if(citations[answer] <= answer) break;
        answer++;
    }
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> citations(n);
    for (int i = 0; i < n; i++)
    {
        cin >> citations[i];
    }

    int answer = solution(citations);

    cout << answer;

    return 0;
}