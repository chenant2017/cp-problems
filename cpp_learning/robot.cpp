#include <bits/stdc++.h>

#define ll long long
#define MAXN 45
#define f first
#define s second

using namespace std;

pair<ll, ll> moves[MAXN];
pair<ll, ll> goal;
ll N;
ll ans[MAXN] = {0};

void find_pairs(pair<ll, ll> curr, ll size, ll index) {
	if (index == N) {
		return;
	}

	find_pairs(curr, size, index + 1);

	curr.f += moves[index].f;
	curr.s += moves[index].s;
	size++;

	if (curr == goal) {
		ans[size]++;
	}

	find_pairs(curr, size, index + 1);
}		

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//string fname = "robot";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	cin >> goal.f >> goal.s;

	for (ll i = 0; i < N; i++) {
		cin >> moves[i].f >> moves[i].s;
	}

	find_pairs(pair<ll, ll>({0, 0}), 0, 0);

	for (ll k = 1; k <= N; k++) {
		cout << ans[k] << "\n";
	}

	return 0;
}