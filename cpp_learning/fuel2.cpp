#include <bits/stdc++.h>
#include <cmath>
#include <deque>

#define ll long long
#define MAXN 50010
#define MAXY 1000010

using namespace std;

pair<ll, ll> stops[MAXN];

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
	
	ll i = 0;
	ll cost = 0;
	ll min_price = MAXB;
	ll min_stop;
	deque<ll> stop_at;

	while (stops[i].f <= B && i < N) {
		if (stops[i].s < min_price) {
			min_price = stops[i].s;
			min_stop = i;
		}
		i++;
	}

	stop_at.push_back(i)


	while (true) {
		ll j = i;
		min_price = MAXB;
		while (stops[j].f - stops[i].f <= G) {
			if (stops[j].s < min_price) {
				min_price = stops[j].s;
				min_stop = j;
			}	
			j++;
		}
		while (stops[stop_at.back()].s > stops[min_stop].s) {
			
			stop_at.pop_back();
		}
		stop_at.push(min_stop);
		i = min_stop;
	}


	return 0;
}