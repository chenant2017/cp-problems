#include <bits/stdc++.h>
#include <cmath>
#include <deque>

#define ll long long
#define MAXN 50010
#define f first
#define s second

using namespace std;

deque<ll> mono_stack;	
pair<ll, ll> stations[MAXN];	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "fuel";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	ll N, G, B, D;
	cin >> N >> G >> B >> D;

	for (ll i = 0; i < N; i++) {
		cin >> stations[i].f >> stations[i].s;
	}

	sort(stations, stations + N);

	stations[N] = pair<ll, ll>({D, 0});

	ll next_cheaper[MAXN];

	for (ll i = 0; i <= N; i++) {
		next_cheaper[i] = -1;
	}

	for (ll i = 0; i <= N; i++) {
		while (!mono_stack.empty() && 
			    stations[mono_stack.back()].s > stations[i].s) {
			next_cheaper[mono_stack.back()] = i;
			mono_stack.pop_back();
		}
		mono_stack.push_back(i);
	}

	ll fuel = B;
	ll curr = 0;
	ll pos = 0;
	ll cost = 0;

	while (curr < N) {
		fuel -= stations[curr].f - pos;
		if (fuel < 0) {
			cout << "-1\n";
			return 0;
		}
		pos = stations[curr].f;

		ll dist = stations[next_cheaper[curr]].f - pos;
		if (dist > G) {
			cost += (G - fuel) * stations[curr].s;
			fuel = G;
			curr++;
		}
		else {
			if (fuel > dist) {
				curr = next_cheaper[curr];
			}
			else {
				cost += (dist - fuel) * stations[curr].s;
				fuel = dist;
				curr = next_cheaper[curr];
			}
		}
	}

	cout << cost << "\n";

	return 0;
}