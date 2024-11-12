#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";

    for (int i = 0; i < (int)phone_number.size() - 4; i++)
    {
        phone_number[i] = '*';
    }

    return phone_number;
}

int main()
{
    string phone_number;
    cin >> phone_number;

    string answer = solution(phone_number);

    cout << answer;

    return 0;
}