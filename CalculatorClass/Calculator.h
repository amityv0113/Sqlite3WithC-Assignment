#include<bits/stdc++.h>
#include "../CalculatorDbModel/CalculatorModel.h"


class DividByZeroException : public exception{  
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
            T _sum =num1+num2;
            return _sum;
        }
        // function overloading 
        T sum(initializer_list<T> list)
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
            catch(exception& e)
            {
                std::cout<<e.what()<<endl;
            }
            return _div;
             
        }
};

template<typename T>
class Calculator:public Sum<T>,public Mul<T>,public Sub<T>,public Div<T>  // calculator class 
{
    T num1;
    T num2;
    const char* DirectoryLocation;
    // location where we want to create calculator.db file 
    DbConnection*ptrDb =nullptr;
    public:
        Calculator(T _num1 ,T _num2,const char*s):num1{_num1},num2{_num2},DirectoryLocation{s}{   // constructor for calculator

            ptrDb=DbConnection::start(DirectoryLocation);
        }
        T calculate_operation(int val)
        {
            T result;
            std::string _num1=to_string(num1);
            std::string _num2=to_string(num2);
            std::string _op;
            std::string _result;
            switch (val)
            {
                case 1:
                    result= this->sum(num1,num2);
                    
                    _op="+";
                    _result=to_string(result);
                    ptrDb->InsertData(_num1,_num2,_op,_result);
                    break;                
                case 2:
                    result= this->sub(num1,num2);
                    _op="-";
                    _result=to_string(result);
                    ptrDb->InsertData(_num1,_num2,_op,_result);
                    break;
                case 3:
                    result= this->mul(num1,num2);
                    _op="*";
                    _result=to_string(result);
                    ptrDb->InsertData(_num1,_num2,_op,_result);
                    break;
                case 4:
                    result= this->div(num1,num2);
                    _op="/";
                    _result=to_string(result);
                    ptrDb->InsertData(_num1,_num2,_op,_result);
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
                std::cout<<"Result : "<<calculate_operation(val)<<endl;
                std::cout<<"if you want to exit program enter -1"<<endl;
                int temp;
                cin>>temp;
                if (temp==-1)
                {
                    flag=false;
                }
            }
        }

        void operationToPerform(int&val)
        {
            std::cout<<"enter 1 for addition"<<endl;
            std::cout<<"enter 2 for subtraction"<<endl;
            std::cout<<"enter 3 for multiplication"<<endl;
            std::cout<<"enter 4 for divsion"<<endl;
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

