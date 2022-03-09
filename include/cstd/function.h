//
// Created by mitos on 01.03.2022.
//

#ifndef WDI_MIM2021_FUNCTION_H
#define WDI_MIM2021_FUNCTION_H

typedef int (*i_operator)(int*, int*);
typedef int (*i_operator_c)(int, int);

typedef void (*i_method)(int*);
typedef void (*i_method_c)(int);

// Standard comparison functions
int i_grater(int lhs, int rhs);
int i_gratereq(int lhs, int rhs);

int i_less(int lhs, int rhs);
int i_lesseq(int lhs, int rhs);

#ifdef CSTD_IMPLEMENTATION

int i_grater(int lhs, int rhs)
{
    return lhs > rhs;
}
int i_gratereq(int lhs, int rhs)
{
    return lhs >= rhs;
}

int i_less(int lhs, int rhs)
{
    return lhs < rhs;
}
int i_lesseq(int lhs, int rhs)
{
    return lhs <= rhs;
}

#endif

#endif //WDI_MIM2021_FUNCTION_H
