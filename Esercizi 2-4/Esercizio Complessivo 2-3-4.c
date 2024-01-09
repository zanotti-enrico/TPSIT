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

void esercizio1() {
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
}

void esercizio2() {
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
        } else if(prezzo > primoScontoPrezzo && prezzo <= secondoScontoPrezzo) {
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
}

void esercizio3 () {
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

void esercizio4() {
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


int main(void) {
    /*Stampa delle consegne dei 4 esercizi*/
    printf("Inserire l'esercizio da eseguire : \n");
    printf(" [1] : Dopo aver letto N numeri (interi), con N scelto dall'utente e non superiore ai 30 elementi,  calcolare la somma e la media dei numeri pari, e dei numeri dispari.\n");
    printf(" [2] : Su una somma di denaro (relativa all'acquito di un prodotto) si vuole applicare uno sconto in base all'importo inserito seguendo il seguente schema:\n\tda 0 a 500 Euro sconto del 10%%;\n\tda 501 a 1000 sconto del 20%%;\n\toltre i 1001 sconto 30%%;\nIl programma dopo aver calcolato e visualizzato a video lo sconto ed il prezzo netto deve permettere di re-inserire ulteriori somme di denaro.\n");
    printf(" [3] : Scrivere un programma in C che, dopo aver letto N numeri (n scelto dall'utente) calcoli e visualizzi a video la somma dei numeri positivi, la somma dei numeri negativi in valore assoluto, il conteggio dei numeri negativi e positivi, la media dei numeri positivi e negativi.\n");
    printf(" [4] : Dato un numero N intero positivo, stampare la somma dei primi N numeri primi alternati (uno si e uno no)\n\n>");
    int esercizio;
    scanf("%d", &esercizio);

    //Richiesta di input
    switch(esercizio) {
        case 1 : esercizio1();break;
        case 2 : esercizio2();break;
        case 3 : esercizio3();break;
        case 4 : esercizio4();break;

        default : printf("Errore : Valore inserito non valido\n");
    }

    printf("Termine programma\n");
}