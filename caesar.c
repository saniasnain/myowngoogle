#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

bool check_valid_key (string s);

int main(int argv, string argc[])
{
    if(argv !=2 || !check_valid_key(argc[1]))
    {
        printf("usage:./caesar key\n");
        return 1;
    }
    int key=atoi(argc[1]);
    string plaintext =get_string("plaintext: ");
    printf("ciphertext: ");
    
    for(int i=0; i<strlen(plaintext);i++)
    {
        char c=plaintext[i];
        if(isalpha(c))
        {
            char m='A';
            if(islower(c))
            {
            m='a';
            printf("%c",(c-m+key)%26+m);
            }
            else
            {
                printf("%c",c);
            }
        }
    }
}
bool check_valid_key(string s)
{
    for(int i=0;i<strlen(s);i++)
    if(!isdigit(s[i]))
    {
    return false;
    }
    return true;
}