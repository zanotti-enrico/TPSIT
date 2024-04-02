#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* La funzione ritorna la lettera passata convertita in minuscolo
 * se la lettera passata e' gia' minuscola la ritorna.
 * se la lettera passata non e' una lettera, ritorna NULL
*/
char toLower(char input) {
    //Se l'input e' una lettera maiuscola
    if(input >= 'A' && input <= 'Z')
        //Calcolare la corrispondente lettera minuscola e ritornarla
        return (input - ('A' - 'a'));
    //Se l'input e' una lettera minuscola
    else if(input >= 'a' && input <= 'z')
        //Ritornare l'input
        return input;
    //Se l'input e' un altro carattere
    else return '\0'; //Ritornare NULL
}

/*
 * La funzione ritorna vero quando il carattere passato e' una lettera (maiuscola o minuscola)
*/
bool isLetter(char check) {
    //Convertire la lettera in carattere minuscolo, per evitare doppi controlli
    check = toLower(check);
    //Controllo se la lettera e' compresa tra A-Z, maiuscola o minuscola, ritornare il risultato
    return (check >= 'a' && check <= 'z');
}

/* La funzione ritorna se la lettera passata e' una vocale*/
bool isVowel (char check) {
    //Convertire la lettera in carattere minuscolo
    check = toLower(check);

    return ( //Controllo se la lettera e' una vocale
        check == 'a' || check == 'e' || check == 'i' || check == 'o' || check == 'u'
    );
}

