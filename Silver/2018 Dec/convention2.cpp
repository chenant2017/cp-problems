#include <bits/stdc++.h>
#include <cmath>
#include <queue>

#define ll long long
#define MAX_N 100000

using namespace std;

struct Cow {
	ll sen, a, t;
};

ll N;
Cow cows[MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "convention2";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;
	
	for (ll i = 0; i < N; i++) {
		cows[i].sen = i;
		cin >> cows[i].a >> cows[i].t;
	}
	
	sort(cows, cows + N, [](auto& a, auto& b){
		return (a.a < b.a || (a.a == b.a && a.sen < b.sen));
	});
	
	auto comp = [](Cow& a, Cow& b) {return a.sen > b.sen;};
	priority_queue<Cow, vector<Cow>, decltype(comp)> line(comp);
	
	ll ans = 0;
	
	ll time = cows[0].a;
	ll ptr = 1;
	line.push(cows[0]);
	
	while (!line.empty()) {
		Cow cow = line.top();
		line.pop();
		
		ll wait = time - cow.a;
		if (wait > ans) {
			ans = wait; 
		}
		
		time += cow.t;
		
		while (ptr < N && cows[ptr].a <= time) {
			line.push(cows[ptr]);
			ptr++;
		}
		
		if (line.empty() && ptr < N) {
			line.push(cows[ptr]);
			time = cows[ptr].a;
			ptr++;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}