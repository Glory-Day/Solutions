#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int to_second(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = -1;
    
    int b = to_second(h1, m1, s1);
    int e = to_second(h2, m2, s2);
    
    int cache = e * 59/3600 + e * 719/43200 - b * 59/3600 - b * 719/43200;
    if (b >= 43200) 
    {
        cache += 1;
    }
    
    if (e >= 43200) 
    {
        cache -= 1;
    }
    
    if (b * 59 % 3600 == 0 || b * 719 % 43200 == 0) 
    {
        cache += 1;
    }
    
    answer = cache;
    
    return answer;
}

int main()
{
    int h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

    int answer = solution(h1, m1, s1, h2, m2, s2);

    cout << answer;

    return 0;
}