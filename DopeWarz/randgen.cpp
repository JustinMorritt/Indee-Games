/*************************************************************
Random Number Generator (randgen.cpp)

RGD 02/22/03 -- Initial Coding
RGD 05/17/2010 -- Implemented randomShuffle for vector templates

Copyright 2003 Earz Music Software Inc. All rights reserved.
**************************************************************/

#include <cassert>
#include <algorithm>
#include "randgen.h"




unsigned long Util::RandGen::ptgfsr[N];
unsigned long Util::RandGen::mag01[2] = {0x0, MATRIX_A};
unsigned Util::RandGen::INDEX = 0;
Util::RandGen RandGen::s_gen;




unsigned Util::RandGen::operator () (unsigned lim)
{

    unsigned long y;

    if(INDEX == N)
    { /* generate N words at one time */
        unsigned long kk;
        for (kk = 0; kk < N - M; kk++) 
        {
            y = (ptgfsr[kk] & UPPER_MASK)|(ptgfsr[kk + 1] & LOWER_MASK);
            ptgfsr[kk] = ptgfsr[kk + M] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        for (;kk < N - 1; kk++) 
        {
            y = (ptgfsr[kk] & UPPER_MASK) | (ptgfsr[kk + 1 ]& LOWER_MASK);
            ptgfsr[kk] = ptgfsr[kk + (M - N)] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        y = (ptgfsr[N - 1] & UPPER_MASK) | (ptgfsr[0] & LOWER_MASK);
        ptgfsr[N - 1] = ptgfsr[M - 1] ^ (y >> 1) ^ mag01[y & 0x1];
        INDEX = 0;
    }

    y = ptgfsr[INDEX++];
    y ^= TEMPERING_SHIFT_U(y);
    y ^= TEMPERING_SHIFT_S(y) & TEMPERING_MASK_B;
    y ^= TEMPERING_SHIFT_T(y) & TEMPERING_MASK_C;
    y &= 0xffffffff; /* you may delete this line if word size = 32 */
    y ^= TEMPERING_SHIFT_L(y);
    
    return y % lim;

}

/*=============================================================================================
Skew() takes a short representing the size of a list in which one element is to 
be chosen randomly and a short that represents the skewing applied to the the 
randomness.  Algorithm details are available at ______.

ARGLIST:
    -  nSizeOfTable:  The size of the list from which elements will be chosen.
    -  nSkewValue: The percentage that the frequency of the first element compared
       to the average frequency.
RETURN:
    -  a short >= 0 and < nSizeOfTable that is the index of the randomly chosen element.

Shorts are chosen in case this function is implemented on a platform in which
counter registers are 16 bit sized and ints are 32 bit sized. (Efficiency considerations.)
===============================================================================================*/



unsigned Util::RandGen::Skew(unsigned nTableSize, int nSkew)
{
    assert(nTableSize > 0);
    if(nTableSize == 1)
        return 0;   

    //adjust skew to (0, 100)
    nSkew = std::min(std::max(nSkew, 0), 100);
    
    nSkew = MarkToSkew(nSkew);
    unsigned nCounter = 0;
    double fDecrement, fFirstValue, fRandomValue;    
    //Calculate the average frequency
    fFirstValue = 1 / static_cast<double>(nTableSize);

    //Calculate the average of the first list element.
    fFirstValue *= (1.0 + (static_cast<double>(nSkew)) / 100.0);

    //Find the size of the excess if fFirstValue is extrapolated across the field.
    fDecrement = fFirstValue * static_cast<double>(nTableSize) - 1.0;

    //Calculate the size of the decrement by dividing the excess by the number
    //of decrements needed.

    fDecrement /= static_cast<double>(nTableSize * (nTableSize - 1) / 2);
    fRandomValue = getNormalized();

    
    //Subtract the frequency of the first value plus the adjustment depending on which iteration
    //If the Random value fall to 0.0 or below, that index is chosen.
    do
    {      
        fRandomValue -= (fFirstValue - (static_cast<double>(nCounter) * fDecrement));
        if(fRandomValue <= 0.0)
		{
            return nCounter;
		}
        nCounter++;
    }while(true);
}

double Util::RandGen::getNormalized(void)
{
    double v = operator()(0xffffffff);
    return v / static_cast<double>(0xffffffff);
}



