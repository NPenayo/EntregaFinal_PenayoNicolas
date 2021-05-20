/*
 * income.c
 *
 *  Created on: 8 May 2021
 *      Author: npenayo
 */

#include "Income.h"
#include "Taxpayer.h"
#include "Arrays.h"
#include "Validations.h"
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#define PENDIENTE 0
#define REFINANCIAR 1
#define SALDAR 2
/**
 * \fn void indexIncomes(Income*, int, TaxPayer*, int, IcType*, int, int)
 * \brief Listar las recaudaciones y sus contribuyentes
 * \param incomes
 * \param arrLength
 * \param tpList
 * \param tpLen
 * \param list
 * \param icLens
 * \param arg
 */
void indexIncomes(Income *incomes, int arrLength, TaxPayer *tpList, int tpLen,
		IcType *list, int icLens, int arg) {
	int aux;
	int flag = 0;
	char auxFullName[51];
	int auxStringSize = 0;
	switch (arg) {
	case PENDIENTE:
		aux = 0;
		for (int i = 0; i < arrLength; i++) {
			if (incomes[i].assigned && (incomes[i].status == PENDIENTE)) {
				for (int j = 0; j < tpLen; j++) {
					if (tpList[j].id == incomes[i].id_taxPayer
							&& tpList[j].assigned) {

						if (flag != tpList[i].id) {
							auxStringSize = sizeof(tpList[j].name);
							strncpy(auxFullName, tpList[j].name, auxStringSize);
							strcat(auxFullName, " ");
							strcat(auxFullName, tpList[j].surname);
							for (int b = 0; b < sizeof(auxFullName); b++) {
								auxFullName[0] = toupper(auxFullName[0]);
								if (auxFullName[b] == ' ') {
									auxFullName[b + 1] = toupper(
											auxFullName[b + 1]);
								}
							}
							printf(
									"\n-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
							printf("\n\n%50s", "Contribuyente");
							printf(
									"\n---------------------------------------------------------------------------------");
							printf("\n %c %5s %3c %15s %8c %15s %8c %-15s ",
									'|', "ID", '|', "Nombre", '|', "Apellido",
									'|', "CUIL");
							printf(
									"\n---------------------------------------------------------------------------------");
							showTaxPayer(tpList[i]);
							printf(
									"\n---------------------------------------------------------------------------------");
							flag = tpList[i].id;
						}

					}

				}
				if (!aux) {
					printf("\n\n%50s %s", "Recaudaciones de", auxFullName);
					printf(
							"\n---------------------------------------------------------------------------------");
					printf("\n\n %s %c %-10s %c %-10s %c %-10s %c %s",
							"ID_recaudacion", '|', "Mes", '|', "Tipo", '|',
							"Monto", '|', "Estado");
					printf(
							"\n---------------------------------------------------------------------------------");
				}
				showIncome(incomes[i], list, icLens);
				aux++;

			}

		}
		if (!aux) {
			printf("\nNo hay recaudaciones saldadas");
		}
		break;
	case REFINANCIAR:
		aux = 0;
		for (int i = 0; i < arrLength; i++) {
			if (incomes[i].assigned && (incomes[i].status == REFINANCIAR)) {
				for (int j = 0; j < tpLen; j++) {
					if (tpList[j].id == incomes[i].id_taxPayer
							&& tpList[j].assigned) {

						if (flag != tpList[i].id) {
							auxStringSize = sizeof(tpList[j].name);
							strncpy(auxFullName, tpList[j].name, auxStringSize);
							strcat(auxFullName, " ");
							strcat(auxFullName, tpList[j].surname);
							for (int b = 0; b < sizeof(auxFullName); b++) {
								auxFullName[0] = toupper(auxFullName[0]);
								if (auxFullName[b] == ' ') {
									auxFullName[b + 1] = toupper(
											auxFullName[b + 1]);
								}
							}
							printf(
									"\n-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
							printf("\n\n%50s", "Contribuyente");
							printf(
									"\n---------------------------------------------------------------------------------");
							printf("\n %c %5s %3c %15s %8c %15s %8c %-15s ",
									'|', "ID", '|', "Nombre", '|', "Apellido",
									'|', "CUIL");
							printf(
									"\n---------------------------------------------------------------------------------");
							showTaxPayer(tpList[i]);
							printf(
									"\n---------------------------------------------------------------------------------");
							flag = tpList[i].id;
						}

					}

				}
				if (!aux) {
					printf("\n\n%50s %s", "Recaudaciones de", auxFullName);
					printf(
							"\n---------------------------------------------------------------------------------");
					printf("\n %s %c %-10s %c %-10s %c %-10s %c %s",
							"ID_recaudacion", '|', "Mes", '|', "Tipo", '|',
							"Monto", '|', "Estado");
					printf(
							"\n---------------------------------------------------------------------------------");
				}
				showIncome(incomes[i], list, icLens);
				aux++;

			}

		}
		if (!aux) {
			printf("\nNo hay recaudaciones saldadas");
		}
		break;
	case SALDAR:
		aux = 0;
		for (int i = 0; i < arrLength; i++) {
			if (incomes[i].assigned && (incomes[i].status == SALDAR)) {
				for (int j = 0; j < tpLen; j++) {
					if (tpList[j].id == incomes[i].id_taxPayer
							&& tpList[j].assigned) {

						if (flag != tpList[i].id) {
							aux = 0;
							auxStringSize = sizeof(tpList[j].name);
							strncpy(auxFullName, tpList[j].name, auxStringSize);
							strcat(auxFullName, " ");
							strcat(auxFullName, tpList[j].surname);
							for (int b = 0; b < sizeof(auxFullName); b++) {
								auxFullName[0] = toupper(auxFullName[0]);
								if (auxFullName[b] == ' ') {
									auxFullName[b + 1] = toupper(
											auxFullName[b + 1]);
								}
							}
							printf(
									"\n-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
							printf("\n\n%50s", "Contribuyente");
							printf(
									"\n---------------------------------------------------------------------------------");
							printf("\n %c %5s %3c %15s %8c %15s %8c %-15s ",
									'|', "ID", '|', "Nombre", '|', "Apellido",
									'|', "CUIL");
							printf(
									"\n---------------------------------------------------------------------------------");
							showTaxPayer(tpList[i]);
							printf(
									"\n---------------------------------------------------------------------------------");
							flag = tpList[i].id;
						}

					}

				}
				if (!aux) {
					printf("\n\n%50s %s", "Recaudaciones de", auxFullName);
					printf(
							"\n---------------------------------------------------------------------------------");
					printf("\n %s %c %-10s %c %-10s %c %-10s %c %s",
							"ID_recaudacion", '|', "Mes", '|', "Tipo", '|',
							"Monto", '|', "Estado");
					printf(
							"\n---------------------------------------------------------------------------------");
				}
				showIncome(incomes[i], list, icLens);
				aux++;

			}

		}
		if (!aux) {
			printf("\nNo hay recaudaciones saldadas");
		}
		break;

	default:
		for (int i = 0; i < tpLen; i++) {
			if (tpList[i].id && tpList[i].assigned) {
				aux = 0;
				auxStringSize = sizeof(tpList[i].name);
				strncpy(auxFullName, tpList[i].name, auxStringSize);
				strcat(auxFullName, " ");
				strcat(auxFullName, tpList[i].surname);
				for (int b = 0; b < sizeof(auxFullName); b++) {
					auxFullName[0] = toupper(auxFullName[0]);
					if (auxFullName[b] == ' ') {
						auxFullName[b + 1] = toupper(auxFullName[b + 1]);
					}
				}
				printf(
						"\n-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
				printf("\n\n%50s", "Contribuyente");
				printf(
						"\n---------------------------------------------------------------------------------");
				printf("\n %c %5s %3c %15s %8c %15s %8c %-15s ", '|', "ID", '|',
						"Nombre", '|', "Apellido", '|', "CUIL");
				printf(
						"\n---------------------------------------------------------------------------------");
				showTaxPayer(tpList[i]);
				printf(
						"\n---------------------------------------------------------------------------------");
				for (int j = 0; j < arrLength; j++) {
					if (incomes[j].assigned
							&& (incomes[j].id_taxPayer == tpList[i].id)) {
						if (!aux) {
							printf("\n\n%50s %s", "Recaudaciones de",
									auxFullName);
							printf(
									"\n---------------------------------------------------------------------------------");
							printf("\n %s %c %-10s %c %-10s %c %-10s %c %s",
									"ID_recaudacion", '|', "Mes", '|', "Tipo",
									'|', "Monto", '|', "Estado");
							printf(
									"\n---------------------------------------------------------------------------------");
						}
						showIncome(incomes[j], list, icLens);
						printf(
								"\n---------------------------------------------------------------------------------");

						aux++;

					}
				}
				if (!aux) {
					printf("\nEste contribuyente no tiene ninguna recaudacion");
					printf(
							"\n*********************************************************************************");

				}
			}
		}
		break;
	}

}
/**
 * \fn void showIncome(Income, IcType*, int)
 * \brief Mostrar una recaudacion
 * \param income
 * \param list
 * \param lens
 */
void showIncome(Income income, IcType *list, int lens) {
	char income_type[20];
	char auxmonth[15];
	char status[15];
	initializeChar(auxmonth, 10);
	initializeChar(income_type, 20);
	getIcStatus(income, status);

	for (int i = 0; i < lens; i++) {
		if (income.id_type == list[i].id) {
			strcpy(income_type, list[i].description);

			break;
		}
	}
	switch (income.month) {
	case 1:
		strcpy(auxmonth, "Enero");
		break;
	case 2:
		strcpy(auxmonth, "Febrero");
		break;
	case 3:
		strcpy(auxmonth, "Marzo");
		break;
	case 4:
		strcpy(auxmonth, "Abril");
		break;
	case 5:
		strcpy(auxmonth, "Mayo");
		break;
	case 6:
		strcpy(auxmonth, "Junio");
		break;
	case 7:
		strcpy(auxmonth, "Julio");
		break;
	case 8:
		strcpy(auxmonth, "Agosto");
		break;
	case 9:
		strcpy(auxmonth, "Septiembre");
		break;
	case 10:
		strcpy(auxmonth, "Octubre");
		break;
	case 11:
		strcpy(auxmonth, "Noviembre");
		break;
	case 12:
		strcpy(auxmonth, "Diciembre");
		break;
	}
	printf("\n %10d %6c %-10s %c %-6s %2c $%.2f %2c %-20s", income.id, '|',
			auxmonth, '|', income_type, '|', income.amount, '|', status);
}
/**
 * \fn int updateIncome(Income*, int, TaxPayer*, int, IcType*, int, int)
 * \brief Actualizar el estado de una recaudacion
 * \param list
 * \param icLens
 * \param tpList
 * \param tplens
 * \param typeList
 * \param typeLens
 * \param action
 * \return
 */
int updateIncome(Income *list, int icLens, TaxPayer *tpList, int tplens,
		IcType *typeList, int typeLens, int action) {
	int resp = 0;
	int isIncome;
	int auxIcIndex;
	int auxTpIndex;
	int aux;
	int registers;
	char opt;
	if (!action) {
		do {
			aux = 0;
			registers = 0;
			for (int i = 0; i < icLens; i++) {
				if (list[i].assigned) {
					registers++;
				}
			}
			for (int i = 0; i < icLens; i++) {
				if (list[i].status && list[i].assigned) {
					aux++;
				}
			}
			if (aux >= registers) {
				printf("\nNo hay recaudaciones para financiar");
				break;
			}
			printf("\n%50s", "Refinanciar");
			printf(
					"\n---------------------------------------------------------------------------------");

			printf("\n\n%50s", "Recaudaciones");
			printf(
					"\n---------------------------------------------------------------------------------");
			printf("\n %s %c %-10s %c %-10s %c %-10s %c %s", "ID_recaudacion",
					'|', "Mes", '|', "Tipo", '|', "Monto", '|', "Estado");
			printf(
					"\n---------------------------------------------------------------------------------");
			for (int i = 0; i < icLens; i++) {
				if (list[i].assigned && !(list[i].status)) {
					showIncome(list[i], typeList, typeLens);
					printf(
							"\n---------------------------------------------------------------------------------");
				}
			}
			printf("\nIngrese el ID de la recaudación a refinanciar: ");
			__fpurge(stdin);
			scanf("%d", &isIncome);
			if (validIncome(list, icLens, isIncome, &auxIcIndex)) {
				if (getTaxPayerById(tpList, tplens,
						list[auxIcIndex].id_taxPayer, &auxTpIndex)) {
					printf(
							"\n---------------------------------------------------------------------------------");

					printf("\n %c %5s %3c %15s %8c %15s %8c %-15s ", '|', "ID",
							'|', "Nombre", '|', "Apellido", '|', "CUIL");
					printf(
							"\n---------------------------------------------------------------------------------");
					showTaxPayer(tpList[auxTpIndex]);
					printf(
							"\n\nSeguro desea refinanciar la recaudacion %d para este contribuyente?(s/n)",
							list[auxIcIndex].id);
					__fpurge(stdin);
				}

				scanf("%c", &opt);
				if (opt == 's') {
					list[auxIcIndex].status = REFINANCIAR;
					resp = 1;
					break;
				} else {
					printf("\nNo se refinancio la recaudacion.");
					printf(
							"Pulse (m) para volver al menu o cualquier tecla para continuar");
					__fpurge(stdin);
					scanf("%c", &opt);
				}
			} else {
				printf("\nError.ID de recaudadicion invalido.");
				printf(
						"\nPulse (m) para volver al menu o cualquier tecla para continuar");
				__fpurge(stdin);
				scanf("%c", &opt);
			}
		} while (!(opt == 'm'));
	} else {
		do {
			aux = 0;
			registers = 0;
			for (int i = 0; i < icLens; i++) {
				if (list[i].assigned) {
					registers++;
				}
			}
			for (int i = 0; i < icLens; i++) {
				if (list[i].status == SALDAR) {
					aux++;
				}
			}
			if (aux == registers) {
				printf("\nNo hay recaudaciones para saldar");
				break;
			}
			printf("\n%50s", "Saldar");
			printf(
					"\n---------------------------------------------------------------------------------");

			printf("\n\n%50s", "Recaudaciones");
			printf(
					"\n---------------------------------------------------------------------------------");
			printf("\n %s %c %-10s %c %-10s %c %-10s %c %s", "ID_recaudacion",
					'|', "Mes", '|', "Tipo", '|', "Monto", '|', "Estado");
			printf(
					"\n---------------------------------------------------------------------------------");
			for (int i = 0; i < icLens; i++) {
				if (list[i].assigned && list[i].status != SALDAR) {
					showIncome(list[i], typeList, typeLens);
					printf(
							"\n---------------------------------------------------------------------------------");
				}
			}
			printf("\nIngrese el ID de la recaudación a saldar: ");
			__fpurge(stdin);
			scanf("%d", &isIncome);
			if (validIncome(list, icLens, isIncome, &auxIcIndex)) {
				getTaxPayerById(tpList, tplens, list[auxIcIndex].id_taxPayer,
						&auxTpIndex);
				printf(
						"\n---------------------------------------------------------------------------------");

				printf("\n %c %5s %3c %15s %8c %15s %8c %-15s ", '|', "ID", '|',
						"Nombre", '|', "Apellido", '|', "CUIL");
				printf(
						"\n---------------------------------------------------------------------------------");
				showTaxPayer(tpList[auxTpIndex]);
				printf(
						"\n\nSeguro desea saldar la recaudacion %d para este contribuyente?(s/n)",
						list[auxIcIndex].id);
				__fpurge(stdin);
				scanf("%c", &opt);
				if (opt == 's') {
					list[auxIcIndex].status = SALDAR;
					resp = 1;
					break;
				} else {
					printf("\nNo se saldo la recaudacion.");
					printf(
							"Pulse (m) para volver al menu o cualquier tecla para continuar");
					__fpurge(stdin);
					scanf("%c", &opt);
				}
			} else {
				printf("\nError.ID de recaudadicion invalido.");
				printf(
						"\nPulse (m) para volver al menu o cualquier tecla para continuar");
				__fpurge(stdin);
				scanf("%c", &opt);
			}
		} while (!(opt == 'm'));
	}

	return resp;
}
/**
 * \fn int createIncome(Income*, int, int*, int, IcType*, int, TaxPayer*, int)
 * \brief Dar de alta una nueva recaudacion
 * \param icList
 * \param icLens
 * \param id
 * \param index
 * \param tyList
 * \param tyLens
 * \param tpList
 * \param tpLens
 * \return
 */
int createIncome(Income *icList, int icLens, int *id, int index, IcType *tyList,
		int tyLens, TaxPayer *tpList, int tpLens) {
	int resp = 0;
	int id_taxPayer;
	char opt;
	int month;
	int id_type;
	float amount;
	char surname[STR_LEN];
	initializeChar(surname, STR_LEN);
	printf("\n%50s", "Alta Recaudaciones");
	do {
		indexTaxpayers(tpList, tpLens);
		printf("\nEscriba ID de contribuyente: ");
		__fpurge(stdin);
		scanf("%d", &id_taxPayer);
		if (getTaxPayerById(tpList, tpLens, id_taxPayer, &id_taxPayer)) {
			if (validInt("Mes(1-12)", "Error.Mes invalido.", &month, 1, 12,
			MAX_ATTEMPTS)) {
				if (validType(tyList, tyLens, MAX_ATTEMPTS, &id_type)
						&& validFloat("Importe", "Error.Dato invalido.",
								&amount, 1, 10000, MAX_ATTEMPTS)) {
					Income newIncome;
					newIncome.id = *id;
					(*id)++;
					newIncome.month = month;
					newIncome.id_type = id_type;
					newIncome.id_taxPayer = tpList[id_taxPayer].id;
					newIncome.amount = amount;
					newIncome.assigned = 1;
					newIncome.status = 0;
					icList[index] = newIncome;
					resp = 1;
					break;
				}
			}
		} else {
			printf("\nNo se encontró el ID del empleado.");
			printf("\nPresione (m) para volver al menu.");
			__fpurge(stdin);
			scanf("%c", &opt);
		}
	} while (!(opt == 'm'));

	return resp;
}
/**
 * \fn void initializeIncomes(Income*, int)
 * \brief Inicializar array de tipo Income
 * \param icList
 * \param tsLens
 */
void initializeIncomes(Income *icList, int tsLens) {
	for (int i = 0; i < tsLens; i++) {
		icList[i].assigned = 0;
	}

}
/**
 * \fn int getIcUnassigned(Income*, int, int*)
 * \brief Obtener una posicion vacia para el array de recaudaciones
 * \param icList
 * \param icLens
 * \param to_assign
 * \return
 */
int getIcUnassigned(Income *icList, int icLens, int *to_assign) {
	int resp = 0;
	for (int i = 0; i < icLens; i++) {
		if (!(icList[i].assigned)) {
			*to_assign = i;
			resp = 1;
			break;
		}
	}
	return resp;
}
/**
 * \fn int validType(IcType*, int, int, int*)
 * \brief Valida el tipo de recaudacion
 * \param list
 * \param lens
 * \param max_attempts
 * \param output
 * \return
 */
int validType(IcType *list, int lens, int max_attempts, int *output) {
	int resp = 0;
	int valid = 0;
	int attempts = 0;
	int isType;
	int aux;
	do {
		indexTypes(list, lens);
		printf("\nCodigo de recaudacion: ");
		__fpurge(stdin);
		isType = scanf("%d", &aux);
		for (int i = 0; i < lens; i++) {
			if (isType && list[i].id == aux) {
				valid = 1;
				resp = 1;
				*output = aux;
				break;
			}
		}
		if (!valid) {
			printf("\nError. Tipo invalida");
		}
		attempts++;
	} while (!valid || attempts >= max_attempts);
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
 * \fn void indexTypes(IcType*, int)
 * \brief Listar tipos de recaudacion
 * \param list
 * \param lens
 */
void indexTypes(IcType *list, int lens) {
	printf("\n************ Recaudaciones disponibles ************");
	printf("\n\n%-15s | %6s", "Codigo_Recaudacion", "Descripcion");
	printf("\n-------------------------------------");
	for (int i = 0; i < lens; i++) {
		showType(list[i]);
	}
}
/**
 * \fn void showType(IcType)
 * \brief Mostrar un tipo de recaudacion
 * \param icType
 */
void showType(IcType icType) {
	printf("\n %6d%10s %-20s", icType.id, "", icType.description);
}
/**
 * \fn int isEmptyIc(Income*, int)
 * \brief Comprueba si el array de recaudaciones esta vacio
 * \param icList
 * \param lens
 * \return
 */
int isEmptyIc(Income *icList, int lens) {
	int resp = 0;
	int aux = 0;
	for (int i = 0; i < lens; i++) {
		if (icList[i].assigned == 0) {
			aux++;
		}
	}
	if (aux == lens) {
		resp = 1;
	}
	return resp;
}
/**
 * \fn void getIcStatus(Income, char*)
 * \brief Obtener el estado de una recaudacion mediante su codigo
 * \param income
 * \param status
 */
void getIcStatus(Income income, char *status) {

	switch (income.status) {
	case PENDIENTE:
		strcpy(status, "Pendiente");
		break;
	case REFINANCIAR:
		strcpy(status, "Refinanciar");
		break;
	case SALDAR:
		strcpy(status, "Saldado");
		break;
	}
}
/**
 * \fn void deleteIncome(Income*, int, int)
 * \brief Dar de baja una recaudacion
 * \param incomes
 * \param icLens
 * \param tpId
 */
void deleteIncome(Income *incomes, int icLens, int tpId) {
	for (int i = 0; i < icLens; i++) {
		if (incomes[i].id_taxPayer == tpId) {
			incomes[i].assigned = 0;
		}
	}
}
/**
 * \fn int validIncome(Income*, int, int, int*)
 * \brief Valida el id de una recaudacion
 * \param incomes
 * \param lens
 * \param to_validate
 * \param output
 * \return
 */
int validIncome(Income *incomes, int lens, int to_validate, int *output) {
	int resp = 0;
	for (int i = 0; i < lens; i++) {
		if (incomes[i].id == to_validate && incomes[i].assigned) {
			*output = i;
			resp = 1;
			break;
		}
	}
	return resp;
}
