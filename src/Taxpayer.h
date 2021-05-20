/*
 * Taxpayer.h
 *
 *  Created on: 29 Apr 2021
 *      Author: Nicolas Alejandro Penayo
 *      Description: Struct Taxpayer y funciones relacionadas
 */

#ifndef TAXPAYER_H_
#define TAXPAYER_H_
#define STR_LEN 20

#define MAX_ATTEMPTS 3
typedef struct {
	int id;
	char name[STR_LEN];
	char surname[STR_LEN];
	long int cuil;
	int assigned;
} TaxPayer;
#include "Income.h"

int createTaxpayer(TaxPayer *tpList, int tpLens, int *id, int index);
void indexTaxpayers(TaxPayer *tpList, int tpLens);
void showTaxPayer(TaxPayer taxPayer);
int updateTaxpayer(TaxPayer taxpayer, TaxPayer *tpList, int tpLens);
int deleteTaxpayer(TaxPayer *tpList, int tpLens, Income *icList, int icLens, IcType *typeList, int typeLens);
int getTaxPayerById(TaxPayer *tpList, int tpLens, int to_find, int *output);
void initializeTaxpayers(TaxPayer *taxpayers, int tpLens);
int getTpUnassigned(TaxPayer *tpList, int tpLens, int *to_assign);
int isEmpty(TaxPayer *tpList, int tpLens);
#endif /* TAXPAYER_H_ */
