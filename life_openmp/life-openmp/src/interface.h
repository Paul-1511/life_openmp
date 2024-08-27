#include "raylib.h"                 // Incluye la librería raylib para gráficos y manejo de ventanas
#undef RAYGUI_IMPLEMENTATION        // Evita la implementación redundante de raygui
#include "raygui.h"                 // Incluye la librería raygui para la creación de interfaces gráficas

#include <string.h>                 // Incluye la librería para manejo de cadenas de caracteres

#ifndef INTERFACE_H
#define INTERFACE_H

// Definición de una estructura para almacenar el estado de la interfaz gráfica
typedef struct {
    // Define puntos de anclaje en la pantalla
    Vector2 BottomAnchor;            // ANCHOR ID:1 - Punto de anclaje en la parte inferior
    Vector2 anchor02;                // ANCHOR ID:2 - Punto de anclaje en la parte superior izquierda
    Vector2 anchor03;                // ANCHOR ID:3 - Punto de anclaje en la parte superior derecha
    
    // Define variables para los controles de la interfaz
    float ProgressBar000Value;       // Valor para la barra de progreso (ProgressBar000)
    bool SpeedMultiplierEditMode;    // Modo de edición para el Spinner de SpeedMultiplier
    int SpeedMultiplierValue;        // Valor del Spinner (SpeedMultiplier)
    bool NextPressed;                // Estado del botón "Next"
    bool PrevPressed;                // Estado del botón "Prev"
    bool Button004Pressed;           // Estado del botón "Play"
    bool ValueBOx005EditMode;        // Modo de edición para el ValueBox005
    int ValueBOx005Value;            // Valor del ValueBox005
    bool ValueBOx006EditMode;        // Modo de edición para el ValueBox006
    int ValueBOx006Value;            // Valor del ValueBox006
    bool ValueBOx007EditMode;        // Modo de edición para el ValueBox007
    int ValueBOx007Value;            // Valor del ValueBox007
    bool ValueBOx010EditMode;        // Modo de edición para el ValueBox010
    int ValueBOx010Value;            // Valor del ValueBox010
    bool ValueBOx011EditMode;        // Modo de edición para el ValueBox011
    int ValueBOx011Value;            // Valor del ValueBox011

    // Variables personalizadas (dependen del software en desarrollo)
    // NOTA: Estas variables deben ser añadidas manualmente si son necesarias

} GuiInterfaceState;

//----------------------------------------------------------------------------------
// Defines y Macros
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Tipos y Definición de Estructuras
//----------------------------------------------------------------------------------
// ...

//----------------------------------------------------------------------------------
// Declaración de Funciones del Módulo
//----------------------------------------------------------------------------------
GuiInterfaceState InitGuiInterface(void);          // Inicializa y devuelve el estado inicial de la interfaz
void GuiInterface(GuiInterfaceState *state);       // Maneja y dibuja la interfaz basada en su estado

#endif // INTERFACE_H

/***********************************************************************************
*
*   IMPLEMENTACIÓN DE LA INTERFAZ
*
************************************************************************************/
#if defined(INTERFACE_IMPLEMENTATION)

#include "raygui.h"                 // Incluye nuevamente raygui para la implementación de la interfaz

//----------------------------------------------------------------------------------
// Definición de Variables Globales
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Definición de Funciones Internas del Módulo
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Definición de Funciones del Módulo
//----------------------------------------------------------------------------------

