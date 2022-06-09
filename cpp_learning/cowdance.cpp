#include <bits/stdc++.h>
#include <cmath>
#include <queue>

#define ll long long
#define N_MAX 10000

using namespace std;

ll N, Tmax;
ll d[N_MAX];

bool works(ll K) {
	if (K >= N) {
		return true; 
	}
	if (K == 0) {
		return false;
	}
	//cout << K <<"K\n";
	auto comp = [](ll a, ll b) {return a > b;};
	priority_queue<ll, vector<ll>, decltype(comp)> stage(comp);
	
	for (ll i = 0; i < K; i++) {
		stage.push(d[i]);
	}
	
	//cout << "size" << stage.size() << "\n";
	
	ll time = 0;
	ll ptrd = K;
	
	while (!stage.empty()) {
		ll min;
		min = stage.top(); 
		//cout << "min" << min << "\n";
		stage.pop();
		
		while (!stage.empty() && stage.top() == min) {
			stage.pop();
			//cout << stage.size() << "\n";
		}
		
		time = min;
		
		while (ptrd < N && stage.size() < K) {
			//cout << "yeet\n";
			stage.push(d[ptrd] + time);
			ptrd++;
			//cout << stage.size() << "sizeee\n";
		}
	}
	//cout << "YAA";
	return time <= Tmax;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cowdance";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> Tmax;
	
	for (ll i = 0; i < N; i++) {
		cin >> d[i];
	}
	
	ll ptrK = 0;
	ll jump = N / 2 + 1;
	
	while (jump > 0) {
		//cout << ptrK << "\n";
		if (works(ptrK + jump)) {
			jump /= 2;
		}
		else {
			ptrK += jump;
		}
	}
	
	cout << ptrK + 1 << "\n";
	
	return 0;
}