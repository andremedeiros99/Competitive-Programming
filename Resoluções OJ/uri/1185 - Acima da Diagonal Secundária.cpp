// Autor: [GAPA] Francisco Arcos Filho<francisco.fepaf@gmail.com>
// Nome: Acima da Diagonal Secundária
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1185

#include<bits/stdc++.h>
#define tam 12
using namespace std;

int i,j,l;
char t;
double m[tam][tam],s=0;

int main(){
	cin>>t;
	for (i=0;i<tam;i++){
		for (j=0;j<tam;j++){
			scanf("%lf",&m[i][j]);
			if (i+j<tam-1) s+=m[i][j];
		}
	}
	printf("%0.1lf\n",(t=='S'?s:s/(tam*(tam-1)/2)));
	return 0;
}
