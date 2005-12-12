/**
 * $Id$
 *
 * \file array_manip/src/div_vec_vec_ncerr.cpp
 */
#include "vec_vec_arith.hpp"
#include "check_inputs.hpp"
#include <stdexcept>
#include <string>
#include <vector>

namespace ArrayManip
{
  // 3.9
  template <typename NumT>
  std::string 
  div_vec_vec_ncerr(std::vector<NumT> const & input1, 
		    std::vector<NumT> const & input1_err2, 
		    std::vector<NumT> const & input2, 
		    std::vector<NumT> const & input2_err2, 
		    std::vector<NumT> & output,
		    std::vector<NumT> & output_err2,
		    void *temp=NULL)
  {
    std::string retstr("");

    try 
      {
	std::string errstr("ArrayManip::div_vec_vec_ncerr: data ");
	check_sizes_2in1out(errstr, input1, input2, output);
      }
    catch (std::invalid_argument e)
      {
	throw e;
      }

    try 
      {
	std::string errstr("ArrayManip::div_vec_vec_ncerr: error ");
	check_sizes_2in1out(errstr, input1_err2, input2_err2, output_err2);
      }
    catch (std::invalid_argument e)
      {
	throw e;
      }

    std::transform(input1.begin(), input1.end(), input2.begin(), 
                   output.begin(), std::divides<NumT>());

    size_t sz = input1.size();
    for (size_t i = 0; i < sz; ++i)
      {
	NumT input2_2 = input2[i] * input2[i];
	output_err2[i] = (input1_err2[i] / input2_2) + 
	  (((input1[i] * input1[i]) / (input2_2 * input2_2)) * input2_err2[i]);
      }

    return retstr;
  }

  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.9.
   *
   * \see div_vec_vec_ncerr()
   */
  template std::string 
  div_vec_vec_ncerr<float>(std::vector<float> const & input1, 
			   std::vector<float> const & input1_err2, 
			   std::vector<float> const & input2, 
			   std::vector<float> const & input2_err2, 
			   std::vector<float> & output,
			   std::vector<float> & output_err2,
			   void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.9.
   *
   * \see div_vec_vec_ncerr()
   */
  template std::string 
  div_vec_vec_ncerr<double>(std::vector<double> const & input1, 
			    std::vector<double> const & input1_err2, 
			    std::vector<double> const & input2, 
			    std::vector<double> const & input2_err2, 
			    std::vector<double> & output,
			    std::vector<double> & output_err2,
			    void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.9.
   *
   * \see div_vec_vec_ncerr()
   */
  template std::string 
  div_vec_vec_ncerr<int>(std::vector<int> const & input1, 
			 std::vector<int> const & input1_err2, 
			 std::vector<int> const & input2, 
			 std::vector<int> const & input2_err2, 
			 std::vector<int> & output,
			 std::vector<int> & output_err2,
			 void *temp);

  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.9.
   *
   * \see div_vec_vec_ncerr()
   */
  template std::string 
  div_vec_vec_ncerr<unsigned int>(std::vector<unsigned int> const & input1, 
			      std::vector<unsigned int> const & input1_err2, 
			      std::vector<unsigned int> const & input2, 
			      std::vector<unsigned int> const & input2_err2, 
			      std::vector<unsigned int> & output,
			      std::vector<unsigned int> & output_err2,
			      void *temp);

} // ArrayManip
