/*
 * Reports.h
 *
 *  Created on: 18 May 2021
 *      Author: npenayo
 */

#ifndef REPORTS_H_
#define REPORTS_H_
#include "Taxpayer.h"
#include "Income.h"

void incomeAmount(TaxPayer *tpList, int tpLens, Income *icList, int icLens, IcType *typeList,int typeLens,int arg);
void incomeType(Income *icList, int icLens,IcType *typeList, int typeLens,int arg,int status);
void sortTaxpayersBy(TaxPayer *tpList, int tpLens, Income *icList, int icLens, IcType *typeList,int typeLens,int arg);
void sortIncomesBy(TaxPayer *tpList, int tpLens, Income *icList, int icLens, IcType *typeList,int typeLens,int arg);
void swapIncomes(Income *icList, Income ic, Income icB);
void swapTaxpayer(TaxPayer *tpList, TaxPayer tpA, TaxPayer tpB);

#endif /* REPORTS_H_ */
