/*
 * Reports.h
 *
 *  Created on: 19 May 2021
 *      Author: npenayo
 */

#ifndef REPORTS_H_
#define REPORTS_H_
#include "Taxpayer.h"
#include "Income.h"


int incomeAmount(TaxPayer *tpList, int tpLens, Income *icList, int icLens, IcType *typeList,int typeLens);
int incomeStatus(TaxPayer *tpList, int tpLens, Income *icList, int icLens,IcType *typeList, int typeLens,int arg,int status);
int sortTaxpayersBy(TaxPayer *tpList, int tpLens, Income *icList, int icLens);
int sortIncomesBy(TaxPayer *tpList, int tpLens, Income *icList, int icLens, IcType *typeList,int typeLens,int arg);
void swapIncomes(Income *icList, Income ic, Income icB);
void swapTaxpayer(TaxPayer *tpList, TaxPayer tpA, TaxPayer tpB);

#endif /* REPORTS_H_ */
