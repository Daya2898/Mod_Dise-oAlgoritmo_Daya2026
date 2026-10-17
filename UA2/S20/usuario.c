// validar acceso de usuario, clave
// convirtiendo inicio sesion con fgets, longitud y 3 intentos limites

#include <stdio.h>
#include <string.h>  // usar strlen, strcmp y strcspn

int main (void){
    char clave[30];
    char usuario[30];
    int intentos = 0;
    int accesoExitoso = 0;
    const int MAX_INTENTOS = 3; 

    do{
        // Uso de fgets para el usuario
        printf("Usuario: ");
        fgets(usuario, sizeof(usuario), stdin);
        usuario[strcspn(usuario, "\n")] = '\0'; // Quita el enter

        // Clave usando fgets
        printf("Clave: ");
        fgets(clave, sizeof(clave), stdin);
        clave[strcspn(clave, "\n")] = '\0';

        // Validacion longitud minima (al menos 4 caracteres)
        if(strlen(usuario) < 4){
            printf("El usuario debe tener al menos 4 caracteres\n");
            continue; // Pasa al siguiente intento sin contar este como intento fallido oficial
        }
    
        intentos++; // Incremento de intentos oficiales

        // Validar si usuario es "admin" y la clave es "Ina2026"
        if(strcmp(usuario, "admin") == 0 && strcmp(clave, "Ina2026") == 0){
            accesoExitoso = 1;
            break; // Termina ciclo
        } else {
            // Si falla, muestra un mensaje indicando el intento actual
            if(intentos < MAX_INTENTOS) {
                printf("Usuario o clave incorrectos (intento %d de %d)\n", intentos, MAX_INTENTOS);
            }
        }
    } while(intentos < MAX_INTENTOS && !accesoExitoso);

    // Resultado final
    if (accesoExitoso){
        printf("Bienvenido al sistema, %s\n", usuario);
    } else {
        printf("Sistema bloqueado. Demasiados intentos fallidos.\n");
    }

    return 0;
}