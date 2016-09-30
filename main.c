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

int main(int argc, char **argv)
{
	
    
    
    
	return 0;
}
