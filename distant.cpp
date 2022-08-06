#include <bits/stdc++.h>
#define MAXN 35
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

string pastures[MAXN];
ll N, A, B;

ll df[2] = {0, 1};
ll ds[2] = {1, 0};

ll bfs(pll start, ll ans) {
	//cout << start.f << " " << start.s << " START\n";
	ll visited[MAXN][MAXN];
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			visited[i][j] = -1;
		}
	}
	queue<pll> q;
	q.push(start);

	while(!q.empty()) {
		auto curr = q.front();
		q.pop();

		if (visited[curr.f][curr.s] != -1) continue;

		//cout << "visiting " << curr.f << " " << curr.s << "\n";

		ll dist = -1;
		if (curr != start) {
			//cout << "hi " << curr.f.f << " " << curr.f.s << " " << curr.s << "\n";
			for (ll d = 0; d < 2; d++) {
				if (0 <= curr.f - df[d] && curr.f - df[d] < N &&
					0 <= curr.s - ds[d] && curr.s - ds[d] < N) {

					ll dist2;
					if (pastures[curr.f - df[d]][curr.s - ds[d]] == 
						pastures[curr.f][curr.s]) {
						
						dist2 = visited[curr.f - df[d]][curr.s - ds[d]] + A;
					}
					else {
						dist2 = visited[curr.f - df[d]][curr.s - ds[d]] + B;
					}

					if (dist2 < dist || dist == -1) {
						//cout << "hey\n";
						dist = dist2;
					}
				}
			}

			visited[curr.f][curr.s] = dist;
			//cout << curr.s + ddist << " " << ans << "\n";
			//cout << curr.s << " " << ddist << " dist\n";
			//cout << dist << " dist" << "\n";

			if (dist > ans) {
				ans = dist;
				//cout << "new ans " << ans << "\n";
			}
		}
		else {
			dist = 0;
			visited[curr.f][curr.s] = 0;
		}

		for (ll d = 0; d < 2; d++) {
			if (0 <= curr.f + df[d] && curr.f + df[d] < N &&
				0 <= curr.s + ds[d] && curr.s + ds[d] < N &&
				visited[curr.f + df[d]][curr.s + ds[d]] == -1) {
				q.push(pll({curr.f + df[d], curr.s + ds[d]}));
			}
		}
	}

	return ans;
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
			pll start = pll({i, j});
			ans = bfs(start, ans);
		}
	}

	cout << ans << "\n";
	
	return 0;
}