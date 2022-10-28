#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;

    int b = 1;
    int idx = 0;
    while (b <= n) {
        if (b >= stations[idx] - w && b <= stations[idx] + w) {
            b = stations[idx] + w;
            idx++;
        }
        else {
            answer++;
            b += w * 2;
        }

        b++;
    }

    return answer;
}

int main() {
    int n, m, w;
    cin >> n >> m;

    vector<int> stations;
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        stations.push_back(input);
    }

    cin >> w;

    int answer = solution(n, stations, w);

    cout << answer;
}