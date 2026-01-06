#pragma once
#include <iostream>
#include <string>
#include"clsDate.h"

class clsInputValidate {
public:

	template <typename T>
	static bool IsNumberBetween(T number, T from, T to) {
		return number >= from && number <= to;
	}

	template <typename T>
	static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
		T Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	template <typename T>
	static T ReadNumberBetween(T from, T to, string ErrorMessage = "Out of range, enter again\n") {
		T num = ReadNumber<T>();
		while (!IsNumberBetween<T>(num, from, to)) {
			cout << ErrorMessage;
			num = ReadNumber<T>();
		}
		return num;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To) {
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
			return true;

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
			return true;

		return false;
	}

	static bool IsValideDate(clsDate date) {
		return clsDate::IsValidDate(date);
	}

	static string ReadString(string message = "") {
		string  S1 = "";
		cout << message;
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}

};