#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin, (x).end()
#define eb emplace_back
#define sz(x) ((int) (x).size())

using namespace std;

struct tvector{//p, q
    double x, y;

    tvector operator +(tvector q) const{
        return {x + q.x, y + q.y};
    }
    tvector operator -(tvector q) const{
        return {x - q.x, y - q.y};
    }
    double operator ~() const {
        return hypot(x, y);
    }
    double operator *(tvector q) const {
        return (x*q.x + y*q.y);
    }
    double operator ^(tvector q) const {
        return (x*q.y - y*q.x);
    }
    int operator <(tvector q) const{
        return (x<q.x || (x==q.x && y < q.y));
    }
};

int cmp(tvector a, tvector b){
    if (a.x != b.x) return (a.x < b.x);
    return (a.y < b.y);
}

int cw(tvector a, tvector b, tvector c){
    return (((b-a)^(c-b)) < 0);
}

int ccw(tvector a, tvector b, tvector c){
    return (((b-a)^(c-b)) > 0);
}

vector<tvector> cima, baixo, a;
set<tvector> pontos;
tvector p1, p2, p;
int n, ans, r;


int main(){_

    cin >> n;

    for (int i=0; i<n; ++i){
        cin >> p.x >> p.y;
        a.eb(p);
    }

    n = sz(a);
    sort(a.begin(), a.end());

    p1 = a[0], p2 = a.back();

    cima.eb(p1);
    baixo.eb(p1);

    for (int i=1; i<n; ++i){
        if (i==n-1 || cw(p1, a[i], p2)){
            while (sz(cima)>=2 && !cw(cima[sz(cima)-2], cima[sz(cima)-1], a[i])){
                cima.pop_back();
            }
            cima.eb(a[i]);
        }
    }

    cout << sz(cima)-1 << endl;

    return 0;
}