#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

ll skills[12];

void swap(ll i, ll j) {
	ll temp = skills[i];
	skills[i] = skills[j];
	skills[j] = temp;
}

pair<ll, ll> solve(ll start) {
	if (start == 9) {
		ll sum1 = skills[9] + skills[10] + skills[11];
		pair<ll,ll> ans;
		ans.first = sum1;
		ans.second = sum1;
		
		return ans;
	}
	
	pair<ll, ll> ans;
	ans.first = 0;
	ans.second = 3000000;
		
	for (ll i = start; i < 12; i++) {
		for (ll j = i + 1; j < 12; j++) {
			for (ll k = j + 1; k < 12; k++) {
				pair<ll, ll> poss;
				
				ll sum = skills[i] + skills[j] + skills[k];
				
				swap(start, i);
				swap(start + 1, j);
				swap(start + 2, k);
				
				poss = solve(start + 3);
				
				swap(start + 2, k);
				swap(start + 1, j);
				swap(start, i);
				
				if (sum < poss.first) {
					poss.first = sum;
				}
				if (sum > poss.second) {
					poss.second = sum;
				}
				
				if (poss.second - poss.first < ans.second - ans.first) {
					ans = poss;
				}
			}
		}
	}
	
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "bteams";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	for (ll i = 0; i < 12; i++) {
		cin >> skills[i]; 
	}
	
	pair<ll, ll> ans = solve(0);
	
	cout << ans.second - ans.first << "\n";
		
	return 0;
}