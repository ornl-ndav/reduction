/*
 *                     SNS Common Libraries
 *           A part of the SNS Analysis Software Suite.
 *
 *                  Spallation Neutron Source
 *          Oak Ridge National Laboratory, Oak Ridge TN.
 *
 *
 *                             NOTICE
 * 
 * For this software and its associated documentation, permission is granted 
 * to reproduce, prepare derivative works, and distribute copies to the public 
 * for any purpose and without fee.
 *  
 * This material was prepared as an account of work sponsored by an agency of 
 * the United States Government.  Neither the United States Government nor the 
 * United States Department of Energy, nor any of their employees, makes any 
 * warranty, express or implied, or assumes any legal liability or 
 * responsibility for the accuracy, completeness, or usefulness of any 
 * information, apparatus, product, or process disclosed, or represents that 
 * its use would not infringe privately owned rights.
 *
 */

// $Id$

#include "num_comparison.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

const std::string EMPTY("");
const std::string ERROR("error ");
const std::string SS("s,s");
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

std::string type_string(double vec)
{
  return std::string("double");
}

std::string type_string(Nessi::Vector<float> & vec)
{
  return std::string("float");
}

std::string type_string(float vec)
{
  return std::string("float");
}

std::string type_string(Nessi::Vector<int> & vec)
{
  return std::string("int");
}

std::string type_string(Nessi::Vector<unsigned int> & vec)
{
  return std::string("unsigned int");
}

// returns true if nothing is wrong
template <typename NumT>
bool test_okay(Nessi::Vector<NumT> & output,
               Nessi::Vector<NumT> & true_output,
               std::string array_type,
               std::string data_type=EMPTY){

  if(!Utils::vector_is_equals(output,true_output))
    {
      std::cout << "(" << type_string(output) << " " << array_type
           << ") FAILED....Output " << data_type
           << "different from vector expected" << std::endl;
      return false;
    }
  return true;
}

// returns true if nothing is wrong
template <typename NumT>
bool test_okay(NumT & output,
               NumT & true_output,
               std::string array_type=SS,
               std::string data_type=EMPTY){

  if(Utils::compare(output,true_output)!=0)
    {
      std::cout << "(" << type_string(output) << " " << array_type
           << ") FAILED....Output " << data_type
           << "different from vector expected" << std::endl;

      std::cout << "Value expected was ";
      std::cout.setf(std::ios::fixed);
      std::cout << std::setprecision(std::numeric_limits<NumT>::digits10+1);
      std::cout << true_output;
      std::cout << ", Value returned was " << output << std::endl;
      std::cout << "Difference (Returned - Expected): ";
      std::cout.setf(std::ios::scientific);
      std::cout << output - true_output << std::endl;

      return false;
    }
  return true;
}
