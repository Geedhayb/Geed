#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=1e4;
const int inf=0x3f3f3f3f;

struct BST{
	int l,r;
	int val;
}a[maxn];
int tot,root;
int New(int val){
	a[++tot].val=val;
	return tot;
}
void build(){
	New(-inf);
	New(inf);
	root=1;
	a[1].r=2;
}
int get(int p,int val){
	if(p==0) return 0;
	if(val==a[p].val) return p;
	return val<a[p].val?get(a[p].l,val):get(a[p].r,val);
}
void insert(int &p,int val){
	if(p==0){
		p=New(val);
		return;
	}
	if(val==a[p].val) return;
	if(val<a[p].val) insert(a[p].l,val);
	else insert(a[p].r,val);
}
int main(){
	int n;
	build();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		insert(root,x);
	}
	int x;
	scanf("%d",&x);
	int k=get(root,x);
	if(k!=0) printf("%d\n",k-2);
	else printf("0\n");
}
