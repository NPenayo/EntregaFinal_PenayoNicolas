/*
 * TaxPayer.c
 *
 *  Created on: 29 Apr 2021
 *      Author: Nicolas Alejandro Penayo
 *     Description: Struct TaxPayer y funciones relacionadas
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Arrays.h"
#include "Taxpayer.h"
#include "Menu.h"
#define UPD_OPT 4
#include "Validations.h"
#define MAX_ATTEMPTS 3

/**
 * \fn int createTaxpayer(TaxPayer*, int, int*, int)
 * \brief Alta de un contribuyente
 * \param tpList
 * \param tpLens
 * \param id
 * \param index
 * \return
 */
int createTaxpayer(TaxPayer *tpList, int tpLens, int *id, int index) {
	int resp = 0;
	char name[STR_LEN];
	char surname[STR_LEN];
	long int cuil;
	initializeChar(name, STR_LEN);
	initializeChar(surname, STR_LEN);
	printf("\n%50s", "Alta Contribuyentes");
	if (validString("Nombre",
			"Error.El nombre no puede estar vacio o contener numeros", name, 20,
			MAX_ATTEMPTS)
			&& validString("Apellido",
					"Error.El apellido no puede estar vacio o contener numeros",
					surname, 20, MAX_ATTEMPTS)
			&& validLongInt("CUIL(sin - )",
					"Error.Tipo de dato ingresado invalido", &cuil, 20000000000,
					40000000000,
					MAX_ATTEMPTS)) {
		TaxPayer newTaxPayer;
		newTaxPayer.id = *id;
		*id += 1;
		strcpy(newTaxPayer.name, name);
		strcpy(newTaxPayer.surname, surname);
		newTaxPayer.cuil = cuil;
		newTaxPayer.assigned = 1;
		tpList[index] = newTaxPayer;
		resp = 1;
	}

	return resp;
}
/**
 * \fn void indexTaxpayers(TaxPayer*, int)
 * \brief Muestra todos los contribuyentes
 * \param tpList
 * \param tpLens
 */
void indexTaxpayers(TaxPayer *tpList, int tpLens) {
	printf("\n\n%50s", "Listado de Contribuyentes");
	printf(
			"\n---------------------------------------------------------------------------------");
	printf("\n %c %5s %3c %15s %8c %15s %8c %-15s ", '|', "ID", '|', "Nombre",
			'|', "Apellido", '|', "CUIL");
	printf(
			"\n---------------------------------------------------------------------------------");

	for (int i = 0; i < tpLens; i++) {
		showTaxPayer(tpList[i]);
	}
}
/**
 * \fn void showTaxPayer(TaxPayer)
 * \brief Muestra un contribuyente
 * \param taxPayer
 */
void showTaxPayer(TaxPayer taxPayer) {
	if (taxPayer.assigned) {
		taxPayer.surname[0] = toupper(taxPayer.surname[0]);

		for (int i = 0; i < sizeof(taxPayer.name); i++) {
			taxPayer.name[0] = toupper(taxPayer.name[0]);
			if (taxPayer.name[i] == ' ') {
				taxPayer.name[i + 1] = toupper(taxPayer.name[i + 1]);
			}
		}
		for (int i = 0; i < sizeof(taxPayer.surname); i++) {
			taxPayer.surname[0] = toupper(taxPayer.surname[0]);
			if (taxPayer.surname[i] == ' ') {
				taxPayer.surname[i + 1] = toupper(taxPayer.surname[i + 1]);
			}
		}
		printf("\n %c %6d %2c %-15s %8c %-15s %8c %-15ld ", '|', taxPayer.id,
				'|', taxPayer.name, '|', taxPayer.surname, '|', taxPayer.cuil);
	}

}
/**
 * \fn int updateTaxpayer(TaxPayer, TaxPayer*, int)
 * \brief Actualizar los datos de un contribuyente
 * \param taxPayer
 * \param tpList
 * \param tpLens
 * \return
 */
