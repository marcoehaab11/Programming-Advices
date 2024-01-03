#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "Global.h"
#include <vector>
#include <fstream>

using namespace std;

class clsBankClient:public clsPerson
{
private:

  enum enMode
  { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
  enMode _Mode;
  string _AccountNumber;
  string _PinCode;
  float _AccountBalance;
  bool _MarkeForDelete=false;

  static clsBankClient _ConvertLinetoClientObject (string Line,
						   string Seperator = "#//#")
  {
    vector < string > vClientData;
    vClientData = clsString::Split (Line, Seperator);

    return clsBankClient (enMode::UpdateMode, vClientData[0], vClientData[1],
			  vClientData[2], vClientData[3], vClientData[4],
			  vClientData[5], stod (vClientData[6]));

  }
  static string _ConverClientObjectToLine (clsBankClient Client,
					   string Seperator = "#//#")
  {

    string stClientRecord = "";
    stClientRecord += Client.GetFirstName () + Seperator;
    stClientRecord += Client.GetLastName () + Seperator;
    stClientRecord += Client.GetEmail () + Seperator;
    stClientRecord += Client.GetPhone () + Seperator;
    stClientRecord += Client.AccountNumber () + Seperator;
    stClientRecord += Client.GetPinCode () + Seperator;
    stClientRecord += to_string (Client.GetAccountBalance ());

    return stClientRecord;

  }
  static vector < clsBankClient > _LoadClientsDataFromFile ()
  {
    vector < clsBankClient > vClient;
    fstream MyFile;
    MyFile.open ("Clients.txt", ios::in);	//readmode
    if (MyFile.is_open ())
      {
	string line;

	while (getline (MyFile, line))
	  {
	    clsBankClient Client = _ConvertLinetoClientObject (line);
	    vClient.push_back (Client);
	  }
	MyFile.close ();

      }
    return vClient;
  }
  static clsBankClient _GetEmptyClientObject ()
  {
    return clsBankClient (enMode::EmptyMode, "", "", "", "", "", "", 0);
  }
  void _AddNew ()
  {
    _AddDataLineToFile (_ConverClientObjectToLine (*this));
  }
  void _AddDataLineToFile (string stDataLine)
  {
    fstream MyFile;
    MyFile.open ("Clients.txt", ios::out | ios::app);
    if (MyFile.is_open ())
      {
	MyFile << stDataLine << endl;
	MyFile.close ();
      }
  }



  static void _SaveClientDataToFile (vector < clsBankClient > vClient)
  {
    fstream MyFile;
    MyFile.open ("Clients.txt", ios::out);	//overwrite

    string dataline;
    if (MyFile.is_open ())
      {
      for (clsBankClient & c:vClient)
	  {    if (c.MarkedForDeleted() == false)
                {
                   dataline = _ConverClientObjectToLine (c);
	                  MyFile << dataline << endl;

                }
	    
	  }
    }
    MyFile.close ();

  }
  void _Update ()
  {
    vector < clsBankClient > _vClients;
    _vClients = _LoadClientsDataFromFile ();

  for (clsBankClient & c:_vClients)
      {
	if (c.AccountNumber () == AccountNumber ())
	  {
	    c = *this;
	    break;
	  }
      }
    _SaveClientDataToFile (_vClients);
  }
  
  string _TransferFiletoLine(string From ,string To ,string User,float Amount,float FromAccountB,float toAccountB)
  {   
        
      string line="",dim="#//#";
      line+=clsInputValidate::GetSystemDateTimeString()+dim;
      line+=From+dim;
      line+=To+dim;
      line+=to_string(Amount)+dim;
      line+=to_string(FromAccountB)+dim;
      line+=to_string(toAccountB)+dim;
      line+=User;
      
      return line;  }
  
  void _SaveTransferData(string line)
  {
      fstream MyFile;
      MyFile.open("Transferlog.txt",ios::out | ios::app);
      if(MyFile.is_open())
      {
        	MyFile << line << endl;
        	MyFile.close ();
      }
      
  }
public:
clsBankClient (enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance):clsPerson (FirstName, LastName, Email,
	     Phone)
  {
    _Mode = Mode;
    _AccountNumber = AccountNumber;
    _PinCode = PinCode;
    _AccountBalance = AccountBalance;

  }
  void Deposit(double Amount)
  {
      _AccountBalance+=Amount;
      Save();
  }
  bool Transfer(float Amount,clsBankClient& Client)
  {
      if(Amount>GetAccountBalance())
      {return false;}
      
      Withdraw(Amount);
      Client.Deposit(Amount);
     string line= _TransferFiletoLine(_AccountNumber,Client.AccountNumber(),CurrentUser.GetUserName(),Amount,GetAccountBalance(),Client.GetAccountBalance());
      _SaveTransferData(line);
      return true;
      
  }
  bool Withdraw(double Amount)
  {     if(_AccountBalance<Amount)
        {
            return false;
            
        }
        else
        {
        _AccountBalance-=Amount;
        Save();
        }
  }
  
