#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    
    unordered_map<string, int> ump;
    ump["iceamericano"] = 4500;
    ump["americanoice"] = 4500;
    ump["hotamericano"] = 4500; 
    ump["americanohot"] = 4500;
    ump["icecafelatte"] = 5000; 
    ump["cafelatteice"] = 5000;
    ump["hotcafelatte"] = 5000; 
    ump["cafelattehot"] = 5000;
    ump["americano"] = 4500;
    ump["cafelatte"] = 5000;
    ump["anything"] = 4500;
    
    for (int i = 0; i < (int)order.size(); i++)
    {
        answer += ump[order[i]];
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> order(n);
    for (int i = 0; i < n; i++)
    {
        cin >> order[i];
    }

    int answer = solution(order);

    cout << answer;

    return 0;
}