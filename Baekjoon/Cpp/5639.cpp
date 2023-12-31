#include <iostream>
#include <vector>

using namespace std;

int tree[10001];
vector<int> postorder;

void dfs(int b, int e) {
    if (b > e) return;

    int mid = tree[b++];
    
    int idx = b;
    while (tree[idx] < mid && idx <= e) idx++;

    postorder.push_back(mid);
    dfs(idx, e);
    dfs(b, idx - 1);
}

int main() {
    int i = 0;
    for (; cin >> tree[i]; i++);

    dfs(0, i - 1);

    for (auto it = postorder.rbegin(); it != postorder.rend(); it++) {
        cout << (*it) << '\n';
    }
}