#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    if(argc!=2){
        return 1;
    }

    int key = atoi(argv[1]);
    string p=get_string("plaintext: ");
    int length = strlen(p);
    char ciphertext[length];

    //key is the int to shift
    //p is the plaintext string
    //length is the string length

    for(int count = 0; count<length; count++)
    {
        if(isalpha((char)p[count]))
        //int downshift = 0;
        {
            int downshift=0;
            if(isupper((char)p[count])){downshift=65;}
            if(islower((char)p[count])){downshift=97;}
            ciphertext[count] = (int) (p[count]-downshift+key)%26+downshift;
        }
        else
        {
            ciphertext[count] = (int) p[count];
        }
    }
    printf("ciphertext:%s\n",ciphertext);
    return 0;
}