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

    char groupName[10];
    char ufo[10];

    input = fopen("ride.in", "r");
    output = fopen("ride.out", "w");

    fscanf(input, "%s", groupName);
    fscanf(input, "%s", ufo);

    fprintf(output, "%s", ufo);

    return 0;
}