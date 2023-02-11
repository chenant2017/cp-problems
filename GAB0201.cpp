#include <bits/stdc++.h>
#define MAXN 40110
using namespace std;

typedef long long ll;

ll N, O, F, M;
set<ll> faves;
map<ll, ll> visits;
vector<ll> choices;
ll dp[MAXN];

ll get_dp(ll i) {
    for (auto c: choices) {
        if (i + c <= N + M && dp[i + c] != -1) {
            dp[i] = max(dp[i], dp[i + c] + c);
        }
    }
    return dp[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0201";
	freopen((fname + ".in").c_str(), "r", stdin);
	
	cin >> N >> O >> F >> M;

    for (ll i = 0; i <= N + M; i++) {
        dp[i] = -1;
    }

    for (ll i = 0; i < O; i++) {
        ll c;
        cin >> c;
        choices.push_back(c);
    }

    for (ll i = 0; i < F; i++) {
        ll f;
        cin >> f;
        faves.insert(f);
    }

    ll i = N;
    dp[N] = 0;
    ll visits = 0;

    while (visits <= (F + 1) * F && i >= 0) {
        get_dp(i);

        if (i!=N && faves.find(i) != faves.end()) {
            visits++;
            if (dp[i] > dp[i + M]) {
                dp[i + M] = dp[i];
                i += M;
                continue;
            }
        }
        i--;
    }

    if (visits > (F + 1) * F) {
        cout << "-1\n";
    }
    else {
        cout << *max_element(dp, dp + N + M + 1) << "\n";
    }
	
	return 0;
}