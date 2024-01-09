#include <stdio.h>

/*Returns wether the parameter is prime or not
*/
int numeroPrimo(int number) {
    //Consider the number as prime initially
    int prime = 1;

    /*Check all numbers form 2 to number - 1 to check if they are divisible by the parameter.
        if a divider is found the number isn't prime.*/
    for(int iterator = 2; iterator < number && prime; iterator++){
        //In case a divider is found the number isn't prime so exit the loop
        if(number % iterator == 0)
            prime = 0;
    }

    //Return the boolean
    return prime;
}

int main(void) {
    //Contains the number inserted and wether to sum it or not
    int userInput;
    int sumNumber = 1; //Prints the altermnating numbers

    //Output value
    int primeSum = 0;

    //Run a check on the number the user inputs
    do {
        //Input
        printf("Inserire il numero di arrivo : ");
        scanf("%d", &userInput);

        if(userInput <= 0) //Error message
            printf("Errore : il numero inserito deve essere positivo");
    } while(userInput <= 0);

    /*Find the first N numbers and sum the alternating ones*/
    for(int iterator = 0; iterator <= userInput; iterator++){
        if(numeroPrimo(iterator)){
            if(sumNumber) 
                primeSum += iterator;
            sumNumber = !sumNumber;
        }
    }

    //Print the output
    printf("La somma dei primi %d numeri primi alternati e' %d\n", userInput, primeSum);
}
