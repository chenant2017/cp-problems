#include <bits/stdc++.h>

#define ll long long
#define f first
#define s second
#define MAX 510

using namespace std;

ll M, N;
ll elevs[MAX][MAX];
bool waypts[MAX][MAX];
ll n_waypts = 0;
ll waypti;
ll wayptj;
ll di[4] = {0, 0, 1, -1};
ll dj[4] = {1, -1, 0, 0};

bool works(ll D) {
	if (D < 0) {
		return false;
	}

	queue<pair<ll, ll>> q;
	q.push(pair<ll, ll>({waypti, wayptj}));
	ll vwaypts = 0;
	bool visited[MAX][MAX] = {false};

	while (!q.empty()) {
		auto curr = q.front();
		q.pop();

		if (visited[curr.f][curr.s]) continue;

		visited[curr.f][curr.s] = true;
		if (waypts[curr.f][curr.s]) vwaypts++;

		for (ll d = 0; d < 4; d++){
			pair<ll, ll> next = pair<ll, ll>({curr.f + di[d], curr.s + dj[d]});
			if (next.f >= 0 && next.f < M &&
				next.s >= 0 && next.s < N &&
				!visited[next.f][next.s] &&
				abs(elevs[next.f][next.s] - elevs[curr.f][curr.s]) <= D) {
				q.push(next);
			}
		}
	}

	return vwaypts == n_waypts;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "ccski";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> M >> N;

	for (ll i = 0; i < M; i++) {
		for (ll j = 0; j < N; j++) {
			cin >> elevs[i][j];
		}
	}

	for (ll i = 0; i < M; i++) {
		for (ll j = 0; j < N; j++) {
			cin >> waypts[i][j];
			if (waypts[i][j]) {
				n_waypts++;
				waypti = i;
				wayptj = j;
			}
		}
	}

	ll mind = -1;
	ll maxd = pow(10, 9) + 1;

	while (maxd - mind > 1) {
		ll mid = (mind + maxd) / 2;
		if (works(mid)) {
			maxd = mid;
		}
		else {
			mind = mid;
		}
	}

	cout << maxd << "\n";

	return 0;
}