#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//出现次数最多的是个单词
void top_k_words() {
    ifstream fin;
    fin.open("bible.txt");
    if (!fin) {
        cout << "can nont open file" << endl;
    }
    string s;
    map<string, int> countwords;
    while (true) {
        fin >> s;
        if (fin.eof()) {
            break;
        }
        countwords[s]++;
    }
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> countmax;
    for (auto& i : countwords) {
        countmax.push(make_pair(i.second, i.first));
        if (countmax.size() > 10) {
            countmax.pop();
        }
    }
    while (!countmax.empty()) {
        cout << countmax.top().first << " " << countmax.top().second << endl;
        countmax.pop();
    }
}


int main() {
    top_k_words();
    return 0;
}

