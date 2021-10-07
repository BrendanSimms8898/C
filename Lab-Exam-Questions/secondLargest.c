#include<stdio.h>
#include<conio.h>

void main()
{
int a[50];
int n,i,large,s_large;
clrscr();

printf("\n Enter number of elements: ");
scanf("%d",&n);

printf("\n Enter the elements: ");
for(i=0;i<n;i++)
{
    scanf("%d",&a[i]);
}

large=s_large=a[0];

for(i=1;i<n;i++)
{
    if(large<a[i])
    {
        s_large=large;
        large=a[i];
    }
    else if(s_large<a[i] && a[i]!=large)
    {
        s_large=a[i];
    }
}