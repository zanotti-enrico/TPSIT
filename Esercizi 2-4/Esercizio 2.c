#include <stdio.h>

int main() {
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