#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//hola
int main(void)
{
    unsigned char arr[] = "holaabbbbBBBBBBBBbbaaaaaa",rep[256] = {0};
    for(uint32_t i=0,ans=arr[0],letter = arr[i]+('a'-'A')*(arr[i]>='A'&&arr[i]<='Z');arr[i]!='\0';letter = arr[i] +('a'-'A')*(arr[i]>='A'&&arr[i]<='Z'),arr[++i] || printf("%c",ans))
        ++rep[letter-'a'] > rep[ans-'a'] ? (ans=letter) : 1;
}