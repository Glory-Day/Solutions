#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    int l = lcm(denom1, denom2);
    numer1 *= l / denom1;
    numer2 *= l / denom2;
    
    int a = numer1 + numer2;
    int b = l;
    
    int g = gcd(a, b);
    answer.push_back(a / g);
    answer.push_back(b / g);
    
    return answer;
}

int main()
{
    int numer1, denom1, numer2, denom2;
    cin >> numer1 >> denom1 >> numer2 >> denom2;

    vector<int> answer = solution(numer1, denom1, numer2, denom2);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}