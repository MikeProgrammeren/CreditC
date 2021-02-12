#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include <stdbool.h> 

long long int GetLong();
int GetLength(long long int);
int GetFirstTwoDigits(long long int);
bool LuhnAlgorithm(long long int, int Length);
int GetSumEveryOtherDigitTimesTwo(long long int Input, int Length);
int GetSumEveryDigit(long long int Input, int Length);

//most MasterCard numbers start with 51, 52, 53, 54, or 55  MasterCard uses 16-digit numbers,
//; and all Visa numbers start with 4.  and Visa uses 13- and 16-digit numbers.  

int main(void){
    ///long long int Input = GetLong();
    //printf ("%lld\n", Input); 

    long long int Input = 4003600000000014LL; 
    int Length = GetLength(Input);
    int FirstTwoDigits = GetFirstTwoDigits(Input); 
    
    LuhnAlgorithm(Input, Length);

 

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
    printf("eerste twee getallen: %i\n", Input);
    return Input;
}


//IN PROGRESS///

//Check if the number qaulifies Luhns Algoritm
//See implementation for the explanation
bool LuhnAlgorithm(long long int Input, int Length){
    
    
    //Method sum of every other digit * 2
    int SumEveryOtherDigitTimesTwo = GetSumEveryOtherDigitTimesTwo(Input, Length);
    //Methode 2 som van elk getal
    int SumEveryDigit = GetSumEveryDigit(Input, Length);

    printf("%i\n",SumEveryOtherDigitTimesTwo);
    printf("%i\n",SumEveryDigit);

    //Check is last digit of both added is = 0

}

//Gets the sum of every other >>digit<< right to left
//In 123456789012345
//that is 4*2+2*2+0*2+8*2+6*2+4*2+2*2 
//8 + 4 + 0 + 16 + 12 + 8 + 4
//!!!--> 8 + 4 + 0 + 1 + 6 + 1 + 2 + 8 + 4 = 24
int GetSumEveryOtherDigitTimesTwo(long long int Input, int Length){
     //j = 8 with length 16, 7 with 15 and 7 with 14
    int j = (int)round((float)Length/2); 
    int array[j];
    int SumEveryOtherDigit = 0;    
    //Remove the most right number
    Input /= 10;
   
    //Add every remaining other digit to the array
    for (int i = 0 ; i < j; i++){      
        array[i] = Input % 10 * 2;         
        Input /= 100;                 
    }   

    //Add each other digit of the array (NOT the product themselves!)
    for( int i = 0 ; i < j ; i++) {
        //If the number in the array consist of 2 digits then digit > 9
        //Then pull them apart and add seperatly
        if (array[i] > 9){
        int FirstNumber = array[i] / 10;
        SumEveryOtherDigit += FirstNumber;

        int SecondNumber = array[i] % 10;
        SumEveryOtherDigit += SecondNumber;
        }
        //if < 9 add 
        else SumEveryOtherDigit += array[i]; 
   }
    printf("Totaal: %i\n", SumEveryOtherDigit);

    return SumEveryOtherDigit;
}

//Gets the sum of every digit right to left
//In 123456789012345
//that is 5+3+1+9+7+5+3+1
int GetSumEveryDigit(long long int Input, int Length){
    int SumEveryDigit = 0;    
    //j = 8 with length 16, 8 with 15 and 7 with 14
    int j = Length/2; 

    for (int i = 0 ; i < j; i++){      
        SumEveryDigit += Input % 10;         
        Input /= 100;                 
    }   
    return SumEveryDigit;
}