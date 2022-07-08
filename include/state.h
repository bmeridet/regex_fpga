#pragma once

#include <string>

class state {

private:

    int c;
    static int nstate;

public:

    static const int match = 256;
    static const int split = 257;

    state* out1;
    state* out2;

    state (int c, state* _out1, state* _out2);

    int get_state ();

    static int num_states ();
    static void traverse (state* start);
};