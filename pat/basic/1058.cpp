#include<stdio.h>
#include<string.h>
bool isright(char a[],char b[]){
    int len1=strlen(a),len2=strlen(b);
    if(len1!=len2) return false;
    for(int i=0;i<len1;i++){
        if(a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int a[1000][3];
    char b[1000][10];
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        //printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
        for(int j=0;j<a[i][2];j++){
            scanf(" %c",&b[i][j]);
            //printf("%c\n",b[i][j]);
        }
    }
    int wrong[1000]={0},anscnt,stu_score[1000];

    for(int i=0;i<n;i++){
        int score=0;
        for(int j=0;j<m;j++){
            char temp,ans[1000]="";
            scanf(" %c",&temp); //ÎüÊÕ×óÀ¨ºÅ
            scanf("%d",&anscnt);
            //printf("%d\n",anscnt);
            for(int k=0;k<anscnt;k++){
                scanf(" %c",&ans[k]);
            }
            //printf("%s\n",ans);
            if(isright(ans,b[j])){
                score+=a[j][0];
                //printf("zheshiduide%s\n",b[j]);
            }else{
                wrong[j]++;
            }
            scanf(" %c",&temp);//ÎüÊÕÓÒÀ¨ºÅ
        }
        stu_score[i]=score;
    }
    for(int i=0;i<n;i++) printf("%d\n",stu_score[i]);
    int wrong_max=wrong[0];
    for(int k=0;k<m;k++){
        if(wrong[k]>wrong_max) wrong_max=wrong[k];
    }
    if(wrong_max==0) printf("Too simple\n");
    else{
        printf("%d",wrong_max);
        for(int k=0;k<m;k++){
            if(wrong[k]==wrong_max){
                int kk=k+1;
                printf(" %d",kk);
            }
        }
    }
    return 0;
}
