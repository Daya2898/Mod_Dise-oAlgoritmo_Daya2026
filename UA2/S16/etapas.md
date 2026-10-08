<!-- Respuestas ejercicio 4
2.	¿Qué archivo contiene el texto de stdio.h? ¿Cómo lo comprobó? 
El archivo preprocesado (que fue generado con gcc -E) contiene el texto de stdio.h expandido. Se comprobó abriendo el archivo resultante, donde se observa todo el código de la biblioteca insertado antes de la función main. 

3.	¿Qué archivo tiene instrucciones como mov y call? 
El archivo en lenguaje ensamblador (`.s`), generado con `gcc -S`, ya que contiene instrucciones de bajo nivel de la arquitectura.

4.	¿Cuál no se puede leer como texto? ¿Por qué? 
El archivo objeto (`.o`) y el archivo ejecutable, porque no están en texto plano, sino en formato binario (código máquina) que la computadora puede ejecutar directamente.

5.	¿Qué etapa une su programa con el código de printf? 
La etapa de enlace (*linking*), que combina el archivo objeto de nuestro programa con las bibliotecas del sistema para resolver las referencias a funciones externas como `printf` o `puts`.
-->