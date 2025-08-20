#include<iostream>
int main()
{
int i;
int arr[5] = {1};
for (i = 0; i < 5; i++)
printf("%d",arr[i]);
//the code will result in all the remaining elements as 0 therefore 10000
return 0;
}
