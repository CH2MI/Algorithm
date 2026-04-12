#include <bits/stdc++.h>
using namespace std;

#define FOR_START \
    for (int w = 0; w < W; w++) { \
        for (int v = 0; v < V; v++) { \
            for (int u = 0; u < U; u++) { \
                for (int t = 0; t < T; t++) { \
                    for (int s = 0; s < S; s++) { \
                        for (int r = 0; r < R; r++) { \
                            for (int q = 0; q < Q; q++) { \
                                for (int p = 0; p < P; p++) { \
                                    for (int o = 0; o < O; o++) { \
                                        for (int n = 0; n < N; n++) { \
                                            for (int m = 0; m < M; m++) {

#define FOR_END \
                                            } \
                                        } \
                                    } \
                                } \
                            } \
                        } \
                    } \
                } \
            } \
        } \
    }

int d0[22] = {-1, 1};
int d1[22] = {0, 0, -1, 1};
int d2[22] = {0, 0, 0, 0, -1, 1};
int d3[22] = {0, 0, 0, 0, 0, 0, -1, 1};
int d4[22] = {0, 0, 0, 0, 0, 0, 0, 0, -1, 1};
int d5[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1};
int d6[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1};
int d7[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1};
int d8[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1};
int d9[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1};
int d10[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1};

class Tomato{
public:
    Tomato(int M, int N, int O, int P, int Q, int R, int S, int T, int U, int V, int W) {
        arr = new int[M * N * O * P * Q * R * S * T * U * V * W];
        this->M = M;
        this->N = N;
        this->O = O;
        this->P = P;
        this->Q = Q;
        this->R = R;
        this->S = S;
        this->T = T;
        this->U = U;
        this->V = V;
        this->W = W;
    }
    ~Tomato() {
        delete[] arr;
    }

    int& get(int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w) {
        int idx = ((((((((((m * N + n) * O + o) * P + p) * Q + q) * R + r) * S + s) * T + t) * U + u) * V + v) * W + w);
        return arr[idx];
    }

private:
    int* arr;
    int M, N, O, P, Q, R, S, T, U, V, W;
};



int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int M, N, O, P, Q, R, S, T, U, V, W;
    cin >> M >> N >> O >> P >> Q >> R >> S >> T >> U >> V >> W;
    Tomato tomato(M, N, O, P, Q, R, S, T, U, V, W);

    queue<array<int, 12>> qq;

    FOR_START
        int a;
        cin >> a;
        if (a == 1) qq.push({m, n, o, p, q, r, s, t, u, v, w, 1});
        else if (a == -1) tomato.get(m, n, o, p, q, r, s, t, u, v, w) = -1;
    FOR_END

    while (!qq.empty()) {
        auto [m, n, o, p, q, r, s, t, u, v, w, cnt] = qq.front();
        qq.pop();

        if (m < 0 || m >= M || n < 0 || n >= N || o < 0 || o >= O || p < 0 || p >= P ||
            q < 0 || q >= Q || r < 0 || r >= R || s < 0 || s >= S || t < 0 || t >= T ||
            u < 0 || u >= U || v < 0 || v >= V || w < 0 || w >= W)
            continue;
        if (tomato.get(m, n, o, p, q, r, s, t, u, v, w)) continue;

        tomato.get(m, n, o, p, q, r, s, t, u, v, w) = cnt;

        for (int i = 0; i < 22; i++) {
            qq.push({
                m + d0[i], n + d1[i], o + d2[i], p + d3[i], q + d4[i], r + d5[i],
                s + d6[i], t + d7[i], u + d8[i], v + d9[i], w + d10[i], cnt + 1
            });
        }
    }

    int ans = 1;
    int mx = 0;
    FOR_START
        ans &= !!tomato.get(m, n, o, p, q, r, s, t, u, v, w);
        mx = max(mx, tomato.get(m, n, o, p, q, r, s, t, u, v, w));
    FOR_END

    if (ans) cout << mx - 1;
    else cout << -1;
}
