#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=10000;
struct men{
    char name[20];
    int height;
    bool operator < (const men &a) const{
        if(height!=a.height)
            return height>a.height;
        else return strcmp(name,a.name)<0;//×ÖµäÐò
        /*strcmp(name,a.name)>0 ×Öµä½µÐò */
    }
}stu[maxn];
int nn=0;
void out(int sum){
    int mid=sum/2,is_odd=sum%2;
    char *s[maxn];
    s[mid]=stu[nn++].name;
    for(int i=1;mid-i>=0;i++){
        s[mid-i]=stu[nn++].name;
        if(!is_odd&&mid==i) break;
        s[mid+i]=stu[nn++].name;
    }
    int first=1;
    for(int i=0;i<sum;i++){
        if(first) {printf("%s",s[i]);first=0;}
        else printf(" %s",s[i]);
    }
    printf("\n");
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>stu[i].name>>stu[i].height;
    sort(stu,stu+n);
    //for(int i=0;i<n;i++) cout<<stu[i].name<<' '<<stu[i].height<<endl;
    int first_row=n-n/k*(k-1);
    out(first_row);
    for(int i=0;i<k-1;i++) out(n/k);
    return 0;
}
