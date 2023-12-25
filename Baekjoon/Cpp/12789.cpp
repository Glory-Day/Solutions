#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int cache = 1;
    stack<int> st;
    while(n--) {
        int a;
        cin >> a;
        
        if (a == cache) {
            cache++;
        }
        else {
            st.push(a);
        }
        
        while (!st.empty() && st.top() == cache) {
            st.pop();
			cache++;
		}
	}
	
	if(st.empty()) {
        cout << "Nice";
    } 
	else {
        cout << "Sad";
    }
}