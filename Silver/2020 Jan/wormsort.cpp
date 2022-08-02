#include <bits/stdc++.h>

#define ll long long
#define MAX 100010	

using namespace std;

ll N, M;
ll cows[MAX];

vector<pair<ll, ll>> adj[MAX];

unordered_set<ll> get_comp(ll start, ll possmin) {
	unordered_set<ll> comp;

	queue<ll> todo;
	todo.push(start);

	while (!todo.empty()) {
		ll curr = todo.front();
		todo.pop();

		if (comp.find(curr) != comp.end()) {
			continue;
		}

		comp.insert(curr);

		for (auto& i: adj[curr]) {
			if (i.second >= possmin && comp.find(i.first) == comp.end()) {
				todo.push(i.first);
			}
		}
	}

	return comp;
}

bool works(ll possmin) {
	bool visited[MAX] = {false};
	for (ll i = 1; i <= N; i++) {
		if (!visited[i]) {
			unordered_set<ll> comp = get_comp(i, possmin);
			for (auto i: comp) {
				visited[i] = true;
				if (comp.find(cows[i]) == comp.end()) {
					return false;
				}
			}
		}
	}

	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "wormsort";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

	for (ll i = 1; i <= N; i++) {
		cin >> cows[i];
	}

	bool already = true;
	for (ll i = 2; i <= N; i++) {
		if (cows[i] != cows[i - 1] + 1) {
			already = false;
		}
	}

	if (already) {
		cout << "-1\n";
		return 0;
	}

	ll widths[MAX];

	widths[0] = -1;

	for (ll i = 1; i <= M; i++) {
		ll a, b, w;
		cin >> a >> b >> w;

		adj[a].push_back(pair<ll, ll>({b, w}));
		adj[b].push_back(pair<ll, ll>({a, w}));

		widths[i] = w;
	}

	widths[M + 1] = pow(10, 10);

	sort(widths, widths + M + 2);

	ll min = 0;
	ll max = M + 1; 

	while (max - min > 1) {
		ll mid = (min + max) / 2;
		if (works(widths[mid])) {
			min = mid;
		}
		else {
			max = mid;
		}
	}

	cout << widths[min] << "\n";

	return 0;
}