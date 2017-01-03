/*
 ID: komron11
 LANG: C++
 PROG: ride
 */

#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    FILE* input;
    FILE* output;

    char groupName[10] = {'\0'};
    char ufo[10] = {'\0'};

    input = fopen("ride.in", "r");
    output = fopen("ride.out", "w");

    fscanf(input, "%s", groupName);
    fscanf(input, "%s", ufo);

    int groupNameProduct = 1;
    int ufoProduct = 1;

    for (int i = 0; i < 6; i++) {
        groupNameProduct *= (groupName[i] - 64);
        ufoProduct *= (ufo[i] - 64);
    }

    groupNameProduct %= 47;
    ufoProduct %= 47;

    if (groupNameProduct == ufoProduct)
        fprintf(output, "GO\n");
    else
        fprintf(output, "STAY\n");

    return 0;
}