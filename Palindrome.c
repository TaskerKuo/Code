// Add at front or tail of input string to make it be a Palindrome
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* Palindrome(char* str, int n){
   char* rev_str = (char*)malloc(n*sizeof(char));
   char* copy = (char*)malloc((2*n+1)*sizeof(char));
   char* ret = (char*)calloc((2*n),sizeof(char));
   int* table = calloc((2*n+1),sizeof(int));
   int* invtable = calloc((2*n+1),sizeof(int));
   strcpy(copy, str);
   copy = strcat(copy," ");
   rev_str = strrev(str);
   copy = strcat(copy,rev_str);
   
   for(int i=1; i <= 2*n+1; i++){
      int idx = table[i-1];
      int iidx = invtable[i-1];
      while(idx>0 && copy[i] != copy[idx]) idx = table[idx-1];
      while(iidx>0 && copy[2*n-i] != copy[2*n-iidx]) iidx = invtable[iidx-1];
      if(copy[i]==copy[idx]) table[i] = idx+1;
      if(copy[(i+n+1)%n]==copy[(iidx+n+1)%n]) invtable[i] = iidx+1;
   }

   int s = n -  table[2*n];
   strncpy(ret,&copy[n+1],s);
   strcat(ret,strrev(str));
   
   return ret;
}




int main()
{
    char str[10];   
    printf(" \n Enter a string: ");
    scanf("%s", &str);
    int len = 0;
    while(str[len]!='\0') len++;
   
    
    char* str1 = str;
    printf("%d\n",len);
    str1 = Palindrome(str1,len);

    printf(" \n Palindorm of a string: %s ", str1);
    return 0;
}