#include<bits/stdc++.h>
#include<gtest/gtest.h>
#include "../../CalculatorClass/Calculator.h"   // adding Calculator class 
using namespace std;
// addition of two integer number //
TEST(calculatorSum,postiveNoSum)
{
    //arrange 
    vector<pair<pair<int,int>,int>>arr;
    arr.push_back(make_pair(make_pair(1,4),5));
    arr.push_back(make_pair(make_pair(9,2),11));
    arr.push_back(make_pair(make_pair(100000,100000),200000));
    arr.push_back(make_pair(make_pair(0,4),4));
    arr.push_back(make_pair(make_pair(0,0),0));

    //act (1 for add)
    for(int i=0 ;i<5 ;i++)
    {
        Calculator<int>c1(arr[i].first.first,arr[i].first.second);
        int val =c1.calculate_operation(1);
        ASSERT_EQ(val,arr[i].second);  //assert
        cout<<"test case passed for "<<arr[i].first.first<<" "<<arr[i].first.second<<endl;
    }  
}

// subtraction of two integer value //
TEST(calculatorSum,postiveNoSub)
{
    //arrange 
    vector<pair<pair<int,int>,int>>arr;
    arr.push_back(make_pair(make_pair(1,4),-3));
    arr.push_back(make_pair(make_pair(9,2),7));
    arr.push_back(make_pair(make_pair(100000,100000),0));
    arr.push_back(make_pair(make_pair(0,4),-4));
    arr.push_back(make_pair(make_pair(0,0),0));

    //act (1 for add)
    for(int i=0 ;i<5 ;i++)
    {
        Calculator<int>c1(arr[i].first.first,arr[i].first.second);
        int val =c1.calculate_operation(2);
        ASSERT_EQ(val,arr[i].second);  //assert
        cout<<"test case passed for "<<arr[i].first.first<<" "<<arr[i].first.second<<endl;
    }  
}


// sum of two number are of type double 
TEST(calculatorSum,DoubleNumberSum)
{
    //arrange 
    vector<pair<pair<double,double>,double>>arr;
    arr.push_back(make_pair(make_pair(1.0,4),5.0));
    arr.push_back(make_pair(make_pair(2.3,2.3),4.6));
    arr.push_back(make_pair(make_pair(100000,100000),200000));
    arr.push_back(make_pair(make_pair(0.0,4.3),4.3));
    arr.push_back(make_pair(make_pair(0,0),0));

    //act (1 for add)
    for(int i=0 ;i<5 ;i++)
    {
        Calculator<int>c1(arr[i].first.first,arr[i].first.second);
        int val =c1.calculate_operation(1);
        ASSERT_DOUBLE_EQ(val,arr[i].second);  //assert
        cout<<"test case passed for "<<arr[i].first.first<<" "<<arr[i].first.second<<endl;
    }  
}

// negative number sum 
TEST(calculatorSum,NegativeNoSum)
{
    //arrange 
    vector<pair<pair<int,int>,int>>arr;
    arr.push_back(make_pair(make_pair(-1,-4),-5));
    arr.push_back(make_pair(make_pair(-9,-2),-11));
    arr.push_back(make_pair(make_pair(-100000,-100000),-200000));
    arr.push_back(make_pair(make_pair(0,-4),-4));
    arr.push_back(make_pair(make_pair(0,0),0));

    //act (1 for add)
    for(int i=0 ;i<5 ;i++)
    {
        Calculator<int>c1(arr[i].first.first,arr[i].first.second);
        int val =c1.calculate_operation(1);
        ASSERT_EQ(val,arr[i].second);  //assert
        cout<<"test case passed for "<<arr[i].first.first<<" "<<arr[i].first.second<<endl;
    }  
}

// multiplication of two integer value 
TEST(calculatorSum,NumberMultiplication)
{
    //arrange 
    vector<pair<pair<int,int>,int>>arr;
    arr.push_back(make_pair(make_pair(1,4),4));
    arr.push_back(make_pair(make_pair(9,2),18));
    arr.push_back(make_pair(make_pair(100,10),1000));
    arr.push_back(make_pair(make_pair(0,4),0));
    arr.push_back(make_pair(make_pair(0,0),0));

    //act (1 for add)
    for(int i=0 ;i<5 ;i++)
    {
        Calculator<int>c1(arr[i].first.first,arr[i].first.second);
        int val =c1.calculate_operation(3);
        ASSERT_EQ(val,arr[i].second);  //assert
        cout<<"test case passed for "<<arr[i].first.first<<" "<<arr[i].first.second<<endl;
    }  
}
// multiplication of two double type value 
TEST(calculatorSum,NumberMultiplicationtypeDouble)
{
    //arrange 
    vector<pair<pair<double,double>,double>>arr;
    arr.push_back(make_pair(make_pair(1.0,4.1),4.1));
    arr.push_back(make_pair(make_pair(9,1.1),9.9));
    arr.push_back(make_pair(make_pair(100.0,10.0),1000.0));
    arr.push_back(make_pair(make_pair(1.2,4.0),4.8));
    arr.push_back(make_pair(make_pair(0,0),0));

    //act (1 for add)
    for(int i=0 ;i<5 ;i++)
    {
        Calculator<int>c1(arr[i].first.first,arr[i].first.second);
        int val =c1.calculate_operation(3);
        ASSERT_DOUBLE_EQ(val,arr[i].second);  //assert
        cout<<"test case passed for "<<arr[i].first.first<<" "<<arr[i].first.second<<endl;
    }  
}
// division of two double type value
TEST(calculatorSum,NumberDivisiontypeDouble)
{
    //arrange 
    vector<pair<pair<double,double>,double>>arr;
    arr.push_back(make_pair(make_pair(62.5,25),2.5));
    arr.push_back(make_pair(make_pair(9,1.1),8.181));
    arr.push_back(make_pair(make_pair(100.0,10.0),10.0));
    arr.push_back(make_pair(make_pair(12,4.0),3.0));
    arr.push_back(make_pair(make_pair(1,1.0),1.0));

    //act (1 for add)
    for(int i=0 ;i<5 ;i++)
    {
        Calculator<int>c1(arr[i].first.first,arr[i].first.second);
        int val =c1.calculate_operation(4);
        ASSERT_DOUBLE_EQ(val,arr[i].second);  //assert
        cout<<"test case passed for "<<arr[i].first.first<<" "<<arr[i].first.second<<endl;
    }  
}



int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}