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
  Solution sol4(d);
  Solution sol5(d);
  Chronometer::Duration time;
  Chronometer::Duration time2;
  Chronometer::Duration time3;
  Chronometer::Duration time4;
  Chronometer::Duration time5;

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
  
  sol4=sol3;
   // 2-Opt heuristic
  if (true)
  {
    std::cout << "2-Opt heuristique d'amélioration" << std::flush;
    Chronometer chr(time4);
    twoOpt(sol4);
  }
  report(sol4.real_value(), time4, d.bkr().value_);
    
  sol4.check();
  
  sol5=sol3;
   // 3-Opt heuristic
  if (true)
  {
    std::cout << "3-Opt heuristique d'amélioration" << std::flush;
    Chronometer chr(time5);
    threeOpt(sol5);
  }
  report(sol5.real_value(), time5, d.bkr().value_);
    
  sol5.check();
  //std::cout << sol << std::endl;
}


// =======================================================================
// metaheuristics
// =======================================================================

void runMetaheuristics (Data & d)
{
    Solution sol(d);
    Solution sol2(d);
    Solution sol3(d);
    Chronometer::Duration time;
    Chronometer::Duration time2;
    Chronometer::Duration time3;
    Cheapest_insertion(sol, 0,1);
    sol2=sol;
    twoOpt(sol);
    //VND 2-Opt
    if (true)
    {
      std::cout << "VND 2-Opt" << std::flush;
      Chronometer chr(time);
      VND2Opt(sol);
      sol3=sol;
    }
    report(sol.real_value(), time, d.bkr().value_);
    
    sol.check();
     //VND 3-Opt
    if (true)
    {
      std::cout << "VND 3-Opt" << std::flush;
      Chronometer chr(time2);
      VND3Opt(sol2);
    }
    report(sol2.real_value(), time2, d.bkr().value_);
    
    sol2.check();
    // VNS
    if (true)
    {
        std::cout << "VNS" << std::flush;
        Chronometer chr(time3);
        VNSShaking(sol3,5);
    }
    report(sol3.real_value(), time3, d.bkr().value_);
    
    sol3.check();
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
  runMetaheuristics(pb); // Metaheuristiques
  return 0;
}


// =======================================================================
// end of file
// =======================================================================
