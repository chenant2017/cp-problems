#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pdl;

ll N;
vector<pdl> cows;
vector<ll> prefix;
map<ll, ll> last;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "fairphoto";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        ll b;
        string x;
        cin >> b >> x;
        pdl p;
        p.f = b;
        if (x == "G") {
            p.s = 1;
        }
        else {
            p.s = -1;
        }
    }

    sort(cows.begin(), cows.end(), [](auto& a, auto& b) {
        
    });

    prefix.push_back(cows[0]);

    for (ll i = 1; i < N; i++) {
        prefix[i] = prefix[i - 1] + cows[i];
        last[prefix[i]] = locs[i];
    }

    ll ans = -1;

    for (ll i = 0; i < N; i++) {
        ans = max(ans, last[prefix[i]] - locs[i]);
    }

    cout << ans << "\n";
	
	return 0;
}