#include <bits/stdc++.h>
#define MAX 50010
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<string, ll> psl;

ll N;
string names[MAX];
set<psl> asc;
set<psl> desc;
ll tops[MAX];
ll bottoms[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "scramble";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        string s;
        cin >> s;

        names[i] = s;
        sort(s.begin(), s.end());
        asc.insert({s, i});
        reverse(s.begin(), s.end());
        desc.insert({s, i});
    }

    for (auto i: asc) {
        desc.insert({i.f, -1});
        auto it = desc.find({i.f, -1});

        reverse(i.f.begin(), i.f.end());
        auto it2 = desc.find({i.f, i.s});
        reverse(i.f.begin(), i.f.end());

        ll top = distance(desc.begin(), it);
        if (distance(desc.begin(), it2) < top) {
            top--;
        }
        tops[i.s] = top;

        desc.erase({i.f, -1});
    }

    for (auto i: desc) {
        asc.insert({i.f, -1});
        auto it = asc.find({i.f, -1});

        reverse(i.f.begin(), i.f.end());
        auto it2 = asc.find({i.f, i.s});
        reverse(i.f.begin(), i.f.end());

        ll bottom = distance(asc.begin(), it);
        if (distance(asc.begin(), it2) < bottom) {
            bottom--;
        }
        bottoms[i.s] = bottom;

        asc.erase({i.f, -1});
    }


    for (ll i = 0; i < N; i++) {
        cout << tops[i] + 1 << " " << bottoms[i] + 1 << endl;
    }
	
	return 0;
}