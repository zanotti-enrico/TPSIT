#include <stdio.h>

int main(void) {
    //Dimensione del vettore definita dall'utente
    int vecSize;

    //Richiesta dimensione numeri
    do {
        printf("Quanti numeri si vogliono inserire?");
        scanf("%d", &vecSize);

        //Controllo sul dato inserito
        if(vecSize <= 0)
            printf("Errore : la dimensione del vettore non puo' essere negativa o nulla.\n");
    } while(vecSize <= 0);

    //Definizione dei tre vettori con dimensione definita dall'utente
    int vec1[vecSize], vec2[vecSize], sum[vecSize];

    //Popolamento del primo vettore
    printf("Popolamento primo vettore :\n");
    for(int i = 0; i < vecSize; i++) {
        printf("Inserire il valore %d: ", i+1);
        scanf("%d", (vec1 + i));
    }
    //Popolamento del secondo vettore
    printf("Popolamento secondo vettore:\n");
    for(int i = 0; i < vecSize; i++) {
        printf("Inserire il valore %d: ", i+1);
        scanf("%d", (vec2 + i));
    }

    //Calcolo e stampa della somma dei due vettori
    printf("Somma dei due vettori:\n");
    for(int i = 0; i < vecSize; i++) {
        sum[i] = vec1[i] + vec2[i];
        printf("Somma numero %d: %d\n", i+1, sum[i]);
    }

    return 0;
}