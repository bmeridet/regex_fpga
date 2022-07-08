#include <iostream>
#include "../include/frag.h"

frag::frag (state* _start, ptrlist* _out) {
    start = _start;
    out = _out;
}

frag::ptrlist* frag::list1 (state** outp) {
    frag::ptrlist* l;
    l = (frag::ptrlist*) outp;
    l->nxt = nullptr;
    return l;
}

void frag::patch (ptrlist* l, state* s) {
    frag::ptrlist* next;
    for ( ; l; l = next) {
        next = l->nxt;
        l->st = s;
    }
}

frag::ptrlist* frag::append (ptrlist* l1, ptrlist* l2) {
    frag::ptrlist* ret = l1;
    while (l1->nxt) l1 = l1->nxt;
    l1->nxt = l2;
    return ret;
}