#include <stdio.h>

int main(void) {
    /* Contiene il range di prezzo tra cui devono essere comprese le azioni specifiche */
    const double minCompeso = 2.50;
    const double maxCompreso = 3.50;

    /* La parola da inserire come nominazione dell'azione nel caso si voglia terminare
     * l'inserimento
    */
    const char terminazioneInserimento[] = "terminato";

    int qtaAzioni = 0; //Quantita' delle azioni
    int qtaAzioniSpecifiche = 0; //Contiene la quantita' delle azioni con importo specifico
    double sommaAzioni = 0.00; //Contiene la somma delle azioni
    double mediaAzioni = 0.00; //Contiene la media delle azioni
    double sommaAzioniSpecifico = 0.00; //Contiene la somma delle azioni con importo compreso tra minCompreso e maxCompreso
    double mediaAzioniSpecifico = 0.00; //Contiene la media delle azioni con importo compreso tra minCompreso e maxCompreso
    double maxAzione = 0.00; //L'azione con importo massimo
    double minAzione = 0.00; //L'azione con importo minimo

    int terminareInserimento = 0; //Determina la chiusura del loop del programma

    do {
        char nomeAzione[100]; //Contiene l'input dell'utente
        //Richiede un nuovo input da parte dell'utente
        printf("Inserire la denominazione dell'azione : ");
        scanf("%s", nomeAzione);

        //Controlla l'uguaglianza della stringa alla stringa di terminazione del programma
        //Terminare il ciclo di for alla terminazione di una delle stringhe
        for(int i = 0; nomeAzione[i] != '\0' && terminazioneInserimento[i] != '\0'; i++) {
            //Se durante il controllo si trovano differenze uscire dal loop
            if(nomeAzione[i] != terminazioneInserimento[i])
                break;
            /* Nel caso si siano sempre trovate uguaglianze e non si sia mai uscito dal loop
             * e l'ultimo elemento della stringa di controllo sia stato raggiunto allora la
             * stringa inserita dall'utente eguaglia quella della terminazione quindi
             * impostare la variabile terminareInserimento a vero in modo da terminare il programma.
             */
            else if(nomeAzione[i] == terminazioneInserimento[i] && terminazioneInserimento[i + 1] == '\0')
                terminareInserimento = 1;
        }
        
        //Se la stringa inserita e la terminazione non eguagliano allora continuare con l'esecuzione
        if(!terminareInserimento)
        {
            double importoCorrente; //Contiene l'importo dell'azione appena inserita

            //Controllo sul dato inserito
            do {
                //Inserimento del dato
                printf("Inserire l'importo dell'azione : ");
                scanf("%lf", &importoCorrente);

                if(importoCorrente <= 0) //Stampa di messaggio di errore in caso di prezzo negativo o nullo
                    printf("Errore : L'importo dell'azione non deve essere negativo.\nReinserire il prezzo.\n");
            } while(importoCorrente <= 0);
            
            /* Il buffer contenente l'input dell'utente va vuotato dopo l'inserimento di un numero
            * tramite scanf() altrimenti quando viene richiamata la funzione per l'inserimento di 
            * una stringa l'input dell'utente viene ignorato.
            * Per fare cio' consumare tutti i caratteri rimasti nel buffer fino al raggiungimento
            * di un '\n' che indica che l'utente ha premuto INVIO.
            */
            while((getchar()) != '\n');

            sommaAzioni += importoCorrente; //Calcolo della somma delle azioni
            qtaAzioni++; //Incremento della quantita' delle azioni
            //Calcolo dell'azione massima e minima
            if(importoCorrente > maxAzione) {
                maxAzione = importoCorrente;
            } else if(importoCorrente < minAzione) {
                minAzione = importoCorrente;
            }
            //Nel caso minAzione non sia stata inizializzata inizializzarla con l'azione corrente
            if(minAzione == 0)
                minAzione = importoCorrente;
            //Calcolo della somma e quantita' delle azioni specifiche (utilizzate per la media)
            if(importoCorrente >= minCompeso && importoCorrente <= maxCompreso)
            {
                qtaAzioniSpecifiche++;
                sommaAzioniSpecifico += importoCorrente;
            }

            //Stampa di una nuova riga come separatore
            printf("\n");
        }
    } while (!terminareInserimento);

    /*Al termine del programma effettuare il calcolo delle medie
    * e stampare i risultati.
    * Effettuare le divisioni solamente se le quantita' sono maggiori di 0
    * altrimenti printf() stampa "nan" in caso di una variabile contenente
    * il risultato di una divisione per 0.
    */
    if(qtaAzioni > 0)
        mediaAzioni = sommaAzioni / qtaAzioni;
    if(qtaAzioniSpecifiche > 0)
        mediaAzioniSpecifico = sommaAzioniSpecifico / qtaAzioniSpecifiche;
    //Stampa del resoconto
    printf(
        "\nResoconto (%d Azioni totali) : \n\
        \tSomma dei prezzi delle azioni : %.2f Euro\n\
        \tMedia dei prezzi delle azioni : %.2f Euro\n\
        \tAzione con prezzo massimo : %.2f Euro\n\
        \tAzione con prezzo minimo : %.2f Euro\n\
        \tMedia azioni con prezzo compreso tra %.2f e %.2f Euro : %.2f Euro\n",
        qtaAzioni,
        sommaAzioni,
        mediaAzioni,
        maxAzione,
        minAzione,
        minCompeso,
        maxCompreso,
        mediaAzioniSpecifico
    );
}