//Silver 2021 Jan #2

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, Q;
string fence;

vector<ll> solve(ll a, ll b, int dir) {
	vector<ll> result;
	ll strokes = 0;
	stack<ll> mono;
	if (dir == 1) {
		for (ll i = a; i <= b; i++) {
			if (mono.empty() || mono.top() < fence[i]) {
				mono.push(fence[i]);
				strokes++;
			}
			else {
				while (!mono.empty() && mono.top() > fence[i]) {
					mono.pop();
				}
				if (mono.empty() || mono.top() < fence[i]) {
					mono.push(fence[i]);
					strokes++;
				}
			}
			result.push_back(strokes);
		}
		return result;
	}
	else {
		for (ll i = a; i >= b; i--) {
			if (mono.empty() || mono.top() < fence[i]) {
				mono.push(fence[i]);
				strokes++;
			}
			else {
				while (!mono.empty() && mono.top() > fence[i]) {
					mono.pop();
				}
				if (mono.empty() || mono.top() < fence[i]) {
					mono.push(fence[i]);
					strokes++;
				}
			}
			result.push_back(strokes);
		}
		return result;
	}
}

ll get(vector<ll>& v, ll i) {
	if (i < 0 || i >= v.size()) {
		return 0;
	}
	else {
		return v[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "notime";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> Q;
	cin >> fence;

	vector<ll> forward = solve(0, N - 1, 1);
	vector<ll> backward = solve(N - 1, 0, -1);

	for (ll i = 0; i < Q; i++) {
		ll a, b;
		cin >> a >> b;
		cout << get(forward, a - 2) + get(backward, N - 1 - b) << "\n";
		//cout << solve(0, a - 2) + solve(b, N - 1) << "\n";
	}
	
	return 0;
}