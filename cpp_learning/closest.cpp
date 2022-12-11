//Silver 2021 December #1

#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pdl;

ll K, M, N;
priority_queue<ll> tasty;
set<ll> ends_;
vector<pdl> new_ends;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "closest";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> K >> M >> N;

    vector<pdl> patches;

    for (ll i = 0; i < K; i++) {
        ll p, t;
        cin >> p >> t;
        patches.push_back(pll({p, t}));
    }

    for (ll i = 0; i < M; i++) {
        ll f;
        cin >> f;
        ends_.insert(f);
    }

    for (ll i = 0; i < K; i++) {
        ll closest = pow(10, 10);
        auto left = ends_.lower_bound(patches[i].f);
        if (left != ends_.begin()) {
            left--;
            ll ldist = patches[i].f - *left;
            if (ldist < closest) {
                closest = ldist;
            }
        }
        auto right = ends_.upper_bound(patches[i].f);
        if (right != ends_.end()) {
            ll rdist = *right - patches[i].f;
            if (rdist < closest) closest = rdist;
        }
        new_ends.push_back(pll({patches[i].f - closest, patches[i].s}));
        new_ends.push_back(pll({patches[i].f + closest, -patches[i].s}));
    }

    sort(new_ends.begin(), new_ends.end(), [](auto& a, auto& b) {
        return a.f < b.f || (a.f == b.f && a.s < b.s);
    });

    ll sum = 0;
    ll total = 0;
    ll max_sum = 0;
    for (ll i = 0; i < new_ends.size(); i++) {
        sum += new_ends[i].s;
        if (new_ends[i].s > 0) total += new_ends[i].s;
        max_sum = max(max_sum, sum);
        if (sum == 0) {
            tasty.push(max_sum);
            tasty.push(total - max_sum); //why this is needed:
            /*
                3 2 2
                14 3
                5 5
                8 4
                2
                15
            */
            max_sum = 0;
            total = 0;
        }
    }

    ll taken = 0;
    ll ans = 0;
    while (taken < N && !tasty.empty()) {
        ans += tasty.top();
        tasty.pop();
        taken++;
    }

    cout << ans << "\n";
	
	return 0;
}
