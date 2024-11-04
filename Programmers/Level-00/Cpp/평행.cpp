#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    vector<int> caches;
    for (int i = 0; i < 4; i++)
    {
        caches.push_back(i);
    }
    
    do
    {
        int a = abs(dots[caches[0]][0] - dots[caches[1]][0]);
        int b = abs(dots[caches[0]][1] - dots[caches[1]][1]);
        int c = abs(dots[caches[2]][0] - dots[caches[3]][0]);
        int d = abs(dots[caches[2]][1] - dots[caches[3]][1]);
        
        int e = gcd(a, b);
        int f = gcd(c, d);
        
        a /= e;
        b /= e;
        c /= f;
        d /= f;
        
        answer = (int)(a == c && b == d);
    }
    while (next_permutation(caches.begin(), caches.end()));
    
    return answer;
}

int main()
{
    vector<vector<int>> dots(4, vector<int>(2));
    for (int i = 0; i < 4; i++)
    {
        cin >> dots[i][0] >> dots[i][1];
    }

    int answer = solution(dots);

    cout << answer;
}