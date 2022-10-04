#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int inorder[100001], postorder[100001];
int cache[100001];

void dfs(int il, int ir, int pl, int pr) {
    if (il > ir || pl > pr) return;

    int rt = postorder[pr];
    cout << rt << ' ';

    dfs(il, cache[rt] - 1, pl, pl + (cache[rt] - il) - 1);
    dfs(cache[rt] + 1, ir, pl + (cache[rt] - il), pr - 1);
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];

    for (int i = 0; i < n; i++) cache[inorder[i]] = i;

    dfs(0, n - 1, 0, n - 1);
}