#include <bits/stdc++.h>
#define MAXN 50010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
pll points[MAXN];
ll xpoints[MAXN];
ll ypoints[MAXN];
vector<ll> candidates;

ll get_area(set<ll>& s) {
    ll xptr1 = 0;
    while (s.find(xpoints[xptr1]) != s.end()) {
        xptr1++;
    }
    ll xptr2 = N - 1;
    while (s.find(xpoints[xptr2]) != s.end()) {
        xptr2--;
    }
    
    ll yptr1 = 0;
    while (s.find(ypoints[yptr1]) != s.end()) {
        yptr1++;
    }
    ll yptr2 = N - 1;
    while (s.find(ypoints[yptr2]) != s.end()) {
        yptr2--;
    }

    pll p1 = points[xpoints[xptr1]];
    pll p2 = points[xpoints[xptr2]];
    pll p3 = points[ypoints[yptr1]];
    pll p4 = points[ypoints[yptr2]];

    return (p2.f - p1.f) * (p4.s - p3.s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "reduce";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> points[i].f >> points[i].s;
        xpoints[i] = i;
        ypoints[i] = i;
    }
	
    sort(xpoints, xpoints + N, [](auto& a, auto& b) {
        return points[a] < points[b];
    });
    sort(ypoints, ypoints + N, [](auto& a, auto& b) {
        return points[a].s < points[b].s || 
              (points[a].s == points[b].s && points[a].f < points[b].f);
    });

    for (ll i = 0; i < 3; i++) {
        candidates.push_back(xpoints[i]);
        candidates.push_back(xpoints[N - 1 - i]);
        candidates.push_back(ypoints[i]);
        candidates.push_back(ypoints[N - 1 - i]);
    }

    ll ans = pow(40010, 2);

    for (ll i = 0; i < candidates.size() - 2; i++) {
        for (ll j = i + 1; j < candidates.size() - 1; j++) {
            for (ll k = j + 1; k < candidates.size(); k++) {
                set<ll> s = {candidates[i], candidates[j], candidates[k]};
                ll area = get_area(s);
                ans = min(ans, area);
            }
        }
    }
    
    cout << ans << "\n";
	
	return 0;
}