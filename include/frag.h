#pragma once
#include <string>
#include "../include/state.h"

class frag {

public:

    union ptrlist {
        state* st;
        ptrlist* nxt;
    };

    frag (state* _start, ptrlist* _out);

    state* start;
    ptrlist* out;

    static ptrlist* list1 (state** outp);
    static void patch (ptrlist* l, state* s);
    static ptrlist* append (ptrlist* l1, ptrlist* l2);
};