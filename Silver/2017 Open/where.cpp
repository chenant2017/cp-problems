#include <bits/stdc++.h>

#define ll long long
#define MAXN 25
#define f first
#define s second

using namespace std;

struct State {
	ll i, j, k, l;
};

ll N;
string image[MAXN];
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};

ll di[4] = {1, 0, 0, 0};
ll dj[4] = {0, 1, 0, 0};
ll dk[4] = {0, 0, -1, 0};
ll dl[4] = {0, 0, 0, -1};

bool states[MAXN][MAXN][MAXN][MAXN] = {false};

bool is_pcl(ll i, ll j, ll k, ll l) {
	bool visited[MAXN][MAXN] = {false};
	auto char1 = pair<char, ll>({'0', 0});
	auto char2 = pair<char, ll>({'0', 0});

	for (ll a = i; a <= k; a++) {
		for (ll b = j; b <= l; b++) {

			if (visited[a][b]) continue;

			if (char1.f == '0') {
				char1.f = image[a][b];
			}
			else if (char2.f == '0') {
				char2.f = image[a][b];
			}
			else if (image[a][b] != char1.f && image[a][b] != char2.f) {
				return false;
			}

			if (image[a][b] == char1.f) {
				char1.s++;
			}
			else {
				char2.s++;
			}

			queue<pair<ll, ll>> q;
			q.push(pair<ll, ll>({a, b}));

			while (!q.empty()) {
				auto curr = q.front(); 
				q.pop();
				if (visited[curr.f][curr.s]) continue;
				visited[curr.f][curr.s] = true;

				for (ll d = 0; d < 4; d++) {
					auto next = pair<ll, ll>({curr.f + dx[d], curr.s + dy[d]});
					if (next.f >= i && next.f <= k &&
						next.s >= j && next.s <= l &&
						image[next.f][next.s] == image[curr.f][curr.s] &&
						!visited[next.f][next.s]) {
						q.push(next);
					}  
				}
			}
		}
	}

	return (char1.f != '0' && char2.f != '0' &&
			((char1.s == 1 && char2.s > 1) || 
			 (char1.s > 1 && char2.s == 1))
		   );
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "where";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		cin >> image[i];
	}

	queue<State> statesq;
	State s;
	s.i = 0; s.j = 0; s.k = N - 1; s.l = N - 1;
	statesq.push(s);

	ll ans = 0;

	while (!statesq.empty()) {
		State c = statesq.front(); 
		statesq.pop();

		if (states[c.i][c.j][c.k][c.l]) continue;
		states[c.i][c.j][c.k][c.l] = true;

		if (is_pcl(c.i, c.j, c.k, c.l)) {
			ans++;
			for (ll p = c.i; p <= c.k; p++) {
				for (ll q = c.j; q <= c.l; q++) {
					for (ll r = p; r <= c.k; r++) {
						for (ll s = q; s <= c.l; s++) {
							states[p][q][r][s] = true;
						}
					}
				}
			}
		}

		for (ll d = 0; d < 4; d++) {
			State n;
			n.i = c.i + di[d];
			n.j = c.j + dj[d];
			n.k = c.k + dk[d];
			n.l = c.l + dl[d];

			if (!states[n.i][n.j][n.k][n.l] &&
				n.i <= n.k && n.j <= n.l) {
				statesq.push(n);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}