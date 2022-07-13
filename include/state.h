#pragma once

#include <string>
#include <set>

class state {

private:

    int c;
    int state_id;
    int visits;
    static std::set<int> L;
    static int nstate;

public:

    static const int match = 256;
    static const int split = 257;

    state* out1;
    state* out2;

    state (int c, state* _out1, state* _out2);

    int get_state ();
    int get_stateid ();
    int inc_visit ();

    static int num_states ();
    static void traverse (state* start);
    static void add_char (int i);
    static void print_language ();
    static void nfa_table (state* start);
};