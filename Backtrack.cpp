#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+100;
const int inf=0x3f3f3f3f;
int n;
double minlen,x[maxn],r[maxn],b[maxn];//���е���̾��룬Բ��x���꣬Բ�İ뾶��Բ�������˳�� 
double center(int k){
    double t=0;
    for(int i=1;i<k;++i){
    	t=max(t,x[i]+2.0*sqrt(r[i]*r[k]));
    }
    return t;
}
void compute(){
    double l=0,h=0;
    for(int i=1;i<=n;++i){
        if(x[i]-r[i]<l) {
            l=x[i]-r[i];
        }
        if(x[i]+r[i]>h){
            h=x[i]+r[i];
        }
    }
    if(h-l<minlen){
        minlen=h-l;
        for(int i=1;i<=n;++i){
            b[i]=r[i];
        }
    }
}
void dfs(int k){
    if(k>n)//���н������������г��� 
        compute();
    else{
        for(int i=k;i<=n;++i) {
            swap(r[k],r[i]);//���� 
            double xx=center(k);
            if(xx+r[1]+r[k]<minlen){//��֦ 
                x[k]=xx;
                dfs(k+1);
            }
            swap(r[k],r[i]);//��ԭ����ֹ��һ������ȱ����� 
        }
    }
}
int main(){
	minlen=inf; 
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf",&r[i]);
    dfs(1);
    printf("��̾���:%f\n",minlen);
    for(int i=1;i<=n;++i){
        printf("%f%c",b[i],"\n "[i!=n]);
    }
    return 0;
}
