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
	freopen((fname + ".in").c_str(), "r", stdin);
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

    ll i = 0;
    auto it = ends_.begin();

    for (; it != ends_.end(); it++) {
        while (i + 1 < K && patches[i + 1].f < *it) {
            i++;
        }
        add_ends_.insert(2 * patches[i].f - *it);
        if (i + 1 < K) {
             add_ends_.insert(2 * patches[i].f - *it);
        }
    }

    ends_.insert(add_ends_.begin(), add_ends_.end());

    for (auto j: ends_) {
        cout << j << " ";
    }
    cout << "\n";

    it = ends_.begin();
    i = 0;
    ll sum = 0;
    while (it != ends_.end() && i < K) {
        if (*it >= patches[i].f) {
            sum += patches[i].s;
            i++;
        }
        else if (*it < patches[i].f) {
            cout << *it << " " << sum << "end\n";
            tasty.push(sum);
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

    ll taken = 0;
    ll ans = 0;
    while (taken < N && !tasty.empty()) {
        ans += tasty.top();
        cout << tasty.top() << "\n";
        tasty.pop();
    }

    cout << ans << "\n";
	
	return 0;
}