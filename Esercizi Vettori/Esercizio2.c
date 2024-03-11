#include <stdio.h>

int main(void) {
    //Dimensione del vettore passato
    int vecSize;
    //Definizione della dimensione del vettore da parte dell'utente
    do {
        //Inserimento dato
        printf("Inserire la quantita' di numeri da inserire :");
        scanf("%d", &vecSize);
        //Controllo sul dato
        if(vecSize <= 0)
            printf("Errore : Il numero inserito non deve essere negativo o nullo\n");
    } while(vecSize <= 0);

    //Definizione dell'array con la dimensione specificata
    int vec[vecSize];
    //Definizione degli array contenenti i numeri pari e dispari
    int vecEven[vecSize];
    int vecOdd[vecSize];
    //Definizione di due variabili che definiscono la dimensione dei due vettori (ora sono vuoti)
    int vecEvenSize = 0;
    int vecOddSize = 0;

    //Popolamento del vettore
    for(int i = 0; i < vecSize; i++) {
        printf("Inserire il valore numero %d: ", i+1);
        scanf("%d", vec+i); //Passaggio del puntatore dell'elemento dell'array a scanf
    }

    //Controllo del vettore
    for(int i = 0; i < vecSize; i++) {
        if(vec[i] % 2 == 0) { //Se il numero corrente e' pari
            //Salvarlo nell'array dei numeri pari, incrementando la dimensione di esso
            vecEven[++vecEvenSize] = vec[i];
        } else { //Altrimenti se esso e' dispari
            //Salvarlo nell'array dei numeri dispari, incrementando la dimensione di esso
            vecOdd[++vecOddSize] = vec[i];
        }
    }

    //Stampa dell'output dei numeri pari
    printf("Numeri pari :\n");
    for(int i = 0; i < vecEvenSize; i++)
        printf("Numero %d: %d\n", i+1, vecEven[i]);

    //Stampa dell'output dei numeri dispari
    printf("Numeri dispari :\n");
    for(int i = 0; i < vecOddSize; i++)
        printf("Numero %d: %d\n", i+1, vecOdd[i]);

    return 0;
}