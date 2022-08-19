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
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> Q;

	for (ll q = 0; q < Q; q++) {
		cin >> t;
		t = " " + t;
		vector<pll> reach (t.size()); //index it can reach, index of string
		vector<pll> ans;

		for (ll i = 1; i < t.size(); i++) {
			reach[i].f = i;
			reach[i].s = -1;
		}

		cin >> N;
		vector<string> s (N + 1);

		for (ll i = 1; i <= N; i++) {
			cin >> s[i];
		}

		for (ll i = 1; i < t.size(); i++) {
			cout << "i " << i << "\n";
			for (ll j = 1; j <= N; j++) {
				ll dest = i + s[j].size() - 1;
				cout << s[j] << " " << t.substr(i, s[j].size()) << " " << dest << "\n";
				if (dest < t.size() &&
					s[j] == t.substr(i, s[j].size())) {

					for (ll k = i; k <= dest; k++) {
						if (dest > reach[k].f) {
							reach[k].f = dest;
							reach[k].s = j;
						}
					}
				}
			}
		}

		for (auto i: reach) {
			cout << i.f << " " << i.s << "\n";
		}
		cout << "\n";

		ll curr = 1;
		ll next;

		bool works = true;

		while (curr < t.size() - 1) {
			next = reach[curr].f;
			if (next == curr) {
				cout << "-1\n";
				works = false;
				break;
			}
			else {
				pll p = pll({reach[curr].s, curr});
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