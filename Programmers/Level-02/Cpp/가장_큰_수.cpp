#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& A, const string& B) {
    return (A + B) > (B + A);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> Vector;
    for(auto i : numbers) {
        Vector.push_back(to_string(i));
    }
    sort(Vector.begin(),Vector.end(),compare);
    if(Vector.front() == "0") return "0";
    for(auto i : Vector) {
        answer += i;
    }
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

    string answer = solution(numbers);

    cout << answer;

    return 0;
}