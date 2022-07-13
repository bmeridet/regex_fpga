#include <iostream>
#include <stack>
#include "../include/state.h"
#include "../include/frag.h"

using namespace std;

int main () {

    string re;
    cout << "Enter postfix regex: ";
    cin >> re;

    state* s;
    frag* f, *f1, *f2, *tmp;
    stack<frag*> stk_frags;

    unsigned long i;
    for (i = 0; i < re.size(); ++i) {
        switch (re[i]) {
            case '|':
                f2 = stk_frags.top ();
                stk_frags.pop ();
                f1 = stk_frags.top ();
                stk_frags.pop ();
                s = new state (state::split, f1->start, f2->start);
                stk_frags.push (new frag (s, frag::append(f1->out, f2->out)));
                break;

            case '.':
                f2 = stk_frags.top ();
                stk_frags.pop ();
                f1 = stk_frags.top ();
                stk_frags.pop ();
                frag::patch (f1->out, f2->start);
                stk_frags.push (new frag (f1->start, f2->out));
                break;

            case '*':
                f = stk_frags.top ();
                stk_frags.pop ();
                s = new state (state::split, f->start, nullptr);
                frag::patch (f->out, s);
                tmp = new frag (s, frag::list1(&s->out2));
                stk_frags.push (tmp);
                break;

            case '+':
                f = stk_frags.top ();
                stk_frags.pop ();
                s = new state (state::split, f->start, nullptr);
                frag::patch (f->out, s);
                stk_frags.push (new frag (f->start, frag::list1(&s->out2)));
                break;

            case '?':
                f = stk_frags.top ();
                stk_frags.pop ();
                s = new state (state::split, f->start, nullptr);
                stk_frags.push (new frag (s, frag::append(f->out, frag::list1(&s->out2))));
                break;
                
            default:
                state::add_char (re[i]);
                s = new state (re[i], nullptr, nullptr);
                stk_frags.push (new frag (s, frag::list1(&s->out1)));
        }
    }

    f = stk_frags.top ();
    stk_frags.pop ();
    s = new state (state::match, nullptr, nullptr);
    frag::patch (f->out, s);

    //state::print_language ();
    //state::traverse (f->start);
    state::nfa_table (f->start);

    // next - construct a transition table and implement in HDL
};