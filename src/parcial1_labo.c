/*
 ============================================================================
 Name        : parcial1_labo.c
 Author      : Nicolas Alejandro Penayo 1 E
 Description : Parcial 1 Laboratorio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Arrays.h"
#include "Menu.h"
#include "Validations.h"
#include "Taxpayer.h"
#include "Income.h"
#define MAIN_OPT 9
#define UPD_OPT 4
#define MAX_ATTEMPTS 3
#define TP_AMOUNT 10
#define IC_AMOUNT 10
void clearConsole();
void cleanBuffer();
int main(void) {
	//Set variables
	int tpId = 1000;
	int icId = 100;
	char opt;
	Option mainMenu[MAIN_OPT];
	int auxIndex;
	int auxId;
	char valid_values[2] = { 's', 'n' };
	TaxPayer tpList[TP_AMOUNT];
	Income icList[IC_AMOUNT];
	IcType types[4] = { { 1, "ARBA", 0 }, { 2, "IIBB", 0 },
			{ 3, "GANANCIAS", 0 } };
	initializeTaxpayers(tpList, TP_AMOUNT);
	initializeIncomes(icList, IC_AMOUNT);

	//Main Menu
	setOption('1', "Alta de contribuyente", mainMenu, 0);
	setOption('2', "Modificar datos contribuyente", mainMenu, 1);
	setOption('3', "Baja de contribuyente", mainMenu, 2);
	setOption('4', "Recaudacion", mainMenu, 3);
	setOption('5', "Refinanciar Recaudacion", mainMenu, 4);
	setOption('6', "Saldar Recaudacion", mainMenu, 5);
	setOption('7', "Imprimir Contribuyentes", mainMenu, 6);
	setOption('8', "Imprimir Recaudacion", mainMenu, 7);
	setOption('x', "Salir", mainMenu, 8);

	do {
		clearConsole();
		printf("\n%50s", "Menu Principal");
		printMenu(mainMenu, MAIN_OPT);
		printf("\nElija una opcion: ");
		cleanBuffer();
		scanf("%c", &opt);
		if (getOption(opt, mainMenu, MAIN_OPT)) {
			clearConsole();
			switch (opt) {
			case '1':

				do {
					if (getTpUnassigned(tpList, TP_AMOUNT, &auxIndex)) {
						if (createTaxpayer(tpList, TP_AMOUNT, &tpId,
								auxIndex)) {
							printf(
									"\n---------------------------------------------------------------------------------");
							printf("\n %c %5s %3c %15s %8c %15s %8c %-15s ",
									'|', "ID", '|', "Nombre", '|', "Apellido",
									'|', "CUIL");
							printf(
									"\n---------------------------------------------------------------------------------");
							showTaxPayer(tpList[auxIndex]);
							cleanBuffer();
							validChar(
									"\nCarga exitosa. Desea cargar otro contribuyente?(s/n) ",
									"Error.Opcion invalida", &opt, valid_values,
									2, 3);
						} else {
							printf(
									"Error. Algo salio mal en la carga de datos, intente nuevamente.");
							printf(
									"\n\nPresione una tecla para volver al menu");
							cleanBuffer();
							getchar();
						}
					} else {
						clearConsole();
						printf(
								"\nError.La base de contribuyentes esta llena. Debe borrar un registro.");
						printf("\n\nPresione una tecla para volver al menu");
						cleanBuffer();
						getchar();
						break;
					}
				} while (!(opt == 'n'));

				break;
			case '2':
				if (!(isEmpty(tpList, TP_AMOUNT))) {
					do {
						indexTaxpayers(tpList, TP_AMOUNT);
						printf("\nID del empleado: ");
						scanf("%d", &auxId);
						if (getTaxPayerById(tpList, TP_AMOUNT, auxId,
								&auxIndex)) {
							clearConsole();
							if (updateTaxpayer(tpList[auxIndex], tpList,
							TP_AMOUNT)) {
								break;
							}
						} else {
							printf("\nError.ID no encontrado");
							printf("\nPresione (m) si quiere volver al menu");
							cleanBuffer();
							scanf("%c", &opt);
						}
					} while (!(opt == 'm'));

				} else {
					clearConsole();
					printf("\nNo hay contribuyentes cargados para mostrar.");
				}
				break;
			case '3':
				if (!(isEmpty(tpList, TP_AMOUNT))) {
					clearConsole();
					if (deleteTaxpayer(tpList, TP_AMOUNT, icList, IC_AMOUNT,
							types, 3)) {
						printf("\nSe eliminó el contribuyente con exito");
					}
				} else {
					clearConsole();
					printf("\nNo hay contribuyentes cargados para mostrar.");
				}
				break;
			case '4':
				if (!(isEmpty(tpList, TP_AMOUNT))) {
					if (getIcUnassigned(icList, IC_AMOUNT, &auxId)) {
						do {
							getIcUnassigned(icList, IC_AMOUNT, &auxId);
							if (createIncome(icList, IC_AMOUNT, &icId, auxId,
									types, 3, tpList, TP_AMOUNT)) {
								printf(
										"\n\nCarga exitosa. Desea cargar otra recaudacion?(s/n) ");
								cleanBuffer();
								scanf("%c", &opt);
							}else{
								break;
							}

						} while (!(opt == 'n'));
					} else {
						printf(
								"\nError.Base llena!!.No se pueden cargar mas recaudaciones.");
						printf("\n\nPresione una tecla para volver al menu");
						cleanBuffer();
						getchar();
					}

				} else {
					clearConsole();
					printf(
							"\nNo hay contribuyentes cargados para asignarles una recaudacion.");
				}
				break;
			case '5':
				if (!(isEmpty(tpList, TP_AMOUNT))) {
					clearConsole();
					if (updateIncome(icList, IC_AMOUNT, tpList, TP_AMOUNT,
							types, 3, 0)) {
						printf("\nRefinanciacion exitosa.");
						printf("\n\nPresione una tecla para volver al menu");
						cleanBuffer();
						getchar();
					}
				} else {
					clearConsole();
					printf("\nNo hay contribuyentes cargados para mostrar.");
				}
				break;
			case '6':
				if (!(isEmpty(tpList, TP_AMOUNT))) {
					clearConsole();
					if (updateIncome(icList, IC_AMOUNT, tpList, TP_AMOUNT,
							types, 3, 2)) {
						printf("\nSe saldo la recaudacion exitosamente.");
						printf("\n\nPresione una tecla para volver al menu");
						__fpurge(stdin);
						getchar();
					}
				} else {
					clearConsole();
					printf("\nNo hay contribuyentes cargados para mostrar.");
				}
				break;
			case '7':
				if (!(isEmpty(tpList, TP_AMOUNT))) {
					indexIncomes(icList, IC_AMOUNT, tpList, TP_AMOUNT, types, 3,
							3);
					printf("\n\nPresione una tecla para volver al menu");
					cleanBuffer();
					getchar();
				} else {
					clearConsole();
					printf("\nNo hay contribuyentes cargados para mostrar.");
				}
				break;
			case '8':
				if (!(isEmptyIc(icList, IC_AMOUNT))) {
					indexIncomes(icList, IC_AMOUNT, tpList, TP_AMOUNT, types, 3,
							2);
					printf("\n\nPresione una tecla para volver al menu");
					cleanBuffer();
					getchar();
				} else {
					clearConsole();
					printf("\nNo hay recaudaciones cargadas para mostrar.");
					printf("\n\nPresione una tecla para volver al menu");
					cleanBuffer();
					getchar();
				}
				break;
			default:
				break;
			}
		} else {
			clearConsole();
			printf("\nError.Opcion invalida");
			printf("\n\nPresione una tecla para volver al menu");
			cleanBuffer();
			getchar();
		}
	} while (!(opt == 'x'));

	return EXIT_SUCCESS;
}
void clearConsole() {
#if defined( __linux__)
	system("clear");
#elif defined( __MINGW32__)
	sytem("cls");
#endif
}
void cleanBuffer() {
#if defined(__linux__)
	__fpurge(stdin);
#elif defined(__MINGW32__)
	fflush(stdin);
#endif
}

