#include <bits/stdc++.h>
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pdl;

ll N, C;
vector<ll> carrots1;
vector<ll> carrots2;
set<ll> sums1;
set<ll> sums2;

void get_sums(vector<ll>& carrots, set<ll>& sums) {
    queue<pdl> q;
    q.push(pdl({0, -1}));

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (curr.s == carrots.size()) continue;

        sums.insert(curr.f);

        q.push(pll({curr.f, curr.s + 1}));
        q.push(pll({curr.f + carrots[curr.s + 1], curr.s + 1}));
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "harvest";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> C;

    for (ll i = 0; i < N / 2; i++) {
        ll a;
        cin >> a;
        carrots1.push_back(a);
    }

    for (ll i = N / 2; i < N; i++) {
        ll a;
        cin >> a;
        carrots2.push_back(a);
    }

    get_sums(carrots1, sums1);
    get_sums(carrots2, sums2);

    ll ans = 0;

    for (auto i: sums1) {
        auto it = sums2.upper_bound(C - i);
        it--;
        ans = max(*it + i, ans);
    }

    cout << ans << "\n";

	return 0;
}