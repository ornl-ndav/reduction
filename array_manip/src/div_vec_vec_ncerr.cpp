/**
 * $Id$
 *
 * \file array_manip/src/div_vec_vec_ncerr.cpp
 */
#include "div_vec_vec_ncerr.hpp"

namespace ArrayManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.9.
   *
   * \see div_vec_vec_ncerr()
   */
  template std::string 
  div_vec_vec_ncerr<float>(Nessi::Vector<float> const & input1, 
			   Nessi::Vector<float> const & input1_err2, 
			   Nessi::Vector<float> const & input2, 
			   Nessi::Vector<float> const & input2_err2, 
			   Nessi::Vector<float> & output,
			   Nessi::Vector<float> & output_err2,
			   void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.9.
   *
   * \see div_vec_vec_ncerr()
   */
  template std::string 
  div_vec_vec_ncerr<double>(Nessi::Vector<double> const & input1, 
			    Nessi::Vector<double> const & input1_err2, 
			    Nessi::Vector<double> const & input2, 
			    Nessi::Vector<double> const & input2_err2, 
			    Nessi::Vector<double> & output,
			    Nessi::Vector<double> & output_err2,
			    void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.9.
   *
   * \see div_vec_vec_ncerr()
   */
  template std::string 
  div_vec_vec_ncerr<int>(Nessi::Vector<int> const & input1, 
			 Nessi::Vector<int> const & input1_err2, 
			 Nessi::Vector<int> const & input2, 
			 Nessi::Vector<int> const & input2_err2, 
			 Nessi::Vector<int> & output,
			 Nessi::Vector<int> & output_err2,
			 void *temp);

  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.9.
   *
   * \see div_vec_vec_ncerr()
   */
  template std::string 
  div_vec_vec_ncerr<unsigned int>(Nessi::Vector<unsigned int> const & input1, 
			      Nessi::Vector<unsigned int> const & input1_err2, 
			      Nessi::Vector<unsigned int> const & input2, 
			      Nessi::Vector<unsigned int> const & input2_err2, 
			      Nessi::Vector<unsigned int> & output,
			      Nessi::Vector<unsigned int> & output_err2,
			      void *temp);
} // ArrayManip
