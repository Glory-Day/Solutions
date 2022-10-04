#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
vector<vector<vector<bool>>> blocks = {
	{ { 1,1,1,1 } },
	{ { 1,1 },{ 1,1 }},
	{ { 1,1,1 },{ 1,0,0 } },
	{ { 1,0,0 },{ 1,1,1 } },
    { { 0,0,1 },{ 1,1,1 } },
	{ { 1,1,1 },{ 0,0,1 } },
    { { 0,1,1 },{ 1,1,0 } },
	{ { 1,1,0 },{ 0,1,1 } },
	{ { 1,1,1 },{ 0,1,0 } },
    { { 0,1,0 },{ 1,1,1 } },
	{ { 1,1 },{ 0,1 },{ 0,1 } },
	{ { 1,1 },{ 1,0 },{ 1,0 } },
	{ { 1,0 },{ 1,0 },{ 1,1 } },
	{ { 0,1 },{ 0,1 },{ 1,1 } },
	{ { 1,0 },{ 1,1 },{ 0,1 } },
	{ { 0,1 },{ 1,1 },{ 1,0 } },
	{ { 0,1 },{ 1,1 },{ 0,1 } },
	{ { 1,0 },{ 1,1 },{ 1,0 } },
    { { 1 },{ 1 },{ 1 },{ 1 } }
};

int getSum(int y, int x) {
    int h = map.size();
    int w = map.front().size();

    int answer = 0;
    for (auto& block: blocks) {
        int bh = block.size();
        int bw = block.front().size();

        if (h < y + bh || w < x + bw) continue;

        int sum = 0;
        for (int i = 0; i < bh; i++) {
            for (int j = 0; j < bw; j++) {
                sum += block[i][j] * map[y + i][x + j];
            }
        }

        answer = max(answer, sum);
    }

    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;

    map = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            answer = max(answer, getSum(i, j));
        }
    }

    cout << answer;
}