int updateTaxpayer(TaxPayer taxPayer, TaxPayer *tpList, int tpLens) {
	int resp = 0;
	int auxIndex;
	char auxName[20];
	char auxSurname[20];
	long int auxCUIL;
	char opt;
	Option updMenu[UPD_OPT];
	//Update Menu
	setOption('a', "Nombre", updMenu, 0);
	setOption('b', "Apellido", updMenu, 1);
	setOption('c', "CUIL", updMenu, 2);
	setOption('x', "Salir", updMenu, 3);
	printf("\n%50s", "Editar Contribuyente");
	do {
		printMenu(updMenu, UPD_OPT);
		printf("\nElija una opcion: ");
		__fpurge(stdin);
		scanf("%c", &opt);
		if (getOption(opt, updMenu, UPD_OPT)) {
			switch (opt) {
			case 'a':
				system("clear");
				if (validString("Nuevo nombre",
						"Error.El nombre no puede estar vacio o contener numeros",
						auxName, 20,
						MAX_ATTEMPTS)) {
					if (getTaxPayerById(tpList, tpLens, taxPayer.id,
							&auxIndex)) {
						strcpy(tpList[auxIndex].name, auxName);
						system("clear");
						printf("\n Se nombre el nombre con exito");
						resp = 1;
					}

				}

				break;
			case 'b':
				system("clear");
				if (validString("Nuevo apellido",
						"Error.El apellido no puede estar vacio o contener numeros",
						auxSurname, 20, MAX_ATTEMPTS)) {
					if (getTaxPayerById(tpList, tpLens, taxPayer.id,
							&auxIndex)) {
						strcpy(tpList[auxIndex].surname, auxSurname);
						system("clear");
						printf("\n Se nombre el apellido con exito");
						resp = 1;
					}

				}
				break;
			case 'c':
				system("clear");
				if (validLongInt("CUIL(sin - )",
						"Error.Tipo de dato ingresado invalido", &auxCUIL,
						20000000000, 40000000000,
						MAX_ATTEMPTS)) {
					if (getTaxPayerById(tpList, tpLens, taxPayer.id,
							&auxIndex)) {
						tpList[auxIndex].cuil = auxCUIL;
						system("clear");
						printf("\n Se modifico el CUIL con exito");
						resp = 1;
					}

				}
				break;
			}
			printf("\nDesea modificar otro dato? (s/n): ");
			system("clear");
			scanf("%c", &opt);
		} else {
			printf("\nError.Opcion invalida.");
			opt = ' ';
		}

	} while (!(opt == 'n'));

	return resp;
}
/**
 * \fn int deleteTaxpayer(TaxPayer*, int, Income*, int, IcType*, int)
 * \brief Dar de baja un contribuyente
 * \param tpList
 * \param tpLens
 * \param icList
 * \param icLens
 * \param typeList
 * \param typeLens
 * \return
 */
int deleteTaxpayer(TaxPayer *tpList, int tpLens, Income *icList, int icLens,
		IcType *typeList, int typeLens) {

	int resp = 0;
	char opt;
	int index;
	do {
		indexIncomes(icList, icLens, tpList, tpLens, typeList, typeLens, 3);
		printf("\n\nIngrese ID de contribuyente a eliminar: ");
		__fpurge(stdin);
		scanf("%d", &index);
		if (getTaxPayerById(tpList, tpLens, index, &index)) {
			printf(
					"\n*********************************************************************************");
			printf("\n\n%50s", "Contribuyente");
			printf(
					"\n---------------------------------------------------------------------------------");
			printf("\n\n %c %5s %3c %15s %8c %15s %8c %-15s ", '|', "ID", '|',
					"Nombre", '|', "Apellido", '|', "CUIL");
			printf(
					"\n---------------------------------------------------------------------------------");
			showTaxPayer(tpList[index]);
			printf(
					"\nSeguro que desea eliminar este contribuyente y todas sus recaudaciones?(s/n)");
			__fpurge(stdin);
			scanf("%c", &opt);
			if (opt == 's') {
				deleteIncome(icList, icLens, tpList[index].id);
				tpList[index].assigned = 0;
				resp = 1;
				break;
			} else {
				printf("\n No se eliminó el registro.");
			}
		} else {
			system("clear");
			printf("\nNo se encuentra el ID ingresado.");
			printf("\nSi quiere volver al menu presione (m): ");
			__fpurge(stdin);
			scanf("%c", &opt);
		}
	} while (!(opt == 'm'));
	return resp;
}
/**
 * \fn int getTaxPayerById(TaxPayer*, int, int, int*)
 * \brief Obtener la posicion de un contribuyente dentro del array mendiante el ID
 * \param tpList
 * \param tpLens
 * \param to_find
 * \param output
 * \return
 */
int getTaxPayerById(TaxPayer *tpList, int tpLens, int to_find, int *output) {
	int resp = 0;
	for (int i = 0; i < tpLens; i++) {
		if (tpList[i].id == to_find && tpList[i].assigned) {
			*output = i;
			resp = 1;
			break;
		}
	}
	return resp;
}
/**
 * \fn void initializeTaxpayers(TaxPayer*, int)
 * \brief Inicializar la estructura de contribuyentes
 * \param tpList
 * \param tpLens
 */
void initializeTaxpayers(TaxPayer *tpList, int tpLens) {
	for (int i = 0; i < tpLens; i++) {
		tpList[i].assigned = 0;
	}

}
/**
 * \fn int getTpUnassigned(TaxPayer*, int, int*)
 * \brief Obtener una posicion vacia dentro del array de contribuyentes
 * \param tpList
 * \param tpLens
 * \param to_assign
 * \return
 */
int getTpUnassigned(TaxPayer *tpList, int tpLens, int *to_assign) {
	int resp = 0;
	for (int i = 0; i < tpLens; i++) {
		if (!(tpList[i].assigned)) {
			*to_assign = i;
			resp = 1;
			break;
		}
	}
	return resp;
}
/**
 * \fn int isEmpty(TaxPayer*, int)
 * \brief Comprobar si el array de contribuyentes esta vacio
 * \param tpList
 * \param tpLens
 * \return
 */
int isEmpty(TaxPayer *tpList, int tpLens) {
	int resp = 0;
	int aux = 0;
	for (int i = 0; i < tpLens; i++) {
		if (!tpList[i].assigned) {
			aux++;
		}
	}
	if (aux == tpLens) {
		resp = 1;
	}
	return resp;
}

