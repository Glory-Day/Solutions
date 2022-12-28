#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;

    sort(data.begin(), data.end(), [&col](const vector<int>& a, const vector<int>& b){
        if (a[col - 1] == b[col - 1]) {
            return a[0] > b[0];
        }

        return a[col - 1] < b[col - 1];
    });

    vector<int> s;
    for (int i = row_begin; i <= row_end; i++) {
        int sum = 0;
        for (auto& j: data[i - 1]) {
            sum += j % i;
        }

        s.push_back(sum);
    }

    answer = s[0];
    for (int i = 1; i < s.size(); i++) {
        answer = answer ^ s[i];
    }

    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> data;
    for (int i = 0; i < n; i++) {
        vector<int> inputs;
        for (int j = 0; j < m; j++) {
            int input;
            cin >> input;
            inputs.push_back(input);
        }
        data.push_back(inputs);
    }

    int col, row_begin, row_end;
    cin >> col >> row_begin >> row_end;

    int answer = solution(data, col, row_begin, row_end);

    cout << answer;
}