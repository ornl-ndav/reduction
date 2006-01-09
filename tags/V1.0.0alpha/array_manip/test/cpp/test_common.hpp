// $Id: mult_ncerr_test.cpp 248 2006-01-06 14:55:59Z pf9 $

#include "num_comparison.hpp"
#include <iostream>
#include <string>

const std::string EMPTY("");
const std::string ERROR("error ");
const std::string SV("s,v");
const std::string VS("v,s");
const std::string VV("v,v");

template <typename NumT>
std::string type_string(Nessi::Vector<NumT> & vec)
{
  return std::string(EMPTY);
}

std::string type_string(Nessi::Vector<double> & vec)
{
  return std::string("double");
}

std::string type_string(Nessi::Vector<float> & vec)
{
  return std::string("float");
}

std::string type_string(Nessi::Vector<int> & vec)
{
  return std::string("int");
}

std::string type_string(Nessi::Vector<unsigned> & vec)
{
  return std::string("unsigned");
}

// returns true if nothing is wrong
template <typename NumT>
bool test_okay(Nessi::Vector<NumT> & output,
               Nessi::Vector<NumT> & true_output,
               std::string array_type,
               std::string data_type=EMPTY){

  int error=0; // dummy variable for usin in testing code

  Utils::vector_comparison(output,true_output,error,10);
  if(error>0)
    {
      std::cout << "(" << type_string(output) << " " << array_type
           << ") FAILED....Output " << data_type
           << "different from vector expected" << std::endl;
      return false;
    }
  return true;
}
