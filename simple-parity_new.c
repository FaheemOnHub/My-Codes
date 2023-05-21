#include <stdio.h>
#include <string.h>
int main()
{
    char string[100];
    int size;
    printf("Enter the Parity String");
    scanf("%s",string);

    size=strlen(string);

    int count=0;
    for(int i=0;i<size;i++)
    {
        if(string[i]=='1')
        count++;
    }

    int parityBit = (count % 2 == 0) ? 1 : 0;
    
    if (parityBit==1) {
        printf("No errors detected. Data transmission successful.\n");
    } else {
        printf("Error detected. Data transmission unsuccessful.\n");
    }

    return 0;

}