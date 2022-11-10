#include <iostream>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vector<int> points = { k };
    while (k != 1) {
        if (k % 2 == 0) {
            k /= 2;
        }
        else {
            k = 3 * k + 1;
        }

        points.push_back(k);
    }

    int n = points.size();
    for (int i = 0; i < ranges.size(); i++) {
        double sum = 0;
        int tmp = n + ranges[i][1] - 1;
        if (ranges[i][0] > tmp) {
            answer.push_back(-1.0);
        }
        else {
            double sum = 0;
            for (int j = ranges[i][0]; j < tmp; j++) {
                sum += (double)(points[j] + points[j + 1]) / (double)2;
            }

            answer.push_back(sum);
        }
    }

    return answer;
}

int main() {
    int n, k;
    cin >> k >> n;

    vector<vector<int>> ranges;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ranges.push_back({ a,b });
    }

    vector<double> answer = solution(k, ranges);

    for (double& i: answer) {
        cout << i << ' ';
    }
}