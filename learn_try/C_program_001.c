#include <stdio.h>

int main()
{

    double var_runoob[10]={0,1,2,3,4,5,6,7,8,9};
    double *p;
    p = &var_runoob[9];
    // p = NULL;
    for(int i=0;i<10;i++)
    {
        printf("%p\n",p);
        printf("%f\n", *p);
        p--;
        printf("%f\n",var_runoob[i]);
        
    }
    return 0;
}