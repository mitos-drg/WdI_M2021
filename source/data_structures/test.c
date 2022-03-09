//
// Created by mitos on 06.03.2022.
//

#include <stdio.h>
#include <stdlib.h>

#include <cstd/list.h>
#define CSTD_IMPLEMENTATION
#include <cstd/function.h>

void print(int a)
{
    printf("%d, ", a);
}

int main()
{
    i_list_s lista = malloc(sizeof(i_node_s));
    lista->data = 0;
    lista->next = NULL;
    push_back_ls(lista, 1);
    push_back_ls(lista, 2);
    push_back_ls(lista, 3);
    printf("Przed\n");
    foreach_ls_const(lista, &print);
    reverse_ls(&lista);
    foreach_ls_const(lista, &print);
    printf("Po");
}