#include <bits/stdc++.h>
#define MAX 35
using namespace std;

typedef long long ll;

ll N, A, B;
string pastures[MAX];
ll times[MAX][MAX];

ll get_max(ll i, ll j) {
	//cout << i << " " << j << "\n";
	ll result = -1;

	times[i][j] = 0;

	for (ll p = i - 1; p >= 0; p--) {
		times[p][j] = times[p + 1][j] + (pastures[p][j] == pastures[p + 1][j] ? A : B);
		result = max(result, times[p][j]); 
	}

	for (ll q = j - 1; q >= 0; q--) {
		times[i][q] = times[i][q + 1] + (pastures[i][q] == pastures[i][q + 1] ? A : B);
		result = max(result, times[i][q]);
	}

	for (ll q = j + 1; q < N; q++) {
		times[i][q] = times[i][q - 1] + (pastures[i][q] == pastures[i][q - 1] ? A : B);
		result = max(result, times[i][q]);
	}

	for (ll p = i - 1; p >= 0; p--) {
		for (ll q = j + 1; q < N; q++) {
			//cout << p << " " << q << "\n";
			ll dist1 = times[p][q - 1] + (pastures[p][q] == pastures[p][q - 1] ? A : B);
			ll dist2 = times[p + 1][q] + (pastures[p][q] == pastures[p + 1][q] ? A : B);
			times[p][q] = min(dist1, dist2);
			result = max(result, times[p][q]);
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "distant";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> A >> B;

	for (ll i = 0; i < N; i++) {
		cin >> pastures[i];
	}

	ll ans = -1;

	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			ans = max(ans, get_max(i, j));
		}
	}

	cout << ans << "\n";
	
	return 0;
}