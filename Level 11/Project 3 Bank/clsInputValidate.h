#pragma once
#include <iostream>
#include <string>
#include "clsString.h"


class clsInputValidate
{

public:

	static short IsNumberBetween(short From, short To,string msg)
	{
		short Number=0;
		cin>>Number;
		while(Number >To || Number <From)
		{
		    cout<<msg;
		    cin>>Number;
		}
		return Number;
		
	}
	static string GetSystemDateTimeString()
	{
	    time_t t=time(0);
	    tm* now =localtime(&t);
	    
	    short Day,Month,Year,Hour,Min,Sec;
	    
	    Year=now->tm_year+1900;
	    Month=now->tm_mon+1;
	    Day=now->tm_mday;
	    Hour = now->tm_hour;
		Min = now->tm_min;
		Sec = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Min)
			+ ":" + to_string(Sec));

	    
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;

	}

	

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}


	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number;
		while (0>Number) {
		    cin >> Number;
			cout << ErrorMessage;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{  
		float Number;
		 cin >> Number;
	while (0>Number) {
		    cin >> Number;
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadFloatNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		float Number = ReadFloatNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
        while (0>Number) {
		    cin >> Number;
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}



	static string ReadString()
	{
		string  S1="";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
};

