#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define f first
#define s second
#define si set<pair<ll, ll>>::iterator


bool cmp(const pair<ll, double>& a, const pair<ll, double>& b) {
	return a.s < b.s;
}

ll N, L;
set<pair<ll, ll>, decltype(&cmp)> rright(cmp);
set<pair<ll, ll>, decltype(&cmp)> lleft(cmp);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "meetings";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> L;

	ll total_weight = 0;

	for (ll i = 0; i < N; i++) {
		ll w, d;
		double x;
		cin >> w >> x >> d;
		if (d == 1)  {
			rright.insert(pair<ll, double>({w, x})); //going right
		}
		else {
			lleft.insert(pair<ll, double>({w, x}));
		}
		total_weight += w;
	}

	ll weight = 0;
	double time = 0;
	ll ans = 0;

	while (weight <= total_weight) { // got stuck in loop
		ll min_dist = pow(10, 10);
		vector<pair<si, si>> min_pairs; 

		auto ptrl = lleft.begin();
		
		for(auto ptrr = rright.begin(); ptrr != rright.end(); ptrr++) {
			while (ptrl != lleft.end() && ptrl->s <= ptrr->s) {
				ptrl++;
			}
			if (ptrl->s > ptrr->s) {
				double dist = ptrl->s - ptrr->s;
				if (dist < min_dist) {
					min_dist = dist;
					min_pairs.clear();
					min_pairs.push_back(pair<si, si>({ptrr, ptrl}));
				}
				else if (dist == min_dist) {
					min_pairs.push_back(pair<si, si>({ptrr, ptrl}));
				}
			}
		}

		time += min_dist / 2.0;

		for (auto& i: min_pairs) {
			ans++;
			double midpoint = (i.f->s + i.s->s) / 2.0;
			rright.insert(pair<ll, double>({i.s->f, midpoint}));
			rright.erase(*i.s);
			lleft.insert(pair<ll, double>({i.f->f, midpoint}));
			lleft.erase(*i.f);
		}

		while (rright.rbegin()->s + time >= L) {
			weight += rright.rbegin()->f;
			rright.erase(*rright.rbegin());
		}

		while (lleft.begin()->s - time <= 0) {
			weight += lleft.begin()->f;
			lleft.erase(*lleft.begin());
		}
	}

	cout << ans << "\n";


	return 0;
}