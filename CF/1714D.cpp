#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll Q, N;
string t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "1714D";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);

	cin >> Q;

	for (ll q = 0; q < Q; q++) {
		cin >> t;
		t = " " + t;
		ll ts = t.size();
		vector<pll> reach (ts); //index it can reach, index of string
		vector<pll> ans;

		for (ll i = 1; i < ts; i++) {
			reach[i].f = -1;
			reach[i].s = -1;
		}

		cin >> N;
		vector<string> s (N + 1);

		for (ll i = 1; i <= N; i++) {
			cin >> s[i];
		}

		for (ll i = 1; i < ts; i++) {
			for (ll j = 1; j <= N; j++) {
				ll dest = i + s[j].size() - 1;
				if (dest < ts &&
					s[j] == t.substr(i, s[j].size())) {

					for (ll k = i; k <= dest; k++) {
						if (dest >= reach[k].f) {
							reach[k].f = dest;
							reach[k].s = j;
						}
					}
				}
			}
		}

		ll curr = 0;
		ll next;

		/*for (ll i = 1; i < ts; i++) {
			cout << i << " " << reach[i].f << " " << reach[i].s << "\n";
		}*/

		bool works = true;

		while (curr < ts - 1) {
			curr++;
			//cout << curr << "\n";
			next = reach[curr].f;
			if (next == -1) {
				cout << "-1\n";
				works = false;
				break;
			}
			else {
				pll p = pll({reach[curr].s, next - s[reach[curr].s].size() + 1});
				ans.push_back(p);
				curr = next;
			}
		}

		if (!works) continue;


		cout << ans.size() << "\n";
		for (auto i: ans) {
			cout << i.f << " " << i.s << "\n";
		}
	}
	
	return 0;
}