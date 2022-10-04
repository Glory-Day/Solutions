#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (int i = triangle.size() - 1; i > 0; i--) {
        for (int j = 0; j < triangle[i].size() - 1; j++) {
            triangle[i - 1][j] = max(triangle[i - 1][j] + triangle[i][j], triangle[i - 1][j] + triangle[i][j + 1]);
        }
    }

    answer = triangle[0][0];

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> triangle;
    for (int i = 1; i <= n; i++) {
        vector<int> temp;
        for (int j = 0; j < i; j++) {
            int input;
            cin >> input;
            temp.push_back(input);
        }
        triangle.push_back(temp);
    }

    int answer = solution(triangle);

    cout << answer;
}