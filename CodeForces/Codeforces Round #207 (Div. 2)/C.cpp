#include<cstdio>
#include<set>
using namespace std;
set<int> q;
const int N = 310000;
int ans[N];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        q.insert(i);
    int a,b,x,now,last=0;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&x);
        if(last!=x && last){
            ans[last]=x;
            q.erase(last);
            last=x;
        }
        now=*q.lower_bound(a);
        while(now<=b){
            if(now!=x){
                ans[now]=x;
                int tmp=now;
                q.erase(tmp);
                if(q.upper_bound(now)==q.end())
                    break;
                now=*q.upper_bound(now);
            }
            else{
                if(q.upper_bound(now)==q.end())
                    break;
                now=*q.upper_bound(now);
            }
        }
    }
    ans[*q.begin()]=0;
    for(int i=1;i<=n;i++)
            printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}
