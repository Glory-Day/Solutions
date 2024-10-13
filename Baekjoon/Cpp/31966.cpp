#include <iostream>
#include <algorithm>

#define P 1000000007LL

using namespace std;

using ll = long long;
 
struct node
{
    ll s, l, r;
    
    node(): s(1LL), l(1LL), r(1LL) {}
};

ll sizes[100001];
node caches[100001];
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill(&sizes[0], &sizes[100000], 1LL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        
        ll s = (caches[a].s + caches[b].s) % P;
        caches[i].s = (s + caches[a].r * sizes[b] + caches[b].l * sizes[a] - 1LL) % P;
        
        sizes[i] = (sizes[a] + sizes[b]) % P;
        
        caches[i].l = (caches[a].l + caches[b].l + sizes[b] - 1LL) % P;
        caches[i].r = (caches[b].r + caches[a].r + sizes[a] - 1LL) % P;

        cout << caches[i].s << '\n';
    }

    return 0;
}