#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, len;
    vector <string> v;
    vector <char> c;
    int comp = 0;

    cin >> n >> len;

    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for(int i = 0; i < len; i++){
        int arr[4] = {0, 0, 0, 0};
        for(int j = 0; j < n; j++){
            switch (v[j][i]){
            case 'A':
                arr[0]++;
                break;
            case 'C':
                arr[1]++;
                break;
            case 'G':
                arr[2]++;
                break;
            case 'T':
                arr[3]++;
                break;
            }
        }
        int max = 0;
        int idx;
        for(int j = 0; j < 4; j++){
            if(arr[j] > max){
                max = arr[j];
                idx = j;
            }
        }

        switch (idx){
        case 0:
            c.push_back('A');
            break;
        case 1:
            c.push_back('C');
            break;
        case 2:
            c.push_back('G');
            break;
        case 3:
            c.push_back('T');
            break;
        }

    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < len; j++){
            if(c[j] != v[i][j])
                comp++;
        }
    }
    for(int i = 0; i < c.size(); i++){
        cout << c[i];
    }
    cout<< "\n" << comp;
}