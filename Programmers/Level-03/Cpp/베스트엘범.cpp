#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

typedef struct _SNode {
    int index;
    int play;

    bool operator<(const _SNode& o) const {
        if (play == o.play) return index < o.index;
        return play > o.play;
    }
} SNode;

typedef struct _Node {
    string genre;
    int total_plays;

    vector<SNode> nodes;

    bool operator<(const _Node& o) {
        return total_plays > o.total_plays;
    }
} Node;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, vector<pii>> mp;
    for (int i = 0; i < genres.size(); i++) {
        if (mp.find(genres[i]) != mp.end()) {
            mp[genres[i]].push_back({ i,plays[i] });
        }
        else {
            mp[genres[i]] = { { i,plays[i] } };
        }
    }

    vector<Node> nds;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        int total_plays = 0;
        vector<SNode> snds;
        for (int i = 0; i < (*it).second.size(); i++) {
            total_plays += (*it).second[i].second;
            snds.push_back({ (*it).second[i].first,(*it).second[i].second });
        }

        sort(snds.begin(), snds.end());

        nds.push_back({ (*it).first,total_plays,snds });
    }

    sort(nds.begin(), nds.end());

    for (auto& i: nds) {
        if (i.nodes.size() <= 2) {
            for (int j = 0; j < i.nodes.size(); j++) {
                answer.push_back(i.nodes[j].index);
            }
        }
        else {
            for (int j = 0; j < 2; j++) {
                answer.push_back(i.nodes[j].index);
            }
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<string> genres;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        genres.push_back(input);
    }

    vector<int> plays;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        plays.push_back(input);
    }

    vector<int> answer = solution(genres, plays);

    for (auto& i: answer) {
        cout << i << ' ';
    }
}