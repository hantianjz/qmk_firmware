#include "action_layer.h"
#include <stdio.h>

#define L_BASE 0
#define L_FUNC (1 << 1)
#define L_SHIFT (1 << 2)
#define L_TMUX (1 << 3)
#define L_SYSTM (1 << 4)

char layer_state_str[24];

const char *read_layer_state(void) {
    switch (layer_state) {
        case L_SYSTM:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: SYSTEM");
            break;
        case L_TMUX:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: TMUX");
            break;
        case L_SHIFT:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: SHIFT");
            break;
        case L_FUNC:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: FUNC");
            break;
        case L_BASE:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: BASE");
            break;
        default:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
    }

    return layer_state_str;
}
