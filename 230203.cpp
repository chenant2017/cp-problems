#include <bits/stdc++.h>
#define MAX 200010
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

typedef tuple<ll, ll, ll> tll;


ll N, M;
ll ans[MAX];
ll latest[MAX];
ll a[MAX];
vector<tll> adj[MAX];

void dfs() {
    stack<pll> q;
    q.push({1, 0});
    ans[1] = 0;

    while (!q.empty()) {
        ll i, t;

        tie (i, t) = q.top(); q.pop(); 

        assert(t <= latest[i]);

        //cout << i << " " << t << endl;

        auto it = lower_bound(adj[i].begin(), adj[i].end(), tll({t, 0, 0}));
        
        t = get<0>(*it);

        for (; it != adj[i].end(); it++) {
            ll r, d, s;
            tie(r, d, s) = *it;

            //cout << r << " " << d << " " << s << endl;

            if (r >= latest[i]) {
                break;
            }

            //cout << r << " " << d << " " << s << endl;

            if (s < ans[d]) {
                //cout << "a\n";

                ans[d] = s;
                auto it2 = lower_bound(adj[d].begin(), adj[d].end(), 
                            tll({s + a[d], 0, 0}));
                if (it2 != adj[d].end()) {

                    ll u = get<0>(*it2);
                    q.push({d, u});
                }
            }
        }

        latest[i] = t;
    }


    //cout << i << " " << t << "\n";
    
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "230203";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    ll c, r, d, s;

    for (ll i = 0; i < M; i++) {
        cin >> c >> r >> d >> s;

        adj[c].emplace_back(r, d, s);
    }

    for (ll i = 1; i <= N; i++) {
        cin >> a[i];
        ans[i] = 1e18;
        latest[i] = 1e18;
        sort(adj[i].begin(), adj[i].end());
    }

    dfs();

    for (ll i = 1; i <= N; i++) {
        if (ans[i] == 1e18) {
            cout << -1 << "\n";
        }
        else {
            cout << ans[i] << "\n";
        }
    }

	
	return 0;
}