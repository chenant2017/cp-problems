#include <bits/stdc++.h>
#include <cmath>
#include <queue>

#define ll long long
#define MAX 20010

using namespace std;

struct Cow {
	ll start, end;
};

struct CompareCow {
	bool operator() (Cow& a, Cow& b) {
		return a.end > b.end;
	}
};

priority_queue<Cow, vector<Cow>, CompareCow> to_assign;

Cow cows[MAX];
ll chickens[MAX];

ll C, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "helpcross";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> C >> N;

	for (ll i = 0; i < C; i++) {
		cin >> chickens[i];
	}

	for (ll i = 0; i < N; i++) {
		ll start, end;
		cin >> cows[i].start >> cows[i].end;
	}

	sort(chickens, chickens + C);
	sort(cows, cows + N, [](auto& a, auto& b) {
		return (a.start < b.start ||
			   (a.start == b.start && a.end < b.end));
	});

	ll ans = 0;
	ll j = 0;

	for (ll i = 0; i < C; i++) {
		while (j < N && cows[j].start <= chickens[i]) {
			to_assign.push(cows[j]);
			j++;
		}

		while (!to_assign.empty() && to_assign.top().end < chickens[i]) {
			to_assign.pop();
		}

		if (!to_assign.empty()) {
			to_assign.pop();
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}