#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int Array[10001];
    for(int i = 1; i <= n; i++)
        Array[i] = i;
    int answer = 0;
    int begin = 1, end = 1, sum = 0;
    while(true) {
        if(sum < n) sum += Array[end++];
        else if(begin == n) break;
        else sum -= Array[begin++];
        
        if(sum == n) answer++;
    }
    return answer;
}

int main()
{
    int n;
    cin >> n;

    int answer = solution(n);

    cout << answer;

    return 0;
}