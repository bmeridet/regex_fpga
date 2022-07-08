#include <stack>
#include <iostream>
#include "../include/state.h"

int state::nstate = 0;

state::state (int _c, state* _out1, state* _out2) {
    c = _c;
    out1 = _out1;
    out2 = _out2;
    nstate++;
}

int state::get_state () {
    return c;
}

int state::num_states () {
    return nstate;
}

void state::traverse (state* start) {
    std::stack<state*> stack;
    stack.push (start);
    state* s;

    std::cout << "Number of States: " << state::num_states() << std::endl;

    while (!stack.empty()) {
        s = stack.top ();
        stack.pop ();
        std::cout << s->get_state() << std::endl;
        if (s->out1 != nullptr) stack.push (s->out1);
        if (s->out2 != nullptr) stack.push (s->out2);
    }

    std::cout << "Reached final state" << std::endl;
}