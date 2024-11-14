#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> Vector;
    deque<int> Deque;
    
    for(int i=0;i<progresses.size();i++) {
        int temp = 100 - progresses[i];
        int day = temp/speeds[i] + ((temp%speeds[i])?1:0);
        
        Deque.push_back(day);
    }
    
    while(!Deque.empty()) {
        if(Vector.empty()) {
            Vector.push_back(Deque.front());
            answer.push_back(1);
            Deque.pop_front();
        }
        else {
            if(Vector.back()>=Deque.front()) {
                answer.back()++;
                Deque.pop_front();
            }
            else {
                Vector.push_back(Deque.front());
                answer.push_back(1);
                Deque.pop_front();
            }
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> progresses(n);
    for (int i = 0; i < n; i++)
    {
        cin >> progresses[i];
    }

    int m;
    cin >> m;

    vector<int> speeds(m);
    for (int i = 0; i < m; i++)
    {
        cin >> speeds[i];
    }

    vector<int> answer = solution(progresses, speeds);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}