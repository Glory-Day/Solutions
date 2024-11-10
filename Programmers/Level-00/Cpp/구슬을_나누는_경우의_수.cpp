#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int balls, int share) {
    int answer = 0;
    
    vector<int> caches(share, 1);
    for (int i = 0; i < balls - share; i++)
    {
        caches.push_back(0);
    }
    
    do
    {
        answer++;
    }
    while (prev_permutation(caches.begin(), caches.end()));
    
    return answer;
}

int main()
{
    int balls, share;
    cin >> balls >> share;

    int answer = solution(balls, share);

    cout << answer;

    return 0;
}