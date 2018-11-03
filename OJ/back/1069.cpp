#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct Stu{
    char no[100];
    char name[100];
    char sex[50];
    int age;
    bool operator < (const Stu &a) const{
        return strcmp(no,a.no)<0;
    }
}buf[1000];
int main(){
    int i,n,m;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%s%s%s%d",buf[i].no,buf[i].name,buf[i].sex,&buf[i].age);
        }
        sort(buf,buf+n);
        scanf("%d",&m);
        while(m--){
            int ans=-1,base=0,top=n-1;
            char x[50];
            scanf("%s",&x);
            while(base<=top){
                int mid=(base+top)/2;
                int tmp=strcmp(buf[mid].no,x);
                if(tmp==0){ans=mid;break;}
                else if(tmp>0){top=mid-1;}
                else base=mid+1;
            }
            if(ans!=-1){printf("%s %s %s %d\n",buf[ans].no,buf[ans].name,buf[ans].sex,buf[ans].age);}
            else printf("No Answer!\n");
        }
    }
    return 0;
}
