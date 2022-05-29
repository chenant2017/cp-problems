#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "slowdown";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	ll N;
	cin >> N;
	
	char dt;
	
	vector<ll> D;
	vector<ll> T;
	ll x;
	
	for (int i = 0; i < N; i++) {
		cin >> dt >> x;
		if (dt == 'D') {
			D.push_back(x);
		}
		else {
			T.push_back(x);
		}
	}
	
	sort(T.begin(), T.end());
	sort(D.begin(), D.end());
	
	ll Ti = 0;
	ll Di = 0;
	double tT, tD;
	
	double dist = 0;
	double time = 0; 
	ll speed_recip = 1;
	
	while (Ti < T.size() && Di < D.size()) {
		tT = T[Ti] - time;
		tD = (D[Di] - dist) * (speed_recip);
		
		if (tT < tD) {
			dist += (1.0/speed_recip) * tT;
			speed_recip++;
			time += tT;
			Ti++;
		}
		else if (tT == tD) {
			dist += (1.0/speed_recip) * tT;
			speed_recip += 2;
			time += tT;
			Ti++;
			Di++;
		}
		else {
			dist += (1.0/speed_recip) * tD;
			speed_recip++;
			time += tD;
			Di++;
		}
	}
	
	while (Ti < T.size()) {
		tT = T[Ti] - time;
		dist += (1.0/speed_recip) * tT;
		speed_recip++;
		time += tT;
		Ti++;
	}
	
	while (Di < D.size()) {
		tD = (D[Di] - dist) * (speed_recip);
		dist += (1.0/speed_recip) * tD;
		speed_recip++;
		time += tD;
		Di++;
	}
	
	time += (1000 - dist) * speed_recip;
	
	cout << (int)(round(time)) << "\n";
	
	return 0;
}