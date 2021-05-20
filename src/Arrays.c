/*
 * arrays.c
 *
 *  Created on: Apr 22, 2021
 *      Author: Nicolas Alejandro Penayo
 */
#include "Arrays.h"

#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
/**
 * @brief Inicializa un array de caracteres
 *
 * @param char[] Array a inicializar
 * @param int Largo del array
 */
void initializeChar(char arr[],int arrLength) {
	for(int i = 0; i < arrLength;i++){
		strcpy(&arr[i], " ");
	}

}
/**
 * @brief Inicializa un string
 *
 * @param char[] Array a inicializar
 * @param int Largo del array
 */
void initializeString(char arr[][STRING_LENGTH], int arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		for (int j = 0; j < arrayLength; j++) {
			strcpy(&arr[i][j], " ");
		}
	}

}
/**
 * @brief Inicializa un array de numeros
 *
 * @param int[] Array a inicializar
 * @param int Largo del array
 */
void initializeInt(int arr[], int arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		arr[i] = 0;
	}
}
/**
 * @brief Inicializa un array de tipo flotante
 *
 * @param float[] Array a inicializar
 * @param int Largo del array
 */
void initializeFloat(float arr[], int arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		arr[i] = 0;
	}
}
/**
 * @brief Insertar un dato en un array de tipo char
 *
 * @param char Dato a insertar
 * @param char[] Array donde se inserta el dato
 * @param int Largo del array
 */
void appendCharToArray(char input, char arr[], int index) {
	arr[index] = input;
}
/**
 * @brief Insertar un dato en un array de tipo int
 *
 * @param int Dato a insertar
 * @param int[] Array donde se inserta el dato
 * @param int Largo del array
 */
void appendIntToArray(int input, int arr[], int index) {
	arr[index] = input;
}
/**
 * @brief Insertar un dato en un array de tipo flotante
 *
 * @param float Dato a insertar
 * @param float[] Array donde se inserta el dato
 * @param int Largo del array
 */
void appendFloatToArray(float input, float arr[], int index) {
	arr[index] = input;
}
/**
 * @fn int appendToString(char*, char*)
 * @brief Cargar texto en un string
 *
 * @param input_string
 * @param output
 * @param strLenght
 */
int appendToString(char message[], char output[], int strLenght) {
	int resp;
	printf("\n%s: ", message);
	__fpurge(stdin);
	char aux[STRING_LENGTH];
	initializeChar(aux,STRING_LENGTH);
	if (fgets(aux, strLenght, stdin) != NULL) {
		resp = 1;
		for (int i = 0; i < strLenght; i++) {
			if (isdigit(aux[i])) {
				resp = 0;
				break;
			}
		}
		for(int i = 0; i<strLenght;i++){
			aux[i] = tolower(aux[i]);
		}
		aux[strcspn(aux, "\n")] = 0;
		strcpy(output, aux);

	}
	return resp;
}
/**
 * @fn void swapInt(int, int)
 * @brief Intercambiar dos valores del tipo int
 *
 * @param arr Array donde se encuentran los valores a intecambiar
 * @param a Valor 1 para intercambiar
 * @param b Valor 2 para intercambiar
 */
void swapInt(int *arr, int a, int b) {
	int aux;
	aux = arr[a];
	arr[a] = arr[b];
	arr[b] = aux;
}
/**
 * @fn void swapFloat(float, float)
 * @brief Intercambiar dos valores del tipo float
 *
 * @param arr Array donde se encuentran los valores a intecambiar
 * @param a Valor 1 para intercambiar
 * @param b Valor 2 para intercambiar
 */
void swapFloat(float *arr, int a, int b) {
	float aux;
	aux = arr[a];
	arr[a] = arr[b];
	arr[b] = aux;
}
/**
 * @fn void swapChar(char*, int, int)
 * @brief Intercambiar dos valores del tipo char
 *
 * @param arr Array donde se encuentran los valores a intecambiar
 * @param a Valor 1 para intercambiar
 * @param b Valor 2 para intercambiar
 */
void swapChar(char *arr, int a, int b) {
	char aux;
	aux = arr[a];
	arr[a] = arr[b];
	arr[b] = aux;
}
/**
 * @fn void swapString(char*, int, int)
 * @brief Intercambiar dos cadenas de caracteres
 *
 * @param arr Array donde se encuentran los valores a intecambiar
 * @param a Valor 1 para intercambiar
 * @param b Valor 2 para intercambiar
 */
void swapString(char arr[][STRING_LENGTH], int arrLength, int a, int b) {
	char aux[1][STRING_LENGTH];
	initializeString(aux, 1);
	strcpy(aux[0], &arr[a][STRING_LENGTH]);
	strcpy(&arr[a][STRING_LENGTH], &arr[b][STRING_LENGTH]);
	strcpy(&arr[b][STRING_LENGTH], aux[0]);

}

void quicksortIntAsc(int *A, int izq, int der) {
	if (der - izq > 1) {
		{
			int centro = (izq + der) / 2;
			if (A[izq] > A[centro]) {

			}
			swapInt(A, izq, centro);
			if (A[izq] > A[der])
				swapInt(A, izq, der);
			if (A[centro] > A[der])
				swapInt(A, centro, der);
			swapInt(A, centro, der - 1);
		}
		{
			int i = izq, j = der - 1;
			int pivote = A[der - 1];
			do {
				do
					i++;
				while (A[i] < pivote);
				do
					j--;
				while (A[j] > pivote);
				swapInt(A, i, j);
			} while (j > i);
		}
	}
}

void quicksortFloatAsc(float *A, int izq, int der) {
	if (der - izq > 1) {
		{
			int centro = (izq + der) / 2;
			if (A[izq] > A[centro]) {

			}
			swapFloat(A, izq, centro);
			if (A[izq] > A[der])
				swapFloat(A, izq, der);
			if (A[centro] > A[der])
				swapFloat(A, centro, der);
			swapFloat(A, centro, der - 1);
		}
		{
			int i = izq, j = der - 1;
			int pivote = A[der - 1];
			do {
				do
					i++;
				while (A[i] < pivote);
				do
					j--;
				while (A[j] > pivote);
				swapFloat(A, i, j);
			} while (j > i);
		}
	}
}
void quicksortCharAsc(char *A, int izq, int der) {
	if (der - izq > 1) {
		{
			int centro = (izq + der) / 2;
			if (A[izq] > A[centro]) {

			}
			swapChar(A, izq, centro);
			if (A[izq] > A[der])
				swapChar(A, izq, der);
			if (A[centro] > A[der])
				swapChar(A, centro, der);
			swapChar(A, centro, der - 1);
		}
		{
			int i = izq, j = der - 1;
			int pivote = A[der - 1];
			do {
				do
					i++;
				while (A[i] < pivote);
				do
					j--;
				while (A[j] > pivote);
				swapChar(A, i, j);
			} while (j > i);
		}
	}
}
