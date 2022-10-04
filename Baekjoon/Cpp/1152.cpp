#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    string w;
    vector<string> words;
    stringstream sstream(s);

    while (getline(sstream, w, ' ')) {
        words.push_back(w);
    }

    if (words.front() == "") {
        cout << words.size() - 1;
    }
    else {
        cout << words.size();
    }
}