/*
Life has never been fucking so easy.
Coding...
...WeiFeng
*/
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
// typedef __int64 i64;
typedef unsigned long long ull;
#define pq priority_queue
#define iscanf(a) scanf("%d", &a)
#define iscanf2(a, b) scanf("%d%d", &a, &b)
#define iscanf3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define mo(a, b) (((a) % (b) + (b)) % (b))
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) \
    sort(all(x)); \
    v.erase(unique(all(v)), end())
#define mp(a, b) make_pair(a, b)
#define clr(x, i) memset(x, i, sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l, m, rt << 1
#define rch m + 1, r, rt << 1 | 1
#define rep(i, x, n) for (int i = x; i < n; i++)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;

// gcd lcm
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int lcm(int a, int b) { return a / gcd(a, b) * b; }

const int maxn = 105;
int a[maxn << 1];
int dp[maxn << 1][maxn << 1];
// (m, r) (r, n)
// m * r * n
int main(int argc, char const *argv[]) {
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int n;
    while (scanf("%d", &n) == 1) {
        clr(a, 0), clr(dp, -1);
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d\n", &x);
            a[i] = x;
            a[i + n] = x;
        }
        // init dp
        for (int i = 0; i < 2 * n; i++) dp[i][i] = a[i];
        // dp
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i < 2 * n - 1; i++) {
                int j = i + len;
                for (int k = i; k < j; k++) {
                    dp[i][j] = Max(dp[i][j], dp[i][k] * dp[k + 1][j] *
                                                 a[(i - 2) % (2 * n)]);
                }
            }
        }
    }
    return 0;
}
