#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

typedef long long ll;

ll N;
ll c[MAX];

bool works(ll i) {
	ll prefix = 0;

	for (ll j = 0; j < N; j++) {
		prefix += c[(i + j) % N] - 1;
		if (prefix < 0) return false;
	}

	return true;
}

ll sum_sq(ll a, ll b) {
	ll result = 0;

	for (ll i = a; i <= b; i++) {
		result += i * i;
	}

	return result;
}

long long sumn2(long long v) {
  return v * (v + 1) * (2 * v + 1) / 6;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "160201";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		cin >> c[i];
	}
	
	ll start = -1;

	for (ll i = 0; i < N; i++) {
		if (works(i)) {
			start = i;
			break;
		}
	}

	rotate(c, c + start, c + N);


	ll ans = 0, ans1 = 0;
	ll extra = 0, e1 = 0;

	for (ll i = 0; i < N; i++) {
		ans += sum_sq(extra, extra + c[i] - 1);
		extra = max(0ll, extra + c[i] - 1);
	}

	cout << ans << "\n";
	
	return 0;
}