//Silver 2022 Jan #1

#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pdl;
ll N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "soulmates";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		ll a, b;
		cin >> a >> b;

		if (a == b)  {
			cout << "0\n";
			continue;
		}

		vector<ll> seqa, seqb;

		seqa.push_back(a);
		seqb.push_back(b);

		while (a > 1) {
			if (a % 2 == 0) {
				a /= 2;
			}
			else {
				a++;
			}
			seqa.push_back(a);
		}

		while (b > 1) {
			if (b % 2 == 0) {
				b /= 2;
			}
			else {
				b--;
			}
			seqb.push_back(b);
		}

		ll ptra = 0;
		ll ptrb = 0;

		ll ans = -1;

		while (seqa[ptra] > seqb[0]) {
			ptra++;
		}

		while (ptra < seqa.size()) {
			while (ptrb < seqb.size() && 
				   seqb[ptrb + 1] >= seqa[ptra]) {
				ptrb++;
			}
			ll moves = ptra + ptrb + seqb[ptrb] - seqa[ptra];
			if (moves < ans || ans == -1) {
				ans = moves;
			}
			ptra++;
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}