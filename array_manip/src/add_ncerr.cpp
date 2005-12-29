/**
 * $Id: $
 *
 * \file array_manip/src/add_ncerr.cpp
 */
#include "add_ncerr.hpp"

namespace ArrayManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.1.
   *
   * \see add_ncerr()
   */
  template std::string 
  add_ncerr<float>(Nessi::Vector<float> const & array_in, 
                   Nessi::Vector<float> const & array_in_err2, 
                   float scalar,
                   float scalar_err2,
                   Nessi::Vector<float> & array_out,
                   Nessi::Vector<float> & array_out_err2,
                   void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.1.
   *
   * \see add_ncerr()
   */
  template std::string 
  add_ncerr<double>(Nessi::Vector<double> const & array_in, 
                    Nessi::Vector<double> const & array_in_err2, 
                    double scalar,
                    double scalar_err2,
                    Nessi::Vector<double> & array_out,
                    Nessi::Vector<double> & array_out_err2,
                    void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.1.
   *
   * \see add_ncerr()
   */
  template std::string 
  add_ncerr<int>(Nessi::Vector<int> const & array_in, 
                 Nessi::Vector<int> const & array_in_err2, 
                 int scalar,
                 int scalar_err2,
                 Nessi::Vector<int> & array_out,
                 Nessi::Vector<int> & array_out_err2,
                 void *temp);

  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.1.
   *
   * \see add_ncerr()
   */
  template std::string 
  add_ncerr<unsigned int>(Nessi::Vector<unsigned int> const & array_in, 
                          Nessi::Vector<unsigned int> const & array_in_err2,
                          unsigned int scalar, 
                          unsigned int scalar_err2,
                          Nessi::Vector<unsigned int> & array_out,
                          Nessi::Vector<unsigned int> & array_out_err2,
                          void *temp);

  /**
   * This is the float declaration of the function defined in 3.6.
   *
   * \see add_ncerr()
   */
  template std::string 
  add_ncerr<float>(Nessi::Vector<float> const & input1, 
                   Nessi::Vector<float> const & input1_err2, 
                   Nessi::Vector<float> const & input2, 
                   Nessi::Vector<float> const & input2_err2, 
                   Nessi::Vector<float> & output,
                   Nessi::Vector<float> & output_err2,
                   void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.6.
   *
   * \see add_ncerr()
   */
  template std::string 
  add_ncerr<double>(Nessi::Vector<double> const & input1, 
                    Nessi::Vector<double> const & input1_err2, 
                    Nessi::Vector<double> const & input2, 
                    Nessi::Vector<double> const & input2_err2, 
                    Nessi::Vector<double> & output,
                    Nessi::Vector<double> & output_err2,
                    void *temp);

  /**
   * This is the integer declaration of the function defined in 3.6.
   *
   * \see add_ncerr()
   */
  template std::string 
  add_ncerr<int>(Nessi::Vector<int> const & input1, 
                 Nessi::Vector<int> const & input1_err2, 
                 Nessi::Vector<int> const & input2, 
                 Nessi::Vector<int> const & input2_err2, 
                 Nessi::Vector<int> & output,
                 Nessi::Vector<int> & output_err2,
                 void *temp);

  /**
   * This is the unsigned integer declaration of the function defined in 3.6.
   *
   * \see add_ncerr()
   */
  template std::string 
  add_ncerr<unsigned int>(Nessi::Vector<unsigned int> const & input1, 
                          Nessi::Vector<unsigned int> const & input1_err2, 
                          Nessi::Vector<unsigned int> const & input2, 
                          Nessi::Vector<unsigned int> const & input2_err2, 
                          Nessi::Vector<unsigned int> & output,
                          Nessi::Vector<unsigned int> & output_err2,
                          void *temp);

} // ArrayManip
