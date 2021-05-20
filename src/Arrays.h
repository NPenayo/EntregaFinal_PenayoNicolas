/*
 * arrays.h
 *
 *  Created on: Apr 22, 2021
 *      Author: Nicolas Alejandro Penayo
 */

#ifndef ARRAYS_H_
#define ARRAYS_H_
#define STRING_LENGTH 20

void appendCharToArray(char, char[], int);

int appendToString(char *message, char *output, int strLenght);

void appendIntToArray(int, int[], int);

void appendFloatToArray(float, float[], int);

void initializeChar(char[], int arrLength);

void initializeString(char[][STRING_LENGTH], int);

void initializeInt(int[], int);

void initializeFloat(float[], int);

void swapInt(int *arr, int a, int b);

void swapFloat(float *arr, int a, int b);

void swapChar(char *arr, int a, int b);

void swapString(char arr[][STRING_LENGTH], int arrLength, int a, int b);

void quicksortIntAsc(int *A, int izq, int der);

void quicksortFloatAsc(float *A, int izq, int der);

void quicksortCharAsc(char *A, int izq, int der);
#endif /* ARRAYS_H_ */
