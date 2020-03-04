#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=1000;
const int inf=0x3f3f3f3f;

int d[maxn][maxn],n,m;
void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	memset(d,inf,sizeof d);
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		d[x][y]=min(d[x][y],z);
	}
	Floyd();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) printf("%d%c",d[i][j],"\n "[j!=n]);
	}
}
