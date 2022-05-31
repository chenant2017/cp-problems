#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

struct var {
	int even = 0;
	int odd = 0;
	int total() {
		return even + odd;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string str = "geteven";
	freopen((str + ".in").c_str(), "r", stdin);
	freopen((str + ".out").c_str(), "w", stdout);
	
	int N;
	cin >> N;
	
	var vars[26];
	
	string c;
	int value;
	
	for (int i = 0; i < N; i++) {
		cin >> c >> value;
		if (value % 2 == 0) {
			vars[c[0]-'A'].even++;
		}
		else {
			vars[c[0]-'A'].odd++;
		}
	}
	
	var b = vars['B' - 'A'];
	var e = vars['E' - 'A'];
	var s = vars['S' - 'A'];
	var i = vars['I' - 'A'];
	var g = vars['G' - 'A'];
	var o = vars['O' - 'A'];
	var m = vars['M' - 'A'];
	
	var goes[4] = {g, o, e, s};
	
	int poss = b.total() * e.total() * s.total() * i.total() * g.total() * o.total() * m.total();
	
	int goes_all_odd = g.odd * o.odd * e.odd * s.odd;
	int goes_all_even = g.even * o.even * e.even * s.even;
	int goes_odd = 0;
	
	int g_o;
	
	for (int x = 0; x < 4; x++) {
		g_o = goes[y].even;
		for (int y = 0; y < 4; y++) {
			if (x != y) {
				g_o *= goes[y].odd;
			}
		}
		goes_odd += g_o;
	}
	
	for (int x = 0; x < 4; x++) {
		g_o = 1;
		for (int y = 0; y < 4; y++) {
			if (x == y) {
				g_o *= goes[y].odd;
			}
			else {
				g_o *= goes[y].even;
			}
		}
		goes_odd += g_o;
	}
	
	int bi_odd = b.even * i.odd + b.odd * i.even;
	int odd = bi_odd * goes_odd * m.odd;
	int ans = poss - odd;
	
	cout << ans << "\n";
	
	return 0;
}