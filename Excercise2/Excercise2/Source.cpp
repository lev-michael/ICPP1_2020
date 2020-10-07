#include "CashRegister.h"
#include "Reciept.h"
#include <iostream>


int main(int argc, char** argv) {
	CashRegister* cashRegister = new CashRegister();
	cashRegister->CreateReciept(1000, 0.21);
	cashRegister->CreateReciept(2000, 0.15);
	cashRegister->CreateReciept(500, 0.21);
	cashRegister->CreateReciept(150, 0.1);

	std::cout << "Total amount without VAT: " << cashRegister->GetTotalAmount() << std::endl;
	std::cout << "Total amount with VAT: " << cashRegister->GetTotalAmountWithVAT() << std::endl;

	Reciept& reciept1 = cashRegister->GetReciept(1001);
	std::cout << "Reciept id: " << reciept1.GetId() << ", amount:" << reciept1.GetAmount() << ", VAT: " << reciept1.GetVAT() << std::endl;
	reciept1.SetAmount(999);
	reciept1.SetVAT(0.18);

	std::cout << std::endl << "After update" << std::endl;
	std::cout << "Reciept id: " << reciept1.GetId() << ", amount:" << reciept1.GetAmount() << ", VAT: " << reciept1.GetVAT() << std::endl;
	std::cout << "Total amount without VAT: " << cashRegister->GetTotalAmount() << std::endl;
	std::cout << "Total amount with VAT: " << cashRegister->GetTotalAmountWithVAT() << std::endl;
}