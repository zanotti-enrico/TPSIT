#include <stdio.h>

int main(void) {
    /* Price range where specific shares are contained in*/
    const double rangeStart = 2.50;
    const double rangeStop = 3.50;

    /* The word that, when inserted as the name of the action, will stop the program*/
    const char terminationString[] = "terminato";

    int shareAmount = 0; //Share amount
    int specificShareAmount = 0; //Amount of shares with the specific price
    double shareSum = 0.00; //Sum of the share price
    double shareAverage = 0.00; //Share price average
    double specificShareSum = 0.00; //Sum of share's price with specific price amount
    double specificShareAverage = 0.00; //Average price of shares with the specific price amount
    double shareMax = 0.00; //Share with maximum price
    double shareMin = 0.00; //Share with minimum price

    int terminate = 0; //Indicates program termination

    do {
        //User inputs string that gets saved in here
        char shareName[100];

        printf("Inserire la denominazione dell'azione : ");
        scanf("%s", shareName);

        /* For cycle which terminates at the termination of one of the two strings.
            checks if the input string equals the termination one*/
        for(int i = 0; shareName[i] != '\0' && terminationString[i] != '\0'; i++) {
            //If any difference is found between the strings terminate the loop
            if(shareName[i] != terminationString[i])
                break;
            /*If no difference found and the last element of the input string is reached then
             * the two strings are equal so stop the program and compute the final data
             */
            else if(shareName[i] == terminationString[i] && terminationString[i + 1] == '\0')
                terminate = 1;
        }
        
        //If the input doesn't match the input string then keep executing the program
        if(!terminate)
        {
            double currentAmount; //Contains the amount of the just inputted share

            //Check on user input
            do {
                printf("Inserire l'importo dell'azione : ");
                scanf("%lf", &currentAmount);

                if(currentAmount <= 0) //Error message
                    printf("Errore : L'importo dell'azione non deve essere negativo.\nReinserire il prezzo.\n");
            } while(currentAmount <= 0);
            
            /* After requesting the input of a number using scanf we need to consume from the input
             * buffer all characters until \n since scanf() doesn't consume them automatically when
             * reading numbers, to avoid scanf() skipping the next string read we call getchar() until
             * it reads a \n to consume all bytes in the buffer up until that.
            */
            while((getchar()) != '\n');

            shareSum += currentAmount; //Compute sum of share amounts
            shareAmount++; //Increment the share quantity
            //Compute the maximum and minimum share amount
            if(currentAmount > shareMax) {
                shareMax = currentAmount;
            } else if(currentAmount < shareMin) {
                shareMin = currentAmount;
            }
            //If the minimum action amount wasn't initialise then initialise it
            if(shareMin == 0)
                shareMin = currentAmount;
            
            //Sum and quantity of specific actions
            if(currentAmount >= rangeStart && currentAmount <= rangeStop)
            {
                specificShareAmount++;
                specificShareSum += currentAmount;
            }

            //Print a newline as separator
            printf("\n");
        }
    } while (!terminate);

    /*Compute averages and print out the results.
     * Compute these values only if they were initialised to avoid a division by 0
     * error, otherwise leave these values as they were initialised earlier, 0.
    */
    if(shareAmount > 0)
        shareAverage = shareSum / shareAmount;
    if(specificShareAmount > 0)
        specificShareAverage = specificShareSum / specificShareAmount;
    //Print all computed values.
    printf(
        "\nResoconto (%d Azioni totali) : \n\
        \tSomma dei prezzi delle azioni : %.2f Euro\n\
        \tMedia dei prezzi delle azioni : %.2f Euro\n\
        \tAzione con prezzo massimo : %.2f Euro\n\
        \tAzione con prezzo minimo : %.2f Euro\n\
        \tMedia azioni con prezzo compreso tra %.2f e %.2f Euro : %.2f Euro\n",
        shareAmount,
        shareSum,
        shareAverage,
        shareMax,
        shareMin,
        rangeStart,
        rangeStop,
        specificShareAverage
    );
}