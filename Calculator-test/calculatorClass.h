#include<bits/stdc++.h>
using namespace std;

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
                cout<<e.what()<<endl;
            }
            return _div;
             
        }
};

template<typename T>
class Calculator:public Sum<T>,public Mul<T>,public Sub<T>,public Div<T>
{
    T num1;
    T num2;
    public:
        Calculator(T _num1 ,T _num2):num1{_num1},num2{_num2}{
            // this->num1= _num1;
            // this->num2= _num2;
        }
        void SetValue(T _num1 ,T _num2)
        {
            this->num1= _num1;
            this->num2= _num2;
        }
        T calculate_operation(int val)
        {
            T result;
            switch (val)
            {
                case 1:
                    result= this->sum(num1,num2);
                    // cout<<"ye"<<endl;
                    break;                
                case 2:
                    result= this->sub(num1,num2);
                    break;
                case 3:
                    result= this->mul(num1,num2);
                    break;
                case 4:
                    result= this->div(num1,num2);
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
                cout<<"Result : "<<calculate_operation(val)<<endl;
                cout<<"if you want to exit program enter -1"<<endl;
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
            cout<<"enter 1 for addition"<<endl;
            cout<<"enter 2 for subtraction"<<endl;
            cout<<"enter 3 for multiplication"<<endl;
            cout<<"enter 4 for divsion"<<endl;
            cin>>val;
        }


};