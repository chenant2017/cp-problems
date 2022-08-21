#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll K, M, N;
priority_queue<ll> tasty;
set<ll> ends_;
set<ll> add_ends_;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "closest";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> K >> M >> N;

    vector<pll> patches;

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
        left--;
        ll ldist = patches[i].f - *left;
        if (ldist > 0 && ldist < closest) {
            closest = ldist;
        }
        auto right = ends_.upper_bound(patches[i].f);
        if (right != ends_.end()) {
            ll rdist = *right - patches[i].f;
            if (rdist < closest) closest = rdist;
        }
        add_ends_.insert(patches[i].f + closest);
        add_ends_.insert(patches[i].f - closest);
    }

    ends_.insert(add_ends_.begin(), add_ends_.end());

    auto it = ends_.begin();
    ll i = 0;
    ll sum = 0;
    while (it != ends_.end() && i < K) {
        if (*it >= patches[i].f) {
            sum += patches[i].s;
            i++;
        }
        else {
            //cout << *it << " end\n";
            tasty.push(sum);
            //cout << "push " << sum << "\n";
            sum = 0;    
            it++;
        }
    }

    if (it == ends_.end()) {
        sum = 0;
        while (i < K) {
            sum += patches[i].s;
            i++;
        }
    }
    else if (i == K) {
        tasty.push(sum);
    }

    ll taken = 0;
    ll ans = 0;
    while (taken < N && !tasty.empty()) {
        ans += tasty.top();
        //cout << tasty.top() << "\n";
        tasty.pop();
        taken++;
    }

    cout << ans << "\n";
	
	return 0;
}