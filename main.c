#include <stdio.h>

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
    if( ( c == '+' ) || ( c == '-' ) ) 
        return(1);
    //le caractere c n'est pas une signe
    return(0);       
}


int main(int argc, char **argv)
{
	
    //declaration des variables
    int partieE = 0; //la partie entiere du nombre
    int partieF = 0; // la partie flottante
    char courant;    // le caractere courant dans le buffer
    char signe = ' '; //le signe du nombre
    
    //premierment en lire le nombre 
    printf("Entrez un nombre");
    courant = getchar();
    
    //verifier la validite du caractere courant
    if( !isNumber(courant) || !isSign(courant) || !isPoint(courant) )
    {
        //on affiche un message d'erreur
        printf("erreur entrer un nombre valide");
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
    
	return 0;
}
