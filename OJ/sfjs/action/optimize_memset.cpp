#include<stdio.h>
#include<string.h>
/*void *word_memeset(void *s, int c, size_t n)
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
    for(int i = 0;i < n / k ;i++)
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
}
*/

void *optimized_memset(void *s, int c, size_t n)
{
    unsigned int K = sizeof(unsigned long);
    unsigned char *schar = (unsigned char*)s;
    unsigned long *lchar;
    unsigned long fill = 0;
    int i = 0;
    //填充long型字节
    for(i = 0; i < K; i++)
        fill += (c&0xff) << (i<<3);

    //地址对齐，字节级的写
    while((unsigned)schar%K && n)
    {
        *schar++ = (unsigned char)c;
        n--;
    }

    //字级的写
    lchar = (unsigned long*) schar;
    while ( n >= K ) {
        *lchar++ = fill;
        n -= K;
    }

    //可能还有多的字节，使用字节级的写
    schar = (unsigned char*) lchar;
    while(n){
        *schar++ = (unsigned char)c;
        --n;
    }
}

int main(){
    char s[]="abcdefghijk";
    optimized_memset(s,97,5);
    for(int i=0;i<10;i++)
        printf("%c",s[i]);
//    printf("%d",sizeof(unsigned char));
    return 0;
}
//
//void *memset(void *s,int c,size_t n);
//int a[]={1,2,3,4,5,6,7};
//memset(a,0,sizeof(int)*7)   //sizeof(int)是4字节，乘以7是长度，可以写成下面一行的形式
//memset(a,0,sizeof(a));      //将a开始的连续的28个字节初始化为int型的0的低字节
//0x00000000                  //数组a中每个元素值，也就是十进制的0
//
//memset(a,0xff,sizeof(a));
//0xffffffff                  //数组a中每个元素值，也就是十进制的-1
//
//memset(a,1,sizeof(a));
//0x01010101                  //数组a中每个元素的值，转化成十进制并不是1。所以memset不能初始化1.
