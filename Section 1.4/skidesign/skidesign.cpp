/*
 ID: komron_1
 LANG: C++
 PROG: skidesign
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main () {

    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);

    int n, a[1001]={0};
    cin >> n;

    int i;

    for (i = 0; i<n; i++) {
        cin >> a[i];
    }

    // sort(a, a + n);

    int cnt = 0, res = 10000000;
    int high, low;
    for (i = 0; i < 84; i++) {
        high = i + 17;
        low = i;
        cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] < low) {
                cnt += (low - a[j]) * (low - a[j]);
            }

            if (a[j] > high) {
                cnt += (a[j] - high) * (a[j] - high);
            }
        }

        if (cnt < res) res = cnt;

    }

    cout << res << endl;
    return 0;
}
