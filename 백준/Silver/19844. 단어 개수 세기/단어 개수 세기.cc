#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    getline(cin, s);
    regex re1(R"([\s-]+)");
    regex re2(R"(([cjnmtsld]|qu)'[aeiouh].*)");
    auto itr = sregex_token_iterator(s.begin(), s.end(), re1, -1);
    auto end = sregex_token_iterator();

    int cnt = 0;
    for (; itr != end; itr++) {
        auto word = itr->str();
        if (regex_match(word.begin(), word.end(), re2)) cnt += 2;
        else cnt += 1;
    }
    cout << cnt;
}