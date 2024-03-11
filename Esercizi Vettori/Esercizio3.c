#include <stdio.h>
#include <stdbool.h>

int main(void) {
    //Richiesta all'utente della dimensione del vettore
    int vecSize = 0;
    do {
        //Ricavo della dimensione del vettore
        printf("Inserire la dimensione del vettore :");
        scanf("%d", &vecSize);
        //Controllo sul dato inserito
        if(vecSize <= 0)
            printf("Errore : il valore inserito non deve essere negativo o nullo.\n");
    } while(vecSize <= 0);

    //Definizione del vettore
    int vettore[vecSize];
    //Riempimento del vettore
    for(int fillIterator = 0; fillIterator < vecSize; fillIterator++) {
        //Richiesta di inserimento del numero corrente nell'array
        printf("Inserire il valore numero %d :", fillIterator);
        scanf("%d", vettore + fillIterator);
    }

    //Inserimento di un nuovo valore
    printf("\nInserire un nuovo valore per controllare se si trova nell'array :");
    int checkValue;
    scanf("%d", &checkValue);

    //Controllo se il valore si trova nell'array
    int valuePresentAmount = 0; //Quante volte il valore si trova nell'array
    for(int checkIterator = 0; checkIterator < vecSize; checkIterator++) {
        //Se il valore viene trovato nell'array allora incrementare il numero di volte che esso viene trovato e stampare su schermo dove
        if(checkValue == vettore[checkIterator])
        {
            valuePresentAmount++;
            printf("Valore trovato nell'array in posizione %d\n", checkIterator);
        }
    }

    //Stampare quante volte il valore e' stato trovato
    printf("Il valore inserito si trova nell'array %d volte\n", valuePresentAmount);

    return 0;
}