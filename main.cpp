#include<bits/stdc++.h>
#include "sqlite3.h"
#include "CalculatorClass/Calculator.h" // including calculator class 
using namespace std;


bool check_num(string num, int&count)  // checking input number is valid or not //
{
    
    if (num.size()>18)   // if input number is length> 18 data type cannot handle such large number  
    {
        return false;
    }
    
    for(int i=0 ;i<num.size() ;i++)  
    {
        if (num[0]=='-')
        {
            continue;
        }
        if (int(num[i])==46)
        {
            count++;
            if (count>1){
                return false;
            }
        }
        else if (int(num[i])<48 || int(num[i])>57)
        {
            return false;
        }
        
    }
    return true;
}



void take_input(string& num1,string& num2)
{
    int count1=0;      // count number of decimal points for number1
    int count2=0;      // count number of decimal points for number2
    cout<<"enter 1st number :"<<endl;
    cin>>num1;
    while(!check_num(num1,count1))      //check for valid number
    {
        cin.clear();                    //
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"You have entered wrong input number 1"<<endl;
        cin>>num1;
    }
    cout<<"enter 2nd number :"<<endl;
    cin>>num2;
    while(!check_num(num2,count2))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"You have entered wrong input number 2"<<endl;
        cin>>num2;
    }
}



int main()
{
    // const char* DirectoryLocation=R"(D:\Go_Basic\projects\go\src\C++ Project\sqliteWithC++\CalculatorDatabase\calculator.db)";
    
    // two sring variable to hold number in form of string 
    string num1,num2;
    
    // take input from user 
    take_input(num1,num2);
    double _num1 = std::stod(num1);
    double _num2 = std::stod(num2);

    Calculator<double>c(_num1,_num2);      
    c.Run();                               // to run calculator //

    cout<<"show all operation "<<endl;
    c.showAllOperationHistory();           // show all operation done on calculator //

    return 0;
}