#include <bits/stdc++.h>
#define MAX 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

pll choices[MAX];
list<ll> cows[MAX];
bool taken[MAX] = {false};
ll N, M;

int give(ll cereal) {
    if (cows[cereal].empty()) return -1;

    ll next = cows[cereal].front();
    if (choices[next].f == cereal) { //is first choice
        cows[choices[next].s].remove(next);
        return give(choices[next].s);
    }
    else {
        return 0;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cereal";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < N; i++) {
        ll c1, c2;
        cin >> c1 >> c2;
        choices[i].f = c1;
        choices[i].s = c2;
        cows[c1].push_back(i);
        cows[c2].push_back(i);
    }

    ll fed = 0;
    for (ll i = 0; i < N; i++) {
        if (taken[choices[i].f]) {
            if (!taken[choices[i].s]) {
                taken[choices[i].s] = true;
                fed++;
            }
        }
        else {
            taken[choices[i].f] = true;
            fed++;
        }
    }

    cout << fed << "\n";

    //return 0;

    for (ll i = 0; i < N - 1; i++) {
        cows[choices[i].f].pop_front();
        cows[choices[i].s].remove(i);
        cout << fed + give(choices[i].f) << "\n";
    }
	
	return 0;
}