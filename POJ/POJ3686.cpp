#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 50 + 5;
int love[maxn][maxn];
int ex_girl[maxn];
int ex_boy[maxn];
bool vis_girl[maxn];
bool vis_boy[maxn];
int match[maxn];
int slack[maxn];
int n, m, T;
bool dfs(int girl) {
  vis_girl[girl] = true;
  for (int boy = 0; boy < n; ++boy) {
    if (vis_boy[boy]) continue;
    int d = ex_girl[girl] + ex_boy[boy] - love[girl][boy];
    if (d == 0) {
      vis_boy[boy] = true;
      if (match[boy] == -1 || dfs(match[boy])) {
        match[boy] = girl;
        return true;
      }
    } else {
      slack[boy] = min(slack[boy], d);
    }
  }
  return false;
}
int KM() {
  memset(match, -1, sizeof(match));
  memset(ex_boy, 0, sizeof(ex_boy));
  for (int i = 0; i < n; ++i) {
    ex_girl[i] = love[i][0];
    for (int j = 1; i < m; ++j) {
      ex_girl[i] = max(ex_girl[i], love[i][j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    fill(slack, slack + n, inf);
    while (true) {
      memset(vis_girl, 0, sizeof(vis_girl));
      memset(vis_boy, 0, sizeof(vis_boy));
      if (dfs(i)) break;
      int d = inf;
      for (int j = 0; j < n; ++j) {
        if (!vis_boy[j]) d = min(d, slack[j]);
      }
      for (int j = 0; j < n; ++j) {
        if (vis_girl[j]) ex_girl[j] -= d;
        if (vis_boy[j]) ex_boy[j] += d;
        else slack[j] -= d;
      }
    }
  }
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    ret += love[match[i]][i];
  }
  return ret;
}
double ans;
int main() {
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", &love[i][j]);
      }
    }

    printf("%.f\n", ans);
  }
  return 0;
}
