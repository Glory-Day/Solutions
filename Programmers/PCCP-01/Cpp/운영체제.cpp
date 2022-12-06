#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

struct cmpA{
    bool operator()(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
};

struct cmpB{
    bool operator()(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }

        return a[0] > b[0];
    }
};

vector<ll> solution(vector<vector<int>> program) {
    vector<ll> answer;
    answer = vector<ll>(11, 0);

    priority_queue<vector<int>, vector<vector<int>>, cmpA> pqA(program.begin(), program.end());
    priority_queue<vector<int>, vector<vector<int>>, cmpB> pqB;

    answer[0] = pqA.top()[1];
    while (!pqA.empty() || !pqB.empty()) {
        while(!pqA.empty() && pqA.top()[1] <= answer[0]) {
            pqB.push(pqA.top());
            pqA.pop();
        }

        if (!pqB.empty()) {
            auto& p = pqB.top();
            answer[p[0]] += (answer[0] - p[1]);
            answer[0] += p[2];
            pqB.pop();
            continue;
        }

        answer[0] = pqA.top()[1];
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> program;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        program.push_back({ a,b,c });
    }

    vector<ll> answer = solution(program);

    for (auto& i: answer) {
        cout << i << '\n';
    }
}