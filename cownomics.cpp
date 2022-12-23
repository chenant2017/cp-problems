#include <bits/stdc++.h>
#define MAXN 1020

using namespace std;

typedef long long ll;

ll N, M;
string seqs[MAXN];
unordered_map<char, ll> convert = { 
    {'A', 0},
    {'C', 1},
    {'G', 2},
    {'T', 3}
};

bool works(ll i, ll j, ll k) {
    unordered_set<ll> s1;

    for (ll p = 0; p < N; p++) {
        ll converted = convert[seqs[p][i]] * 16 + 
                        convert[seqs[p][j]] * 4 +
                        convert[seqs[p][k]];
        s1.insert(converted);
    }

    for (ll p = N; p < 2 * N; p++) {
        ll converted = convert[seqs[p][i]] * 16 + 
                        convert[seqs[p][j]] * 4 +
                        convert[seqs[p][k]];
        if (s1.find(converted) != s1.end()) return false;
    }

    return true;
}

ll solve() {
    ll result = 0;

    for (ll i = 0; i < M - 2; i++) {
        for (ll j = i + 1; j < M - 1; j++) {
            for (ll k = j + 1; k < M; k++) {
                if (works(i, j, k)) {
                    result++;
                }
            }
        }
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cownomics";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < 2 * N; i++) {
        cin >> seqs[i];
    }


    cout << solve() << "\n";
	
	return 0;
}