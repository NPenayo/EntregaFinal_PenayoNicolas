/*
 * income.h
 *
 *  Created on: 8 May 2021
 *      Author: npenayo
 */

#ifndef INCOME_H_
#define INCOME_H_
#define STR_LEN 20
typedef struct {
	int id;
	char description[STR_LEN];
	int assigned;
} IcType;

typedef struct {
	int id;
	int id_taxPayer;
	int month;
	int id_type;
	float amount;
	int status;
	int assigned;
} Income;
#include "Taxpayer.h"

int createIncome(Income *icList, int icLens, int *id, int index, IcType *tyList,
		int tyLens, TaxPayer *tpList, int tpLens);
void indexIncomes(Income *incomes, int lens, TaxPayer *tpList, int tpLen,
		IcType *list, int icLens, int arg);
void showIncome(Income income, IcType *list, int lens);

int updateIncome(Income *list, int icLens, TaxPayer *tpList, int tpLens,
		IcType *typeList, int typeLens, int action);

int validIncome(Income *incomes, int lens, int to_validate, int *output);

void deleteIncome(Income *incomes, int icLens, int tpId);

void initializeIncomes(Income *icList, int icLens);

int getIcUnassigned(Income *icList, int icLens, int *to_assign);
int validType(IcType *list, int lens, int max_attempts, int *output);
void indexTypes(IcType *list, int lens);
void showType(IcType icType);
int isEmptyIc(Income *icList, int lens);
void getIcStatus(Income income, char *status);
#endif /* INCOME_H_ */
