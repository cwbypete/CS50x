#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    //Ensure only one parameter has been supplied
    if(argc!=2){
        printf("Invalid Key. Plaintext Only\n");
        return 1;
    }
    // Then apply that parameter to the string k
    string k = argv[1];
    // And check that k is a valid, plaintext alpha string, converted to uppercase
    for (int count=0;count<strlen(k);count++)
    {
        if(!isalpha(k[count])){
            printf("Invalid Key. Plaintext Only\n");
            return 1;
        }
        else
        {
            k[count]=toupper(k[count]);
        }
    }

    string p=get_string("plaintext: ");
    int length = strlen(p);
    //char ciphertext[length];
    int klen=strlen(k);

    //k is our uppercase key
    //p is the plaintext string
    //length is the length of p
    //klen is the key length


    for(int count = 0, kj = 0; count<length; count++) //for each character in p
    {
        if(isalpha(p[count]))                   //if the character is alpha
        {
            int downshift=0;
            if(isupper(p[count])){downshift=65;}    //depending on case, we'll downshift
            if(islower(p[count])){downshift=97;}    //through the ascii table by 65 or 97

            int plain = (p[count]-downshift);
            int shiftby =(k[kj%klen]-65);

            p[count] = ((plain+shiftby)%26+downshift);

            kj++;
        }
    }
    printf("ciphertext: %s\n",p);
    return 0;
}