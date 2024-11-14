#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> Queue;
    for(auto i : scoville) {
        Queue.push(i);
    }
    while(Queue.top() < K && Queue.size() > 1) {
        int A = Queue.top(); Queue.pop();
        int B = Queue.top(); Queue.pop();
        Queue.push(A + B * 2);
        answer++;
    }
    if(Queue.top() < K)
        return -1;
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> scoville(n);
    for (int i = 0; i < n; i++)
    {
        cin >> scoville[i];
    }

    int k;
    cin >> k;

    int answer = solution(scoville, k);

    cout << answer;

    return 0;
}