#include <bits/stdc++.h>
#define MAX 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
pll all[MAX];
vector<ll> incr;
vector<ll> decr;
bool invalid[MAX]; 

void process_same(vector<ll>& v) {
    ll max_end = -1e18;
    ll j = -1;

    for (auto i: v) {
        ll p, q;
        tie(p, q) = all[i];
        if (p > q) swap(p, q);

        if (q <= max_end) {
            invalid[i] = true;
            if (j != -1) invalid[j] = true;
        }

        if (q > max_end) {
            max_end = q;
            j = i;
        }
    }
}

void process_diff() {
    stack<ll> st;

    for (ll i = 0; i < N; i++) {
        if (all[i].f < all[i].s) {
            st.push(i);
        }
        else {
            while (!st.empty()) {
                ll j = st.top();

                if (all[i].s < all[j].s) {
                    invalid[i] = true;
                    invalid[j] = true;
                }

                st.pop();
            }
        }
    }

    while (!st.empty()) st.pop();

    for (ll i = 0; i < N; i++) {
        if (all[i].f > all[i].s) {
            st.push(i);
        }
        else {
            while (!st.empty()) {
                ll j = st.top();

                if (all[i].f < all[j].f) {
                    invalid[i] = true;
                    invalid[j] = true;
                }

                st.pop();
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "crossings";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);

    cin >> N;

    for (ll i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;

        all[i] = {a, b};
    }

    sort(all, all + N, [](auto& a, auto& b) { 
        ll a1 = min(a.f, a.s), a2 = max(a.f, a.s);
        ll b1 = min(b.f, b.s), b2 = max(b.f, b.s);
        return a1 < b1 || (a1 == b1 && a2 < b2); 
    });

    for (ll i = 0; i < N; i++) {
        if (all[i].f <= all[i].s) {
            incr.push_back(i);
        }
        if (all[i].s <= all[i].f) {
            decr.push_back(i); 
        }
    }

    process_same(incr); process_same(decr);
    process_diff();

    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        ans += !invalid[i];
    }

    cout << ans << endl;
	
	return 0;
}