#pragma once
#include <string>
#include "../include/state.h"

class frag {

private:

    struct ptrlist {
        state* st;
        ptrlist* nxt;
    };

    state* start;
    ptrlist* out;

public:
    frag (state* _start, ptrlist* _out);

    state* get_start ();
    ptrlist* get_out ();
    void set_start (state* s);
    void set_out (ptrlist* p);

    static ptrlist* list1 (state* outp);
    static void patch (ptrlist* l, state* s);
    static ptrlist* append (ptrlist* l1, ptrlist* l2);
};