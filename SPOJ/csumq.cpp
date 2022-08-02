#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_N 150000


using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	/*string s = "csumq";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);*/
	
	ll N;
	cin >> N;
	
	ll prefix[MAX_N] = {0};
	
	ll value;
	for (ll i = 1; i <= N; i++) {
		cin >> value;
		prefix[i] = prefix[i - 1] + value;
	}
	
	ll Q;
	cin >> Q;
	
	ll start, end;
	
	for (ll i = 0; i < Q; i++) {
		cin >> start >> end;
		cout << prefix[end + 1] - prefix[start] << "\n";
	}
	
	return 0;
}