#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
 
using namespace std;

typedef tuple<int, int, int> edge;
 
typedef struct _UnionFind{
	int n; vector<int> parts, sizes;

	_UnionFind(int n) : n(n), parts(vector<int>(n + 1)), sizes(vector<int>(n + 1, 1)) {
		for (int i = 1; i <= n; i++) {
			parts[i] = i;
		}
	}

	int find(int x) {
		if (x == parts[x]) return x;
		else return parts[x] = find(parts[x]);
	}

	void unions(int y, int x) {
		y = find(y);
        x = find(x);

		if (y == x) return;

		parts[y] = x;
		sizes[x] += sizes[y];
	}
} UnionFind;
 
typedef struct _Query {
	int x, y, left, right, move, root;
} Query;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, cnt;
	cin >> n >> m;
 
	vector<edge> edges;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.emplace_back(c, a, b);
	}
 
	cin >> cnt;

	vector<Query> qs;
	for (int i = 0; i < cnt; i++) {
		int a, b;
		cin >> a >> b;
		qs.push_back({ a,b,1,m,0,-1 });
	}

	sort(edges.begin(), edges.end());
 
	while (true) {
		vector<vector<int>> map(m + 1);
		bool chk = false;

		for (int i = 0; i < cnt; i++) {
			Query& q = qs[i];

			if (q.left <= q.right) {
				chk = true;
				map[(q.left + q.right) / 2].push_back(i);
			}
		}

		if (!chk) break;
 
		UnionFind us(n + 1);
		for (int i = 0; i < m; i++) {
			int w, x, y; 
			tie(w, x, y) = edges[i];

			if (us.find(x) != us.find(y)) us.unions(x, y);

			for (int j: map[i + 1]) {
				Query& q = qs[j];

				if (us.find(q.x) == us.find(q.y)) {
					q.right = i;
					q.move = us.sizes[us.find(x)];
					q.root = w;
				}
				else {
					q.left = i + 2;
                }
			}
		}
	}

	for (int i = 0; i < cnt; i++) {
		if (qs[i].root == -1) cout << -1 << '\n';
		else cout << qs[i].root << ' ' << qs[i].move << '\n';
	}
		
	return 0;
}