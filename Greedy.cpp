#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=1e4+100;
const int inf=0x3f3f3f3f;

struct action{
	int s;
	int f;
	int i;
}a[maxn];
int n;
bool comp(const action &a,const action &b){
    return a.f<=b.f;
}
int Greedy() {
    int num=1;
	sort(a+1,a+n+1,comp);
    int temp=0;
	cout<<a[1].i;
    for(int i=2;i<=n;i++){
        if(a[i].s>=a[temp].f){
			num++;
            temp=i;
			cout<<" "<<a[temp].i;
        }
    }
	cout<<"\n";
    return num;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].f;
		a[i].i=i;
	}
    cout<<Greedy()<<"\n";
    return 0;
}
/*
11
1 4
3 5
5 7
0 6
3 8
5 9
8 11
6 10
8 12
2 13
12 14
*/
