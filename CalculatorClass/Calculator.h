#ifndef _BITSTDC_
#define _BITSTDC_
#include <bits/stdc++.h>
#endif
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "../CalculatorDbModel/CalculatorModel.h"
#include <memory>

class DividByZeroException : public std::exception
{
public:
  const char *what() const throw() { return "Attempted to divide by zero!\n"; }
};
class OverFlow : public std::exception
{
public:
  const char *what() const throw() { return "overflow condition \n"; }
};

template<typename T> class OperationAbstract
{
public:
  virtual T sum(T num1, T num2) = 0;
  virtual T mul(T num1, T num2) = 0;
  virtual T sub(T num1, T num2) = 0;
  virtual T div(T num1, T num2) = 0;
};
template<typename T> class Calculator : public OperationAbstract<T>// calculator class
{
  T num1;
  T num2;
  std::string DirectoryLocation;
  // location where we want to create calculator.db file
  // DbConnection*ptrDb =nullptr;
  std::shared_ptr<DbConnection> ptrDb;
  // checks if you want to update database or not check=false ->do not want to update check=true want to update database
  bool check = false;
  // function to sum two number
  T sum(T num1, T num2)
  {
    T _sum;
    try {
      _sum = num1 + num2;
      if (num1 > 0 && num2 > 0 && _sum < 0) {
        OverFlow overflow;
        throw overflow;
      } else if (num1 < 0 && num2 < 0 && _sum > 0) {
        OverFlow overflow;
        throw overflow;
      } else {
        return _sum;
      }
      // return _sum;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    return _sum;
  }
  // function for multiplcation of two number //
  T mul(T num1, T num2)
  {
    T _mul;
    try {
      _mul = num1 * num2;
      if (num1 > 0 && num2 > 0 && _mul < 0) {
        OverFlow overflow;
        throw overflow;
      } else if (num1 < 0 && num2 < 0 && _mul > 0) {
        OverFlow overflow;
        throw overflow;
      } else {
        return _mul;
      }
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    return _mul;
  }
  // function to to subtraction
  T sub(T num1, T num2)
  {
    T _sub;
    try {
      _sub = num1 - num2;
      if (num1 > 0 && num2 < 0 && _sub < 0) {
        OverFlow overflow;
        throw overflow;
      } else if (num1 < 0 && num2 > 0 && _sub > 0) {
        OverFlow overflow;
        throw overflow;
      } else {
        return _sub;
      }
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }

    return _sub;
  }
  // function to divide two number
  T div(T num1, T num2)
  {
    T _div;
    try {
      if (num2 == 0) {
        DividByZeroException err1;
        throw err1;
      } else {
        _div = num1 / num2;
        return _div;
      }
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
    return _div;
  }

public:
  Calculator(T _num1, T _num2) : num1{ _num1 }, num2{ _num2 } { this->check = false; }
  Calculator(T _num1, T _num2, std::string &s) : num1{ _num1 }, num2{ _num2 }, DirectoryLocation{ s }
  {// constructor for calculator
    this->check = true;
    std::unique_ptr<DbConnection> ptrDbTemp(DbConnection::start(DirectoryLocation.c_str()));
    ptrDb = std::move(ptrDbTemp);
  }
  enum ArithmeticOperation { temp_add = 1, temp_sub = 2, temp_mul = 3, temp_div = 4 };
  T calculate_operation(int val)
  {
    T result;
    std::string _num1 = std::to_string(num1);
    std::string _num2 = std::to_string(num2);
    std::string _op;
    std::string _result;
    switch (val) {
    case ArithmeticOperation::temp_add:
      result = this->sum(num1, num2);
      _op = "+";
      _result = std::to_string(result);
      if (check) {
        if ((num1 == -num1) && result == 0) {
          ptrDb->InsertData(_num1, _num2, _op, _result);
        } else if (result != 0) {
          ptrDb->InsertData(_num1, _num2, _op, _result);
        }
      }

      break;
    case ArithmeticOperation::temp_sub:
      result = this->sub(num1, num2);
      _op = "-";
      _result = std::to_string(result);
      if (check) {
        if ((num1 == num1) && result == 0) {
          ptrDb->InsertData(_num1, _num2, _op, _result);
        } else if (result != 0) {
          ptrDb->InsertData(_num1, _num2, _op, _result);
        }
      }
      break;
    case ArithmeticOperation::temp_mul:
      result = this->mul(num1, num2);
      _op = "*";
      _result = std::to_string(result);
      if (check) {
        if (result == 0 && (num1 == 0 || num2 == 0)) {
          ptrDb->InsertData(_num1, _num2, _op, _result);
        } else if (result != 0) {
          ptrDb->InsertData(_num1, _num2, _op, _result);
        }
      }
      break;
    case ArithmeticOperation::temp_div:
      result = this->div(num1, num2);
      _op = "/";
      _result = std::to_string(result);
      if (check) {
        if (result == 0 && num1 == 0) {
          ptrDb->InsertData(_num1, _num2, _op, _result);
        } else if (result != 0) {
          ptrDb->InsertData(_num1, _num2, _op, _result);
        }
      }
      break;
    }
    return result;
  }
  void Run()
  {
    int val = 0;
    bool flag = true;
    while (flag) {
      val = operationToPerform();
      std::cout << "Result : " << calculate_operation(val) << std::endl;
      std::cout << "if you want to exit program enter -1" << std::endl;
      int temp;
      std::cin >> temp;
      if (temp == -1) { flag = false; }
    }
  }

  int operationToPerform()
  {
    int val;
    std::cout << "enter 1 for addition" << std::endl;
    std::cout << "enter 2 for subtraction" << std::endl;
    std::cout << "enter 3 for multiplication" << std::endl;
    std::cout << "enter 4 for divsion" << std::endl;
    std::cin >> val;
    bool temp_flag = true;
    if ((val == 1 || val == 2 || val == 3 || val == 4)) { return val; }
    while (temp_flag) {
      std::cin.clear();// clears the error flag on cin (so that future I/O operations will work correctly),
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "You have entered wrong input! please enter valid input :" << std::endl;
      std::cin >> val;
      if ((val == 1 || val == 2 || val == 3 || val == 4)) {
        temp_flag = false;
        break;
      }
      std::cout << val << std::endl;
    }
    return val;
  }

  void showAllOperationHistory() { ptrDb->selectData(); }
  void setNum1(T _num1) { this->num1 = _num1; }
  void setNum2(T _num2) { this->num2 = _num2; }
  void setNum(T _num1, T _num2)
  {
    this->num1 = num1;
    this->num2 = num2;
  }
};

#endif
