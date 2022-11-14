#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    sort(score.begin(), score.end());
    
    int n = m;
    while (!score.empty()) {
        if (n == 1) {
            answer += score.back() * m;
            n = m + 1;
        }

        score.pop_back();
        n--;
    }

    return answer;
}

int main() {
    int n, m, k;
    cin >> k >> m >> n;
    
    vector<int> score;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        score.push_back(input);
    }

    int answer = solution(k, m, score);

    cout << answer;
}