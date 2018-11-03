#include<stdio.h>
int main(){
    FILE *fin,*fout;
    fin=fopen("in.txt","r");
    fout=fopen("out.txt","w");
    int n;
    while(!feof(fin)){
        fscanf(fin,"%d",&n);
        for(int i=0;i<n;i++) fprintf(fout,"%d\n",i);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
