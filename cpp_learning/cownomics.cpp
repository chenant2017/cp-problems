#include <bits/stdc++.h>
#include <cmath>
#include <unordered_set>

#define ll long long
#define MAX_N 500

using namespace std;

ll N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cownomics";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;
	
	string spotty[MAX_N];
	string non[MAX_N];
	
	for (ll i = 0; i < N; i++) {
		cin >> spotty[i];
	}
	
	for (ll i = 0; i < N; i++) {
		cin >> non[i]; 
	}
	
	ll ans = 0;
	
	for (ll i = 0; i < M; i++) {
		for (ll j = i + 1; j < M; j++) {
			for (ll k = j + 1; k < M; k++) {
				
				bool valid = true;
				
				unordered_set<string> spotty_triples; 
				for (ll m = 0; m < N; m++) { //spotty
					spotty_triples.insert(string() + spotty[m][i] + spotty[m][j] + spotty[m][k]);
					//cout << string() + spotty[m][i] + spotty[m][j] + spotty[m][k] << "\n";
				}
				
				for (ll m = 0; m < N; m++) {
					string non_triple = string() + non[m][i] + non[m][j] + non[m][k];
					if (spotty_triples.find(non_triple) != spotty_triples.end()) {
						valid = false;
						break;
					}
				}
				
				if (valid) {
					ans++;
				}
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}