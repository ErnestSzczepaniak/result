#ifndef _t_h
#define _t_h

/**
 * @file	t.h
 * @author	en2
 * @date	20-04-2020
 * @brief	
 * @details	
**/

#include "result.h"

template<typename T>
Result<T> t()
{
    Result<T> t;

    return t;
}

struct WE
{
    char s[2];
}; /* structure: WE */


static void h()
{
    auto [a, b] = t<WE>();

}

#endif /* define: t_h */