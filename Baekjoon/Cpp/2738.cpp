#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map;
    for (int i = 0; i < n; i++) {
        vector<int> inputs;
        for (int j = 0; j < m; j++) {
            int input;
            cin >> input;
            inputs.push_back(input);
        }

        map.push_back(inputs);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int input;
            cin >> input;
            map[i][j] += input;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}