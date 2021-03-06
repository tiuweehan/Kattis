#define INPUT "2.in"
#define DEBUG 1

#include <bits/stdc++.h>

using namespace std;

#ifndef ENABLE_DEBUG
#define DEBUG 0
#endif
#if DEBUG == 1
#define DE(x) x;
#else
#define DE(x)
#endif

#define IOSBASE ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define umap unordered_map
#define uset unordered_set
#define mst(a, b) memset((a),(b),sizeof(a))
#define mp(a, b) make_pair(a,b)
#define pi acos(-1)
#define pii pair<int,int>
#define pb push_back
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const ll mod = 1e9 + 7;

ull M = 1e5;

void OnSort(vector<ull> &s) {
    vector<queue<int>> v(M);
    for (ull x : s) {
        v[x % M].push(x);
    }

    int j = 0;
    for (auto &q : v) {
        while (!q.empty()) {
            s[j++] = q.front();
            q.pop();
        }
    }

    for (ull x : s) {
        v[(x / M) % M].push(x);
    }

    for (auto &q : v) {
        while (!q.empty()) {
            s[j++] = q.front();
            q.pop();
        }
    }
}

void solve() {
    ull tc, n, a, b, c, x, y;
    cin >> tc;
    while (tc--) {
        cin >> n >> a >> b >> c >> x >> y;
        vector<ull> s(n);
        s[0] = a;
        for (int i = 1; i < n; i++) {
            s[i] = (s[i - 1] * b + a) % c;
        }

//        OnSort(s);
//        sort(s.begin(), s.end());

        vector<queue<int>> v(M);
        for (ull i : s) {
            v[i % M].push(i);
        }

        int j = 0;
        for (auto &q : v) {
            while (!q.empty()) {
                s[j++] = q.front();
                q.pop();
            }
        }

        for (ull i : s) {
            v[(i / M) % M].push(i);
        }

        ull ans = 0;
        for (auto &q : v) {
            while (!q.empty()) {
                ans = (ans * x + q.front()) % y;
                q.pop();
            }
        }

        cout << ans << '\n';
    }
}

int main() {
#ifdef READ_STDIN_FROM_FILE
    freopen(INPUT, "r", stdin);
#endif
    IOSBASE;
    solve();
    return 0;
}
