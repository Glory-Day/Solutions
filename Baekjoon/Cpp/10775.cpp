#include <iostream>

using namespace std;

int cache1[100001];
int cache2[100001];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cache2[i] = i;
    }

    int answer = 0;
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;

        bool chk = false;
        for (int j = cache2[input]; j > 0; j--) {
            if (cache1[j] == 0) {
                cache1[j] = 1;
                cache2[input] = j - 1;
                answer++;
                chk = true;
                break;
            }
        }

        if (!chk) break;
    }

    cout << answer;
}