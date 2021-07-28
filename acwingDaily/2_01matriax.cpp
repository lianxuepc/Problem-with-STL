#include <iostream>

using namespace std;

const int N = 110;

int n, m;
char s[N][N];

void print1(int i, int j) { 
    printf("%d %d %d %d %d %d\n", i, j, i, j + 1, i + 1, j);
}

void print2(int i, int j) { 
    printf("%d %d %d %d %d %d\n", i, j, i + 1, j, i + 1, j + 1);
}

void print3(int i, int j) {
    printf("%d %d %d %d %d %d\n", i, j, i, j + 1, i + 1, j + 1);
}

void print4(int i, int j) { 
    printf("%d %d %d %d %d %d\n", i + 1, j, i, j + 1, i + 1, j + 1);
}

int main() {
    int T;
    cin >> T;
    while (T -- ) {
        int ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i ++ ) scanf("%s", s[i] + 1);

        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ )
                if (s[i][j] == '1') ans += 3;

        cout << ans << endl;

        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ )
                if (s[i][j] == '1') {
                    if (i == 1 && j < m) {
                        print1(i, j);
                        print2(i, j);
                        print3(i, j);
                        continue;
                    } else if (j == 1 && i > 1) {
                        print1(i - 1, j);
                        print2(i - 1, j);
                        print4(i - 1, j);
                        continue;
                    } else if (i == n && j > 1) {
                        print2(i - 1, j - 1);
                        print3(i - 1, j - 1);
                        print4(i - 1, j - 1);
                        continue;
                    } else if (j == m && i < n) {
                        print1(i, j - 1);
                        print3(i, j - 1);
                        print4(i, j - 1);
                        continue;
                    } else {
                        print1(i, j);
                        print2(i, j);
                        print3(i, j);
                    }
                }
    }

    return 0;
}

