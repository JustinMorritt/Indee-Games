/*************************************************************
      Random Number Generator (randgen.h)

RGD 02/22/03 -- Initial Coding
RGD 03/26/03 -- Implemented the Mersenne Twister algorithm for random number generation.
RGD 05/17/2010 -- Implemented randomShuffle for vector templates


Copyright 2003 Earz Music Software Inc. All rights reserved.
**************************************************************/


#ifndef RANDGEN_H__
#define RANDGEN_H__

#include <cstddef>
#include <ctime>
#include <vector>
#include <cassert>



//-----------------
// class definition
//-----------------


/* Period parameters */  

const unsigned N = 624;
const unsigned M  = 397;


#define MATRIX_A 0x9908b0df   /* constant vector a */
#define UPPER_MASK 0x80000000 /* most significant w-r bits */
#define LOWER_MASK 0x7fffffff /* least significant r bits */
/* for tempering */   
#define TEMPERING_MASK_B 0x9d2c5680
#define TEMPERING_MASK_C 0xefc60000
#define TEMPERING_SHIFT_U(y)  (y >> 11)
#define TEMPERING_SHIFT_S(y)  (y << 7)
#define TEMPERING_SHIFT_T(y)  (y << 15)
#define TEMPERING_SHIFT_L(y)  (y >> 18)

class RandGen;


namespace Util
{

    class RandGen 
    {
        // get a psuedo-random number from 0 to (lim - 1)
        unsigned operator () (unsigned lim);
//        unsigned operator () (void);
        //get a normalized pseudo random number
        unsigned Skew(unsigned nTableSize, int nSkew); 
        // constructor
        RandGen(unsigned long initSeed = static_cast<unsigned long>(time(0)));   
        int MarkToSkew(int Mark);
        static unsigned long ptgfsr[N]; /* set initial seeds: N = 624 words */
        static unsigned INDEX;
        static unsigned long mag01[2];
        double getNormalized(void);
        friend class ::RandGen;
    };

    //----------------------------
    // inline function definitions
    //----------------------------

    inline RandGen::RandGen(unsigned long seed)
    {
        unsigned long k;
          
        /* setting initial seeds to ptgfsr[N] using     */
        /* the generator Line 25 of Table 1 in          */
        /* [KNUTH 1981, The Art of Computer Programming */
        /*    Vol. 2 (2nd Ed.), pp102]                  */
        ptgfsr[0]= seed & 0xffffffff;
        for (k=1; k<N; k++)
        {
            ptgfsr[k] = (69069 * ptgfsr[k-1]) & 0xffffffff;
        }

    }



    inline int RandGen::MarkToSkew(int Mark)
    {
        int ret = (Mark * -2) + 100;
        return ret;
    }
}


class RandGen
{
public:

    // get a psuedo-random number from 0 to (lim - 1)
    unsigned operator () (unsigned lim = 0xffffffff) 
    {
        unsigned u = s_gen.operator()(lim);
        return u;
    }
    //        unsigned operator () (void);
    //get a normalized pseudo random number
    unsigned Skew(unsigned nTableSize, int nSkew)
    {
        assert(nTableSize != 0);
        unsigned u = s_gen.Skew(nTableSize, nSkew);
        return u;
    }
    double getNormalized()
    {
        double d = s_gen.getNormalized();
        return d;
    }

    bool coinFlip() 
    {
        return (operator()(2) == 0);
    }

    template <typename T>
    inline void randomShuffle(std::vector<T>& vec, unsigned int len = UINT_MAX) 
    {
        len = std::min(len, static_cast<unsigned int>(vec.size())); 
        switch(len)
        {
            case 0:
            case 1:
                return;
            case 2:
                if(coinFlip() == true)
                {
                    swap(vec[0], vec[1]);
                }
                return;
        }
        //More than 2
        for(unsigned int from = 0; from < len; ++from)
        {
            unsigned to;
            do
            {
                to = operator()(len);
            }while(to == from);
            swap(vec[from], vec[to]);
        }
    }

private:
    static Util::RandGen s_gen;

    template <typename T>
    inline void swap(T& x, T& y)
    {
        T tmp = x;
        x = y;
        y = tmp;
    }
};





#endif
