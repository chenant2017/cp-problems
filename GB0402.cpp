#include <bits/stdc++.h>
#define MAXM 1010
using namespace std;

typedef long long ll;

struct Interval {
    ll s, e, f;
    bool operator<(const Interval& i) {
        return e < i.e || (e == i.e && s < i.s);
    }
};

ll N, M, R;
Interval intervals[MAXM];
vector<ll> past[MAXM];

void get_past() {
    for (ll i = 0; i < M; i++) {
        for (ll j = i + 1; j < M; j++) {
            if (intervals[i].e <= intervals[j].s) {
                past[j].push_back(i);
            }
        }
    }
}

ll solve_dp() {
    vector<ll> dp (M, 0);
    dp[0] = intervals[0].f;
    
    for (ll i = 1; i < M; i++) {
        dp[i] = intervals[i].f;
        for (auto p: past[i]) {
            dp[i] = max(dp[i], dp[p] + intervals[i].f);
        }
    }

    return *max_element(dp.begin(), dp.end());
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0402";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> R;

    for (ll i = 0; i < M; i++) {
        auto& ii = intervals[i];
        cin >> ii.s >> ii.e >> ii.f;
        ii.e += R;
    }

    sort(intervals, intervals + M);

    for (ll i = 0; i < M; i++) {
        //cout << intervals[i].s << " " << intervals[i].e << " " << intervals[i].f << "\n";
    }

    get_past();

    cout << solve_dp() << "\n";
	
	return 0;
}