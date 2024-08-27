#include <stdio.h>              // Librería estándar de entrada y salida
#include <string.h>             // Librería para manejo de cadenas de caracteres
#include <stdlib.h>             // Librería estándar de utilidades (para funciones como malloc, free, etc.)
#include <omp.h>                // Librería para programación en paralelo (OpenMP)

#include "parse.h"              // Incluye la cabecera del módulo parse (definición de funciones para parsing)
#include "life.h"               // Incluye la cabecera del módulo life (posiblemente para simulación de Conway's Game of Life)

#define BUFFER_SIZE 1024        // Tamaño del buffer para leer archivos
#define PATH_SIZE 255           // Tamaño máximo de la ruta del archivo
#define DATA_DIR "/data"        // Directorio por defecto donde se encuentran los archivos de patrones
#define COMMENT '!'             // Carácter que indica una línea de comentario en el archivo
#define NEWLINE '\n'            // Carácter que indica el fin de una línea (nueva línea)

char fbuffer[BUFFER_SIZE];      // Buffer global para almacenar fragmentos leídos del archivo

// Función que analiza un patrón dentro de un buffer
// `s`: Cadena que contiene los datos a analizar
// `size`: Tamaño de la cadena `s`
void parsepattern(char *s, int size) {
    int i, x = 0, y = 0;  // Inicializa contadores para las posiciones x e y
    for (i = 0; i <= size; i++) {
        if (s[i] == NEWLINE) {  // Si encuentra un carácter de nueva línea
            x++;  // Incrementa la posición x
            if (s[i] == '.' || s[i] == ',' || s[i] == ' ') {
                // Aquí se podría manejar espacios vacíos, comas o puntos
            } else {
                // Aquí se podría manejar otros caracteres
            }
        }
        y++;  // Incrementa la posición y
    }
}

// Función que obtiene un patrón desde un archivo
// `fname`: Nombre del archivo que contiene el patrón
// Retorna 0 si tiene éxito, o 1 si falla al abrir el archivo
int getpattern(char *fname)
{
    long bsize, fsize, fpos = 0;  // Variables para tamaño del buffer, tamaño del archivo y posición actual
    char c, chunk, in;            // Variables auxiliares para leer caracteres
    FILE *f;                      // Puntero al archivo

    /* Abre el archivo de patrón */
    char dir[PATH_SIZE] = DATA_DIR;     // Inicializa la ruta con el directorio de datos
    strncat(dir, fname, 20);            // Añade el nombre del archivo a la ruta
    f = fopen(fname, "r");              // Abre el archivo en modo lectura
    if (!f) return 1;                   // Si no se puede abrir, retorna 1 (error)

    fseek(f, 0, SEEK_END);              // Mueve el puntero al final del archivo
    fsize = ftell(f);                   // Obtiene el tamaño del archivo
    fseek(f, 0, SEEK_SET);              // Vuelve el puntero al inicio del archivo
  
    /* Analiza las líneas de comentarios */
    while ((c = fgetc(f)) == COMMENT) {     // Mientras la línea comience con un comentario
        while ((c = fgetc(f)) != NEWLINE);  // Ignora el resto de la línea hasta encontrar una nueva línea
    }
  
    /* Analiza el archivo en fragmentos */
    while (fpos < fsize) {
        bsize = fread(fbuffer, 1, BUFFER_SIZE, f);  // Lee un fragmento del archivo en el buffer
        fpos = ftell(f);                            // Actualiza la posición actual del archivo
        parsepattern(fbuffer, bsize);               // Analiza el patrón del fragmento leído
    }
  
    fclose(f);  // Cierra el archivo
    return 0;   // Retorna 0 indicando éxito
}
