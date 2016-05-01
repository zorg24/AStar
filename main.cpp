//
// Created by nathan on 4/30/16.
//

#include "GridEnvironment.h"
#include "InefficientAStar.h"
#include <string>

int main() {
    struct FakeHeur{ int h(GridState a, GridState b) {return 0;}};
    GridEnvironment g("arena.map");
    GridState start {3,3};
    GridState goal {45,45};
    InefficientAStar<GridState, GridAction, GridEnvironment, FakeHeur> slowAS;
    slowAS.GetPath(g, start, goal);
}