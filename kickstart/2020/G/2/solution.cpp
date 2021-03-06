#define INPUT "1.in"
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
#define mst(a,b) memset((a),(b),sizeof(a))
#define mp(a,b) make_pair(a,b)
#define pi acos(-1)
#define pii pair<int,int>
#define pb push_back
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const ll mod = 1e9 + 7;

const int N = 1e3 + 5;
ll arr[N][N];

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    ll m = 0;

    for (int i = 0; i < n; i++) {
        ll s = 0;
        for (int j = 0; i + j < n; j++) {
            s += arr[j][i + j];
        }
        m = max(m, s);
    }

    for (int i = 0; i < n; i++) {
        ll s = 0;
        for (int j = 0; i + j < n; j++) {
            s += arr[i + j][j];
        }
        m = max(m, s);
    }

    cout << m;
}

int main() {
#ifdef READ_STDIN_FROM_FILE
    freopen(INPUT, "r", stdin);
#endif
    IOSBASE;
    int t, tc = 0;
    cin >> t;

    while (t--) {
        cout << "Case #" << ++tc << ": ";
        solve();
        cout << '\n';
    }
    return 0;
}
