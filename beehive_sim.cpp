#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> A;
vector<vector<int>> visited;

int N, M, F, T; 
double P;
int di[] = {0, 0, 0, -1, 1};
int dj[] = {0, -1, 1, 0, 0};

void fill_A(int i, int j, double a) {
    for (int i2 = 0; i2 < N; i2++) {
        for (int j2 = 0; j2 < M; j2++) {
            double dist = sqrt(pow(i2 - i, 2) + pow(j2 - j, 2));
            A[i2][j2] += a / pow(dist + 1, P);
        }
    }
}

double random_double(double min, double max) {
    return min + ((double) rand()/RAND_MAX) * (max - min);
}

void simulate(int hivei, int hivej) {
    int i = hivei, j = hivej;
    vector<double> probs;
    for (int t = 0; t < T; t++) {
        visited[i][j]++;

        probs.clear(); 
        probs.push_back(A[i][j]);

        int i2, j2;

        for (int d = 1; d < 5; d++) {
            i2 = i + di[d];
            j2 = j + dj[d];
            if (0 <= i2 && i2 < N &&
                0 <= j2 && j2 < M) {
                probs.push_back(probs[d - 1] + A[i2][j2]);
            }
            else {
                probs.push_back(probs[d - 1]);
            }
        }

        double rd = random_double(0, probs[4]);
        
        int move;
        for (int p = 0; p < 5; p++) {
            if (rd <= probs[p]) {
                move = p;
                break;
            }
        }

        i += di[move];
        j += dj[move];
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    srand(time(NULL));
	
	string fname = "sim";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> P >> F >> T;
    A.resize(N, vector<double>(M, 0));
    visited.resize(N, vector<int>(M, 0));

	int i, j;
    double a;
	for (int f = 0; f < F; f++) {
		cin >> i >> j >> a;
        fill_A(i, j, a);
	}

    for (int s = 0; s < 3 * pow(10, 4); s++) {
        simulate(N/2 + 1, M/2 + 1);
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << visited[i][j] << ", ";
        }
        cout << "\n";
    }

	return 0;
}