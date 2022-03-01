//
// Created by mitos on 01.03.2022.
//

#ifndef WDI_MIM2021_FUNCTION_H
#define WDI_MIM2021_FUNCTION_H

typedef int (*i_operator)(int*, int*);
typedef int (*i_operator_c)(int, int);

typedef void (*i_method)(int*);
typedef void (*i_method_c)(int);

// Standard operator functions
int i_grater(int lhs, int rhs)
{
    return lhs > rhs ? lhs : rhs;
}
int i_gratereq(int lhs, int rhs)
{
    return lhs >= rhs ? lhs : rhs;
}

int i_less(int lhs, int rhs)
{
    return lhs < rhs ? lhs : rhs;
}
int i_lesseq(int lhs, int rhs)
{
    return lhs <= rhs ? lhs : rhs;
}

#endif //WDI_MIM2021_FUNCTION_H
