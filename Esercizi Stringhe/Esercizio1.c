#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    //Array contenente la stringa
    char input[128];
    //Il carattere da rimuovere dalla stringa
    char removeChar;
    //La posizione del carattere da rimuovere dalla stringa
    int removePosition;
    //Il carattere da aggiungere a fine stringa
    char addChar;

    //Riempire la stringa con l'input utente
    printf("Inserire una stringa :");
    scanf("%s", input);
    //Salvare la lunghezza iniziale della stringa
    int length = strlen(input);

    //Una volta riempita la stringa, richiedere all'utente il carattere da rimuovere
    printf("Inserire il carattere da rimuovere dalla stringa :");
    scanf(" %c", &removeChar);

    //Rimuovere i caratteri indicati dalla stringa
    //Ricercare tutti i caratteri interessati dalla stringa
    for(int currentChar = 0; currentChar < length; currentChar++)
        //Se viene trovato il carattere da rimuovere
        if(input[currentChar] == removeChar)
        {
            //Decrementare la lunghezza
            length--;
            //Spostare, dall'elemento corrente, tutti i caratteri della stringa indietro di 1
            for(int removeChar = currentChar; removeChar <= length; removeChar++)
                input[removeChar] = input[removeChar + 1];
            //Riportare l'iteratore indietro di una posizione perche' ora il carattere successivo e' il carattere corrente
            currentChar--;
        }
    //Stampare la nuova stringa con i caratteri rimossi
    printf("Stringa modificata : %s\n", input);

    //Chiedere all'utente la posizione del carattere da andare a eliminare nella stringa
    bool invalidInput = false;
    do {
        //Reimpostare la variabile di input non valido
        invalidInput = false;

        //Richiedere l'input all'utente
        printf("Inserire la posizione del carattere da eliminare all'interno della stringa:\n");
        scanf("%d", &removePosition);

        //Verificare l'inserimento
        if(removePosition < 0 || removePosition >= length)
        {
            printf("Errore : l'inserimento deve essere compreso fra %d e %d\n", 0, length);
            invalidInput = true;
        }
    } while(invalidInput); //Continuare l'esecuzione finche' l'input e' valido

    //Decrementare la lunghezza della stringa
    length--;
    //Partendo dalla posizione specificata, traslare tutti i caratteri della stringa di 1
    for(int removeChar = removePosition; removeChar <= length; removeChar++)
        input[removeChar] = input[removeChar + 1];

    //Stampare la nuova stringa con il carattere rimosso
    printf("Stringa modificata : %s\n", input);

    //Richiedere all'utente il carattere da inserire in posizione finale
    printf("Inserire il carattere da inserire in posizione finale:\n");
    scanf(" %c", &addChar);
    //Incrementare la lunghezza di 1
    length++;
    //Aggiungere alla fine della stringa il carattere
    input[length - 1] = addChar;
    input[length] = '\0';

    //Stampare la stringa modificata con il carattere aggiunto
    printf("Stringa modificata : %s\n", input);

    return 0;
}