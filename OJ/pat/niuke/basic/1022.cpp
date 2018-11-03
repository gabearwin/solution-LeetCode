#include<stdio.h>
#include<math.h>
int main() {
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        int cnt=0;
        while(pow(3,cnt)<n) {
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
