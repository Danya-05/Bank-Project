#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include <iomanip>

class clsFindCurrencyScreen :protected clsScreen {
private:
	enum enFindCurrencyOptions {
		eFindByCode = 1, eFindByCountry = 2
	};

	static short _ReadFindCurrencyOptions() {
		cout << "Find By: [1] Code or [2] Country ? ";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 2, "Enter Number between 1 to 2? ");
		return Choice;
	}

	static void _PrintCurrency(clsCurrency Currency) {
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";
	}

	static void _ShowResults(clsCurrency Currency){
		if (!Currency.IsEmpty()){
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
			cout << "\nCurrency Was not Found :-(\n";
	}

public:
	static void ShowFindCurrencyScreen() {
		_DrawScreenHeader("     Find Currency Screen");
		
		short option = _ReadFindCurrencyOptions();

		switch (enFindCurrencyOptions(option)) {
		
		case enFindCurrencyOptions::eFindByCode: {
			string code = clsInputValidate::ReadString("\nPlease Enter CurrencyCode : ");
			clsCurrency currency = clsCurrency::FindByCode(code);

			_ShowResults(currency);
			break;
		}

		case enFindCurrencyOptions::eFindByCountry: {
			string name = clsInputValidate::ReadString("\nPlease Enter Country Name : ");
			clsCurrency currency = clsCurrency::FindByCountry(name);

			_ShowResults(currency);			
			break;
		}
		}

	}

};
