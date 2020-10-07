#pragma once
#ifndef _CASHREGISTER_H
#define _CASHREGISTER_H
#include "Reciept.h"


class CashRegister
{
private:
	Reciept** reciepts;
	int recieptCounter;
	static int idCounter;

public:
	CashRegister();
	~CashRegister();
	Reciept& CreateReciept(double amount, double VAT);
	Reciept& GetReciept(int id);
	double GetTotalAmount() const;
	double GetTotalAmountWithVAT() const;
};

#endif