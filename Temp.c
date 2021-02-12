#include <stdio.h>

int main(void){
    int array[4] = {1,2,18,10}; //13
    int TotaalGetallen = 0;

    for( int i = 0 ; i < 4 ; i++) {
        if (array[i] > 9){
        int EersteGetal = array[i] / 10;
        TotaalGetallen += EersteGetal;
        printf("Eerste getal: %i\n", EersteGetal);

        int TweedeGetal = array[i] % 10;
        printf("Tweede getal: %i\n", TweedeGetal);
        TotaalGetallen += TweedeGetal;
        }
        else TotaalGetallen += array[i]; ;
   }
    printf("Totaal: %i\n", TotaalGetallen);

}