#include <bits/stdc++.h>

#define ll long long
#define f first
#define s second
#define MAXN 510

using namespace std;

ll N;
ll elevs[MAXN][MAXN];
ll threshold;
ll di[4] = {0, 0, 1, -1};
ll dj[4] = {1, -1, 0, 0};

bool works(ll D) {
	if (D < 0) {
		return false;
	}

	bool visited[MAXN][MAXN] = {false};
	ll max_vcount = 0;

	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {

			if (!visited[i][j]) {
				ll vcount = 0;

				queue<pair<ll, ll>> q;
				q.push(pair<ll, ll>({i, j}));

				while (!q.empty()) {
					auto curr = q.front();
					q.pop();
					if (visited[curr.f][curr.s]) continue;
					visited[curr.f][curr.s] = true;
					vcount++;

					for (ll d = 0; d < 4; d++) {
						pair<ll, ll> next = pair<ll, ll>({curr.f + di[d], curr.s + dj[d]});
						if (next.f >= 0 && next.f < N && 
							next.s >= 0 && next.s < N && 
							abs(elevs[next.f][next.s] - elevs[curr.f][curr.s]) <= D &&
							!visited[next.f][next.s]) {
							q.push(next);
						}
					}
				}

				if (vcount > max_vcount) max_vcount = vcount;
			}
		}
	}
	return max_vcount >= threshold;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "tractor";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			cin >> elevs[i][j];
		}
	}

	ll minD = -1;
	ll maxD = pow(10, 6);

	if (N % 2 == 0) threshold = pow(N, 2) / 2;
	else threshold = pow(N, 2) / 2 + 1;

	while (maxD - minD > 1) {
		ll mid = (minD + maxD) / 2;

		if (works(mid)) {
			maxD = mid;
		}
		else {
			minD = mid;
		}
	}

	cout << maxD << "\n";

	return 0;
}