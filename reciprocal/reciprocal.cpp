#include<cassert>
#include "reciprocal.hpp"

double reciprocal (int i)
{
    // i shouldn't be zero
    assert(i != 0);
    return (1.0/i);
}
