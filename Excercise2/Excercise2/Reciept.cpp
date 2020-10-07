#include "Reciept.h"

Reciept::Reciept()
	:id(0), amount(0), VAT(0) {};

Reciept::Reciept(int cisloUctenky, double castka, double dph)
	:id(cisloUctenky), amount(castka), VAT(dph) {};

int Reciept::GetId() const
{
	return this->id;
}

double Reciept::GetAmount() const
{
	return this->amount;
}

double Reciept::GetVAT() const
{
	return this->VAT;
}

void Reciept::SetId(int id)
{
	this->id = id;
}

void Reciept::SetAmount(double amount)
{
	this->amount = amount;
}

void Reciept::SetVAT(double VAT)
{
	this->VAT = VAT;
}
