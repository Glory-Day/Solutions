#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end());
    for(int i=0;i<phone_book.size()-1;i++) {
        if(phone_book[i] == phone_book[i+1].substr(0,phone_book[i].length()))
            return false;
    }
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> phone_book(n);
    for (int i = 0; i < n; i++)
    {
        cin >> phone_book[i];
    }

    bool answer = solution(phone_book);

    cout << answer;

    return 0;
}