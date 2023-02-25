#include <bits/stdc++.h>
#define f first 
#define s second
#define MAX 50010
using namespace std;

typedef long long ll;
typedef tuple<string, ll, ll> tp;

ll N;
vector<tp> names;
ll top[MAX];
ll bottom[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "scramble";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        string st;
        cin >> st;
        sort(st.begin(), st.end());
        names.emplace_back(st, 0, i);
        reverse(st.begin(), st.end());
        names.emplace_back(st, 1, i);
    }

    sort(names.begin(), names.end());

    ll asc = 0, desc = 0;
    for (auto [a, b, c]: names) {
        if (b == 0) {
            asc++;
            top[c] = desc + 1;
        }
        else {
            desc++;
            bottom[c] = asc;
        }
    }

    for (ll i = 0; i < N; i++) {
        cout << top[i] << " " << bottom[i] << endl;
    }
	
	return 0;
}