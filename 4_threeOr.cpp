#include <bits/stdc++.h>
using namespace std;
using ll = long long; 

int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string a;
        cin >> a;

        string s = "", t = "";
        bool ok = false; // 记录是否出现了不均匀分配

        for(int i = 0; i < n; i++) {
            if(a[i] == '2') {
                if(ok) {
                    s += '0';
                    t += '2';
                } else {
                    s += '1';
                    t += '1';
                }
            } else if(a[i] == '1') {
                if(ok) {
                    s += '0';
                    t += '1';
                } else {
                    s += '1';
                    t += '0';
                    ok = true;
                }
            } else {
                s += '0';
                t += '0';
            }
        }


        cout << s << endl << t << endl;

    }
}