/*
 * Reports.c
 *
 *  Created on: 19 May 2021
 *      Author: npenayo
 */
#include <stdio.h>
#include <string.h>
#include "Income.h"
#include "Taxpayer.h"
#define PENDIENTE 0
#define REFINANCIAR 1
#define SALDAR 2

int incomeAmount(TaxPayer *tpList, int tpLens, Income *icList, int icLens,
		IcType *typeList, int typeLens) {
	int icAmount = 0;
	for (int i = 0; i < icLens; i++) {
		if (icList[i].assigned && icList[i].status == SALDAR
				&& icList[i].amount > 1000) {
			icAmount++;
		}

	}
	return icAmount;
}

int incomeStatus(TaxPayer *tpList, int tpLens, Income *icList, int icLens,
		IcType *typeList, int typeLens, int arg, int status) {
	int tpIndex;
	int max = 0;
	int icAmount;
	int flag = 1;
	for (int i = 0; i < tpLens; i++) {
		icAmount = 0;
		for (int j = 0; j < icLens; j++) {
			if ((icList[j].id_taxPayer == tpList[i].id
					&& icList[j].status == REFINANCIAR && tpList[i].assigned)
					|| flag) {
				icAmount++;
			}
		}
		if (max < icAmount) {
			max = icAmount;
			tpIndex = i;
		}
	}
	if (!max) {
		printf(
				"\n---------------------------------------------------------------------------------");
		printf("\n %c %5s %3c %15s %8c %15s %8c %-15s ", '|', "ID", '|',
				"Nombre", '|', "Apellido", '|', "CUIL");
		printf(
				"\n---------------------------------------------------------------------------------");
		showTaxPayer(tpList[tpIndex]);
		printf("\nCantidad de recaudaciones: %d", icAmount);
	}
	return max;
}
int sortTaxpayersBy(TaxPayer *tpList, int tpLens, Income *icList, int icLens) {
	int resp = 0;
	for (int i = 0; i < tpLens; i++) {
		for (int j = 0; j < icLens; j++) {
			if (tpList[i].id == icList[j].id_taxPayer && tpList[i].assigned
					&& icList[j].month == 2) {
				printf(
						"\n---------------------------------------------------------------------------------");
				printf("\nNombre| CUIL");
				printf(
						"\n---------------------------------------------------------------------------------");
				printf("\n %s | %ld",tpList[i].name,tpList[i].cuil);
				resp++;
			}
		}
	}
	return resp;
}
int sortIncomesBy(TaxPayer *tpList, int tpLens, Income *icList, int icLens,
		IcType *typeList, int typeLens, int arg) {
	int resp;
	int auxType;
	int aux = 0;
	int flag;
	char income_type[20];
	if (validType(typeList, typeLens, 3, &auxType)) {

		for (int i = 0; i < icLens; i++) {
			if (icList[i].assigned && icList[i].id_type == auxType) {
				flag = 0;
				for (int j = 0; j < tpLens; j++) {
					if (flag != tpList[j].id) {
						printf(
								"\n-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
						printf("\n\n%50s", "Contribuyente");
						printf(
								"\n---------------------------------------------------------------------------------");
						printf("\n %c %5s %3c %15s %8c %15s %8c %-15s ", '|',
								"ID", '|', "Nombre", '|', "Apellido", '|',
								"CUIL");
						printf(
								"\n---------------------------------------------------------------------------------");
						showTaxPayer(tpList[j]);
						printf(
								"\n---------------------------------------------------------------------------------");
						flag = tpList[j].id;
						aux++;
					}
				}
			}

		}
		if (!aux) {
			for (int i = 0; i < icLens; i++) {
				if (auxType == typeList[i].id) {
					strcpy(income_type, typeList[i].description);
					break;
				}
			}
			printf("\nNo hay recaudaciones del tipo %s", income_type);
		}
	} else {
		resp = 0;
	}
	return resp;
}
