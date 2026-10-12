//caja.c - caja registradora con MENU

#include <stdio.h>

int main (void){

    //Declaracion de varibles
    int opcion;     //opcion elegida en el menu
    int productos = 0; // CONTADOR de productos de la venta
    double precio;     //precio para cada producto
    double total = 0; //Acumulador de la venta

    //DO .... WHILE ....: EL MENU SE MUESTRA  AL MENOS UNA VEZ
    do {
        //Mostrar el menu y lee opcion -> 1
        printf("\n1. Agregar 2. Ver total 3. Cobrar 0. Salir\n");
        
        printf("Opcion: ");
        scanf("%d", &opcion);

        //SWITCH: (segun) : salta al case caso que coincida con la opcion elegida 
        switch (opcion){
            case 1 :
            //Validacion: repite mientras el precio no sea positivo
            do
            {
                printf("Precio del producto: ");
                scanf("%lf", &precio);  // ->1500 (-200)
                if (precio <=0){
                    printf("Precio invalido\n");

                }                   
                
                
            } while(precio <=0);
            productos ++; //cuenta productos
            total += precio; //suma el precio
            break;       //sale del switch

            case 2:
            //Muestra el avance -> Productos: 2 Total de 4000.0
            printf("Productos: %d Total: %.2f\n", productos, total);
            break;

            case 3:
            //Cobra y reinicia el contador y acumulador
            printf("Cobrado: %.2f. Nueva venta\n", total);
            productos = 0;
            total = 0;
            break;

            case 0:
            printf("Caja Cerrada\n");
            break;

            default:
            //Ningun case coinside -> 9 
            printf("Opcion invalida\n");

        }
        
        //repita el menu mientras no se elija el 0

    }while(opcion != 0);

    return 0; 
}