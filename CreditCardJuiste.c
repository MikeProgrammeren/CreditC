#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include <stdbool.h> 


long long int GetLong();
int GetLength(long long int);
int GetFirstTwoDigits(long long int);
bool LuhnAlgorithm(long long int);
int GetSumEveryOtherDigit(long long int);

//most MasterCard numbers start with 51, 52, 53, 54, or 55  MasterCard uses 16-digit numbers,
//; and all Visa numbers start with 4.  and Visa uses 13- and 16-digit numbers.  

int main(void){
    ///long long int Input = GetLong();
    //printf ("%lld\n", Input); 

    long long int Input = 4003600000000014LL; 
    int Length = GetLength(Input);
    int FirstTwoDigits = GetFirstTwoDigits(Input); 
    int SumEveryOtherDigit = GetSumEveryOtherDigit(Input);
    printf("%i", SumEveryOtherDigit);
    
    //LuhnAlgorithm(Input);d


    //Aangegeven of het een terecht nummer is 
    // All American Express numbers start with 34 or 37; American Express uses 15-digit numbers, 
    // if(GetLength(Input) == 15 && (GetFirstTwoDigits(Input) == 34 || GetFirstTwoDigits(Input) == 37))
    // {
    //     printf ("In the IF statement: %lld\n", Input);
    //     printf ("Length: %i\n", GetLength(Input));
    //     printf ("First two %lld\n", GetFirstTwoDigits(Input));
    //     printf ("Card American Express\n");
    // }    
    
}

long long int GetLong(){
    char StringIput[18];
    long long int Input;
    printf("Creditcard number: ");
    fgets(StringIput, 20, stdin); 
    Input = atoll(StringIput);
    return Input;
}

int GetLength(long long int Input){
    long long int LengthLong = floor(log10(llabs(Input))) + 1;
    printf("Length is: %i\n", LengthLong);
    return LengthLong;
}

int GetFirstTwoDigits(long long int Input){ 
    while (Input >= 100) {
        Input /= 10;
    }
    printf("eerste twee getallen: %d\n", Input);
    return Input;
}



//IN PROGRESS///

bool LuhnAlgorithm(long long int Input){
    
    
    //Twee methodes 
    //Methode 1 som van elk ander getal * 2
    int SumEveryOtherDigit = GetSumEveryOtherDigitTimesTwo(Input);
    //Methode 2 som van elk getal
    

    printf("\n");

    long long int temp2 = Input;

    //Elk getal opslaan in een array van rechts naar links
    int EveryDigit[8];    
    for (int i = 0; i < 8; i++){      
        EveryDigit[i] = temp2 % 10;         
        temp2 /= 100;                 
    }   

    for(int loop = 0; loop < 8; loop++)
         printf("%d ", EveryDigit[loop]);


    int totaal = 0;

    for(int i = 0, n = GetLength(Input); i < n; i++)
    {
        int totaal =+ EveryDigit[i] + EveryOtherDigit[i];
          
    }
    printf("%i", totaal);


}

int GetSumEveryOtherDigitTimesTwo(long long int Input){
    int SumEveryOtherDigit;    
    Input /= 10;
    for (int i = 0; i < 8; i++){      
        SumEveryOtherDigit += Input % 10 * 2;         
        Input /= 100;                 
    }   
    return SumEveryOtherDigit;
}