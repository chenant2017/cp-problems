#include <bits/stdc++.h>
#include <cmath>
#include <queue>

#define ll long long
#define f first
#define s second
#define MAXN 50010

using namespace std;

ll N, G, B, D;
pair<ll, ll> stops[MAXN];
ll fuel;
queue<ll> monoq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "fuel";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> G >> B >> D;

	for (ll i = 0; i < N; i++) {
		cin >> stops[i].f >> stops[i].s;
	}

	sort(stops, stops + N);

	monoq.push(0);

	for (ll i = 1; i < N; i++) {
		if (stops[i].s < stops[monoq.back()].s) {
			cout << i << " ";
			monoq.push(i);
		}
	}

	cout << "\n";

	fuel = B;

	ll next_stop = monoq.front();
	ll pos = 0;
	ll cost = 0;
	ll fuel_added;

	for (ll i = 0; i < N; i++) {
		fuel -= stops[i].f - pos;
		pos = stops[i].f;

		if (fuel < 0) {
			break;
		}

		if (i == next_stop) {
			fuel_added = min(G, D - pos) - fuel;
			cost += fuel_added * stops[i].s;
			cout << fuel_added << " " << stops[i].s << "aaa\n";
			fuel += fuel_added;
			monoq.pop();
			if (!monoq.empty()) {
				next_stop = monoq.front();
			}
		}
		else {
			if (i < N - 1) {
				fuel_added = min(G, stops[i + 1].f - pos) - fuel;
			}
			else {
				fuel_added = min(G, D - pos) - fuel;
			}
			cost += fuel_added * stops[i].s;
			cout << fuel_added << " " << stops[i].s << "bbb\n";
			fuel += fuel_added;
		}
	}

	pos += fuel;

	if (pos < D) {
		cout << "-1\n";
	}
	else {
		cout << cost << "\n";
	}

	return 0;
}