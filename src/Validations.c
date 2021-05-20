/**
 * validations.c
 *
 *  Author: Nicolas Alejandro Penayo
 *  Description: Validaciones de datos
 */
//#include "Validations.h"
#include "Arrays.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define attempts_MSG "Cantidad de intentos supereda. Vuelva a intentar mas tarde."
/**
 * @fn int validChar(char*,char *,char*,char *,int,int)
 * @brief Valida que el dato ingresado sea un char
 *
 * @param requestMsg Mensaje a para mostrar al usuario en primera instancia
 * @param errorMsg Mensaje a mostrar en caso de error
 * @param output Variable donde se guarda el dato a validar
 * @param valid_values Chars validos
 * @param arrLength Cantidad de chars validos
 * @param max_attempts Numero de intentos
 * @return 1 si es valido 0 si es invalido
 */
int validChar(char *requestMsg, char *errorMsg, char *output,
		char *valid_values, int arrLength, int max_attempts) {
	char aux;
	int isChar = 0;
	int valid = 0;
	int attempts = 0;
	int resp = 0;
	do {
		printf("\n%s ", requestMsg);
		__fpurge(stdin);
		isChar = scanf("%c", &aux);
		for (int i = 0; i < arrLength; i++) {
			if (aux == valid_values[i] && isChar) {
				valid = 1;
				resp = 1;
				*output = aux;
				break;
			}
		}
		if (!valid) {
			printf("\n%s ", errorMsg);
		}
		attempts++;
	} while (!valid && attempts < max_attempts);
	if (attempts == max_attempts) {
		system("clear");
		printf(
				"\nCantidad de intentos superada. Presione una tecla para volver al menu");
		__fpurge(stdin);
		getchar();
	}
	return resp;
}
/**
 * @fn int validInt(char[], char[], int*, int, int, int)
 * @brief Valida que el dato ingresado sea un int
 *
 * @param requestMsg Mensaje a para mostrar al usuario en primera instancia
 * @param errorMsg Mensaje a mostrar en caso de error
 * @param output Variable donde se guarda el dato a validar
 * @param min_value Valor minimo que puede tomar la variable
 * @param max_value Valor maximo que puede tomar la variable
 * @param max_attempts Numero de intentos
 * @return 1 si es valido 0 si es invalido
 */
int validInt(char *requestMsg, char *errorMsg, int *output, int min_value,
		int max_value, int max_attempts) {
	int aux;
	int resp = 0;
	int isInt;
	int valid = 0;
	int attempts = 0;
	do {
		printf("\n%s :", requestMsg);
		__fpurge(stdin);
		isInt = scanf("%d", &aux);
		if (isInt && (aux >= min_value && aux <= max_value)) {
			valid = 1;
			resp = 1;
			*output = aux;
			break;
		} else {
			printf("\n%s ", errorMsg);
		}
		attempts++;
	} while (!valid && attempts < max_attempts);
	if (attempts == max_attempts) {
		system("clear");
		printf(
				"\nCantidad de intentos superada. Presione una tecla para volver al menu");
		__fpurge(stdin);
		getchar();
	}
	return resp;
}
/**
 * \fn int validLongInt(char*, char*, long int*, long int, long int, int)
 * \brief
 * \param requestMsg Mensaje a para mostrar al usuario en primera instancia
 * \param errorMsg Mensaje a mostrar en caso de error
 * \param output Variable donde se guarda el dato a validar
 * \param min_value Valor minimo que puede tomar la variable
 * \param max_value Valor maximo que puede tomar la variable
 * \param max_attempts Numero de intentos
 * \return 1 si es valido 0 si es invalido
 */
int validLongInt(char *requestMsg, char *errorMsg, long int *output,
		long int min_value, long int max_value, int max_attempts) {
	long int aux;
	int resp = 0;
	int isLong;
	int valid = 0;
	int attempts = 0;
	do {
		printf("\n%s ", requestMsg);
		__fpurge(stdin);
		isLong = scanf("%ld", &aux);
		if (isLong && (aux >= min_value && aux <= max_value)) {
			valid = 1;
			resp = 1;
			*output = aux;
			break;
		} else {
			printf("\n%s ", errorMsg);
		}
		attempts++;
	} while (!valid && attempts < max_attempts);
	if (attempts == max_attempts) {
		system("clear");
		printf(
				"\nCantidad de intentos superada. Presione una tecla para volver al menu");
		__fpurge(stdin);
		getchar();
	}
	return resp;
}
/**
 * @fn int validFloat(char[], char[], float*, float, float, int)
 * @brief Valida que el dato ingresado sea un float
 *
 * @param requestMsg Mensaje a para mostrar al usuario en primera instancia
 * @param errorMsg Mensaje a mostrar en caso de error
 * @param output Variable donde se guarda el dato a validar
 * @param min_value Valor minimo que puede tomar la variable
 * @param max_value Valor maximo que puede tomar la variable
 * @param max_attempts Numero de intentos
 * @return 1 si es valido 0 si es invalido
 */
int validFloat(char *requestMsg, char *errorMsg, float *output, float min_value,
		float max_value, int max_attempts) {
	float aux;
	int resp = 0;
	float isFloat = 0;
	int valid = 0;
	int attempts = 0;
	do {
		printf("\n%s: ", requestMsg);
		__fpurge(stdin);
		isFloat = scanf("%f", &aux);
		if (isFloat && (aux >= min_value || aux <= max_value)) {
			valid = 1;
			resp = 1;
			*output = aux;
			break;
		} else {
			printf("\n%s ", errorMsg);
		}
		attempts++;
	} while (!valid && attempts < max_attempts);
	if (attempts == max_attempts) {
		system("clear");
		printf(
				"\nCantidad de intentos superada. Presione una tecla para volver al menu");
		__fpurge(stdin);
		getchar();
	}
	return resp;
}
/**
 * @fn int appendToString(char*, char*)
 * @brief Validate if a string have an number in it
 *
 * @param input_string
 * @param output
 * @param strLenght
 */
int validString(char *message, char *errMessage, char *output, int strLenght,
		int max_attempts) {
	int resp = 0;
	int attempts = 0;
	char aux[strLenght];
	initializeChar(aux, strLenght);

	if (strcmp(message, "\0") && strcmp(errMessage, "\0") && strLenght > 0) {
		do {
			printf("\n%s: ", message);
			__fpurge(stdin);
			fgets(aux, strLenght, stdin);
			if (strcmp(&aux[0], "\n") && strcmp(&aux[0], "\0")) {
				resp = 1;
				for (int i = 0; i < sizeof(aux); i++) {
					if (isdigit(aux[i])) {
						resp = 0;
						break;
					}
				}
				if (!resp) {
					printf("\n%s", errMessage);
					printf("\nSi desea salir presione x: ");
					__fpurge(stdin);
					attempts++;
				} else {
					for (int i = 0; i < strLenght; i++) {
						aux[i] = tolower(aux[i]);
					}
					aux[strcspn(aux, "\n")] = 0;
					strcpy(output, aux);
				}

			} else {
				printf("\n%s", errMessage);
				attempts++;
			}
		} while (!resp && attempts < max_attempts);
	} else {
		system("clear");
		printf("\nError.Parametro de validString() invalido.");
	}

	if (attempts == max_attempts) {
		system("clear");
		printf(
				"\nMaxima cantidad de intentos superada. Presione una tecla para volver atras.");
		__fpurge(stdin);
		getchar();
	}

	return resp;
}
