#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int bfs(ll b, ll e)
{
    ll answer = -1;
	
    queue<pll> q;
    q.push({ b,1 });
	
    while (!q.empty())
    {
        ll n = q.front().first;
        ll i = q.front().second;
        q.pop();
		
        if (n == e)
        {
            answer = i;
	        
			break;
        }
		
        string s = to_string(n);
        s.push_back('1');
		
        ll nn1 = n * 2;
        ll nn2 = stoll(s);
		
        if (nn1 <= e)
        {
	        q.push({ nn1,i + 1 });
	    }
        
        if (nn2 <= e)
        {
	        q.push({ nn2,i + 1 });
	    }
    }
	
    return answer;
}

int main()
{
    ll b, e;
    cin >> b >> e;
	
    ll answer = bfs(b, e);
	
    cout << answer;
	
	return 0;
}