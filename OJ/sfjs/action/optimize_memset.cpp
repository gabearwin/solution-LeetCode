#include<stdio.h>
#include<string.h>
/*void *word_memeset(void *s, int c, size_t n)
{
    size_t cnt = 0;
    size_t k = sizeof(unsigned long);
    unsigned long l;
    unsigned char* schar = (unsigned char*)s;
    unsigned char* lchar = (unsigned char *)&l;

    //�Ƚ�long�ĸ��ֽڱ�Ϊc�ĵ�λ�ֽ�
    for(int i = 0; i < k; i++)
        lchar[i] = (unsigned char)c;
    //����ַ����Ϊk�ı�����ֱ���ܹ���k����
    while((size_t)schar % k)
    {
        *schar++ = (unsigned char)c;
        cnt++;
    }

    //�������ַ֮������µ�n������cnt=0
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

    //������󼸸�Ԫ��
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
    //���long���ֽ�
    for(i = 0; i < K; i++)
        fill += (c&0xff) << (i<<3);

    //��ַ���룬�ֽڼ���д
    while((unsigned)schar%K && n)
    {
        *schar++ = (unsigned char)c;
        n--;
    }

    //�ּ���д
    lchar = (unsigned long*) schar;
    while ( n >= K ) {
        *lchar++ = fill;
        n -= K;
    }

    //���ܻ��ж���ֽڣ�ʹ���ֽڼ���д
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
//memset(a,0,sizeof(int)*7)   //sizeof(int)��4�ֽڣ�����7�ǳ��ȣ�����д������һ�е���ʽ
//memset(a,0,sizeof(a));      //��a��ʼ��������28���ֽڳ�ʼ��Ϊint�͵�0�ĵ��ֽ�
//0x00000000                  //����a��ÿ��Ԫ��ֵ��Ҳ����ʮ���Ƶ�0
//
//memset(a,0xff,sizeof(a));
//0xffffffff                  //����a��ÿ��Ԫ��ֵ��Ҳ����ʮ���Ƶ�-1
//
//memset(a,1,sizeof(a));
//0x01010101                  //����a��ÿ��Ԫ�ص�ֵ��ת����ʮ���Ʋ�����1������memset���ܳ�ʼ��1.
