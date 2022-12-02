#include <bits/stdc++.h>
#define MAXN 100010
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M, C;
ll at_least[MAXN];
vector<pll> adj[MAXN];
bool visited[MAXN] = {false};
ll ans[MAXN];

deque<ll> topo_sort() {
    deque<ll> result;

    for (ll i = 1; i <= N; i++) {
        //cout << "i " << i << "\n";
        stack<ll> q;
        q.push(i);
        
        vector<ll> path;

        while (!q.empty()) {
            auto curr = q.top();
            q.pop();

            if (visited[curr]) continue;
            visited[curr] = true;
            //cout << "at " << curr << "\n";
            path.push_back(curr);

            for (auto j: adj[curr]) {
                //cout << "consider " << j.f << "\n";
                if (!visited[j.f]) {
                    //cout << "push " << j.f << "\n";
                    q.push(j.f);
                }
            }
        }

        result.insert(result.begin(), path.begin(), path.end());
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "center";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> C;

    for (ll i = 1; i <= N; i++) {
        cin >> at_least[i];
    }

    for (ll i = 0; i < C; i++) {
        ll a, b, x;
        cin >> a >> b >> x;
        adj[a].push_back(pll({b, x}));
    }

    /*for (ll i = 1; i <= N; i++) {
        cout << i << "   ";
        for (auto j: adj[i]) {
            cout << j.f << " ";
        }
        cout << "\n";
    }*/


    auto order = topo_sort();

    for (ll i = 1; i <= N; i++) {
        ans[i] = at_least[i];
    }
   

    for (ll i = 0; i < N; i++) {
        //cout << order[i] << "\n";
        for (auto j: adj[order[i]]) {
            ll poss = ans[order[i]] + j.s;
            poss += max(at_least[j.f] - poss, (ll)0);
            ans[j.f] = max(ans[j.f], poss);
        }
    }
    //cout << "\n";
    for (ll i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }
	
	return 0;
}