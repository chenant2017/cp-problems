#include <bits/stdc++.h>
#define MAXN 210
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pdl;

struct Slope {
    ll dy, dx;
    bool operator<(const Slope& s) const {
        return dy * s.dx < dx * s.dy;
    }
};

ll N;
pdl points[MAXN];
set<Slope> slopes;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "ropes";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> points[i].f >> points[i].s;
    }

    for (ll i = 0; i < N; i++) {
        for (ll j = i + 1; j < N; j++) {
            ll num = points[i].s - points[j].s;
            ll denom = points[i].f - points[j].f;
            if (denom * num >= 0) {
                num = abs(num);
                denom = abs(denom);
            }   
            else {
                num = -abs(num);
                denom = abs(denom);
            }
            Slope s;
            s.dy = num;
            s.dx = denom;
            //cout << s.dy << " " << s.dx << "\n";
            slopes.insert(s);
        }
    }

    cout << slopes.size() << "\n";

	return 0;
}