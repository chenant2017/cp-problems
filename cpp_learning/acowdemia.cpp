//2021 Silver Open #3

#include <bits/stdc++.h>

#define ll long long
#define MAXN 100010

using namespace std;

ll N, K, L;
ll citations[MAXN];

bool works(ll H) {
	ll good = 0;
	priority_queue<ll, vector<ll>, greater<ll>> to_cite;

	for (ll i = 0; i < N; i++) {
		if (citations[i] >= H) {
			good++;
		}
		else if (H - citations[i] <= K) {
			to_cite.push(H - citations[i]);
		}
	}

	if (good >= H) return true;
	if (to_cite.size() < H - good) return false;

	ll cited = 0;

	while (!to_cite.empty()) {
		if (cited + to_cite.top() <= K * L) {
			cited += to_cite.top();
			to_cite.pop();
			good++;
		}
		else {
			break;
		}
	}

	return good >= H;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//string fname = "acowdemia";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K >> L;

	for (ll i = 0; i < N; i++) {
		cin >> citations[i];
	}

	ll minH = 0;
	ll maxH = N + 1;

	while (maxH - minH > 1) {
		ll mid = (minH + maxH) / 2;
		if (works(mid)) {
			minH = mid;
		}
		else {
			maxH = mid;
		}
	}

	cout << minH << "\n";

	return 0;
}