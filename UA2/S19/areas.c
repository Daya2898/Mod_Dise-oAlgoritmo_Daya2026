//areas.c - calculo areas misma ejecucion 


#include<stdio.h>

#define PI 3.14159265//contante

int main(void){
    //Declaracion variables
    int opcion;
    double lado, base, altura, radio, area;

    do {//ciclo do-while para repetir menu con opcion 0

        //Muestra menu interactivo opcion 
        printf("\n1. Cuadrado 2. Rectangulo 3. circulo 0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion){
        case 1:
            //calculo area del cuadrado con lado x lado
            printf("Lado: ");
            scanf("%lf", &lado);
            area = lado * lado;
            printf("Area: %.2f\n", area);
            break;// es obligatorio para salir del case

        //Reutilizo codigo ,cambio informacion 
        case 2:
            //calculo area del rectangulo con base x altura
            printf("Base: ");
            scanf("%lf", &base);
            area = base * altura;
            printf("Area: %.2f\n", area);
            break;// es obligatorio para salir del case

            case 3:
            //calculo area del circulo  con PI x radio ^ 2 = radio x radio
            printf("Radio: ");
            scanf("%lf", &radio);
            area = PI * (radio * radio);
            printf("Area: %.2f\n", area);
            break;// es obligatorio para salir del case

            case 0:
            //para salir del programa
            printf("Hasta luego\n");
            break;

            default:
            //Mensaje cuando ingresan una opcion que no esta 
            printf("Opcion invalida\n");
            break;
    }
}   while (opcion != 0); // se repite mientras opcion sea diferente a 0

    return 0;
}