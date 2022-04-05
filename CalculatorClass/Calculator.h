#ifndef _BITSTDC_
#define _BITSTDC_
#include<bits/stdc++.h>
#endif

#include "../CalculatorDbModel/CalculatorModel.h"

#ifndef CALCULATOR_H
#define CALCULATOR_H // TODO: header guards must be at the very top

class DividByZeroException : public std::exception{  
    public:  
        const char * what() const throw()  
        {  
            return "Attempted to divide by zero!\n";  
        }  
}; 

template<typename T>
class Sum{
    public:
        Sum(){};
        T sum(T num1,T num2)
        {
            T _sum =num1+num2; // TODO: not handling overflows, ditto for others
            return _sum;
        }
        // function overloading 
        T sum(std::initializer_list<T> list)
        {
            T total=0;
            for( auto val: list )
            {
                total=total+val;
            }
            return total;
        }
};

template<typename T>
class Mul{
    public:

        Mul(){};
        T mul(T num1,T num2)
        {
            T _mul =num1*num2;
            return _mul;
        }
        
};

template<typename T>
class Sub{
    public:
        Sub(){};
        T sub(T num1,T num2)
        {
            T _sub =num1-num2;
            return _sub;
        }
        
};

template<typename T>
class Div{
    public:
        Div(){};
        T div(T num1,T num2)
        {
            T _div;
            try{
                if (num2==0)
                {
                    DividByZeroException err1;
                    throw err1;
                }
                else{
                    _div=num1/num2;
                    return _div;
                }
            }
            catch(std::exception& e)
            {
                std::cout<<e.what()<<std::endl;
            }
            return _div;
             
        }
};

// TODO: we don't need inheritance here. you can just call the sub, sum functions
template<typename T>
class Calculator:public Sum<T>,public Mul<T>,public Sub<T>,public Div<T>  // calculator class 
{
    T num1;
    T num2;
    const char* DirectoryLocation; // TODO: use std::stringview or std::string here
    // location where we want to create calculator.db file 
    DbConnection*ptrDb =nullptr; // TODO: no raw pointers! use the correct smart pointer

    //checks if you want to update database or not check=false ->do not want to update check=true want to update database
    bool check=false;
    public:
        Calculator(T _num1 ,T _num2):num1{_num1},num2{_num2}{
            this->check=false;
        }
        Calculator(T _num1 ,T _num2,const char*s):num1{_num1},num2{_num2},DirectoryLocation{s}{   // constructor for calculator
            this->check=true;
            ptrDb=DbConnection::start(DirectoryLocation);
        }
        T calculate_operation(int val) // TODO: Use enum as input
        {
            T result;
            std::string _num1=std::to_string(num1);
            std::string _num2=std::to_string(num2);
            std::string _op;
            std::string _result;
            switch (val)
            {
                case 1:
                    result= this->sum(num1,num2);
                    _op="+";
                    _result=std::to_string(result);
                    if (check==true) // TODO: if (check)
                    {
                        ptrDb->InsertData(_num1,_num2,_op,_result);
                    }
                    
                    break;                
                case 2:
                    result= this->sub(num1,num2);
                    _op="-";
                    _result=std::to_string(result);
                    if(check)
                    {
                        ptrDb->InsertData(_num1,_num2,_op,_result);
                    }
                    break;
                case 3:
                    result= this->mul(num1,num2);
                    _op="*";
                    _result=std::to_string(result);
                    if(check==true)
                    {
                        ptrDb->InsertData(_num1,_num2,_op,_result);
                    }
                    break;
                case 4:
                    result= this->div(num1,num2);
                    _op="/";
                    _result=std::to_string(result);
                    if(check==true)
                    {
                        ptrDb->InsertData(_num1,_num2,_op,_result);
                    }
                    break;

            }
            return result;
        }
        void Run()
        {
            int val=0;
            bool flag=true;
            while(flag)
            {
                operationToPerform(val);
                std::cout<<"Result : "<<calculate_operation(val)<<std::endl;
                std::cout<<"if you want to exit program enter -1"<<std::endl;
                int temp;
                std::cin>>temp;
                if (temp==-1)
                {
                    flag=false;
                }
            }
        }

        void operationToPerform(int&val) // TODO: out params are an anti-pattern
        {
            std::cout<<"enter 1 for addition"<<std::endl;
            std::cout<<"enter 2 for subtraction"<<std::endl;
            std::cout<<"enter 3 for multiplication"<<std::endl;
            std::cout<<"enter 4 for divsion"<<std::endl;
            std::cin>>val;
        }

        void showAllOperationHistory(){
            ptrDb->selectData();
        }
        void setNum1(T _num1)
        {
            this->num1=_num1;
        }
        void setNum2(T _num2)
        {
            this->num2=_num2;
        }
        void setNum(T _num1,T _num2)
        {
            this->num1=num1;
            this->num2=num2;
        }
};

#endif


