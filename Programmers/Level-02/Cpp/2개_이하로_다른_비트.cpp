#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for (int i = 0; i < (int)numbers.size(); i++)
    {
        bitset<64> bit(numbers[i]);

        int j = 0;
        while (bit[j] == true)
        {
            j++;
        }

        long long number = (j == 0) ? numbers[i] + 1 : numbers[i] + (1LL << j) - (1LL << (j - 1));

        answer.push_back(number);
    }

    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<long long> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    vector<long long> answer = solution(numbers);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}