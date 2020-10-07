#include "CashRegister.h"
#include "Reciept.h"
#include <exception>

int CashRegister::idCounter = 1000;

CashRegister::CashRegister()
{
	reciepts = new Reciept*[10];
	for (size_t i = 0; i < 10; i++)
	{
		reciepts[i] = new Reciept();
	}
	recieptCounter = 0;
}

CashRegister::~CashRegister() {
	for (size_t i = 0; i < 10; i++)
	{
		delete reciepts[i];
	}
	delete[] reciepts;
}

Reciept& CashRegister::CreateReciept(double amount, double VAT)
{
	if (recieptCounter == 10)
		throw new std::exception("Cash register is full");

	reciepts[recieptCounter]->SetAmount(amount);
	reciepts[recieptCounter]->SetVAT(VAT);
	reciepts[recieptCounter]->SetId(idCounter++);

	return *reciepts[recieptCounter++];
}

	
Reciept& CashRegister::GetReciept(int id)
{
	if (recieptCounter == 0)
		throw new std::exception("Cash register is empty");

	for (size_t i = 0; i < recieptCounter; i++)
	{
		if (reciepts[i]->GetId() == id) {
			return *reciepts[i];
		}
	}
	return *reciepts[0];
}

double CashRegister::GetTotalAmount() const
{
	double sum = 0;
	if (recieptCounter == 0) {
		return 0;
	}
	for (int i = 0; i < recieptCounter; i++)
	{
		sum += reciepts[i]->GetAmount();
	}
	return sum;
}

double CashRegister::GetTotalAmountWithVAT() const
{
	double sum = 0;
	double VAT = 0;
	if (recieptCounter == 0) {
		return 0;
	}
	for (int i = 0; i < recieptCounter; i++)
	{
		sum += reciepts[i]->GetAmount()*(1 + reciepts[i]->GetVAT());
	}
	return sum;
}
