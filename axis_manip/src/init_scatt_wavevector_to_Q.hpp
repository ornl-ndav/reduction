/**
 * $Id$
 *
 * \file axis_manip/src/init_scatt_wavevector_to_Q.hpp
 */
#ifndef _INIT_SCATT_WAVEVECTOR_TO_Q_HPP
#define _INIT_SCATT_WAVEVECTOR_TO_Q_HPP 1

#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.32
 template <typename NumT>
 std::string
 init_scatt_wavevector_to_Q(
                           const Nessi::Vector<NumT> & initial_wavevector,
			   const Nessi::Vector<NumT> & initial_wavevector_err2,
                           const Nessi::Vector<NumT> & final_wavevector,
                           const Nessi::Vector<NumT> & final_wavevector_err2,
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

  template <typename NumT>
   std::string
   init_scatt_wavevector_to_Q(
                           const NumT initial_wavevector,
                           const NumT initial_wavevector_err2,
                           const Nessi::Vector<NumT> & final_wavevector,
                           const Nessi::Vector<NumT> & final_wavevector_err2,
                           const NumT azimuthal,
                           const NumT azimuthal_err2,
                           const NumT polar,
                           const NumT polar_err2,
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

  template <typename NumT>
   std::string
   init_scatt_wavevector_to_Q(
                           const Nessi::Vector<NumT> & initial_wavevector,
                           const Nessi::Vector<NumT> & initial_wavevector_err2,
                           const NumT final_wavevector,
                           const NumT final_wavevector_err2,
                           const NumT azimuthal,
                           const NumT azimuthal_err2,
                           const NumT polar,
                           const NumT polar_err2,
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

  template <typename NumT>
   std::string
   init_scatt_wavevector_to_Q(const NumT initial_wavevector,
			      const NumT initial_wavevector_err2,
			      const NumT final_wavevector,
			      const NumT final_wavevector_err2,
			      const NumT azimuthal,
			      const NumT azimuthal_err2,
			      const NumT polar,
			      const NumT polar_err2,
			      NumT & Qx,
			      NumT & Qx_err2,
			      NumT & Qy,
			      NumT & Qy_err2,
			      NumT & Qz,
			      NumT & Qz_err2,
			      void *temp=NULL)
 {
    throw std::runtime_error("Function [init_scatt_wavevector_to_Q] not implemented");
 }
} // AxisManip
#endif
