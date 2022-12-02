#include <bits/stdc++.h>
#define f first 
#define s second

using namespace std;

typedef pair<int, int> pi;

int ddi[4] = {0, 0, 1, -1};
int ddj[4] = {1, -1, 0, 0};

vector<int> di;
vector<int> dj;
vector<vector<int>> flowers;
set<pi> locs;
vector<pi> placed;
vector<int> ans; //ans[h] = flowers pollinated after h hives placed 

int N, M, F, R, D;

void get_di_dj() {
    di.push_back(0);
    dj.push_back(0);

    for (int r = 1; r <= R; r++) {
        for (int d = 0; d < 4; d++) {
            di.push_back(ddi[d] * r);
            dj.push_back(ddj[d] * r);
        }
    }

    for (int ri = 1; ri <= R; ri++) {
        for (int rj = 1; rj <= R; rj++) {
            for (int si = -1; si <= 1; si += 2) {
                for (int sj = -1; sj <= 1; sj += 2) {
                    double dist2 = pow(ri, 2) + pow(rj, 2);
                    if (dist2 <= pow(R, 2)) {
                        di.push_back(ri * si);
                        dj.push_back(rj * sj);
                    }
                }
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "beehive";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> M >> F >> R >> D;
    
    flowers.resize(N, vector<int>(M, 0));
    get_di_dj();


    for (int f = 0; f < F; f++) {
        int i, j;
        cin >> i >> j;

        int i2, j2;
        for (int d = 0; d < di.size(); d++) {
            i2 = i + di[d];
            j2 = j + dj[d];

            if (0 <= i2 && i2 < N &&
                0 <= j2 && j2 < M) {
                flowers[i2][j2]++;
                locs.insert(pi({i2, j2}));
            }
        }
    }

    ans.push_back(0);
    int flower_count = 0;

    while (true) {
        if (flower_count == F) break;

        set<pi> locs2;
        pi next = pi({-1, -1});

        bool enough_space;
        for (auto l: locs) {
            enough_space = true;
            for (auto p: placed) {
                double dist2 = pow(l.f - p.f, 2) + pow(l.s - p.s, 2);
                if (dist2 < pow(D, 2)) {
                    enough_space = false;
                }
            }
            
            if (enough_space) {
                if ((next == pi({-1, -1}) && 
                    flowers[l.f][l.s] > 0) || 
                    (next != pi({-1, -1}) &&
                    flowers[l.f][l.s] > flowers[next.f][next.s])) {
                    next = l;
                }
            }
        }

        if (next == pi({-1, -1})) break;

        flower_count += flowers[next.f][next.s];

        int i2, j2;

        for (int d = 0; d < di.size(); d++) {
            i2 = next.f + di[d];
            j2 = next.s + dj[d];

            if (0 <= i2 && i2 < N &&
                0 <= j2 && j2 < M) {
                flowers[i2][j2]--;
            }
        }

        


        locs.erase(next);
        placed.push_back(next);
    }

	return 0;
}