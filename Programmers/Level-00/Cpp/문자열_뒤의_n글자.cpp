#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    
    int l = (int)my_string.length();
    answer = my_string.substr(l - n, l);
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    int n;
    cin >> n;

    string answer = solution(my_string, n);

    cout << answer;

    return 0;
}