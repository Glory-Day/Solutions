#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size() - 1,0);
    deque<int> Deque;
    
    for(auto i:prices) {
        Deque.push_back(i);
    }
    
    int index = 0;
    while(!Deque.empty()) {
        int temp = Deque.front();
        Deque.pop_front();
        for(int i=0;i<Deque.size();i++) {
            if(temp > Deque[i]) {
                answer[index]++;
                break;
            }
            else {
                answer[index]++;
            }
        }
        index++;
    }
    
    answer.push_back(0);
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    vector<int> answer = solution(prices);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}