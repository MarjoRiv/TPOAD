#pragma once

class Solution;

// constructive heuristics
void H1_heuristic           (Solution &);
void Nearest_neighboor (Solution &, int a = 0 );
void Cheapest_insertion(Solution &, int a = 0 , int b =1);

// basic moves for the local search
int twoOpt (Solution &);

// local search

// metaheuristics
