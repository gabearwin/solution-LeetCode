#include<stdio.h>
void *word_memeset(void *s, int c, size_t n)
{
    size_t cnt = 0;
    size_t k = sizeof(unsigned long);
    unsigned long l;
    unsigned char* schar = (unsigned char*)s;
    unsigned char* lchar = (unsigned char *)&l;

    //先将long的各字节变为c的低位字节
    for(int i = 0; i < k; i++)
        lchar[i] = (unsigned char)c;
    //将地址调整为k的倍数，直到能够被k整除
    while((size_t)schar % k)
    {
        *schar++ = (unsigned char)c;
        cnt++;
    }

    //调整完地址之后求出新的n，更新cnt=0
    n = n - cnt;
    cnt = 0;
    for(int i = 0;i < n - k +1;i+=k)
    {
        for(int j = 0;j < k/4;j++)
        {
            schar[0] = lchar[0];
            schar[1] = lchar[1];
            schar[2] = lchar[2];
            schar[3] = lchar[3];
            schar += 4;
            cnt +=4;
        }
    }

    //遍历最后几个元素
    while(cnt < n)
    {
        *schar++ = (unsigned char)c;
        cnt++;
    }
    return s;
}
int main(){
    char s[]="abcdefg";
    printf("%c\n",(unsigned char)97);
    word_memeset(s,98,3);
    for(int i=0;i<7;i++)
        printf("%c",s[i]);
    return 0;
}
