#include "solution.h"
#include "heuristics.h"
#include "bkr.h"
#include "chronometer.h"


inline double relative_gap (double curr, double best)
{
  return (100.0 * (curr - best) / best);
}


inline void report (double value, double time, double best_value)
{
  std::cout << " val = " << value << "  in ";

  auto old_fmt = std::cout.flags();
  auto old_precision = std::cout.precision(2);
  std::cout.flags(std::ios::fixed);

  std::cout << time << " s (gap = " << relative_gap(value, best_value);

  std::cout.precision(old_precision);
  std::cout.flags(old_fmt);

  std::cout << " %)" << std::endl;
}


// =======================================================================
// some constructive heuristics
// =======================================================================

void runHeuristics (Data & d)
{
  Solution sol(d);
  Solution sol2(d);
  Solution sol3(d);
  Chronometer::Duration time;
  Chronometer::Duration time2;
  Chronometer::Duration time3;

  // first basic heuristic
  if (true)
  {
    std::cout << "H1 heuristic" << std::flush;
    Chronometer chr(time);
    H1_heuristic (sol);
  }
  report(sol.real_value(), time, d.bkr().value_);

  sol.check();
  
  // nearest neighboors heuristic
  if (true)
  {
    std::cout << "Nearest neighboors heuristic" << std::flush;
    Chronometer chr(time2);
    Nearest_neighboor(sol2, 0);
  }
  report(sol2.real_value(), time2, d.bkr().value_);

  sol2.check();
  
  // cheapest neighboors heuristic
  if (true)
  {
    std::cout << "Cheapest neighboors heuristic" << std::flush;
    Chronometer chr(time3);
    Cheapest_insertion(sol3, 0,1);
  }
  report(sol3.real_value(), time3, d.bkr().value_);
    
  sol3.check();
  //std::cout << sol << std::endl;
}


// =======================================================================
// metaheuristics
// =======================================================================

void runMetaheuristics (Data &)
{
}


// =======================================================================
// main function: parse the command line and call the functions
// =======================================================================

int main (int argc, char * argv[])
{
  //std::string instance("./../DATA/burma14.tsp");
  //std::string instance("./../DATA/ulysses16.tsp");
  //std::string instance("./../DATA/ulysses22.tsp");
  //std::string instance("./../DATA/berlin52.tsp");
  //std::string instance("./../DATA/kroA100.tsp");
  //std::string instance("./../DATA/ch150.tsp");
  std::string instance("./../DATA/gr202.tsp");

  // parse the command line
  if (argc > 2)
  {
    std::cerr << "error: wrong number of argument\n" << "usage: " << argv[0] << " instance" << std::endl;
    exit(1);
  }
  if (argc > 1)
  {
    instance = argv[1];
  }

  // set the RNG
  RNG rng(0);

  // load the data
  Data pb(instance, rng);
  std::cout << pb << std::endl;

  // create a solution
  Solution sol(pb);

  /* answer the questions */
  runHeuristics (pb); // heuristics

  return 0;
}


// =======================================================================
// end of file
// =======================================================================
