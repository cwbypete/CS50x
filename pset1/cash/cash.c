#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    float n = 0;
    int coinsused = 0;
    do
    {
        n=get_float("Change: ");
    }
    while (n<0);

    //float round(float n)

    int changedue = round(n*100); //Because we want an int, but we want to avoid any nonsense rounding errors
    printf("Change due: %d\n", changedue);

// Outside of the pset, you would instead itterate over an array that holds the US coin values. But for now...

    while (changedue>=25)
    {
        changedue-=25;
        coinsused++;
    }

    while (changedue>=10)
    {
        changedue-=10;
        coinsused++;
    }

    while (changedue>=5)
    {
        changedue-=5;
        coinsused++;
    }

    while (changedue>=1)
    {
        changedue-=1;
        coinsused++;
    }


    printf("%d\n", coinsused);
}