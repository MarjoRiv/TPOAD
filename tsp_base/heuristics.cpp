#include "heuristics.h"

#include "solution.h"

#include <algorithm>


// H1: create the natural sequence (0, 1, 2 ..., n-1)
void H1_heuristic (Solution & sol)
{
  // initialization
  sol.clear();

  // main loop
  sol.insert(0);
  for (unsigned i = 1; i < sol.size(); ++i)
  {
    sol.insert(i, i - 1);
  }
}



int twoOpt (Solution & sol)
{
  //std::cout << "entering " << __PRETTY_FUNCTION__ << std::endl;
  int delta = 0;
  const Data & data = sol.data();

  // scan for an improving 2opt
  unsigned best_i, best_j;
  unsigned start_i = 0;
  unsigned next_i = sol.next(0);
  unsigned stop_i = sol.prev(sol.prev(0));
  for (unsigned i = start_i; i != stop_i; i = next_i, next_i = sol.next(next_i))
  {
    unsigned start_j = sol.next(next_i);
    unsigned next_j = sol.next(start_j);
    unsigned stop_j = ((i == start_i) ? stop_i : sol.prev(start_i));
    for (unsigned j = start_j; j != stop_j; j = next_j, next_j = sol.next(next_j))
    {
      delta = int(data(i,next_i) + data(j,next_j)) - int(data(i,j) + data(next_i,next_j));
      if (delta > 0)
      {
          best_i = i;
          best_j = j;

          // std::cout << "2opt: got an improvement, gain = " << delta << " on i = " << i << " and  j = " << j << std::endl;
          goto twoOpt_update;
      }
    }
  }

  // check for an improving 2opt
  if (delta > 0)
  {
    twoOpt_update:
    // found one
    unsigned i = best_i;
    next_i = sol.next(i);
    unsigned j = best_j;
    unsigned next_j = sol.next(j);

    // revert the segment next_i -> j
    for (unsigned k = next_i; k != next_j; k = sol.prev((k)))
    {
      std::swap(sol.prev(k), sol.next(k));
    }

    // set the connections (i,j) (next_i,next_j)
    sol.next(i) = j; sol.prev(j) = i;
    sol.next(next_i) = next_j; sol.prev(next_j) = next_i;
    sol.value() -= delta;

    sol.check();
  }

  //std::cout << "leaving " << __PRETTY_FUNCTION__ << std::endl;

  return std::max(delta,0);
}


// Nearest Neighboor: create the nearest neighboor sequence
void Nearest_neighboor (Solution & sol,int a)
{
	const Data & data = sol.data();
	const unsigned n = data.size();
	const std::vector<Node> nodes =data.nodes();
	std::vector<unsigned> neighboors;
	int k;
	unsigned i = a;
	unsigned int neighboor=a;
	bool visite[n]={false};
	sol.clear();
	sol.insert(a);
	visite[a]=true;
	while (std::find(visite,visite+n,false) != visite+n)
	{
		 k=0;
		 neighboors=nodes[i].neighbours();
		 while (visite[neighboors[k]])
		  {
			  k++;
		  }
		neighboor= nodes[i].neighbours()[k];
	    visite[neighboor]=true;
		sol.insert(neighboor,i);
		
		 i=neighboor;	
	  }
	sol.check();
}

// Cheapest Insertion: create the cheapest insertion sequence
void Cheapest_insertion (Solution & sol,int a, int b)
{
	const Data & data = sol.data();
	const unsigned n = data.size();
	const std::vector<Node> nodes =data.nodes();
	Node node1 = nodes[a];
	Node node2 =nodes[b];
	std::vector<unsigned> neighboors;
	int k ;
	unsigned i = a,j = b,min;
	unsigned int neighboor=a,tmp;
	unsigned int neighboormin=a;
	bool visite[n]={false};
	sol.clear();
	sol.insert(b);
	sol.insert(a,b);
	visite[a]=true;
	visite[b]=true;
	while (std::find(visite,visite+n,false) != visite+n)
	{
		 k=0;
		 neighboors=nodes[a].neighbours();
		 while (visite[neighboors[k]])
		  {
			  k++;
		  }
		  min=RAND_MAX;
		 for(unsigned l= k; l < n ; ++l)
		  {
                            neighboor= nodes[a].neighbours()[k];
                            if(!visite[neighboor])
                            {
                                    tmp=data.operator ()(a,neighboor) + data.operator ()(neighboor,b);
                                    if(tmp < min)
                                    {
                                            min=tmp;
                                            neighboormin=neighboor;
                                    }
                            }
                    }
	    visite[neighboormin]=true;
	    sol.remove(b);
		sol.insert(neighboormin,a);
		sol.insert(b,neighboormin);
		a=neighboormin;
		
		
	  }
	sol.check();
}


/* ======================================================================= */
/* end of file                                                             */
/* ======================================================================= */
