#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 200000;
char str[N];
int a[N],sum[N],real[N];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        sum[i]=a[i];
    for(int i=1;i<n;i++)
        sum[i]+=sum[i-1];
    scanf("%s",str);
    int ans=0,ans1=0;
    int len=strlen(str);
    for(int i=0;i<len;i++)
        if(str[i]=='1')
            real[i]=a[i];
    for(int i=len-2;i>=0;i--)
        real[i]+=real[i+1];
    ans=real[0];
    for(int i=1;i<len;i++)
        if(str[i]=='1')
            ans=max(ans,sum[i-1]+real[i+1]);
    printf("%d\n",ans);
    return 0;
}
