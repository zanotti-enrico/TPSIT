#include <stdio.h>

/*
 *Funzione che ritorna se un numero e' primo o no
*/
int numeroPrimo(int numero) {
    //Inizializza una variabile considerando il numero come primo
    int primo = 1;

    /*Ciclo che controlla tutti i numeri da 2 a numero - 1 se sono divisibili per il numero inserito
      se si, il numero non e' primo*/
    for(int iteratore = 2; iteratore < numero && primo; iteratore++){
        //Se si trova un divisore il numero non e' primo
        if(numero % iteratore == 0)
            primo = 0;
    }

    //Ritornare lo stato della variabile
    return primo;
}

int main(void) {
    //Contiene il nuero inserito e se sommare il numero o no
    int numeroInserito;
    int sommareNumero = 1; //Questa variabile si utilizza per stampare i numeri alternati

    //Valore di uscita
    int sommaNumeriPrimi = 0;

    /*Controllo sul numero inserito dall'utente*/
    do {
        //Richiesta di input
        printf("Inserire il numero di arrivo : ");
        scanf("%d", &numeroInserito);

        //Stampa di un messaggio di errore nel caso il numero inserito non sia positivo
        if(numeroInserito <= 0)
            printf("Errore : il numero inserito deve essere positivo");
    } while(numeroInserito <= 0);

    /*Ricerca dei primi N numeri primi e somma di essi in modo alternato*/
    for(int iteratore = 0; iteratore <= numeroInserito; iteratore++){
        if(numeroPrimo(iteratore)){
            if(sommareNumero) 
                sommaNumeriPrimi += iteratore;
            sommareNumero = !sommareNumero;
        }
    }

    //Stampa del risultato
    printf("La somma dei primi %d numeri primi alternati e' %d\n", numeroInserito, sommaNumeriPrimi);
}
