#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define f first
#define s second
#define si set<pair<ll, double>>::iterator


bool cmp(const pair<ll, double>& a, const pair<ll, double>& b) {
	return a.s < b.s;
}

ll N, L;
set<pair<ll, double>, decltype(&cmp)> rright(cmp);
set<pair<ll, double>, decltype(&cmp)> lleft(cmp);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "meetings";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> L;

	double total_weight = 0;

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

	double weight = 0;
	double time = 0;
	ll ans = 0;

	while (weight < total_weight / 2) { // got stuck in loop
		//cout << weight << " " << time << "\n";

		for (auto& i: rright) {
			cout << i.f << " " << i.s << "   ";
		}
		cout << "\n";

		for (auto& i: lleft) {
			cout << i.f << " " << i.s << "   ";
		}

		cout << "\n\n\n";

		double min_dist = pow(10, 10);
		vector<pair<si, si>> min_pairs; 

		auto ptrl = lleft.begin();
		
		for(auto ptrr = rright.begin(); ptrr != rright.end(); ptrr++) {
			while (ptrl != lleft.end() && ptrl->s <= ptrr->s) {
				ptrl++;
			}
			if (ptrl->s - time > ptrr->s + time) {
				double dist = ptrl->s - time - (ptrr->s + time);
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

		//cout << min_dist << " mindist\n";
		time += min_dist / 2.0;

		for (auto& i: min_pairs) {
			ans++;
			double midpoint = (i.f->s + i.s->s) / 2.0;

			cout << midpoint - min_dist / 2.0 << " yYYS\n";
			rright.insert(pair<ll, double>({i.s->f, midpoint - min_dist / 2.0}));
			rright.erase(i.f);
			lleft.insert(pair<ll, double>({i.f->f, midpoint + min_dist / 2.0}));
			lleft.erase(i.s);
		}

		//cout <<"hi\n";

		while (!rright.empty() && rright.rbegin()->s + time >= L) {
			weight += rright.rbegin()->f;
			rright.erase(*rright.rbegin());
		}

		while (!lleft.empty() && lleft.begin()->s - time <= 0) {
			weight += lleft.begin()->f;
			lleft.erase(*lleft.begin());
		}
	}

	cout << ans << "\n";


	return 0;
}