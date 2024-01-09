#include <stdio.h>

int main(void) {
    /* Request the quantity of numbers to get the array length.
     * execute a check to make sure it doesn't exceed the limit 30
    */
    int numAmount;
    do {
        printf("Inserire la quantita' di numbers di cui calcolare la somma e la media : ");
        scanf("%d", &numAmount);

        if(numAmount > 30) //Print error message
            printf("Errore : La quantita' dei numbers non deve essere maggiore di 30\n");
    } while(numAmount > 30);

    int numbers[numAmount]; //Contains the inserted numbers

    //Keeps track of the average and the sum of even and odd numbers
    int sumEven = 0;
    int sumOdd = 0;
    double averageEven = 0;
    double averageOdd = 0;

    //Fill the array with user input
    for(int counter = 0; counter < numAmount; counter++) {
        printf("Inserire il numero %d : ", counter + 1);
        scanf("%d", &numbers[counter]);
    }
    
    //Compute the sum of even and odd numbers saving it in the respective variables
    for(int counter = 0; counter < numAmount; counter++) {
        if(numbers[counter] % 2 == 0)
            sumEven += numbers[counter];
        else
            sumOdd += numbers[counter];
    }

    //Compute the averages
    averageEven = (double)sumEven / numAmount;
    averageOdd = (double)sumOdd / numAmount;

    //Output results
    printf(
        "La somma dei numeri pari risulta : %d\nLa somma dei numeri dispari risulta : %d\nLa media dei numeri pari risulta : %.2f\nLa media dei numeri dispari risulta : %.2f\n", 
        sumEven, 
        sumOdd, 
        averageEven, 
        averageOdd
    );

    //Terminate the program
    return 0;
}