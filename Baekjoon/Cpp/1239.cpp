#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cache[100];

int main() {
    int n;
    cin >> n;
    
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    int answer = 0;
    do {
        int sum = 0;
        fill(cache, cache + 100, 0);

        cache[sum] = 1;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum < 100) {
                cache[sum]++;
            }
        }

        sum = 0;
        for (int i = 0; i < 100; i++) {
            if (cache[i] && i + 50 < 100) {
                sum += cache[i + 50];
            }
        }

        answer = max(answer, sum);
    }
    while (next_permutation(arr.begin(), arr.end()));

    cout << answer;
}