#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define INF 0x3f3f3f3f
#define MAX (1<<20)
#define MAXN  (1<<10) // 2**10=1024 aporximadamente 1000
#define MOD 1000000007
#define BRANCO 0
#define CINZA 1
#define PRETO 2
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
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;

using namespace std;

/*lista de Adjacencia nao direcionado e nao ponderado*/
/*Verifica se o grafo é conexo ou não*/

int n; //número vertices
int m; //números arestas
int u, v, w; // vertice de uma aresta de u -> v, com peso w
vvi adj;
vi vis;

int dfs(int u){
    vis[u] = CINZA;
    int ans = 1;
    for (int v : adj[u]){
        if (vis[v]==BRANCO){
            ans += dfs(v);
        }
    }
    vis[u] = PRETO;
    return ans;
}

int main(){_
    cin >> n >> m;
    adj = vvi(n+1);
    for (int i=m; i--;){
        cin >> u >> v ;
        adj[u].eb(v);// u->v
        adj[v].eb(u);// v->u
    }
    
    vis = vi(n+1, BRANCO);
    cout << (dfs(1) == n ? "Conexo\n" : "Nao Conexo\n");
    return 0;
}
