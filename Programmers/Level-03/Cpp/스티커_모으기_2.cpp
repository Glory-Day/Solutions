#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sticker) {
    int answer = 0;

    int n = sticker.size();
    vector<int> cache1(n, 0);
    vector<int> cache2(n, 0);

    if (n == 1) {
        return sticker[0];
    }

    cache1[0] = cache1[1] = sticker[0];
    for (int i = 2; i < n - 1; i++) {
        cache1[i] = max(cache1[i - 2] + sticker[i], cache1[i - 1]);
    }
    
    for (int i = 1; i < n; i++) {
        cache2[i] = max(cache2[i - 2] + sticker[i], cache2[i - 1]);
    }

    answer = max(cache1[n - 2], cache2[n - 1]);

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> sticker;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        sticker.push_back(input);
    }

    int answer = solution(sticker);

    cout << answer;
}