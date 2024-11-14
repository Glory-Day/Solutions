#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int,int> PAIR;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<PAIR> Deque;
    for(int i = 0; i < priorities.size(); i++) {
        Deque.push_back({ priorities[i],i });
    }
    sort(priorities.begin(), priorities.end(), greater<int>());
    int index = 0;
    while(!Deque.empty()) {
        if(priorities[index] == Deque.front().first) {
            if(location == Deque.front().second) {
                return index + 1;
            }
            else {
                Deque.pop_front();
                index++;
            }
        }
        else {
            PAIR temp = Deque.front();
            Deque.push_back(temp);
            Deque.pop_front();
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> priorities(n);
    for (int i = 0; i < n; i++)
    {
        cin >> priorities[i];
    }

    int location;
    cin >> location;

    int answer = solution(priorities, location);

    cout << answer;

    return 0;
}