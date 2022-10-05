#include <stdio.h>
#include <stdlib.h>

int main()
{

    int tunnusluku = 1550, syote;
    double saldo = 10000, nosta, temp;



    //kysytaan kayttajalta tunnuslukua, tallentaa tunnusluvun "tunnusluku"
    printf("Syota nelinumeroinen tunnusluku. Pankkiautomaatin Demoversion tunnusluku 1550 >");
    scanf("%d", &tunnusluku);





    //varmistetaan että käyttäjä käyttää demoversion tunnuslukua eli 1550
    for(tunnusluku; tunnusluku != 1550; scanf("%d", &tunnusluku)) {
        if(tunnusluku )
        printf("VIRHE!!! Syota demoversion tunnusluku  >");

    }
    printf("\n");

    printf("paina 1 paaset nakemaan saldo\nPaina 2 paaset nostamaan rahaa\nPaina 3 naet tapahtumat\nPoistu automaatista 0\n>");

    // aloitetaan do while looppi jotta pääsemme käyttämään valikkoa niin kauan kun painetaan numeroa 0 josta se poistuu sen jälkeen
    do {
    // scanf ottaa kayttajan antaman numeron ja alkaa switch lauseella katsomaan vaihto ehdon mikä on valittu
    scanf("%d", &syote);
    switch(syote){

    case 1:
        printf("saldosi on > %.2f Euroa\n\npaina 1, 2 tai 3 jatkaaksesi tai 0 poistuaaksesi\n", saldo);
        break;
    case 2:
        printf("valitse syotettava summa: \n");
        scanf("%lf", &nosta);
        temp = nosta;
        saldo -= nosta;
        printf("Tililta nostettiin %.2lf euroa. jaljella enaan %.2lf\n\npaina 1, 2 tai 3 jatkaaksesi tai 0 poistuaaksesi\n", nosta, saldo);
        break;
    case 3:
        printf("viimeaikaisin nosto %.2lf\n\npaina 1, 2 tai 3 jatkaaksesi tai 0 poistuaaksesi\n", temp);

        break;
    case 0:
        printf("Kiitos demoversion testaamisesta.\n");
        return 0;
        break;
    // jos ei ole oikea syotetta kysytaan kayttajalta oikeaa sellaista
    default:
        printf( "Anna oikea syote\n" );
        printf( "1, 2 tai 3 : " );
        scanf( "%d", &syote);
        break;

        } //switch loppuu
    } /*  do loppuuu*/ while(syote != 0); //  whilen sisalle laitetaan ehto


    return 0;
}
