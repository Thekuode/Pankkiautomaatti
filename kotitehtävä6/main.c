#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vaihtoehdot();
int kayttajanAntamasyote();
void tervetuloa();
void katsoSaldo(double saldo);
double nostaRahaa(double saldo);
int luetiedosto();


int main()
{
    int rahe;


    rahe = luetiedosto();
    tervetuloa();
    kayttajanAntamasyote();
    vaihtoehdot(kayttajanAntamasyote, rahe);

    return 0;
}


//sanoo tervetuloa kaytttajalle
void tervetuloa(){
printf("\nTervetuloa kayttamaan pankkiautomaattia! Paina 1 jotta paaset etusivulle.\n\n>");
}

//kayttajalle niinsanottu valikko jossa kehoitetaan painamaan joitakin nappeja
int kayttajanAntamasyote(){
    int syote;
    for(; syote != 1; scanf("%d", &syote)){
        if(syote)
        printf("VIRHE!!! paina 1 paastaaksesi valikkoon! > ");
    }
    return(syote);
}

void vaihtoehdot(int n, int m){

    double saldo = m;
    double muisti;


    for(; n != 0; scanf("%d", &n)){ // for loopi alkaa

        if(n == 1){
            katsoSaldo(saldo);
        }

        if(n == 2){
            muisti = nostaRahaa(saldo);
            saldo -=muisti;

        }

        if(n == 3){
           printf("\nviimeaikaisin nosto %.2lf\n", muisti);
        }

        if(n !=0 || n != 1 || n !=2 || n !=3){
            printf("\nSyota 1 naet saldon\nPaina 2 paaset nostamaan rahaa\nPaina 3 naet viimeaikaiset tapahtumat\nTai 0 poistuakseesi\n\n> ");
        }

    } //for looppi loppuu


} //functio loppuu

void katsoSaldo(double saldo) {

    printf("\nSaldosi on %.2lf\n", saldo);

}

double nostaRahaa(double saldo){
    int nosta;
    double muisti = 0;

    printf("\nTilillasi on %.lf\n\nSyota summa jonka haluat nostaa >",saldo);
    scanf("%d", &nosta);

    int seteli50 = nosta / 50 - (nosta > 50 && nosta % 50 %20);
    int seteli20 = (nosta - seteli50 * 50) / 20;

    if(nosta != seteli50 * 50 + seteli20 * 20 || nosta > 1000){
        printf("Ei voi nostaa\n");
    } else {
        printf("\nsait %d. 20setelia\n", seteli20);
        printf("sait %d. 50setelia\n", seteli50);

    }

    muisti = nosta;

    return (muisti);
}

int luetiedosto(){

    char kayttajaNumero[256];
    char pinKoodi[256];
    char tarkistaPinKoodi[256];
    FILE *tiedosto;
    int saldo;
    int result;

    do{ // do alkaa
        printf("\n\nPankkiautomaatti\n\n\nAnna tilinumerosi > ");
        fgets(kayttajaNumero, 256, stdin);

        if(kayttajaNumero[strlen(kayttajaNumero)-1]== '\n'){
            kayttajaNumero[strlen(kayttajaNumero)-1]= '\0';
        }

        strcat(kayttajaNumero, ".acc");

        if((tiedosto = fopen(kayttajaNumero, "r")) != NULL){
            printf("Syota pin koodisi > ");

            fgets(pinKoodi, 256, stdin);

            if(pinKoodi[strlen(pinKoodi)-1] == '\r'){
                pinKoodi[strlen(pinKoodi)-1] = '\0';
            }

            fgets(tarkistaPinKoodi, 256, tiedosto);
            do{
                if(tarkistaPinKoodi[strlen(tarkistaPinKoodi)-1] == '\r'){
                    tarkistaPinKoodi[strlen(tarkistaPinKoodi)-1] = '\0';
                }

                if((result = strcmp(pinKoodi, tarkistaPinKoodi)) == 0){
                    fscanf(tiedosto,"%d", &saldo);
                    fclose(tiedosto);
                    return(saldo);
                } else{
                    printf("Vaara pin-koodi, yrita uudelleen");
                }

            } while (!result); /* toka do loppuu*/

        }/* eka iso if loppuu*/ else{
            printf("kayttajasi on suljettu");
        }

    } while (1);/*eka do loppuu */


} // functio loppuu


