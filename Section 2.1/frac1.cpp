/*
 ID: komron_1
 LANG: C++
 PROG: frac1
*/

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

bool check(pair<pair <int, int>, double> a, pair<pair <int, int>, double> b) {
    return a.second < b.second;
}

int main () {
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);

    vector < pair<pair <int, int>, double> > vals;

    int n, i;
    cin >> n;

    pair<int, int> temp;

    for (i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (gcd(i,j) == 1) {
                temp = make_pair(j,i);
                vals.push_back( make_pair(temp, (double)j/i));
            }
        }
    }

    sort (vals.begin(), vals.end(), check);

    for (i=0; i<vals.size(); i++) {
        cout << vals[i].first.first << "/" << vals[i].first.second << endl;
    }
    return 0;
}
