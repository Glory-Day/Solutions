#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*
    문제 풀이: 3가지 물품이 있다.
    (1) a는 개 전용 사료
    (2) b는 고양이 전용 사료
    (3) c는 개, 고양이 전용 사료
    x마리의 개와 y마리의 고양이가 있다. 
    주어진 사료 a, b, c로 가지고 있는 개, 고양이들을 빠짐없이 먹일 수 있는지 출력한다.

    풀이: 먼저 주어진 a, b로 개와 고양이를 먹인다. 
    그러면 남은 개와 고양이의 마리 수는 x - a, y - b이다.
    남은 마리수의 총 합과 c의 개수를 비교해 c가 많거나 같으면 모든 개, 고양이를 먹일 수 있고
    아니면 모든 개, 고양이를 먹일 수 없다.
*/

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;

        x = (x - a < 0) ? 0 : x - a;
        y = (y - b < 0) ? 0 : y - b;

        if (c >= x + y) cout << "YES\n";
        else cout << "NO\n";
    }
}