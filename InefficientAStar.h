//
// Created by nathan on 4/30/16.
//

#ifndef ASTAR_INEFFICIENTASTAR_H
#define ASTAR_INEFFICIENTASTAR_H
#include <vector>
#include <algorithm>

template<typename state>
struct state_wrapper_t {
    state s;
    int g;
    int h;
};
template<typename state, typename action, typename environment, typename heuristic>
class InefficientAStar
{
    typedef state_wrapper_t<state> state_wrapper;
public:
    int GetPath(environment &e, state &start, state &goal)
    {
        int h = heur.h(start, goal);
        open.emplace_back(state_wrapper {start,0,h});
        while(!open.empty())
        {
            int min = std::numeric_limits<int>::max();
//            for(int i=0;i<open.size();i++)
//            {
//                min = std::min(open[i].second, min);
            auto m = min_element(open.begin(), open.end(), [](state_wrapper& a, state_wrapper& b) {return (a.g + a.h) < (b.g + b.h);});
            auto st = *m;
            open.erase(m);
            std::vector<action> moves;
            e.GetActions(st.s, moves);
            for (auto& m : moves) {
                e.ApplyAction(st.s, m);
                if (st.s == goal) {
                    return st.g;
                }
                for(int i=0;i<open.size();i++)
                {
                    if(open[i] == st)
                    {

                       //skip
                    }
                }
//               this checks if the f-cost is better b/c of the way we wrote op== Kappa
                if {

                }
                else {
                    open.emplace_back(state_wrapper {st.s, st.g + 1, heur.h(st.s, goal)});
                }
                e.UndoAction(st.s, m);

            }
//            }
        }
    }

private:


    std::vector<state_wrapper> open;
    std::vector<state_wrapper> closed;
    heuristic heur;
    std::vector<action> path;
    const int FOUND = -1;
    const int NOT_FOUND = -2;
};

template<typename state>
bool operator==( const state_wrapper_t<state>& lhs, const state_wrapper_t<state>& rhs ) {
    if (lhs.s == rhs.s && (lhs.g + lhs.h) < (rhs.g + rhs.h))
        return true;
    return false;
}
#endif //ASTAR_INEFFICIENTASTAR_H
