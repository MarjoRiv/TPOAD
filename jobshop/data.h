#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include "Operation.h"
#include <vector>
class Data
{
    protected:
        int n;
        int m;
        std::vector< std::vector <Operation> > Op;
    public:
        int get_n(); void set_n(int nn);
        int get_m(); void set_m(int mm);
};

#endif // DATA_H_INCLUDED
