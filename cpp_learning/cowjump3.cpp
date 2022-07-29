#include <bits/stdc++.h>
#define MAXN 100010
#define x real()
#define y imag()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<long double> vec;

struct Seg {
	vec p1, p2;
};

ll N;
Seg segs[MAXN];

bool cmpvec(vec v1, vec v2) {
	return v2.x - v1.x > 1e-9 || (abs(v1.x - v2.x) < 1e-9 && v2.y - v1.y > 1e-9);
}

ld cp(vec v1, vec v2) {
	return v1.x * v2.y - v2.x * v1.y;
}

bool intersect(Seg s1, Seg s2) {
	ld sides1 = cp(s1.p1 - s2.p1, s1.p1 - s2.p2) * 
			 	cp(s1.p2 - s2.p1, s1.p2 - s2.p2);
	ld sides2 = cp(s2.p1 - s1.p1, s2.p1 - s1.p2) *
				cp(s2.p2 - s1.p1, s2.p2 - s1.p2);

	if (sides1 < -1e-9 && sides2 < -1e-9) return true;
	if (sides1 < -1e-9 && abs(sides2) < 1e-9) return true;
	if (sides2 < -1e-9 && abs(sides1) < 1e-9) return true;
	if (abs(sides1) < 1e-9 && abs(sides2) < 1e-9) {
		return !(cmpvec(s1.p2, s2.p1) || cmpvec(s2.p2, s1.p1));
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cowjump";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		vec p1 = vec(x1, y1);
		vec p2 = vec(x2, y2);

		Seg s;
		if (cmpvec(p1, p2)) {
			s.p1 = p1;
			s.p2 = p2;
		}
		else {
			s.p1 = p2;
			s.p2 = p1;
		}
		segs[i] = s;
	}

	ll ans1 = N, ans2 = N;

	for (ll i = 0; i < N - 1; i++) {
		for (ll j = i + 1; j < N; j++) {
			if (intersect(segs[i], segs[j])) {
				ans1 = i;
				ans2 = j;
				break;
			}
		}
	}

	ll count = 0;
	for (ll i = 0; i < N; i++) {
		if (i == ans2) continue;
		if (intersect(segs[ans2], segs[i])) count++;
	}

	if (count > 1) {
		cout << ans2 + 1 << "\n";
	}
	else {
		cout << ans1 + 1 << "\n";
	}

	return 0;
}