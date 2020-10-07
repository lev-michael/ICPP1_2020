#pragma once
#ifndef _RECIEPT_H
#define _RECIEPT_H

class Reciept
{
private: 
	int id;
	double amount;
	double VAT;
public:
	Reciept();
	Reciept(int cisloUctenky, double castka, double dph);
	int GetId() const;
	double GetAmount() const;
	double GetVAT() const;
	void SetId(int cisloUctenky);
	void SetAmount(double castka);
	void SetVAT(double VAT);

};

#endif 

