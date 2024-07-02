#include <stdio.h>
#include <stdlib.h>

int main()
{ 
   char str[30] = "21.32301 Hoc C tai QTM";
   char *ptr;
   double ret;

   ret = strtod(str, &ptr);
   printf("Phan gia tri (double) la: %lf\n", ret);
   printf("Phan chuoi la: |%s|", ptr);

   return(0);
}