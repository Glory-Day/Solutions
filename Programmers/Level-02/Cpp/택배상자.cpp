#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    stack<int> st;
    for (int i = 1; i <= (int)order.size(); i++)
    {
        st.push(i);
        
        while (st.empty() == false && st.top() == order[answer])
        {
            st.pop();
            answer++;
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> order(n);
    for (int i = 0; i < n; i++)
    {
        cin >> order[i];
    }

    int answer = solution(order);

    cout << answer;

    return 0;
}