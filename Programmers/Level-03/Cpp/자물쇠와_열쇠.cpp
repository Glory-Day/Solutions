#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>>& key) {
    vector<vector<int>> rotated;
    for (int i = 0; i < key.size(); i++) {
        vector<int> temp;
        for (int j = key.size() - 1; j >= 0; j--) {
            temp.push_back(key[j][i]);
        }
        rotated.push_back(temp);
    }

    return rotated;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    int n = key.size() * 2 + lock.size();
    vector<vector<int>> map = vector<vector<int>>(n, vector<int>(n, 0));

    n = lock.size() + key.size();
    for (int i = key.size(); i < n; i++) {
        for (int j = key.size(); j < n; j++) {
            map[i][j] = lock[i - key.size()][j - key.size()];
        }
    }

    vector<vector<int>> temp;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                temp = map;
                for (int y = 0; y < key.size(); y++) {
                    for (int x = 0; x < key.size(); x++) {
                        temp[y + j][x + k] = (temp[y + j][x + k] ^ key[y][x]);
                    }
                }

                bool check = true;
                for (int y = key.size(); y < n; y++) {
                    for (int x = key.size(); x < n; x++) {
                        if (!temp[y][x]) {
                            check = false;
                            break;
                        }
                    }

                    if (!check) break;
                }

                if (check) {
                    answer = true;
                    return answer;
                }
            }
        }

        key = rotate(key);
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> key;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            temp.push_back(input);
        }
        key.push_back(temp);
    }

    cin >> n;

    vector<vector<int>> lock;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            temp.push_back(input);
        }
        lock.push_back(temp);
    }

    bool answer = solution(key, lock);

    if (answer) cout << "true";
    else cout << "false";
}