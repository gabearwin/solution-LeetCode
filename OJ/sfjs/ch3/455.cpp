#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        char s[100];
        scanf("%s",s);
        int len=strlen(s),ans=0;
        char str[100];
        for(int i=0;i<len/2;i++){
            char temp[100];
            memset(temp,'\0',sizeof(temp));
            memset(str,'\0',sizeof(str));
            strncpy(temp,s,i+1);
            //printf("%s\n",temp);
            if(len%(i+1)==0){
                for(int j=1;j<=len/(i+1);j++){
                    strcat(str,temp);
                }
                //printf("%s\n",str);
                if(strcmp(str,s)==0) {ans=i+1;break;}
            }
        }
        //�ύ�˺ü��Σ�һֱ�����⣬��Ҫ����������
        printf("%d\n",ans==0?len:ans);//���ans=0��ʱ��Ҫ��ans=len������ȫ������ѭ��һ��
        if(T!=0) printf("\n");//�����ʽ�������һ�������������֮��Ҫ����
    }
    return 0;
}
