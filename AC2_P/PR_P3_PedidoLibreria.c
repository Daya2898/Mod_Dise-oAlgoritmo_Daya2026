//PR_P3_PedidoLibreria.c
/*Una libreria registra pedido de cada libro. 
lee eltitulo dec ada libro hasta que se digite FIN o fin-maximo 19 titulos y para cada libro, el precio y cantidad-ambos positivos-
Cuenta las unidades, acumula el total de libros; se aplica 10 % de descuento, si hay 5 unidades o
mas; calculo del envio (8 si el total es menor que 50, 4 si es menor que 150 y gratis desde 150); calculo de impuesto con(13 % del total con descuento) y el total a pagar (total - descuento + impuesto + envio).
SE LOGRA: Mostrar el detalle de cada libro (titulo, precio, cantidad, subtotal) y el
resumen del pedido con dos decimales.
COMO SE LOGRA:Un while con lectura previa lee el titulo; termina con FIN o fin(comparado con strcmp) o al llegar a 10 libros.
se guarda con strcpy en un arreglo paralelo -titulo-; el precio y la cantidad con do...while hasta que sean positivos.
Se acumulan unidades y total de libros,con if / else if se calculan descuento y envio; luego impuesto y total.
for recorre los arreglos paralelos para imprimir el detalle.
 RESULTADO FINAL (Cocori 12.50 x2, El principito 8 x3):
Unidades: 5 | Total de libros: 49.00 | Descuento: 4.90
Impuesto (13%): 5.73 | Envio: 8.00 | TOTAL A PAGAR: 57.83*/


#include <stdio.h>
#include <string.h>
 
//Constantes 
#define MAX_LIBROS 10                    //maximo de libros por pedido
#define LARGO_TITULO 50                  //tamano maximo de un titulo
const int    UNIDADES_DESCUENTO = 5;     //unidades minimas para descuento 
const double TASA_DESCUENTO = 0.10;      // 10 % de descuento 
const double TASA_IMPUESTO = 0.13;       // 13 % de impuesto 
const double LIMITE_ENVIO_ALTO = 50.0;   // menor que esto: envio de 8 
const double LIMITE_ENVIO_BAJO = 150.0;  //menor que esto: envio de 4 
const double ENVIO_ALTO = 8.0;           //costo de envio si total < 50 
const double ENVIO_BAJO = 4.0;           //costo de envio si total < 150 
 
int main(void)
{
    //arreglos paralelos: misma posicion = mismo libro
    char titulos[MAX_LIBROS][LARGO_TITULO]; //titulo de cada libro 
    double precios[MAX_LIBROS];             //precio de cada libro 
    int cantidades[MAX_LIBROS];             //cantidad de cada libro 
 
    char titulo[LARGO_TITULO];  // titulo recien leido 
    int cantidadLibros = 0;     // cuantos libros se han registrado 
    int unidades = 0;           // acumulador de unidades 
    double totalLibros = 0.0;   // acumulador del total de libros 
    double descuento = 0.0;     //descuento aplicado 
    double totalConDescuento;   //total menos descuento 
    double impuesto;            //13 % del total con descuento 
    double envio;               //costo de envio 
    double totalPagar;          //total final a pagar 
    int i;                      //indice del for
 
    printf("=== Pedido de la libreria ===\n");
 
    //Lectura previa del primer titulo 
    printf("Titulo del libro (FIN para terminar): ");
    scanf(" %49[^\n]", titulo);
 
    while (strcmp(titulo, "FIN") != 0 && strcmp(titulo, "fin") != 0)
    {
        strcpy(titulos[cantidadLibros], titulo);    //guarda el titulo 
 
        do
        {
            printf(" Precio: ");
            scanf("%lf", &precios[cantidadLibros]);
        } while (precios[cantidadLibros] <= 0);
 
        do
        {
            printf(" Cantidad: ");
            scanf("%d", &cantidades[cantidadLibros]);
        } while (cantidades[cantidadLibros] <= 0);
 
        unidades += cantidades[cantidadLibros];
        totalLibros += precios[cantidadLibros] * cantidades[cantidadLibros];
        cantidadLibros++;
 
        //Siguiente lectura (si ya hay 10 libros, se termina solo) 
        if (cantidadLibros < MAX_LIBROS)
        {
            printf("Titulo del libro (FIN para terminar): ");
            scanf(" %49[^\n]", titulo);
        }
        else
        {
            strcpy(titulo, "FIN");
        }
    }
 
    //Descuento 
    if (unidades >= UNIDADES_DESCUENTO)
    {
        descuento = totalLibros * TASA_DESCUENTO;
    }
 
    //Envio segun el total de libros 
    if (totalLibros < LIMITE_ENVIO_ALTO)
    {
        envio = ENVIO_ALTO;
    }
    else if (totalLibros < LIMITE_ENVIO_BAJO)
    {
        envio = ENVIO_BAJO;
    }
    else
    {
        envio = 0.0;
    }
 
    //Impuesto y total 
    totalConDescuento = totalLibros - descuento;
    impuesto = totalConDescuento * TASA_IMPUESTO;
    totalPagar = totalConDescuento + impuesto + envio;
 
    //Detalle de cada libro 
    printf("%-20s %8s %5s %10s\n", "Titulo", "Precio", "Cant", "Subtotal");
    for (i = 0; i < cantidadLibros; i++)
    {
        printf("%-20s %8.2f %5d %10.2f\n", titulos[i], precios[i],
               cantidades[i], precios[i] * cantidades[i]);
    }
 
    //Resumen del pedido 
    printf("Unidades: %d\n", unidades);
    printf("Total de libros: %.2f\n", totalLibros);
    printf("Descuento: %.2f\n", descuento);
    printf("Impuesto (13%%): %.2f\n", impuesto);
    printf("Envio: %.2f\n", envio);
    printf("TOTAL A PAGAR: %.2f\n", totalPagar);
 
    return 0;
}
