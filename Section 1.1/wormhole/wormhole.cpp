/*
 ID: komron_1
 LANG: C++
 PROG: wormhole
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int x[20], y[20];
int teleport[20];
int next[20];

bool is_cycled() {
    int curpos;
    for (int i = 1; i<=n; i++) {
        curpos = i;
        for (int j=0; j<n; j++) {
            curpos = next[teleport[curpos]];
        }

        if (curpos != 0) {
            return true;
        }
    }

    return false;
}

int solve() {
    int cnt = 0, i;
    for (i = 1; i <= n; i++)
    {
        if (teleport[i] == 0) {
            break;
        }
    }

    if (i > n) {
        return is_cycled();
    }

    for (int j = i+1; j<=n; j++) {
        if (teleport[j] == 0) {
            teleport[i] = j;
            teleport[j] = i;
            cnt += solve();
            teleport[i] = 0;
            teleport[j] = 0;
        }
    }

    return cnt;
}

int main () {

    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out","w",stdout);
    int i;
    cin >> n;

    for (i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }

    for (i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (x[i] < x[j] && y[i] == y[j] &&
                (next[i] == 0 || x[next[i]] > x[j])) {
                    next[i] = j;
                }
        }
    }

    cout << solve() << endl;
    return 0;
}
