#include "../include/state.h"

int state::nstate = 0;

state::state (int _c, state* _out1, state* _out2) {
    c = _c;
    out1 = _out1;
    out2 = _out2;
    nstate++;
}

state* state::get_out1 () {
    return out1;
}

state* state::get_out2 () {
    return out2;
}

void state::set_out1 (state* s) {
    out1 = s;
}

void state::set_out2 (state* s) {
    out2 = s;
}

int state::num_states () {
    return nstate;
}