#include <stdio.h>

int main() {
    //Costanti utilizzate nel programma
    const int primoScontoPrezzo = 500;
    const int secondoScontoPrezzo = 1000;
    const int primoSconto = 10;
    const int secondoSconto = 20;
    const int terzoSconto = 30;

    //Variabili utilizzate all'interno del programma
    int terminaCiclo = 0;
    double prezzo, sconto, prezzoScontato;

    //Ciclo continuo fino al settaggio della variabile terminaCiclo
    do {
        //Richiesta inserimento prezzo da scontare
        printf("Inserire un prezzo da scontare : ");
        scanf("%f", &prezzo);

        //Prezzo compreso tra 0 e la prima soglia di sconto
        if(prezzo > 0 && prezzo <= primoScontoPrezzo) {
            printf("Sconto applicato : %d%%", primoSconto);

            //Calcolo dello sconto
            sconto = prezzo * (primoSconto / 100.00);
            prezzoScontato = prezzo - sconto;
        //Prezzo compreso tra la prima soglia di sconto e la seconda soglia di sconto
        } else if(prezo > primoScontoPrezzo && prezzo <= secondoScontoPrezzo) {
            printf("Sconto applicato : %d%%", secondoSconto);

            //Calcolo dello sconto
            sconto = prezzo * (primoSconto / 100.00);
            prezzoScontato = prezzo - sconto;
        //Prezzo oltre la seconda soglia di sconto
        } else if(prezzo > secondoScontoPrezzo) {
            printf("Sconto applicato : %d%%", terzoSconto);

            //Calcolo dello sconto
            sconto = prezzo * (terzoSconto / 100.00);
            prezzoScontato = prezzo - sconto;
        //Prezzo negativo - errore
        } else {
            printf("Errore : il prezzo non deve essere negativo.");
        }

        //Richiesta di chiusura ciclo
        printf("Si vuole inserire un nuovo valore di prezzo? [0, 1]");
        scanf("%d", &terminaCiclo);

        //Se il numero inserito dall'utente differisce da 0 impostarlo a 1 per terminare il ciclo while
        if(terminaCiclo != 0)
            terminaCiclo = 1;
    } while(!terminaCiclo);

    return 0;
}