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
    frag* f, *f1, *f2;
    stack<frag*> stk_frags;

    for (int i = 0; i < re.size(); ++i) {
        switch (re[i]) {
            case '|':
                f2 = stk_frags.top ();
                stk_frags.pop ();
                f1 = stk_frags.top ();
                stk_frags.pop ();
                s = new state (state::split, f1->get_start(), f2->get_start());
                stk_frags.push (new frag (s, frag::append(f1->get_out(), f2->get_out())));
                break;

            case '.':
                f2 = stk_frags.top ();
                stk_frags.pop ();
                f1 = stk_frags.top ();
                stk_frags.pop ();
                frag::patch (f1->get_out(), f2->get_start());
                stk_frags.push (new frag (f1->get_start(), f2->get_out()));
                break;

            case '*':
                f = stk_frags.top ();
                stk_frags.pop ();
                s = new state (state::split, f->get_start(), nullptr);
                frag::patch (f->get_out(), s);
                stk_frags.push (new frag (s, frag::list1(s->get_out2())));
                break;

            case '+':
                break;

            case '?':
                break;
                
            default:
                s = new state (re[i], nullptr, nullptr);
                stk_frags.push (new frag (s, frag::list1(s->get_out1())));
        }
    }

};