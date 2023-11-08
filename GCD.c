#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 256

int* str2num(char* str){
    int len = strlen(str);
    int* num = (int*)calloc(MAX,sizeof(int));
    for(int i=len-1;i>=0;--i){
        num[len-i-1] = str[i]-'0';
    }
    return num;
}

int* sub(int* a, int* b){
    int* ans = (int*)malloc(sizeof(int)*MAX);
    int borrow = 0, sum = 0;
    for(int i=0;i<MAX;++i){
        sum = a[i] - b[i] - borrow;
        if(sum<0){
            borrow = 1;
        }
        else borrow = 0;
        ans[i] = sum + borrow*10;
    }
    return ans;
}

int* mul(int* a, int* b){
    int* ans = (int*)malloc(sizeof(int)*MAX);
    
    int carry = 0, sum = 0;
    for(int i=0; i<MAX; i++){
        //if(a[i] = 0) continue;
        for(int j=0;j+i<MAX;j++){
            ans[i+j] = a[i]*b[j];
        }
    }
    for(int i=0; i<MAX; i++){
        if(ans[i]>=0){
            ans[i+1] += ans[i]/10;
            ans[i]%=10;
        }
    }
    return ans;
}

void multiply_2(int* a){
    int carry = 0, sum = 0;
    for(int i=0; i<MAX; ++i){
        a[i]*=2; 
    }
    for(int i=0; i<MAX; ++i){
        sum = carry + a[i]%10;
        carry = floor(a[i]/10);
        a[i] = sum;
    }
}

void half(int* a){
    int rst = 0, ans = 0;
    for(int i=MAX-1; i>=0; --i){
        ans = floor((a[i]+rst*10)/2);
        rst = a[i]%2;
        a[i] = ans;
    }    
}

int isEven(int* a){
    if(a[0]%2==0) return 1;
    else return 0;
}

int equal_zero(int* a){
    int i = MAX -1;
    while (i>0 && a[i]==0) --i;
    return a[i];
}

int compare(int* a,int* b){
    int i = MAX - 1;
    while (i>0 && a[i]==b[i]) --i;
    return a[i]-b[i];
}

int main(){

    char c[MAX] = "987654321987654321987654321";
    char d[MAX] = "123456789123456789123456789";
    char ans[MAX] = "1";
    int* Ans = str2num(ans);    
    int* cc = str2num(c);
    int* dd = str2num(d);
   
    while (equal_zero(cc)>0 && equal_zero(dd)>0)  
    {
        if(isEven(cc) && isEven(dd)){
            multiply_2(Ans);
            half(cc);
            half(dd);
        }
        else if(isEven(dd)){
            half(dd);
        }
        else if(isEven(cc)){
            half(cc);
        }
        
        if(compare(cc,dd)<0){
            int* tmp = cc;
            cc = dd;
            dd = tmp;
        }
        cc = sub(cc,dd);
    }
      
    int* GCD = mul(dd,Ans);
    int i = MAX-1;
    for(i=MAX-1;i>0 && GCD[i]==0; --i);
    while(i>=0) printf("%d", GCD[i]), --i;
    return 0;
}
