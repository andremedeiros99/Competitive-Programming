#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define vi vector<i64>
#define pb push_back
#define i64 long long

/*
soma dos bits setados da representacao binaria de todos os numeros entre A e B inclusive
*/


using namespace std;

i64 dp[60][2][200];
i64 n,m,a,b;
vi dig;
string c;

vi getDigit(i64 x){
    vi digitos;

    do{
        digitos.pb(x%2);
        x/=2;
    }while(x);

    return digitos;
}

i64 toral(i64 x){
    i64 a = 0LL;
    for (i64 i=x+1; i--;){
        int check = 1;
        vi digitos = getDigit(i);
        for (auto ch : digitos){
            check &= (c[ch]=='S');
        }
        a += check;
    }
    return a;
}

i64 solve(int idx, int restrito, int sum){
    if (idx==-1) return sum;

    if (~dp[idx][restrito][sum]) return dp[idx][restrito][sum];

    int limit = (restrito ? dig[idx] : 1);

    i64 ans = 0LL;

    for (int d=0; d<=limit; d++){
        ans += solve(idx-1, (d < dig[idx] ? 0 : restrito), sum+d);
    }

    return dp[idx][restrito][sum] = ans;
}

i64 f(i64 x){
    dig = getDigit(x);

    memset(dp,-1,sizeof(dp));

    return solve(dig.size()-1,1,0);;
}

int main(){_
    while ((cin>>n>>m)&&(~n && ~m)){
        a = min(n,m) , b = max(n,m);
        cout<<(f(b)-f(a-1))<<endl;
    }
}
