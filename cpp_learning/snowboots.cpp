#include <bits/stdc++.h>

#define ll long long
#define f first
#define s second
#define MAX 260

using namespace std;

ll N, B;
ll snow[MAX];
pair<ll, ll> boots[MAX];
bool visited[MAX][MAX] = {false};
ll ans;

void dfs(ll b, ll pos) {
	if (visited[b][pos]) return;

	visited[b][pos] = true;

	if (b == B) return;
	if (boots[b].f < snow[pos]) return;
	if (pos == N - 1) {
		if (b < ans) {
			ans = b;
		}
		return;
	}

	for (ll i = 1; i <= boots[b].s; i++) {
		if (pos + i >= N) break;
		if (boots[b].f >= snow[pos + i]) {
			dfs(b, pos + i);
		}
	}

	dfs(b + 1, pos);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "snowboots";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);

	cin >> N >> B;
	ans = B + 1;

	for (ll i = 0; i < N; i++) {
		cin >> snow[i];
	}
	for (ll i = 0; i < B; i++) {
		cin >> boots[i].f >> boots[i].s;
	}

	dfs(0, 0);

	cout << ans << "\n";

	return 0;
}