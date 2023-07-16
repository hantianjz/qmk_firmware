#include "quantum.h"
#include <stdio.h>

#define L_BASE 0
#define L_FUNC (1 << 1)
#define L_SHIFT (1 << 2)
#define L_TMUX (1 << 3)
#define L_SYSTM (1 << 4)

char layer_state_str[24];

const char *read_layer_state(void) {
    if (layer_state & L_SYSTM) {
        snprintf(layer_state_str, sizeof(layer_state_str), "SYSM");
    } else if (layer_state & L_TMUX) {
        snprintf(layer_state_str, sizeof(layer_state_str), "TMUX");
    } else if (layer_state & L_SHIFT) {
        snprintf(layer_state_str, sizeof(layer_state_str), "SHFT");
    } else if (layer_state & L_FUNC) {
        snprintf(layer_state_str, sizeof(layer_state_str), "FUNC");
    } else if (layer_state == L_BASE) {
        snprintf(layer_state_str, sizeof(layer_state_str), "BASE");
    } else {
        snprintf(layer_state_str, sizeof(layer_state_str), "Un:%d", layer_state);
    }

    return layer_state_str;
}
