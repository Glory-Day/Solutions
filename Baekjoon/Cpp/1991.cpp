#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

typedef pair<char, char> pcc;

unordered_map<char, pcc> mp;

void preorder(char nd) {
    if (nd == '.') return;

    cout << nd;
    preorder(mp[nd].first);
    preorder(mp[nd].second);
}

void inorder(char nd) {
    if (nd == '.') return;

    inorder(mp[nd].first);
    cout << nd;
    inorder(mp[nd].second);
}

void postorder(char nd) {
    if (nd == '.') return;

    postorder(mp[nd].first);
    postorder(mp[nd].second);
    cout << nd;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> b >> c;

        mp[a] = {b, c};
    }

    preorder('A');
    cout << '\n';

    inorder('A');
    cout << '\n';

    postorder('A');
}