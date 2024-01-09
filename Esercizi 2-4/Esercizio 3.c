#include <stdio.h>

int main(void) {
    int numAmount;

    //Request user input
    printf("Determinare la quantita' di numeri da inserire : ");
    scanf("%d", &numAmount);

    //Variables
    int sumPositive = 0;
    int sumNegative = 0;
    int quantityPositive = 0;
    int quantityNegative = 0;
    double positiveAverage, negativeAverage;
    int currentNumber;

    // Iterate trough all the requested number inputs
    for(unsigned int iterator = 0; iterator < numAmount; iterator++)
    {
        printf("Inserire il numero %d : ", iterator + 1);
        scanf("%d", &currentNumber);

        /* Depending on the sign and increment quantity of numbers, sum
            of absolute values and the relative numbers.*/
        if(currentNumber >= 0) {
            quantityPositive++;
            sumPositive += currentNumber;
        } else if(currentNumber < 0) {
            quantityNegative++;
            sumNegative += (currentNumber * -1);
        }
    }

    //Calculate the averages
    positiveAverage = (double)sumPositive / (double)quantityPositive;
    negativeAverage = (double)sumNegative / (double)quantityNegative;

    //Output results
    printf(
        "Quantita' numeri positivi : %d\n\
        Somma numeri positivi : %d\n\
        Media numeri positivi : %lf\n\n\
        Quantita' numeri negativi : %d\n\
        Somma numeri negativi : %d\n\
        Media numeri negativi : %lf\n\n", 
        quantityPositive, sumPositive, positiveAverage, quantityNegative, sumNegative, negativeAverage
    );
}