#include <stdio.h>

//declarations des constantes
//ces constantes sont utilisées juste 
//pour garder lq beauté du programme 
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

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

/**
 * @brief affichage du text colore dans la console
 * @param couleur : la couleur(definie dans les constantes)
 * @param message : le message a afficher
 */
void printColored(char couleur[9], char *message)
{
    printf(couleur);
    printf(message);
    printf(RESET);
}

int main(int argc, char **argv)
{  
    //declaration des variables
    int partieE = 0; //la partie entiere du nombre
    int partieF = 0; // la partie flottante
    double nombre = 0; //le nombre la partie entier + la partie flottante
    char courant;    // le caractere courant dans le buffer
    short signe = 1; //le signe du nombre
    char signeA = '\0'; //la signe a afficher, utiliser pour afficher
                        //le signe + si l'utilisateur l'a taper
    short nbrInt = 0;  // pour detecter si le nombre entre est un nombre
                       //purement entier ou bien decimal, qui va sert a
                       //a afficher le bon nombre
    double f = 1;
    
    printColored(BLUE, "\t******************************************\n");
    printColored(BLUE, "\t***Convertion from a string to a number***\n");
    printColored(BLUE, "\t******************************************\n");
    printf("\n\n\t");
    //premierment en lire le nombre 
    printColored(CYAN, "Entrez un nombre ...");
    printf("\n\n\t");
    courant = getchar();
    
    //verifier la validite du caractere courant
    if( !isNumber(courant) && !isSign(courant) && !isPoint(courant) )
    {
        //on affiche un message d'erreur
        printColored(RED, "\n\terreur entrer un nombre valide");
        printf("\n\n\t");
        return(0);
    }
    
    //si le caractere courant est un signe
    if( isSign(courant) )
        //on sauvgarde le signe dans une variable
        (courant == '-') ? (signe = -1): (signe = 1, signeA = '+') ;
        
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
            printColored(RED, "\n\terreur entrer un nombre valide 2");
            printf("\n\n\t");
            return(0);
        }
        //si il est valide on l'ajout a la partie entiere
        partieE = (partieE*10) + (courant - '0') ;
    }
    
    //si on est dans la fin de la chaine on saute vers la fin du programme
    if( courant == '\n' ) 
    {
        //il y a pas de virgule entree, alors le nombre est purmemet entier
        nbrInt = 1;
        //on saut vers la fin du programme pour afficher le nombre
        goto Fin;
    }

    //calcule de la partie flottante
    flottant :
    while( (courant = getchar()) != '\n' )
    {
        //test la validite du nombre
        if( !isNumber(courant) )
        {
            //on affiche un message d'erreur
            printColored(RED, "\n\terreur entrer un nombre valide 2");
            printf("\n\n\t");
            return(0);
        }
        //si il est valide on l'ajoute a parie flottante
        partieF = (partieF*10) + (courant - '0');
        f *= 0.1;
    }
       
       
    Fin :
    //calcule de la valuer du nombre
    nombre = (partieE + (partieF*f)) * signe;
    
    //affichage du nombre
    printf("\n\n\t");
    printColored(CYAN, "**************************************************\n");
    printf("\t");
    printColored(CYAN, "* la chaine de caractere Transformée en nombre : *\n");
    printColored(CYAN, "\t**************************************************");
    printf("\n\n\t");
    printf( BLUE );//changer la couleur du text vers le vert
    //si le nombre est purment entier, on affiche la partie entier
    if( nbrInt )
        signeA == '+' ? printf("+%d", partieE) : printf("%d", partieE);
    //le nombre contient une partie flottante, alors on doit l'afficher
    else
        signeA == '+' ? printf("+%f", nombre) : printf("%f", nombre);
    printf( RESET "\n\n\t");
    
	return (0);
}
