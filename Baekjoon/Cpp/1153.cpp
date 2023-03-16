#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> answer;
    if (n < 8) {
        answer.push_back(-1);
    }
    else {
        vector<bool> cache(1000001, true);
        for (int i = 2; i <= 1000000; i++) {
            if (cache[i] == false) {
                continue;
            }

            for (int j = 2; i * j <= 1000000; j++) {
                cache[i * j] = false;    
            }
        }

        if (n % 2) {
            answer = { 2,3 };
            n -= 5;
        }
        else {
            answer = { 2,2 };
            n -= 4;
        }

        for (int i = 2; i <= n / 2; i++) {
            if (cache[i] && cache[n - i]) {
                answer.push_back(i);
                answer.push_back(n - i);
                break;
            }
        }        
    }

    sort(answer.begin(), answer.end());

    for (auto& i: answer) {
        cout << i << ' ';
    }
}