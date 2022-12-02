#include <bits/stdc++.h>
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, string> pls;

ll rubiks = 12345678;
ll target;
set<ll> visited;

ll A(ll i) {
    ll j = 0;
    for (ll a = 7; a >= 0; a--) {
        ll digit = i % 10;
        j += digit * pow(10, a);
        i -= digit;
        i /= 10;
    }
    return j;
}

ll B(ll i) {
    return (i / 100000) * pow(10, 4) + 
            (i % 1000) * 10 +
            ((i / 10000) % 10) * 10000000 +
            (i / 1000) % 10;
}

ll swap_ij(ll n, ll i, ll j) {
    ll id = ( (ll) (n / (pow(10, i))) ) % 10;
    ll jd = ( (ll) (n / (pow(10, j))) ) % 10;
    n -= id * pow(10, i);
    n += id * pow(10, j);
    n -= jd * pow(10, j);
    n += jd * pow(10, i);
    return n;
}

ll C(ll i) {
    i = swap_ij(i, 1, 2);
    i = swap_ij(i, 2, 5);
    i = swap_ij(i, 5, 6);
    return i;
}

string bfs() {
    queue<pls> q;
    q.push(pls({rubiks, string()}));

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
  
        if (visited.find(curr.f) != visited.end()) continue;
        visited.insert(curr.f);

        if (curr.f == target) {
            return curr.s;
        }

        ll a = A(curr.f);
        q.push(pls({a, curr.s + 'A'}));
        ll b = B(curr.f);
        q.push(pls({b, curr.s + 'B'}));
        ll c = C(curr.f);
        q.push(pls({c, curr.s + 'C'}));
    }

    return string();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "squares";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	for (ll i = 7; i >= 0; i--) {
        ll a;
        cin >> a;
        target += a * pow(10, i);
    }

    string ans = bfs();

    cout << ans.size() << "\n";
    cout << ans << "\n";
	
	return 0;
}