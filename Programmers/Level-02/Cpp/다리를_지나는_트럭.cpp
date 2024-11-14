#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> Queue;
    int sum = 0;
    for(int i=0;i<truck_weights.size();i++) {
        int truck = truck_weights[i];
        while(true) {
            if(Queue.empty()) {
                sum += truck;
                Queue.push(truck);
                answer++;
                break;
            }
            else if(Queue.size()==bridge_length) {
                sum -= Queue.front();
                Queue.pop();
            }
            else {
                if(truck + sum > weight) {
                    Queue.push(0);
                    answer++;
                }
                else {
                    sum += truck;
                    Queue.push(truck);
                    answer++;
                    break;
                }
            }
        }
    }
    return answer + bridge_length;
}

int main()
{
    int bridge_length, weight;
    cin >> bridge_length >> weight;

    int n;
    cin >> n;

    vector<int> truck_weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> truck_weights[i];
    }

    int answer = solution(bridge_length, weight, truck_weights);

    cout << answer;

    return 0;
}