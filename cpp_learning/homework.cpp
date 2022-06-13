#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXN 100010

using namespace std;
ll N;
ll scores[MAXN];
ll scorespf[MAXN];
ll currmin[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "homework";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		cin >> scores[i];
	}

	currmin[N - 1] = scores[N - 1];
	scorespf[N - 1] = scores[N - 1]; 

	for (ll i = N - 2; i >= 0; i--) {
		scorespf[i] = scores[i] + scorespf[i + 1];

		currmin[i] = currmin[i + 1];
		if (scores[i] < currmin[i + 1]) {
			currmin[i] = scores[i];
		}
	}

	double max_score = 0;
	set<ll> poss_k;

	for (ll k = 1; k <= N - 2; k++) {
		ll points = scorespf[k];
		double score = (points - currmin[k]) / (N - k - 1);
		if (score > max_score) {
			max_score = score;
			poss_k.clear();
			poss_k.insert(k);
		}
		else if (score == max_score) {
			poss_k.insert(k); 
		}
	}

	for (auto i: poss_k) {
		cout << i << "\n";
	}

	return 0;
}