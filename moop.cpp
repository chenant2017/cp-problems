#include <bits/stdc++.h>
#define MAXN 100010
#define x first 
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
pll points[MAXN];
vector<ll> adj[MAXN];
bool visited[MAXN] = {false};

void floodfill(ll i) {
    if (visited[i]) return;
    visited[i] = true;

    for (auto j: adj[i]) {
        floodfill(j);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "moop";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points, points + N);

    stack<ll> mono;
    for (ll i = 0; i < N; i++) {
        if (!mono.empty() && points[mono.top()].y <= points[i].y) {
            ll put_back = mono.top();
            
            while (!mono.empty() && points[mono.top()].y <= points[i].y) {
                adj[mono.top()].push_back(i);
                adj[i].push_back(mono.top());
                //cout << mono.top() << " " << i << "\n";
                mono.pop();
            }

            mono.push(i);
            mono.push(put_back);
        }
        else {
            mono.push(i);
        }
    }
    
    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        if (!visited[i]) {
            ans++;
            floodfill(i);
        }
    }

    cout << ans << "\n";
	
	return 0;
}