#include <bits/stdc++.h>
#define MAX 200010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll K, M, N;
pll grass[MAX];
pll ints[MAX];
ll closest[MAX];
ll nhoj[MAX];
vector<pll> locs;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "211201";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> K >> M >> N;

    for (ll i = 0; i < K; i++) {
        cin >> grass[i].f >> grass[i].s;
    }

    sort(grass, grass + K);

    for (ll i = 0; i < M; i++) {
        cin >> nhoj[i];
    }

    sort(nhoj, nhoj + M);

    for (ll i = 0; i < K; i++) {
        closest[i] = 1e18;
    }

    ll ptr = 0;

    for (ll i = 0; i < K; i++) {
        while (ptr < M && nhoj[ptr] < grass[i].f) {
            ptr++;
        }

        if (nhoj[ptr] > grass[i].f) {
            closest[i] = min(closest[i], nhoj[ptr] - grass[i].f);
        }
    }

    ptr = M - 1;

    for (ll i = K - 1; i >= 0; i--) {
        while (ptr >= 0 && nhoj[ptr] > grass[i].f) {
            ptr--;
        }

        if (nhoj[ptr] < grass[i].f) {
            closest[i] = min(closest[i], grass[i].f - nhoj[ptr]);
        }
    }
    
    for (ll i = 0; i < K; i++) {
        ints[i] = {grass[i].f - closest[i], grass[i].f + closest[i]};
        locs.push_back({ints[i].f, i});
        locs.push_back({ints[i].s, i});
    }

    sort(locs.begin(), locs.end());

    priority_queue<ll> q;

    set<ll> active;
    ll tasty = 0;
    for (ll i = 0; i < locs.size(); i++) {
        //assert(active.size() <= 2);

        if (active.find(locs[i].s) == active.end()) {
            active.insert(locs[i].s);
            tasty += grass[locs[i].s].s;
        }
        else {
            if (active.find(locs[i - 1].s) != active.end()) {
                q.push(tasty);
            }
            tasty -= grass[locs[i].s].s;
            active.erase(locs[i].s);
        }
    }

    ll ans = 0;
    ll count = 0;

    while (!q.empty() && count < N) {
        ans += q.top();
        q.pop();
        count++;
    }

    cout << ans << "\n";
	
	return 0;
}