#include <stdio.h>

int main(void) {
    int qtaNumeri;

    //Richiedere l'input all'utente
    printf("Determinare la quantita' di numeri da inserire : ");
    scanf("%d", &qtaNumeri);

    /*Variabili utilizzate */
    int sommaPositivi = 0;
    int sommaNegativi = 0;
    int qtaPositivi = 0;
    int qtaNegativi = 0;
    double mediaPositivi, mediaNegativi;
    int numeroCorrente;

    for(unsigned int iterator = 0; iterator < qtaNumeri; iterator++)
    {
        printf("Inserire il numero %d : ", iterator + 1);
        scanf("%d", &numeroCorrente);

        /*In base al segno del numero incrementare la quantita' di numeri
            e la somma dei valori assoluti dei numeri relativi*/
        if(numeroCorrente >= 0) {
            qtaPositivi++;
            sommaPositivi += numeroCorrente;
        } else if(numeroCorrente < 0) {
            qtaNegativi++;
            sommaNegativi += (numeroCorrente * -1);
        }
    }

    /*Calcolo della media dei numeri positivi e negativi*/
    mediaPositivi = (double)sommaPositivi / (double)qtaPositivi;
    mediaNegativi = (double)sommaNegativi / (double)qtaNegativi;

    //Stampa risultati
    printf(
        "Quantita' numeri positivi : %d\n\
        Somma numeri positivi : %d\n\
        Media numeri positivi : %lf\n\n\
        Quantita' numeri negativi : %d\n\
        Somma numeri negativi : %d\n\
        Media numeri negativi : %lf\n\n", 
        qtaPositivi, sommaPositivi, mediaPositivi, qtaNegativi, sommaNegativi, mediaNegativi
    );
}