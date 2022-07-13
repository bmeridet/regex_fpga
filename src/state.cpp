#include <stack>
#include <queue>
#include <iostream>
#include <vector>
#include <map>
#include "../include/state.h"

int state::nstate = 0;
std::set<int> state::L;

state::state (int _c, state* _out1, state* _out2) {
    c = _c;
    state_id = nstate;
    visits = 0;
    out1 = _out1;
    out2 = _out2;
    nstate++;
}

int state::get_state () {
    return c;
}

int state::get_stateid () {
    return state_id;
}

int state::inc_visit () {
    return visits++;
}

int state::num_states () {
    return nstate;
}

void state::add_char (int i) {
    state::L.insert(i);
}

void state::print_language () {
    for (auto itr = state::L.begin(); itr != state::L.end(); itr++) std::cout << *itr << " ";
    std::cout << "end" << std::endl;
}

void state::traverse (state* start) {
    std::stack<state*> stack;
    stack.push (start);
    state* s;

    std::cout << "Number of States: " << state::num_states() << std::endl;

    while (!stack.empty()) {
        s = stack.top ();
        stack.pop ();
        std::cout << "sid: " << s->get_stateid() << " state: " << s->get_state() << std::endl;
        if (s->inc_visit() > 0) break;
        if (s->out1 != nullptr) stack.push (s->out1);
        if (s->out2 != nullptr) stack.push (s->out2);
    }

    std::cout << "Finished traversal" << std::endl;
}

void print_nfa (std::vector< std::pair< int, std::map<int, std::vector<int> > > > &nfa_table) {
    for (int i = 0; i < (int) nfa_table.size (); ++i) {
        std::cout << "state_id: " << nfa_table[i].first << " ";
        for (auto j = nfa_table[i].second.begin(); j != nfa_table[i].second.end(); j++) {
            std::cout << "Letter: " << j->first << " " << "states: ";
            for (int k = 0; k < (int) j->second.size(); ++k)
                std::cout << j->second[k] << " ";
        }
        std::cout << std::endl;
    }
}

void state::nfa_table (state* start) {
    std::vector< std::pair< int, std::map<int, std::vector<int> > > > nfa_table;
    std::queue<state*> Q;
    std::map<int, std::vector<int>> tmp_map;
    std::pair<int, std::map<int, std::vector<int>>> tmp_pair;
    std::set<int> visited;
    
    Q.push (start);
    state* s;

    while (!Q.empty ()) {
        s = Q.front ();
        Q.pop ();

        if (visited.find (s->get_stateid ()) != visited.end ()) continue;
        if ((int)visited.size () == state::nstate) break;
        else visited.insert (s->get_stateid ());

        tmp_map.clear ();

        if (s->out1 != nullptr) {
            tmp_map[s->out1->c].push_back (s->out1->state_id);
            Q.push (s->out1);
        }

        if (s->out2 != nullptr) {
            tmp_map[s->out2->c].push_back (s->out2->state_id);
            Q.push (s->out2);
        }

        tmp_pair.first = s->state_id;
        tmp_pair.second = tmp_map;
        nfa_table.push_back (tmp_pair);
    }

    print_nfa (nfa_table);
}
