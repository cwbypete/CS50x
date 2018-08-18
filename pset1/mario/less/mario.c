#include<stdio.h>
#include<cs50.h>

int main(void)
{
int n = 0;
    //Prompt for input between 0 and 23
    do {
        n = get_int("Height: ");
    }
    while (n <0 || n >23);

    //for each line
    // perform 2 loops, one calculating the number of spaves, the second, the number of #
    for (int line=1; line<n+1; line++){
        for (int spaces=n-line; spaces>0 ;spaces--){
            printf(" ");
        }

        for (int hashes=0; hashes<line;hashes++){
            printf("#");
        }
        printf("#\n");
    }
}