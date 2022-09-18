#include <bits/stdc++.h>
#define MAXN 110
#define f first  
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

set<ll> xs, ys;
vector<ll> xi, yi;
map<ll, ll> ix, iy;

ll N;
ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};
pll points[MAXN];

ll dijkstra(ll a, ll b) {
    ll dists[MAXN][MAXN];
    for (ll i = 0; i < xs.size(); i++) {
        for (ll j = 0; j < ys.size(); j++) {
            dists[i][j] = (ll) 3000000 * 20000;
        }
    }
    for (ll i = 1; i <= N; i++) {
        if (i != a && i != b) {
            dists[ix[points[i].f]][iy[points[i].s]] = -1;
        }
    }
    
    priority_queue<tll, vector<tll>, greater<tll>> q;
    q.push(tll({0, points[a].f, points[a].s}));
    //cout << points[a].f << " " <<  points[a].s << " start\n";

    while (!q.empty()) {
        auto curr = q.top();
        q.pop();

        ll d, x, y;
        tie(d, x, y) = curr;

        if (pll({x, y}) == points[b]) {
            //cout << x << " " << y << "REACHED\n";
            return d;
        }
        if (dists[ix[x]][iy[y]] != (ll) 3000000 * 20000) continue;
        dists[ix[x]][iy[y]] = d;

       //cout << x << " " << y << "reached\n";

        for (ll dd = 0; dd < 4; dd++) {
            ll nextx = ix[x] + dx[dd];
            ll nexty = iy[y] + dy[dd];

            //cout << xi[nextx] << " " << yi[nexty] << " consider\n";

            if (0 <= nextx && nextx < xs.size() &&
                0 <= nexty && nexty < ys.size() &&
                dists[nextx][nexty] == (ll) 3000000 * 20000) {
                    ll newdist = d + abs(xi[nextx] - x + yi[nexty] - y);
                    q.push(tll({newdist, xi[nextx], yi[nexty]}));
                    //cout << "push " << xi[nextx] << " " <<  yi[nexty] << "\n";
            }
        }
    }
    return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "sightseeing";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 1; i <= N; i++) {
        cin >> points[i].f >> points[i].s;
        xs.insert(points[i].f);
        ys.insert(points[i].s);
    }

    xs.insert(*xs.begin() - 1);
    xs.insert(*xs.rbegin() + 1);
    ys.insert(*ys.begin() - 1);
    ys.insert(*ys.rbegin() + 1);

    for (auto i: xs) {
        ix[i] = xi.size();
        xi.push_back(i);
    }
    for (auto i: ys) {
        iy[i] = yi.size();
        yi.push_back(i);
    }

    ll ans = 0;

    for (ll i = 1; i <= N; i++) {
        //cout << i % N + 1 << " a\n";
        ll d = dijkstra(i, i % N + 1);
        if (d == -1) {
            cout << "-1\n";
            return 0;
        }
       //cout << d << " result\n";
        ans += d;
    }

    cout << ans << "\n";

	return 0;
}