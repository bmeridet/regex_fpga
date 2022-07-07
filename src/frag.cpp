#include "../include/frag.h"

frag::frag (state* _start, ptrlist* _out) {
    start = _start;
    out = _out;
}

state* frag::get_start () {
    return start;
}

frag::ptrlist* frag::get_out () {
    return out;
}

void frag::set_start (state* s) {
    start = s;
}

void frag::set_out (frag::ptrlist* p) {
    out = p;
}

frag::ptrlist* frag::list1 (state* outp) {
    frag::ptrlist* l = (frag::ptrlist*) outp;
    l->nxt = nullptr;
    return l;
}

void frag::patch (ptrlist* l, state* s) {
    while (l) {
        l->st = s;
        l = l->nxt;
    }
}

frag::ptrlist* frag::append (ptrlist* l1, ptrlist* l2) {
    frag::ptrlist* ret = l1;
    while (l1->nxt) l1 = l1->nxt;
    l1->nxt = l2;
    return ret;
}