  static int CheckAmountInData(string AN)
  {
          vector<clsBankClient> vClient=_LoadClientsDataFromFile();
          
          for(clsBankClient c :vClient)
          {
            if(AN==c.AccountNumber())   
            {
                return c.GetAccountBalance();
            }
          }
    }
    
     static clsBankClient ChatchUser(string AN)
  {
          vector<clsBankClient> vClient=_LoadClientsDataFromFile();
          
          for(clsBankClient c :vClient)
          {
            if(AN==c.AccountNumber())   
            {
                return c;
            }
          }
    }
    static bool  TransferMoney(string AccFromm, string  AccToo, int Amount)
     {
            clsBankClient AccFrom= ChatchUser(AccFromm);
            clsBankClient AccTo= ChatchUser(AccToo);
            
            AccFrom.SetAccountBalance( (AccFrom.GetAccountBalance()-Amount) );
            
            AccTo.SetAccountBalance( (AccTo.GetAccountBalance()+Amount));
            AccFrom._Mode=UpdateMode;
            AccTo._Mode=UpdateMode;
            AccTo.Save();
            AccFrom.Save();
            return true;
            
     } 
  
static vector<clsBankClient> GetClientsList()
    {return _LoadClientsDataFromFile();}
    bool MarkedForDeleted()
    {return _MarkeForDelete;}
    bool Delete()
    {
    vector<clsBankClient> _vClients;
    _vClients=_LoadClientsDataFromFile();
    
    for(clsBankClient& c:_vClients)
    {
        if(c.AccountNumber()==AccountNumber())
        {
            c._MarkeForDelete=true;
            break;
        }
    }
    _SaveClientDataToFile(_vClients);
    *this=_GetEmptyClientObject();
    return true;
}
static float TotalAccBalance()
{
    vector<clsBankClient> vClient=_LoadClientsDataFromFile();
    float t;
    for(clsBankClient c:vClient)
    {
        t+=c.GetAccountBalance();
    }
    return t;
}
static clsBankClient GetAddNewClientObject (string AccountNumberr)
  {
    return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumberr,
			  "", 0);
  }


    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


  string AccountNumber ()
  {
    return _AccountNumber;
  }

  void SetPinCode (string PinCode)
  {
    _PinCode = PinCode;
  }
  string GetPinCode ()
  {
    return _PinCode;
  }
  enum enSaveResults
  { svFaildEmptyObject = 0, svSucceeded = 1,svFaildAccountNumberExists=2 };

  enSaveResults Save ()
  {

    switch (_Mode)
    {
      case enMode::EmptyMode:
    	{
    
    	  return enSaveResults::svFaildEmptyObject;
    	}

          case enMode::UpdateMode:
    	{
    
    
    	  _Update ();
    
    	  return enSaveResults::svSucceeded;
    
    	  break;
    	}
      case enMode::AddNewMode:
    	{
    
    	  if (clsBankClient::IsClientExist (_AccountNumber))
    	    {
    	      return enSaveResults::svFaildAccountNumberExists;
    	    }
    	  else
    	    {
    	      _AddNew ();
    	      _Mode = enMode::UpdateMode;
    	      return enSaveResults::svSucceeded;
    	    }
    
    	  break;
    	}



      }


  }

  void SetAccountBalance (float AccountBalance)
  {
    _AccountBalance = AccountBalance;
  }

  float GetAccountBalance ()
  {
    return _AccountBalance;
  }
    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }
void Print ()
  {
    cout << "\nClient Card:";
    cout << "\n___________________";
    cout << "\nFirstName   : " << GetFirstName ();
    cout << "\nLastName    : " << GetLastName ();
    cout << "\nFull Name   : " << FullName ();
    cout << "\nEmail       : " << GetEmail ();
    cout << "\nPhone       : " << GetPhone ();
    cout << "\nAcc. Number : " << AccountNumber ();
    cout << "\nPinCode     : " << GetPinCode ();
    cout << "\nBalance     : " << GetAccountBalance ();
    cout << "\n___________________\n";

  }

  static clsBankClient Find (string AN)
  {
    fstream MyFile;
    MyFile.open ("Clients.txt", ios::in);

    if (MyFile.is_open ())
      {
	string line;
	while (getline (MyFile, line))
	  {
	    clsBankClient Client = _ConvertLinetoClientObject (line);
	    if (Client.AccountNumber () == AN)
	      {
		MyFile.close ();
		return Client;
	      }

	  }
      }
 return _GetEmptyClientObject();

  }


};
