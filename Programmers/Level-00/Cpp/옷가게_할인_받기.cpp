#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    int answer = 0;
    
    if (500000 <= price)
    {
        price *= 0.8;
    }
    else if (300000 <= price && price < 500000)
    {
        price *= 0.9;
    }
    else if (100000 <= price && price < 300000)
    {
        price *= 0.95;
    }
    
    answer = price;
    
    return answer;
}

int main()
{
    int price;
    cin >> price;

    int answer = solution(price);

    cout << answer;

    return 0;
}