#include <stdio.h>
#include <math.h>

//declarations des constantes
//ces constantes sont utilisées juste 
//pour garder lq beauté du programme 
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


/**
 * @brief verifier si un caratere est nombre ou non 
 * @param c : le caractere a verifier
 * @return  0 si le caractere n'est pas un nomre
 *          1 si le caractere est un nombre
 **/
int isNumber(char c)
{
    //le caractere c n'est un nombre
    if( ( c > '9' ) || ( c < '0' ) ) 
        return(0);
    //le caractere c est pas un nombre
    return(1);
}

/**
 * @brief verifier si un caratere est une signe ou non 
 * @param c : le caractere a verifier
 * @return 0 si le caractere n'est pas une signe
 *         1 si le caractere est une signe
 */
int isSign(char c)
{
    //le caractere c est une signe
    if( ( c == '+' ) || ( c == '-' ) ) 
        return(1);
    //le caractere c n'est pas une signe
    return(0);
}

/**
 * @brief verifier si un caratere est un point ou non 
 * @param c : le caractere a verifier
 * @return 0 si le caractere n'est pas un point
 *         1 si le caractere est un point
 */
int isPoint(char c)
{
     //le caractere c est un point
    if(  c == '.'  ) 
        return(1);
    //le caractere c n'est pas une signe
    return(0);       
}

int main(int argc, char **argv)
{  
    //declaration des variables
    int partieE = 0; //la partie entiere du nombre
    int partieF = 0; // la partie flottante
    double nombre = 0; //le nombre la partie entier + la partie flottante
    char courant;    // le caractere courant dans le buffer
    char signe = '\0'; //le signe du nombre
    double f = 1;
    
    printf(ANSI_COLOR_BLUE "\t***Convertion from a string to a number***");
    printf(ANSI_COLOR_RESET "\n\n");
    
    //premierment en lire le nombre 
    printf( ANSI_COLOR_YELLOW "\tEntrez un nombre ..." );
    printf( ANSI_COLOR_RESET "\n\n\t" );
    courant = getchar();
    
    //verifier la validite du caractere courant
    if( !isNumber(courant) && !isSign(courant) && !isPoint(courant) )
    {
        //on affiche un message d'erreur
        printf(ANSI_COLOR_RED "erreur entrer un nombre valide");
        printf( ANSI_COLOR_RESET "\n");
        return(0);
    }
    
    //si le caractere courant est un signe
    if( isSign(courant) )
        //on sauvgarde le signe dans une variable
        signe = courant;
        
    //si le caractere courant est un nombre
    if( isNumber(courant) )
        //on calcule sa valuer puit on lajout a partieE
        partieE = courant - '0';
    
    if( isPoint(courant) )
        //on saut vers la partie qui calcule la partie flottant
        goto flottant;

    
    //calcule de la partie entiere
    while ( (( courant = getchar() ) != '\n') && ( courant != '.' ) )
    {
        //si le caractere entre n'est pas valide
        if( !isNumber(courant) )
        {
            //on affiche un message d'erreur
            printf(ANSI_COLOR_RED "erreur le nombre n'est pas valide [0-9]");
            printf( ANSI_COLOR_RESET "\n");
            return(0);
        }
        partieE = (partieE*10) + (courant - '0') ;
    }
    
    //calcule de la partie flottante
    flottant :
    while( ( courant = getchar() ) != '\n' )
    {
        if( !isNumber(courant) )
        {
            //on affiche un message d'erreur
            printf(ANSI_COLOR_RED "erreur le nombre n'est pas valide [0-9]");
            printf( ANSI_COLOR_RESET "\n\n\t");
            return(0);
        }
        partieF = (partieF*10) + (courant - '0');
        f *= 0.1;
    }
       
       
    
    nombre = (partieE + (partieF*f));
    //apres en pris en considiration le signe
    
    printf(ANSI_COLOR_GREEN);
    printf("\n\n\t%c%f \n\n\t", signe, nombre);
    printf(ANSI_COLOR_RESET);
    
	return 0;
}
