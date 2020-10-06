#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define MAX (1<<20)
#define MAXN (1<<10)
#define MAXC (1<<10)
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

int a[MAX];// array original

int ft[MAX];// array da estrutura de dados do FT
int n; //tamanho do array 

void update(int idx, int val){
    while (idx<=n){
        ft[idx] += val;
        idx += lsb(idx);
    }
}

int query(int idx){
    int ans = 0;
    while (idx>0){
        ans += ft[idx];
        idx -= lsb(idx);
    }
    return ans;
}

i64 ans;
int mp[MAX];

int main(){_
    cin >> n;

    for(int i=0; i<=n; ++i){
        ft[i] = 0;
    }

    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    for (int i=1; i<=n; ++i){
        mp[i] = n+1-i;
    }
    
    for (int i=1; i<=n; ++i){
        ans += query(mp[a[i]]);
        // cout << query(mp[a[i]]) << endl;
        update(mp[a[i]], 1);
    }

    cout << ans << endl;

    return 0;
}