#include <bits/stdc++.h>
#define MAX 1010
#define f first
#define s second
using namespace std;

typedef long long ll;

ll N;
ll beauty[MAX][MAX];

ll dr[4] = {0, 1, 0, 1};
ll dc[4] = {0, 0, 1, 1};

ll cr1[6] = {0, 0, 1, 1, 1, 1};  
ll cc1[6] = {0, 0, 0, 0, 0, 1};
ll cr2[6] = {1, 0, 0, 1, 0, 0};
ll cc2[6] = {1, 1, 0, 1, 1, 1};

pair<ll, ll> get_next(ll i, ll j) {
	pair<ll, ll> result;
	if (j < N - 2) {
		result.f = i;
		result.s = j + 1;
	}	
	else {
		result.f = i + 1;
		result.s = 0;
	}
	return result;
}

bool has_2(vector<vector<bool>> next, ll i, ll j) {
	//cout << i << " " << j << "\n";
	if (i == -1 || j == -1) return true;
	ll count = 0;
	for (ll d = 0; d < 4; d++) {
		if (next[i + dr[d]][j + dc[d]]) {
 			count++;
 		}
	} 
	return (count == 2);
}

 ll solve(ll i, ll j, vector<vector<bool>> curr) {
 	//cout << i << " " << j << " A\n";
 	if (i == N - 1) {
 		ll lala = 0;
 		for (ll p = 0; p < N; p++) {
 			for (ll q = 0; q < N; q++) {
 				//cout << curr[p][q] << " ";
 				if (curr[p][q]) {
 					lala += beauty[p][q];
 				}
 			}
 			//cout << "\n";
 		}
 		//cout << "lala is " << lala << "\n";
 		return 0;
 	}

 	ll ans = 0;
 	ll old = 0;
 	
 	for (ll d = 0; d < 4; d++) {
 		if (curr[i + dr[d]][j + dc[d]]) {
 			old++;
 		}
 	}

 	for (ll x = 0; x < 6; x++) {
 		ll b = 0;
 		ll novel = 0;
 		auto next = curr;
 		if (!curr[i + cr1[x]][j + cc1[x]]) {
 			next[i + cr1[x]][j + cc1[x]] = true; 
 			novel++;
 			b += beauty[i + cr1[x]][j + cc1[x]];
 		}
 		if (!curr[i + cr2[x]][j + cc2[x]]) {
 			next[i + cr2[x]][j + cc2[x]] = true; 
 			novel++;
 			b += beauty[i + cr2[x]][j + cc2[x]];
 		}

 		if (old + novel == 2 && 
 			has_2(next, i - 1, j) &&
 			has_2(next, i, j - 1)) { //must check above and right squares also ok
 			auto p2 = get_next(i, j);
 			ll s = solve(p2.f, p2.s, next);
 			b += s;
 			if (b > ans) {
	 			ans = b;
	 		}
 		}
 	}

 	return ans;
 }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "spaced";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			cin >> beauty[i][j];
		}
	}

	vector<vector<bool>> start;
	for (ll i = 0; i < N; i++) {
		vector<bool> v;
		for (ll j = 0; j < N; j++) {
			v.push_back(false);
		}
		start.push_back(v);
	}

	ll ans = solve(0, 0, start);

	cout << ans << "\n";

	return 0;
}