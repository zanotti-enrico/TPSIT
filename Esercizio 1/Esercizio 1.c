#include <stdio.h>

int main(void) {
    //Richiedere all'utente la quantitá di numeri da inserire verificando
    // un controllo in modo che non sia maggiore di 30
    int qtaNumeri;
    do {
        printf("Inserire la quantita' di numeri di cui calcolare la somma e la media : ");
        scanf("%d", &qtaNumeri);

        if(qtaNumeri > 30)
            printf("Errore : La quantita' dei numeri non deve essere maggiore di 30\n");
    } while(qtaNumeri > 30);

    int numeri[qtaNumeri]; //Contiene i numeri inseriti

    //Contiene la somma e la media dei numeri pari e dei numeri dispari
    int sommaPari = 0;
    int sommaDispari = 0;
    double mediaPari = 0;
    double mediaDispari = 0;

    //Riempire l'array con numeri interi inseriti dall'utente
    for(int contatore = 0; contatore < qtaNumeri; contatore++) {
        printf("Inserire il numero %d : ", contatore + 1);
        scanf("%d", &numeri[contatore]);
    }

    //Calcolare la somma dei numeri pari e dispari e salvarla nelle rispettive variabili
    for(int contatore = 0; contatore < qtaNumeri; contatore++) {
        if(numeri[contatore] % 2 == 0)
            sommaPari += numeri[contatore];
        else
            sommaDispari += numeri[contatore];
    }

    //Calcolare la media dei numeri pari e dispari usando il cast per fare una divisione fra numeri a virgola mobile
    mediaPari = (double)sommaPari / qtaNumeri;
    mediaDispari = (double)sommaDispari / qtaNumeri;

    //Stampare a schermo i risultati
    printf(
        "La somma dei numeri pari risulta : %d\nLa somma dei numeri dispari risulta : %d\nLa media dei numeri pari risulta : %.2f\nLa media dei numeri dispari risulta : %.2f\n", 
        sommaPari, 
        sommaDispari, 
        mediaPari, 
        mediaDispari
    );

    //Terminare il programma
    return 0;
}