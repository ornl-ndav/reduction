// $Id: mult_ncerr_test.cpp 248 2006-01-06 14:55:59Z pf9 $

#include "arith.hpp"
#include "num_comparison.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const string EMPTY("");
const string ERROR("error");
const string SV("s,v");
const string VS("v,s");
const string VV("v,v");

template <typename NumT>
string type_string(Nessi::Vector<NumT> & vec)
{
  return string(EMPTY);
}

string type_string(Nessi::Vector<double> & vec)
{
  return string("double");
}

string type_string(Nessi::Vector<float> & vec)
{
  return string("float");
}

string type_string(Nessi::Vector<int> & vec)
{
  return string("int");
}

string type_string(Nessi::Vector<unsigned> & vec)
{
  return string("unsigned");
}

// returns true if nothing is wrong
template <typename NumT>
bool test_okay(Nessi::Vector<NumT> & output,
               Nessi::Vector<NumT> & true_output,
               string array_type,
               string data_type=EMPTY){

  int error=0; // dummy variable for usin in testing code

  Utils::vector_comparison(output,true_output,error,10);
  if(error>0)
    {
      cout << "(" << type_string(output) << " " << array_type
           << ") FAILED....Output " << data_type
           << "different from vector expected" << endl;
      return false;
    }
  return true;
}
