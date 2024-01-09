#include <stdio.h>

/*Returns wether the parameter is prime or not
*/
int isPrime(int number) {
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

void ex1() {
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

void ex2() {
    //Constants
    const int firstDiscountTreshold = 500;
    const int secondDiscountTreshold = 1000;
    const int firstDiscount = 10;
    const int secondDiscount = 20;
    const int thirdDiscount = 30;

    //Variables
    int terminateLoop = 0;
    double price, discount, discountedPrice;

    //Infinite loop until terminateLoop is true
    do {
        //Input the price
        printf("Inserire un prezzo da scontare : ");
        scanf("%f", &price);

        //Check if the price is between 0 and the first discount treshold
        if(price > 0 && price <= firstDiscountTreshold) {
            printf("Sconto applicato : %d%%", firstDiscount);

            //Calculate the discount
            discount = price * (firstDiscount / 100.00);
            discountedPrice = price - discount;
        //Check if the price is between the first and the second discount treshold
        } else if(price > firstDiscountTreshold && price <= secondDiscountTreshold) {
            printf("Sconto applicato : %d%%", secondDiscount);

            //Calculate the discount
            discount = price * (firstDiscount / 100.00);
            discountedPrice = price - discount;
        //Check if the price is over the second discount treshold
        } else if(price > secondDiscountTreshold) {
            printf("Sconto applicato : %d%%", thirdDiscount);

            //Calculate the discount
            discount = price * (thirdDiscount / 100.00);
            discountedPrice = price - discount;
        //Negative price - throw an error
        } else {
            printf("Errore : il prezzo non deve essere negativo.");
        }

        //Request loop stop
        printf("Si vuole inserire un nuovo valore di prezzo? [0, 1]");
        scanf("%d", &terminateLoop);

        //If the user requested for loop exit set the variable which terminates the loop to true
        if(terminateLoop != 0)
            terminateLoop = 1;
    } while(!terminateLoop);

    return 0;
}

void esercizio3 () {
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

void esercizio4() {
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
        if(isPrime(iterator)){
            if(sumNumber) 
                primeSum += iterator;
            sumNumber = !sumNumber;
        }
    }

    //Print the output
    printf("La somma dei primi %d numeri primi alternati e' %d\n", userInput, primeSum);
}


int main(void) {
    /*Primt the 4 exercises*/
    printf("Inserire l'esercizio da eseguire : \n");
    printf(" [1] : Dopo aver letto N numeri (interi), con N scelto dall'utente e non superiore ai 30 elementi,  calcolare la somma e la media dei numeri pari, e dei numeri dispari.\n");
    printf(" [2] : Su una somma di denaro (relativa all'acquito di un prodotto) si vuole applicare uno sconto in base all'importo inserito seguendo il seguente schema:\n\tda 0 a 500 Euro sconto del 10%%;\n\tda 501 a 1000 sconto del 20%%;\n\toltre i 1001 sconto 30%%;\nIl programma dopo aver calcolato e visualizzato a video lo sconto ed il prezzo netto deve permettere di re-inserire ulteriori somme di denaro.\n");
    printf(" [3] : Scrivere un programma in C che, dopo aver letto N numeri (n scelto dall'utente) calcoli e visualizzi a video la somma dei numeri positivi, la somma dei numeri negativi in valore assoluto, il conteggio dei numeri negativi e positivi, la media dei numeri positivi e negativi.\n");
    printf(" [4] : Dato un numero N intero positivo, stampare la somma dei primi N numeri primi alternati (uno si e uno no)\n\n>");
    int esercizio;
    scanf("%d", &esercizio);

    //Input request
    switch(esercizio) {
        case 1 : ex1();break;
        case 2 : ex2();break;
        case 3 : ex3();break;
        case 4 : ex4();break;

        default : printf("Errore : Valore inserito non valido\n");
    }

    printf("Termine programma\n");
}