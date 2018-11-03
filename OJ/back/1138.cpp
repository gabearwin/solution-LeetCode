#include <stdio.h>
#include <string.h>
char str[30];
int main() {
    while(scanf("%s",str)!=EOF) {
        int i,j=0,sum = 1;
        int ans[100];
        while(sum) {
            sum = 0;
            int len = strlen(str);
            for(i = 0;i<len;i++) {
                int d = (str[i] - '0') % 2;
                int x = (str[i] - '0') / 2;
                sum += x;
                if(i == len - 1) {
                    ans[j++] = d;
                }
                else
                    str[i+1] += d * 10;
                str[i] = x + '0';
            }
        }
        for(i = j - 1;i>=0;--i)
            printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}
