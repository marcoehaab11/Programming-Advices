#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsScreen.h"


using namespace std;

class TransferLoginScreenwithUsers :protected clsScreen
{
  private:
  struct stdataline
  {
      string Date;
      string FromA;
      string ToA;
      string Amount;
      string FromB;
      string ToD;
      string UserName;
  };
  
static stdataline  ConvertFromLineToObject(string line)
{
        vector<string> vClientData;
        vClientData = clsString::Split(line, "#//#");
        
        stdataline OneTransfer;
        
        OneTransfer.Date=vClientData[0];
        OneTransfer.FromA=vClientData[1];
        OneTransfer.ToA=vClientData[2];
        OneTransfer.Amount=vClientData[3];
        OneTransfer.FromB=vClientData[4];
        OneTransfer.ToA=vClientData[5];
        OneTransfer.UserName=vClientData[6];

    return OneTransfer;
}

static vector<stdataline>  _LoadDataFromFile()
  {     vector<stdataline> dataline;
        string line;
        stdataline stData;
      fstream MyFile;
      MyFile.open("Transferlog.txt",ios::in);
     if(MyFile.is_open())
     {
        while(getline(MyFile,line))
         {      
             stData=ConvertFromLineToObject(line);
             dataline.push_back(stData);
             
         }
         
         MyFile.close();
         
     }
     
     return dataline;
  }  
    static void PrintClientRecordLine()
    {
        
        cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________________________________________\n";
        cout << setw(8) << left << "  " ;
        cout << "| " << left << setw(35) << "Data";
        cout << "| " << left << setw(10) << "From";
        cout << "| " << left << setw(10) << "To";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(12) << "From Balance";
        cout << "| " << left << setw(12) << "To Balance";
        cout << "| " << left << setw(12) << "UserName";
        cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________________________________________";
   

    }

 static void Print(vector<stdataline> Data)
  {
       for(stdataline &Transfer :Data)
       {
           
        cout << setw(8) << left << " " << endl;
        cout << setw(8) << left << "  " ;
            cout << "| " << left << setw(35) << Transfer.Date;
            cout << "| " << setw(10) << left << Transfer.FromA;
            cout << "| " << setw(10) << left << Transfer.ToA;
            cout << "| " << setw(10) << left << Transfer.Amount;
            cout << "| " << setw(12) << left << Transfer.FromB;
            cout << "| " << setw(12) << left << Transfer.ToD;
            cout << "| " << setw(12) << left << Transfer.UserName<<endl;
       }
    cout << setw(8) << left << "" << "___________________________________________________________________________________________________________________\n";

   
  }
        
  
  public:
  
static  void ShowTransferLogsScreen()
  { 
    
    vector<stdataline> Data = _LoadDataFromFile();
    

        string Title = "\t  Transfer List Screen";
        string SubTitle = "\t    (" + to_string(Data.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

    PrintClientRecordLine();
    Print(Data);
      
      
      
  }
    
};