// Función para inicializar el estado de la interfaz gráfica
GuiInterfaceState InitGuiInterface(void)
{
    GuiInterfaceState state = { 0 }; // Inicializa la estructura con ceros

    // Inicializa los puntos de anclaje
    state.BottomAnchor = (Vector2){ 912, 808 };     // ANCHOR ID:1 - Posición en la parte inferior
    state.anchor02 = (Vector2){ 264, 24 };          // ANCHOR ID:2 - Posición en la parte superior izquierda
    state.anchor03 = (Vector2){ 1200, 24 };         // ANCHOR ID:3 - Posición en la parte superior derecha
    
    // Inicializa las variables de los controles
    state.ProgressBar000Value = 0.0f;               // Inicializa la barra de progreso a 0.0
    state.SpeedMultiplierEditMode = false;          // Modo de edición desactivado para el Spinner
    state.SpeedMultiplierValue = 0;                 // Inicializa el valor del Spinner en 0
    state.NextPressed = false;                      // Botón "Next" no presionado
    state.PrevPressed = false;                      // Botón "Prev" no presionado
    state.Button004Pressed = false;                 // Botón "Play" no presionado
    state.ValueBOx005EditMode = false;              // Modo de edición desactivado para ValueBox005
    state.ValueBOx005Value = 0;                     // Inicializa ValueBox005 a 0
    state.ValueBOx006EditMode = false;              // Modo de edición desactivado para ValueBox006
    state.ValueBOx006Value = 0;                     // Inicializa ValueBox006 a 0
    state.ValueBOx007EditMode = false;              // Modo de edición desactivado para ValueBox007
    state.ValueBOx007Value = 0;                     // Inicializa ValueBox007 a 0
    state.ValueBOx010EditMode = false;              // Modo de edición desactivado para ValueBox010
    state.ValueBOx010Value = 0;                     // Inicializa ValueBox010 a 0
    state.ValueBOx011EditMode = false;              // Modo de edición desactivado para ValueBox011
    state.ValueBOx011Value = 0;                     // Inicializa ValueBox011 a 0

    // Inicialización de variables personalizadas si es necesario

    return state;                                   // Devuelve el estado inicializado
}

// Función que maneja y dibuja la interfaz gráfica basada en el estado actual
void GuiInterface(GuiInterfaceState *state)
{
    // Dibuja los controles de la interfaz
    GuiProgressBar((Rectangle){ state->BottomAnchor.x + -312, state->BottomAnchor.y + 56, 624, 24 }, NULL, NULL, &state->ProgressBar000Value, 0, 1);
    if (GuiSpinner((Rectangle){ state->BottomAnchor.x + -72, state->BottomAnchor.y + 24, 144, 24 }, NULL, &state->SpeedMultiplierValue, 0, 100, state->SpeedMultiplierEditMode)) 
        state->SpeedMultiplierEditMode = !state->SpeedMultiplierEditMode;  // Alterna el modo de edición del Spinner
    state->NextPressed = GuiButton((Rectangle){ state->BottomAnchor.x + 80, state->BottomAnchor.y + 24, 48, 24 }, "NEXT"); 
    state->PrevPressed = GuiButton((Rectangle){ state->BottomAnchor.x + -136, state->BottomAnchor.y + 24, 56, 24 }, "PREV"); 
    state->Button004Pressed = GuiButton((Rectangle){ state->BottomAnchor.x + -48, state->BottomAnchor.y + 72, 96, 24 }, "PLAY"); 
    if (GuiValueBox((Rectangle){ state->anchor02.x + 24, state->anchor02.y + 32, 72, 16 }, "X ", &state->ValueBOx005Value, 0, 100, state->ValueBOx005EditMode)) 
        state->ValueBOx005EditMode = !state->ValueBOx005EditMode;  // Alterna el modo de edición del ValueBox005
    if (GuiValueBox((Rectangle){ state->anchor02.x + 120, state->anchor02.y + 32, 72, 16 }, "Y ", &state->ValueBOx006Value, 0, 100, state->ValueBOx006EditMode)) 
        state->ValueBOx006EditMode = !state->ValueBOx006EditMode;  // Alterna el modo de edición del ValueBox006
    if (GuiValueBox((Rectangle){ state->anchor02.x + 216, state->anchor02.y + 32, 72, 16 }, "Z ", &state->ValueBOx007Value, 0, 100, state->ValueBOx007EditMode)) 
        state->ValueBOx007EditMode = !state->ValueBOx007EditMode;  // Alterna el modo de edición del ValueBox007
    GuiGroupBox((Rectangle){ state->anchor02.x + 0, state->anchor02.y + 24, 304, 32 }, "CORDINATES");  // Dibuja un cuadro de grupo con título "CORDINATES"
    GuiGroupBox((Rectangle){ state->anchor03.x + 0, state->anchor03.y + 24, 304, 32 }, "SACE");  // Dibuja un cuadro de grupo con título "SACE"
    if (GuiValueBox((Rectangle){ state->anchor03.x + 48, state->anchor03.y + 32, 120, 16 }, "CELLS ", &state->ValueBOx010Value, 0, 100, state->ValueBOx010EditMode)) 
        state->ValueBOx010EditMode = !state->ValueBOx010EditMode;  //
}
#endif // INTERFACE_IMPLEMENTATION
