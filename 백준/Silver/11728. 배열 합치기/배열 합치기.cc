#include <bits/stdc++.h>
using namespace std;

int main() 
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, M; cin >> N >> M;
    vector<int> v(N + M);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());
    for (int i : v) cout << i << ' '; 
  
}