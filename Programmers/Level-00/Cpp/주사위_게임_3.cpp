#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    
    vector<int> caches = { a,b,c,d };
    
    sort(caches.begin(), caches.end());
    
    if (caches[0] == caches[1] && caches[1] == caches[2] && caches[2] == caches[3])
    {
        answer = caches[0] * 1111;
    }
    else if (caches[0] == caches[1] && caches[1] == caches[2])
    {
        answer = (10 * caches[0] + caches[3]) * (10 * caches[0] + caches[3]);
    }
    else if (caches[1] == caches[2] && caches[2] == caches[3])
    {
        answer = (10 * caches[1] + caches[0]) * (10 * caches[1] + caches[0]);
    }
    else if (caches[0] == caches[1] && caches[2] == caches[3])
    {
        answer = (caches[0] + caches[2]) * abs(caches[0] - caches[2]);
    }
    else if (caches[0] == caches[1])
    {
        answer = caches[2] * caches[3];
    }
    else if (caches[1] == caches[2])
    {
        answer = caches[0] * caches[3];
    }
    else if (caches[2] == caches[3])
    {
        answer = caches[0] * caches[1];
    }
    else
    {
        answer = caches[0];
    }
    
    return answer;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int answer = solution(a, b, c, d);

    cout << answer;

    return 0;
}