int main(void) {
    //Lunghezza massima della stringa
    const int maxLen = 100;
    //La stringa da utilizzare
    char string[maxLen];
    
    //Riempire str con un array contenente la stringa
    printf("Inserire una stringa: ");
    scanf("%s", string);

    //Richiedere all'utente quale lettera vuole contare all'interno della stringa
    char letterToCheck;
    printf("Inserire una lettera da contare all'interno della stringa inserita: ");
    scanf(" %c", &letterToCheck);
    //Determina quante volte la lettera viene trovata all'interno della stringa
    int letterToCheckFound = 0;

    //Salvare in una variabile la lunghezza della stringa senza dover invocare la funzione ogni volta
    int strLength = strlen(string);

    //Contare il numero di vocali e consonanti
    int vowelAmount = 0;
    int consonantAmount = 0;
    //Determina se la stringa contiene soltanto lettere
    bool letterOnly = true;
    //Determina se la stringa contiene doppie
    bool doubles = false;
    //Contiene le lettere presenti nella prima e seconda stringa
    bool lettersFirstStr[26];
    bool lettersSecondStr[26];

    //Inizializzare i vettori contenenti le lettere presenti nella prima e nella seconda stringa
    // con tutti i valori falsi
    for(int initialisingIterator = 0; initialisingIterator < 26; initialisingIterator++)
    {
        lettersFirstStr[initialisingIterator] = false;
        lettersSecondStr[initialisingIterator] = false;
    }

    /*Iterare per tutti i caratteri della stringa
     *Ciclo utilizzato per il conteggio di consonanti e vocali, per il controllo se la stringa e' formata soltanto da lettere
     * e per il controllo di quante volte la lettera determinata dall'utente si trova nella stringa.
    */
    for(int currentChar = 0; currentChar < strLength; currentChar++) {
        //Se il carattere corrente e' una lettera
        if(isLetter(string[currentChar]))
        {
            //Se e' una vocale incrementa il numero di vocali
            if(isVowel(string[currentChar]))
                vowelAmount++;
            else //Altrimenti e' una consonante
                consonantAmount++;

            //Controllo per le doppie
            //Se siamo almeno in posizione 1 e il carattere nella posizione corrente eguaglia quello nella posizione precedente abbiamo trovato una doppia
            if(currentChar > 0 && string[currentChar] == string[currentChar - 1])
                doubles = true;

            //Salvare la presenza della lettera corrente nella stringa
            lettersFirstStr[toLower(string[currentChar]) - 'a'] = true;
        } else //Se viene trovato un carattere che non e' una lettera allora la stringa non contiene soltanto lettere
            letterOnly = false;


        //Se il carattere corrente e' la lettera da contare, allora incrementare il contatore di quella lettera
        if(string[currentChar] == letterToCheck)
            letterToCheckFound++;
    }
    
    /*Creazione di altre due stringhe una contenente le lettere pari e l'altra contenente le lettere dispari
     * vengono inoltre creati i due iteratori per la modifica delle due stringhe
    */
    char evenStr[(strLength / 2 + 1)];
    int evenStrIterator = 0;
    char oddStr[(strLength / 2 + 1)];
    int oddStrIterator = 0;

    //Riempimento delle due stringhe
    for(int fillStr = 0; fillStr < strLength; fillStr++) {
        //In base all'iteratore del ciclo, modificare la stringa apposita, incrementando il suo iteratore
        //Se siamo in posizione pari, modificare la stringa delle posizioni pari, altrimenti modificare quella delle posizioni dispari
        if(fillStr % 2 == 0)
            evenStr[evenStrIterator++] = string[fillStr];
        else
            oddStr[oddStrIterator++] = string[fillStr];
    }

    //Appendere alla fine delle due stringhe il terminatore in modo da terminare correttamente la stringa
    evenStr[evenStrIterator] = '\0';
    oddStr[oddStrIterator] = '\0';

    //Stampa dei risultati
    printf("\nNumero di vocali : %d | Numero di consonanti : %d\n", vowelAmount, consonantAmount);
    printf("La stringa ");
    if(!letterOnly)
        printf("non ");
    printf("e' composta da sole lettere.\n");
    printf("Conteggio lettera '%c' : %d\n", letterToCheck, letterToCheckFound);
    printf("Separazione stringa:\n\tStringa posizioni pari : '%s'\n\tStringa posizioni dispari : '%s'\n", evenStr, oddStr);
    printf("La stringa ");
    if(!doubles)
        printf("non ");
    printf("contiene doppie.\n");

    //Inserimento della seconda stringa
    char secondString[maxLen];
    printf("\nInserire una seconda stringa:");
    scanf("%s", secondString);
    //Determinare la lunghezza della seconda stringa
    int secondStrLen = strlen(secondString);

    //Determinare quale delle due stringhe e' piu' lunga
    printf("La ");
    if(strLength > secondStrLen)
        printf("prima");
    else
        printf("seconda");
    printf(" stringa e' la piu' lunga.\n");

    //Contiene il numero di vocali e consonanti presenti nella seconda stringa
    int secondStrConsonants = 0;
    int secondStrVowels = 0;

    //Iterare in tutti i caratteri della seconda stringa per i rispettivi controlli
    for(int currentChar = 0; currentChar < secondStrLen; currentChar++)
    {
        //Nel caso si trovi una lettera
        if(isLetter(secondString[currentChar]))
        {
            //Se la lettera corrente e' una vocale
            if(isVowel(secondString[currentChar]))
                //Incrementare il numero di vocali nella seconda stringa
                secondStrVowels++;
            else
                //Altrimenti incrementare il numero di consonanti
                secondStrConsonants++;

            //Salvare la presenza della lettera corrente della stringa
            lettersSecondStr[toLower(secondString[currentChar]) - 'a'] = true;
        }
    }

    //Stampare quale delle due stringhe contiene piu' consonanti
    printf("La ");
    if(secondStrConsonants > consonantAmount)
        printf("seconda");
    else    
        printf("prima");
    printf(" stringa contiene piu' consonanti.\n");
    //Stampare quale delle due stringhe contiene piu' vocali
    printf("La ");
    if(secondStrVowels > vowelAmount)
        printf("seconda");
    else    
        printf("prima");
    printf(" stringa contiene piu' vocali.\n");
    
    //Effettuare una ricerca sui caratteri presenti in entrambe le stringhe
    printf("Lettere presenti in entrambe le stringhe :\n");
    //Ricerca in tutte le lettere
    for(int currentLetter = 0; currentLetter < 26; currentLetter++)
        //Se la lettera corrente e' presente in entrambe le stringhe
        if(lettersFirstStr[currentLetter] && lettersSecondStr[currentLetter])
            //Stampare la lettera
            printf("\tlettera '%c'\n", (char)(currentLetter + 'a'));

    return 0;
}