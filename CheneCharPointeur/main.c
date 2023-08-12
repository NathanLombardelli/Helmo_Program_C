#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char maString[7+1]; /*7 caractére +1 pour le /0 */
    char *p;

    strncpy(maString,"coucou\0",7);

    p = strstr(maString, "uco");

    if(p!= NULL){
        printf("Trouvé à la position %li -> %s\n", (p-maString), p);
    }else{
        printf("Non trouvé\n");
    }
    return EXIT_SUCCESS;
}
