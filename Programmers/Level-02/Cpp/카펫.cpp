#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

typedef pair<int, int> PAIR;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<PAIR> Array;
    int N = brown + yellow;
    for(int i = 1; i * i <= N; i++) {
        if(i * i == N) Array.push_back({i, i});
        else {
            if(N % i == 0) Array.push_back({i, N / i});
        }
    }
    
    for(auto i : Array) {
        int B = (i.second * 2) + (((i.first < 3) ? 0 : i.first - 2) * 2);
        
        cout << B << endl;
        
        if(B == brown) {
            answer.push_back(i.second);
            answer.push_back(i.first);
            break;
        }
    }
    
    return answer;
}

int main()
{
    int brown, yellow;
    cin >> brown >> yellow;

    vector<int> answer = solution(brown, yellow);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}