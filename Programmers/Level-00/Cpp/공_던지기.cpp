#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    
    int cache = 1;
    for (int i = 1; i < k; i++)
    {
        cache += 2;
        cache %= (int)numbers.size();
    }
    
    answer = cache == 0 ? numbers.back() : cache;
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int k;
    cin >> k;

    int answer = solution(numbers, k);

    cout << answer;

    return 0;
}