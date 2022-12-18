#include <bits/stdc++.h>
#define MAXN 45
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
ll xg, yg;

pll moves[MAXN];
map<pll, map<ll, ll>> counts1;
map<pll, map<ll, ll>> counts2;
ll ans[MAXN];

vector<vector<ll>> get_subsets(ll low, ll high) {
    vector<vector<ll>> result;
    if (low == high) {
        result = {{}, {high}};
    }
    else {
        vector<vector<ll>> ss = get_subsets(low + 1, high);
        for (auto i: ss) {
            result.push_back(i);
            i.push_back(low);
            result.push_back(i);
        }
    }
    return result;
}

pll move_sum(vector<ll>& m) {
    pll result = pll({0, 0});
    for (auto& i: m) {
        result.f += moves[i].f;
        result.s += moves[i].s;
    }
    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "robot";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    cin >> xg >> yg;

    for (ll i = 0; i < N; i++) {
        ll xi, yi;
        cin >> xi >> yi;
        moves[i] = pll({xi, yi});
    }   

    vector<vector<ll>> subsets1 = get_subsets(0, N / 2);
    vector<vector<ll>> subsets2 = get_subsets(N / 2 + 1, N - 1);
	
    for (auto& ss: subsets1) {
        pll ms = move_sum(ss);
        counts1[ms][ss.size()]++;
    }

    for (auto& ss: subsets2) {
        pll ms = move_sum(ss);
        counts2[ms][ss.size()]++;
    }

    for (auto& c1: counts1) {
        pll ct = pll({xg - c1.f.f, yg - c1.f.s}); // complement
        auto it = counts2.find(ct);
        if (it == counts2.end()) continue;

        for (auto& d1: c1.s) {
            for (auto& d2: it->s) { //what if counts2.find... is end
                ans[d1.f + d2.f] += d1.s * d2.s;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }

	return 0;
}