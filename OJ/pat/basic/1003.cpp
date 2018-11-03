#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char s[100];
        scanf("%s",s);
        int flag=0,a,b,c,cnt1=0,cnt2=0,i=0;
        for(i=0;s[i]!='\0';i++){
            if(s[i]!='P'&&s[i]!='A'&&s[i]!='T') {break;}
            if(s[i]=='P'){if(cnt1==0){a=i;} cnt1++;}
            if(s[i]=='T'){if(cnt2==0){b=i;} cnt2++;}
        }
        if(a<b&&cnt1==1&&cnt2==1){
            c=i-b-1;
            b=b-a-1;
            if(a==c&&b==1) flag=1;
            if(a==0&&c==0&&b!=0) flag=1;
            if(a!=0&&b!=0&&a*b==c) flag=1;
        }
        if(flag==1) printf("YES\n");
        if(flag==0) printf("NO\n");
    }
    return 0;
}
