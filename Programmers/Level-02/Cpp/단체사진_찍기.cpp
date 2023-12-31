#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getDistance(vector<char>& chs, char a, char b) {
    int l, r;
    for (int i = 0; i < chs.size(); i++) {
        if (chs[i] == a) l = i;
        else if (chs[i] == b) r = i;
    }

    return abs(l - r) - 1;
}

int solution(int n, vector<string> data) {
    int answer = 0;

    vector<char> chs = { 'A','C','F','J','M','N','R','T' };

    do {
        int check = 0;
        for (string& i: data) {
            char a = i[0], b = i[2], op = i[3];
            int c = (i[4] - '0');

            int d = getDistance(chs, a, b);

            switch (op) {
                case '=':
                    if (d == c) check++; 
                    break;
                case '<':
                    if (d < c) check++; 
                    break;
                case '>':
                    if (d > c) check++; 
                    break;
            }
        }

        if (check == data.size()) {
            answer++;
        }
    } while (next_permutation(chs.begin(), chs.end()));

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<string> data;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        data.push_back(input);
    }

    int answer = solution(n, data);

    cout << answer;
}