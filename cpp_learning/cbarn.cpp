#include <bits/stdc++.h>

#define ll long long
#define MAXN 1010
using namespace std;

ll N;
ll barn[MAXN];
unordered_set<ll> sources;
unordered_set<ll> not_emptied;

ll get_energy(ll i) {
	cout << "NEW I " << i << "\n"; 
	ll d[MAXN] = {0};
	ll energy = 0;

	queue<ll> to_put;

	for (ll j = 0; j < 3 * N; j++) {
		if (barn[i] + d[i] == 0) {
			to_put.push(i);
		}

		i = (i - 1 + 5 * N) % N;

		if (sources.find(i) != sources.end()) {
			while (!to_put.empty() && barn[i] + d[i] > 0 && not_emptied.find(i) != not_emptied.end()) {
				ll a = to_put.front();
				to_put.pop();
				d[i]--;
				d[a]++;
				energy += pow((a - i + 5 * N) % N, 2);
				cout << a << " " << (a - i + 5 * N) % N << "\n";

				if (barn[i] + d[i] == 0) {
					not_emptied.erase(i);
				}
			}
		}
	}
	return energy;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cbarn";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		cin >> barn[i];
		if (barn[i] > 0) {
			sources.insert(i);
			not_emptied.insert(i);
		}
	}

	ll ans = pow(N, 4);

	for (ll i = 0; i < N; i++) {
		if (barn[i] == 0) {
			ll energy = get_energy(i);
			cout << "energy is " << energy << " for i " << i << "\n";
			if (energy < ans) {
				ans = energy;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}