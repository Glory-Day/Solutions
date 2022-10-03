#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
vector<char> ops, v;
bool visited[12];
vector<int> answers;
int len;

int calc(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

void f(int lv) {
    if (lv == len) {
        int answer = calc(nums[0], nums[1], v[0]);
        for (int i = 1; i < v.size(); i++) {
            answer = calc(answer, nums[i + 1], v[i]);
        }
        answers.push_back(answer);
        return;
    }

    for (int i = 0; i < len; i++) {
        if (!visited[i]) {
            v.push_back(ops[i]);
            visited[i] = true;

            f(lv + 1);

            v.pop_back();
            visited[i] = false;
        }
    }

}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        nums.push_back(input);
    }

    int op[4];
    cin >> op[0] >> op[1] >> op[2] >> op[3];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < op[i]; j++) {
            switch (i) {
                case 0: ops.push_back('+'); break;
                case 1: ops.push_back('-'); break;
                case 2: ops.push_back('*'); break;
                case 3: ops.push_back('/'); break;
            }
        }
    }

    len = ops.size();

    f(0);

    sort(answers.begin(), answers.end());

    cout << answers.back() << '\n' << answers.front();
}