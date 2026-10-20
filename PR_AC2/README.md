##AC2 · Práctica preparatoria

Se Compilo con: gcc -Wall -Wextra archivo.c -o programa X

P1 · Pago de un vendedor (PR_P1_PagoVendedor.c)

Calcula el pago mensual con las ventas de 4 semanas: comisión 5 %, bono de 50 si pasa de 2000 y retención de 2 %. Prueba: Carlos Vega, 600, 450, 700, 500 → pago 159.25.

P2 · Evaluación de desempeño (PR_P2_Desempeno.c)

Calcula el promedio de 3 criterios (0 a 10), el nivel y el criterio más bajo. Prueba: Laura Solis, 9, 11, 8.5, 10 → promedio 9.17, EXCELENTE, más bajo: calidad (8.5).

P3 · Pedido en una librería (PR_P3_PedidoLibreria.c)

Lee libros hasta FIN y calcula descuento de 10 % (5 unidades o más), envío, impuesto de 13 % y total. Prueba: Cocori 12.50 × 2 y El principito 8 × 3 → total 57.83.

Tuve dificultades 
stdin marcado en rojo en VS Code: era solo el editor, que no encontraba las cabeceras de gcc. Al compilar en la terminal no daba error. Se arregló configurando la ruta del compilador.
Salida distinta al ejemplo (P1): faltaba la línea en blanco y alinear los valores. Se resolvió con %-18s y %11.2f en el printf.
Muchos errores rojos "se esperaba una declaración": era una llave } de más que cerraba main antes de tiempo. Se encontró revisando las llaves y la indentación.
