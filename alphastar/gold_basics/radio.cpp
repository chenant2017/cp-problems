#include <bits/stdc++.h>
#define f first 
#define MAXN 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, K;
set<ll> to_visit;

ll get_dist(ll a, ll b) {
    if (a > b) swap(a, b);
    return (2019201913 * a + 2019201949 * b) % 2019201997;
}

vector<ll> prim() {
    vector<ll> result;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, 1}); // dist, node
    while (!q.empty()) {
        auto curr = q.top();
        q.pop();

        if (to_visit.find(curr.s) == to_visit.end()) {
            continue;
        }

        to_visit.erase(curr.s);
        result.push_back(curr.f);

        for (auto i: to_visit) {
            q.push({get_dist(curr.s, i), i});
        }
    }
    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "radio";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    for (ll i = 1; i <= N; i++) {
        to_visit.insert(i);
    }

    vector<ll> lengths = prim();

    sort(lengths.begin(), lengths.end(), greater<ll>());

    cout << lengths[K - 2] << "\n";
	
	return 0;
}