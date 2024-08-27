#include "raylib.h"
#undef RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <string.h>

#ifndef GUI_H
#define GUI_H

typedef struct {
    // Define anchors
    Vector2 BottomAnchor;            // ANCHOR ID:1
    Vector2 anchor02;            // ANCHOR ID:2
    Vector2 anchor03;            // ANCHOR ID:3
    
    // Define controls variables
    float ProgressBar000Value;            // ProgressBar: ProgressBar000
    bool SpeedMultiplierEditMode;
    int SpeedMultiplierValue;            // Spinner: SpeedMultiplier
    bool NextPressed;            // Button: Next
    bool PrevPressed;            // Button: Prev
    bool Button004Pressed;            // Button: Button004
    bool ValueBOx005EditMode;
    int ValueBOx005Value;            // ValueBOx: ValueBOx005
    bool ValueBOx006EditMode;
    int ValueBOx006Value;            // ValueBOx: ValueBOx006
    bool ValueBOx007EditMode;
    int ValueBOx007Value;            // ValueBOx: ValueBOx007
    bool ValueBOx010EditMode;
    int ValueBOx010Value;            // ValueBOx: ValueBOx010
    bool ValueBOx011EditMode;
    int ValueBOx011Value;            // ValueBOx: ValueBOx011

    // Custom state variables (depend on development software)
    // NOTE: This variables should be added manually if required

} GuiGuiState;

//----------------------------------------------------------------------------------
// Defines and Macros
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
// ...

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
GuiGuiState InitGuiGui(void);
void GuiGui(GuiGuiState *state);

#endif // GUI_H

/***********************************************************************************
*
*   GUI IMPLEMENTATION
*
************************************************************************************/
#if defined(GUI_IMPLEMENTATION)

#include "raygui.h"

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Internal Module Functions Definition
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
GuiGuiState InitGuiGui(void)
{
    GuiGuiState state = { 0 };

    // Init anchors
    state.BottomAnchor = (Vector2){ 912, 808 };            // ANCHOR ID:1
    state.anchor02 = (Vector2){ 264, 24 };            // ANCHOR ID:2
    state.anchor03 = (Vector2){ 1200, 24 };            // ANCHOR ID:3
    
    // Initilize controls variables
    state.ProgressBar000Value = 0.0f;            // ProgressBar: ProgressBar000
    state.SpeedMultiplierEditMode = false;
    state.SpeedMultiplierValue = 0;            // Spinner: SpeedMultiplier
    state.NextPressed = false;            // Button: Next
    state.PrevPressed = false;            // Button: Prev
    state.Button004Pressed = false;            // Button: Button004
    state.ValueBOx005EditMode = false;
    state.ValueBOx005Value = 0;            // ValueBOx: ValueBOx005
    state.ValueBOx006EditMode = false;
    state.ValueBOx006Value = 0;            // ValueBOx: ValueBOx006
    state.ValueBOx007EditMode = false;
    state.ValueBOx007Value = 0;            // ValueBOx: ValueBOx007
    state.ValueBOx010EditMode = false;
    state.ValueBOx010Value = 0;            // ValueBOx: ValueBOx010
    state.ValueBOx011EditMode = false;
    state.ValueBOx011Value = 0;            // ValueBOx: ValueBOx011

    // Custom variables initialization

    return state;
}

void GuiGui(GuiGuiState *state)
{
    // Draw controls
    GuiProgressBar((Rectangle){ state->BottomAnchor.x + -312, state->BottomAnchor.y + 56, 624, 24 }, NULL, NULL, &state->ProgressBar000Value, 0, 1);
    if (GuiSpinner((Rectangle){ state->BottomAnchor.x + -72, state->BottomAnchor.y + 24, 144, 24 }, NULL, &state->SpeedMultiplierValue, 0, 100, state->SpeedMultiplierEditMode)) state->SpeedMultiplierEditMode = !state->SpeedMultiplierEditMode;
    state->NextPressed = GuiButton((Rectangle){ state->BottomAnchor.x + 80, state->BottomAnchor.y + 24, 48, 24 }, "NEXT"); 
    state->PrevPressed = GuiButton((Rectangle){ state->BottomAnchor.x + -136, state->BottomAnchor.y + 24, 56, 24 }, "PREV"); 
    state->Button004Pressed = GuiButton((Rectangle){ state->BottomAnchor.x + -48, state->BottomAnchor.y + 72, 96, 24 }, "PLAY"); 
    if (GuiValueBox((Rectangle){ state->anchor02.x + 24, state->anchor02.y + 32, 72, 16 }, "X ", &state->ValueBOx005Value, 0, 100, state->ValueBOx005EditMode)) state->ValueBOx005EditMode = !state->ValueBOx005EditMode;
    if (GuiValueBox((Rectangle){ state->anchor02.x + 120, state->anchor02.y + 32, 72, 16 }, "Y ", &state->ValueBOx006Value, 0, 100, state->ValueBOx006EditMode)) state->ValueBOx006EditMode = !state->ValueBOx006EditMode;
    if (GuiValueBox((Rectangle){ state->anchor02.x + 216, state->anchor02.y + 32, 72, 16 }, "Z ", &state->ValueBOx007Value, 0, 100, state->ValueBOx007EditMode)) state->ValueBOx007EditMode = !state->ValueBOx007EditMode;
    GuiGroupBox((Rectangle){ state->anchor02.x + 0, state->anchor02.y + 24, 304, 32 }, "CORDINATES");
    GuiGroupBox((Rectangle){ state->anchor03.x + 0, state->anchor03.y + 24, 304, 32 }, "SACE");
    if (GuiValueBox((Rectangle){ state->anchor03.x + 48, state->anchor03.y + 32, 120, 16 }, "CELLS ", &state->ValueBOx010Value, 0, 100, state->ValueBOx010EditMode)) state->ValueBOx010EditMode = !state->ValueBOx010EditMode;
    if (GuiValueBox((Rectangle){ state->anchor03.x + 216, state->anchor03.y + 32, 72, 16 }, "GRIDS ", &state->ValueBOx011Value, 0, 100, state->ValueBOx011EditMode)) state->ValueBOx011EditMode = !state->ValueBOx011EditMode;
}

#endif // GUI_IMPLEMENTATION
