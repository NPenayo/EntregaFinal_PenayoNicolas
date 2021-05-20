/**
 * validations.h
 *
 *  Author: Nicolas Alejandro Penayo
 *  Description: Validaciones de datos
 */

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_

int validChar(char *requestMsg, char *errorMsg, char *output,
		char *valid_values, int arrLength, int max_attempts);

int validInt(char *requestMsg, char *errorMsg, int *output, int min_value,
		int max_value, int max_attempts);

int validLongInt(char *requestMsg, char *errorMsg, long int *output,
		long int min_value, long int max_value, int max_attempts);

int validFloat(char *requestMsg, char *errorMsg, float *output, float min_value,
		float max_value, int max_attempts);

int validString(char *message, char *errMessage, char *output, int strLenght,
		int max_attempts);
#endif /* VALIDATIONS_H_ */
