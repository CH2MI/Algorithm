#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>& A, const pair<int, int>& B) {
    if (A.first == B.first)
        return A.second < B.second;
    return A.first < B.first;
}

int main() {
    vector<pair<int, int>> X, Y;
    int N;
    cin >> N;
    while (N--) {
        int x, y; cin >> x >> y;
        X.push_back({x, y});
        Y.push_back({y, x});
    }
    
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    
    int sum = 0;
    for (int i = 0; i < X.size(); i += 2) {
        sum += X[i + 1].second - X[i].second + Y[i + 1].second - Y[i].second;
    }
    cout << sum;
}