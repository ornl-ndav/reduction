/**
 * $Id$
 *
 * \file axis_manip/src/init_scatt_wavevector_to_Q.hpp
 */
#include "conversions.hpp"
#include <stdexcept>
#include <string>

namespace AxisManip
{
  // 3.32
 template <typename NumT>
 std::string
 init_scatt_wavevector_to_Q(Nessi::Vector<NumT> const & initial_wavevector,
			    Nessi::Vector<NumT> const & initial_wavevector_err2,
			    Nessi::Vector<NumT> const & final_wavevector,
			    Nessi::Vector<NumT> const & final_wavevector_err2,
			    const NumT azimuthal_angle,
			    const NumT azimuthal_angle_err2,
			    const NumT polar_angle,
			    const NumT polar_angle_err2,
			    Nessi::Vector<NumT> & Qx,
			    Nessi::Vector<NumT> & Qx_err2,
			    Nessi::Vector<NumT> & Qy,
			    Nessi::Vector<NumT> & Qy_err2,
			    Nessi::Vector<NumT> & Qz,
			    Nessi::Vector<NumT> & Qz_err2,
			    void *temp=NULL)
 {
    throw std::runtime_error("Function [init_scatt_wavevector_to_Q] not implemented");
 }
} // AxisManip
