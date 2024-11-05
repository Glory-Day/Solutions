#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, int s, int e) {
    string answer = "";
    
    reverse(my_string.begin() + s, my_string.begin() + e + 1);
    
    answer = my_string;
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    int s, e;
    cin >> s >> e;

    string answer = solution(my_string, s, e);

    cout << answer;

    return 0;
}