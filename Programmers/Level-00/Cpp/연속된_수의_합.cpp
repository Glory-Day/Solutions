#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;

    int sum = 0;
    vector<int> cache;
    for (int i = 0; i < num; i++) {
        sum += i;
        cache.push_back(i);
    }

    int j = 0;
    while (true) {
        if (sum < total) {
            j++;
        }
        else {
            j--;
        }

        if (sum + j * num == total) {
            break;
        }
    }

    for (int i = 0; i < num; i++) {
        cache[i] += j;
    }

    answer = cache;

    return answer;
}

int main() {
    int num, total;
    cin >> num >> total;

    vector<int> answer = solution(num, total);

    for (auto& i: answer) {
        cout << i << ' ';
    }
}