#include <bits/stdc++.h>
#define f first 
#define s second 
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, K;

ll get_dist(ll a, ll b) {
    if (a > b) swap(a, b);
    return (2019201913 * a + 2019201949 * b) % 2019201997;
}

void prims(vector<ll>& edge_lengths) {
    vector<ll> dists(N + 1, 2019201998);
    vector<bool> visited (N + 1, false);

    dists[1] = 0;

    for (ll i = 1; i <= N; i++) {
        ll curr = 0;
        for (ll j = 1; j <= N; j++) {
            if (!visited[j] && (curr == 0 || dists[j] < dists[curr])) {
                curr = j;
            }
        }

        visited[curr] = true;
        edge_lengths.push_back(dists[curr]);
        dists[curr] = 0;
        
        for (ll j = 1; j <= N; j++) {
            ll dist = get_dist(curr, j);
            dists[j] = min(dists[j], dist);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GA1002";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    vector<ll> edge_lengths;
    prims(edge_lengths);
    sort(edge_lengths.begin(), edge_lengths.end());

    cout << edge_lengths[N + 1 - K] << "\n";
	
	return 0;
}