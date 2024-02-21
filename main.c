#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int is_armstrong(int);
int is_magical(int);
int main()
{
    int n;
    int stat;
    int count=0;
    FILE*input;
    input = fopen("numbers.txt","r");
    FILE*output;
    output = fopen("outfile.txt","w");
    stat = fscanf(input, "%d", &n);
    while(stat!=EOF)
    {
        count++;
        if ( is_magical(n)&&! is_armstrong(n))
        {
            fprintf(output,"%d is not armstrong but it is a magical number...\n",n);
        }
        else if (!is_magical(n)&& is_armstrong(n))
        {
            fprintf(output,"%d is not magical and armstrong number...\n",n);
        }
         else if (is_magical(n)&& is_armstrong(n))
        {
            fprintf(output,"%d is both magical and armstrong number...\n",n);
        }
        else
        {
            fprintf(output,"%d is nither magical nor armstrong number...\n",n);
        }
        stat=fscanf(input, "%d", &n);
    }
    return 0;
}
int is_armstrong(int n)
{
    int arm1;
    int arm2;
    int sum=0;
    int m;
    int count=0;
    arm1=n;
    arm2=n;
    while (arm1!=0)
    {
        m=arm1%10;
        arm1/=10;
        count++;
    }
    while(arm2!=0)
     {
        m=arm2%10;
        sum+=pow(n, count);
        arm2/=10;
    }
    if (sum==n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int is_magical(int n)
{
    int magicl=n;
    int sum=0;
    int h;
    int count=0;
    while (count!=1)
    {
        sum=0;
        count=0;

    while (magicl!=0)
    {
        h=magicl%10;
        sum+=h;
        magicl/=10;
        count++;
    }
        magicl=sum;
    }
   if (magicl==1)
    return 1;
   else
    return 0;
}


