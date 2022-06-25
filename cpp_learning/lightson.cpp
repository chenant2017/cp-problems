#include <bits/stdc++.h>

#define ll long long
#define MAXN 110
#define f first
#define s second

using namespace std;

struct pair_hash {
	size_t operator() (const pair<ll, ll>& p) const {
		return p.first * 1000 + p.second;
	}
};

ll N, M;
unordered_map<pair<ll, ll>, vector<pair<ll, ll>>, pair_hash> switches;
bool visited[MAXN][MAXN] = {false};
bool lit[MAXN][MAXN] = {false};
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {-1, 1, 0, 0};

ll get_rooms_lit() {
	queue<pair<ll, ll>> q;
	q.push(pair<ll, ll>({1, 1}));
	lit[1][1] = true;
	ll rooms_lit = 1;

	while (!q.empty()) {
		pair<ll, ll> curr = q.front();
		q.pop();

		if (visited[curr.f][curr.s]) {
			continue;
		}

		visited[curr.f][curr.s] = true;

		ll newx, newy;

		for (auto& c: switches[curr]) {
			if (!lit[c.f][c.s]) {
				lit[c.f][c.s] = true;
				rooms_lit++;
			}
			
			for (ll d = 0; d < 4; d++) {
				newx = c.f + dx[d];
				newy = c.s + dy[d];

				if (1 <= newx && newx <= N &&
					1 <= newy && newy <= N) {
					if (visited[newx][newy] && !visited[c.f][c.s]) {
						q.push(c);
						break;
					}
				}
			}
		}

		for (ll d = 0; d < 4; d++) {
			newx = curr.f + dx[d];
			newy = curr.s + dy[d];

			if (1 <= newx && newx <= N &&
				1 <= newy && newy <= N) {
				if (lit[newx][newy] && !visited[newx][newy]) {
					q.push(pair<ll, ll>({newx, newy}));
				}
			}
		}
	}
	return rooms_lit;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "lightson";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

	for (ll i = 0; i < M; i++) {
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		switches[pair<ll, ll>({x, y})].push_back(pair<ll, ll>({a, b}));
	}

	ll rooms_lit = get_rooms_lit();

	cout << rooms_lit << "\n";

	return 0;
}