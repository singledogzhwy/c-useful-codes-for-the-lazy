#include<stdio.h>  
#include<string.h>  
int shu(char a)  
{  
    return (a-'0');  
}  
int main(){  
    char a[1000],b[1000];  
    int num[1001];  
    int n,i,j=1,al,bl,k,t;  //n是实例总数，j是当前实例编号（从1开始)，al是较长数字长，bl是较短数字长，
    scanf("%d",&n);  
    while(n--)  
    {  
        if(j!=1)  
       printf("\n");  
       scanf("%s",a);  
       al=strlen(a);  
       scanf("%s",b);  
       bl=strlen(b);  
       k=(al>bl)?al:bl;  
       for(i=0;i<=k;i++)  //k是较长的那个长度，用于初始化
		num[i]=0;  
       t=k;  
       for(k;al>0&&bl>0;k--)  //num[0]最高位，num[k]最低位
       {  
           num[k]+=shu(a[--al])+shu(b[--bl]);  
  
           if(num[k]/10)  
           {  
               num[k-1]++;  
               num[k]%=10;  
           }  
       }  
       while(al>0)  
       {  
            num[k--]+=shu(a[--al]);  
            if(num[k+1]/10)  
           {  
               num[k]++;  
               num[k+1]%=10;  
           }  
       }  
       while(bl>0)  
       {  
            num[k--]+=shu(b[--bl]);  
            if(num[k+1]/10)  
           {  
               num[k]++;  
               num[k+1]%=10;  
           }  
       }  
  
       printf("Case %d:\n",j++);  
       printf("%s + %s = ",a,b);  
       for(i=0;i<=t;i++)  
       {  
           if(i==0&&num[i]==0)  
           i++;  
           printf("%d",num[i]);  
       }  
       printf("\n");  
   }  
   return 0;  
}  
