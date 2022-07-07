#pragma once

#include <string>

class state {

private:

    int c;
    state* out1;
    state* out2;
    static int nstate;

public:

    static const int match = 256;
    static const int split = 257;

    state (int c, state* _out1, state* _out2);
    state* get_out1 ();
    state* get_out2 ();
    void set_out1 (state* s);
    void set_out2 (state* s);
    int num_states ();
};