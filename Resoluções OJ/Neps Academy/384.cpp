#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define INF 0x3f3f3f3f
#define MAX (1<<20)
#define MOD 1000000007
#define i64 long long
#define all(x) (x).begin() , (x).end()
#define sz(x) (int)(x).size()
#define ii pair<int, int>
#define fs first
#define sc second
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<ii>
#define vvii vector<vii>
#define lsb(x) ((x) & (-x))
#define gcd(x,y) __gcd((x),(y))

using namespace std;

int n, m, a[MAX], b[MAX], ans[MAX];

int main(){_
    cin >> n;
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    cin >> m;
    for (int i=0; i<m; ++i){
        cin >> b[i];
    }
    sort(b, b+m);
    int t=0;
    for (int i=0; i<n; ++i){
        if (binary_search(b, b+m, a[i])) continue;
        ans[t++] = a[i];
    }
    cout << ans[0];
    for (int i=1; i<t; ++i){
        cout << ' ' << ans[i];
    }
    cout << endl;
    return 0;
}