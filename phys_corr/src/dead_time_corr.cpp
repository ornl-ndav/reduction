/**
 * $Id$
 *
 * \file phys_corr/src/dead_time_corr.cpp
 */
#include "dead_time_corr.hpp"

namespace PhysCorr
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.36.
   *
   * \see dead_time_corr()
   */
  template std::string
  dead_time_corr<float>(Nessi::Vector<float> const & axis_in,
			Nessi::Vector<float> const & input,
			Nessi::Vector<float> const & input_err2,
			float corr_factor,
			Nessi::Vector<float> & output,
			Nessi::Vector<float> & output_err2,
			void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.36.
   *
   * \see dead_time_corr()
   */
  template std::string
  dead_time_corr<double>(Nessi::Vector<double> const & axis_in,
			 Nessi::Vector<double> const & input,
			 Nessi::Vector<double> const & input_err2,
			 double corr_factor,
			 Nessi::Vector<double> & output,
			 Nessi::Vector<double> & output_err2,
			 void *temp);

  /**
   * This is the integer declaration of the function defined in 3.36.
   *
   * \see dead_time_corr()
   */
  template std::string
  dead_time_corr<int>(Nessi::Vector<int> const & axis_in,
		      Nessi::Vector<int> const & input,
		      Nessi::Vector<int> const & input_err2,
		      int corr_factor,
		      Nessi::Vector<int> & output,
		      Nessi::Vector<int> & output_err2,
		      void *temp);

  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.36.
   *
   * \see dead_time_corr()
   */
  template std::string
  dead_time_corr<unsigned int>(Nessi::Vector<unsigned int> const & axis_in,
			   Nessi::Vector<unsigned int> const & input,
			   Nessi::Vector<unsigned int> const & input_err2,
			   unsigned int corr_factor,
			   Nessi::Vector<unsigned int> & output,
			   Nessi::Vector<unsigned int> & output_err2,
			   void *temp);

} // PhysCorr
