#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
    // i used the solution in the video tutorial link in this repository
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int p = 0;
		int r = 1;
		for (int i = k - 2; i >= 0; i--) {
			if (a[i] == a[k - 1]) {
				p++;
			}
		}
		for (int i = k; i < n; i++) {
			if (a[i] == a[k - 1]) {
				r++;
			} else {
				break;
			}
		}
		if (r == 1) {
			cout << 1 << '\n';
			continue;
    }
    long long max_num = p + 1 > r - 1 ? p + 1 : r - 1;
    long long min_num = p + 1 < r - 1 ? p + 1 : r - 1;
    int y = p + r;
    long long e = 1;
    int w = 1;
    while (y > max_num) {
    	e *= y;
    	if (e % w == 0 && w <= min_num) {
    		e /= w;
    		w++;
      }
      y--;
    }
    while (w <= min_num) {
    	e /= w;
    	w++;
    }
    cout << e << '\n';
	}
 	return 0;
}
