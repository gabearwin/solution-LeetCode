#include<cstdio>
int main(){
    char s[15],a[10],b[10];
    while(~scanf("%s",s)){
        for(int i=0;i<6;i++){
            a[i]=s[i];
            b[i]=s[i+6];
        }
        int sum=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<6;j++){
                if(a[i]==b[j]&&a[5-i]==b[5-j]){
                    b[j]=b[5-j]='x';
                    sum++;break;
                }
            }
        }
        //printf("%d\n",sum);
        puts(sum==3?"TRUE":"FALSE");//puts×Ô´ø»»ÐÐ
    }
}



1 2 3 4 5 6
1 3 5 2 4 6
1 4 2 5 3 6
1 5 4 3 2 6

2 6 3 4 1 5
2 4 6 1 3 5
2 1 4 3 6 5
2 3 1 6 4 5

1 2 2 3 3 1
1 2 2 3 3 1

1 2 3 3 2 1
1 3 2 2 3 1
