#include <raylib.h>            // Incluye la librería raylib para gráficos y manejo de ventanas
#include <stdio.h>             // Incluye la librería estándar de entrada y salida
#include <omp.h>               // Incluye la librería OpenMP para programación paralela

#include "life.h"              // Incluye la cabecera del módulo life, probablemente para simulación del Juego de la Vida
#include "parse.h"             // Incluye la cabecera del módulo parse, probablemente para manejo de patrones

#define RAYGUI_IMPLEMENTATION  // Define la implementación de raygui (biblioteca para interfaces gráficas)
#include "../thirdparty/raygui.h"  // Incluye la implementación de raygui desde un directorio de terceros

#define IMRGUI_IMPLEMENTATION  // Define la implementación de la interfaz gráfica personalizada
#include "interface.h"         // Incluye la cabecera de la interfaz personalizada

// Array que contiene las rutas o nombres de estilos para la interfaz gráfica
const char *styles[] = {"../data/raygui/cyber.rgs", "amber", "table"};

int main()
{
    // Configura la ventana para que sea redimensionable
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    
    // Inicializa una ventana con dimensiones de 1000x1000 píxeles y título "GAME OF LIFE"
    InitWindow(1000, 1000, "GAME OF LIFE");
    
    // Establece el objetivo de FPS (cuadros por segundo) a 60
    SetTargetFPS(60);
    
    // Carga un estilo de la interfaz gráfica desde el array `styles`
    GuiLoadStyle(styles[1]);  // Carga el segundo estilo ("amber")

    // Inicializa el estado de la interfaz gráfica personalizada
    GuiInterfaceState state = GuiInterface();

    // Bucle principal del juego (se ejecuta hasta que se cierre la ventana)
    while (!WindowShouldClose()) {
        BeginDrawing();  // Comienza a dibujar en la ventana

        // Llama a la función que maneja la interfaz gráfica personalizada, pasando el estado actual
        GuiInterface(&state);

        // Limpia el fondo de la ventana con el color de fondo definido en el estilo
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        EndDrawing();  // Termina de dibujar en la ventana
    }

    // Cierra la ventana y libera los recursos
    CloseWindow();
    
    return 0;  // Retorna 0 indicando que el programa terminó correctamente
}
