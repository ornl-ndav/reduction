/**
 * $Id$
 *
 * \file axis_manip/inc/conversions.hpp
 */
#ifndef _CONVERSIONS_H
#define _CONVERSIONS_H 1

#include <string>
#include <vector>

/**
 * This sub-library contains the various physical axis conversions
 * that are useful for time-of-flight neutron scattering. Some
 * conversions are identical to those used in monochromatic neutron
 * scattering. None of the functions in this name space will reorder
 * the resulting axes so they are monotonically increasing.
 *
 * All of these functions are written in reference to SNS
 * 107030214-TD0001-R00, "Data Reduction Library Software Requirements
 * and Specifications."
 */
namespace AxisManip
{
  /**
   * \brief This function is described in section 3.15.
   *
   * This function converts the time-of-flight to wavelength according
   * to the equation
   * \f[
   * \lambda[i]=\frac{h TOF[i]}{m_n L}
   * \f]
   * Where \f$\lambda[i]\f$ is the wavelength, \f$h\f$ is Planck's
   * constant, \f$TOF[i]\f$ is the time-of-flight, \f$m_n\f$ is the
   * mass of the neutron, and \f$L\f$ is the total flight path of the
   * neutron.
   *
   * \param tof (INPUT) is the time-of-flight axis in units of
   * micro-seconds
   * \param tof_err2 (INPUT) is the square of the uncertainty in the
   * time-of-flight axis
   * \param pathlength (INPUT) is the total flight path of the neutron
   * in units of meter THERE SHOULD BE AN UNCERTAINTY WITH THIS AS
   * WELL.
   * \param wavelength (OUTPUT) is the wavelength axis in units of
   * angstrom
   * \param wavelength_err2 (OUTPUT) is the square of the uncertainty
   * in the wavelength axis
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    tof_to_wavelength(std::vector<NumT> const & tof,
		      std::vector<NumT> const & tof_err2,
		      const NumT pathlength,
		      std::vector<NumT> & wavelength,
		      std::vector<NumT> & wavelength_err2,
		      void *temp=NULL);

  /**
   * \brief This function is described in section 3.16.
   *
   * This function converts the wavelength to time-of-flight according
   * to the equation
   * \f[
   * TOF[i]=\frac{m_n L \lambda[i]}{h}
   * \f]
   * Where \f$TOF[i]\f$ is the time-of-flight, \f$m_n\f$ is the mass
   * of the neutron, \f$L\f$ is the total flight path of the neutron,
   * \f$\lambda\f$ is the wavelength, and \f$h\f$ is Planck's
   * constant.
   *
   * \param wavelength (INPUT) is the wavelength axis in units of
   * angstroms
   * \param wavelength_err2 (INPUT) is the square of the uncertainty
   * in the wavelength axis
   * \param pathlength (INPUT) is the total flight path of the neutron
   * in units of meter THERE SHOULD BE AN UNCERTAINTY WITH THIS AS
   * WELL.
   * \param tof (OUTPUT) is the time-of-flight axis in units of
   * micro-seconds
   * \param tof_err2 (OUTPUT) is the square of the uncertainty in the
   * time-of-flight axis
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    wavelength_to_tof(std::vector<NumT> const & wavelength,
		      std::vector<NumT> const & wavelength_err2,
		      const NumT pathlength,
		      std::vector<NumT> & tof,
		      std::vector<NumT> & tof_err2,
		      void *temp=NULL);

  /**
   * \brief This function is described in section 3.17.
   *
   * This function converts time-of-flight to scalar momentum transfer
   * according to the equation
   * \f[
   * Q[i]=\frac{4\pi m_n L \sin(polar)}{h TOF[i]}
   * \f]
   * Where \f$Q[i]\f$ is the scalar momentum transfer, \f$m_n\f$ is
   * the mass of the neutron, \f$L\f$ is the total flight path of the
   * neutron, \f$polar\f$ is the angle between the positive z-axis and
   * the direction of the scattered neutron, \f$h\f$ is Planck's
   * constant, and \f$TOF[i]\f$ is the time-of-flight.
   *
   * \param tof (INPUT) is the time-of-flight axis in units of
   * micro-seconds
   * \param tof_err2 (INPUT) is the square of the uncertainty in the
   * time-of-flight axis
   * \param pathlength (INPUT) is the total flight path of the neutron
   * in units of meter THERE SHOULD BE AN UNCERTAINTY WITH THIS AS
   * WELL.
   * \param polar (INPUT) is the polar angle in the equation above in
   * units of radians THERE SHOULD BE AN UNCERTAINTY WITH THIS AS
   * WELL.
   * \param Q (OUTPUT) is the scalar momentum transfer, Q, axis in
   * units of reciprocal angstroms
   * \param Q_err2 (OUTPUT) is the square of the uncertainty in the
   * scalar momentum transfer axis
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    tof_to_scalar_Q(std::vector<NumT> const & tof,
		    std::vector<NumT> const & tof_err2,
		    const NumT pathlength,
                    const NumT polar,
		    std::vector<NumT> & Q,
		    std::vector<NumT> & Q_err2,
		    void *temp=NULL);

  /**
   * \brief This function is described in section 3.18.
   *
   * This function converts the wavelength to scalar momentum transfer
   * according to the equation
   * \f[
   * Q[i]=\frac{4\pi}{\lambda[i]}\sin(polar)
   * \f]
   * Where \f$Q[i]\f$ is the scalar momentum transfer, \f$\lambda\f$
   * is the wavelength, and \f$polar\f$ is the angle between the
   * positive z-axis and the direction of the scattered neutron.
   *
   * \param wavelength (INPUT) is the wavelength axis in units of
   * angstroms
   * \param wavelength_err2 (INPUT) is the square of the uncertainty in the
   * wavelength axis
   * \param polar (INPUT) is the polar angle in the equation above in
   * units of radians THERE SHOULD BE AN UNCERTAINTY WITH THIS AS
   * WELL.
   * \param Q (OUTPUT) is the scalar momentum transfer, Q, axis in
   * units of reciprocal angstroms
   * \param Q_err2 (OUTPUT) is the square of the uncertainty in the
   * scalar momentum transfer axis
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    wavelength_to_scalar_Q(std::vector<NumT> const & wavelength,
			   std::vector<NumT> const & wavelength_err2,
			   const NumT polar,
			   std::vector<NumT> & Q,
			   std::vector<NumT> & Q_err2,
			   void *temp=NULL);
  
  /**
   * \brief This function is described in section 3.19.
   *
   * This function calculates the initial velocity of the neutron for
   * a direct geometry spectrometer according to the equation
   * \f[
   * v=\frac{L_d-L_u}{t_d-t_u}
   * \f]
   * Where \f$v\f$ is the initial velocity, \f$L_d\f$ is the distance
   * to the downstream monitor, \f$L_u\f$ is the distance to the
   * upstream monitor, \f$t_d\f$ is the time-of-flight to reach the
   * downstream monitor, and \f$t_u\f$ is the time-of-flight to reach
   * the upstream monitor.
   *
   * \param dist_upstream_mon (INPUT) is the distance to the upstream
   * monitor in units of meters THERE SHOULD BE AN UNCERTAINTY WITH
   * THIS AS WELL
   * \param time_upstream_mon (INPUT) is the time-of-flight to reach
   * the upstream monitor in units of micro-seconds THERE SHOULD BE AN
   * UNCERTAINTY WITH THIS AS WELL
   * \param dist_downstream_mon (INPUT) is the distance to the
   * downstream monitor in units of meters THERE SHOULD BE AN
   * UNCERTAINTY WITH THIS AS WELL
   * \param time_downstream_mon (INPUT) is the time-of-flight to reach
   * the downstream monitor in units of micro-seconds THERE SHOULD BE
   * AN UNCERTAINTY WITH THIS AS WELL
   * \param initial_velocity (OUTPUT) is the initial velocity of the
   * neutron in units of meter/mirco-seconds THERE SHOULD BE AN
   * UNCERTAINTY WITH THIS AS WELL
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    initial_velocity_dgs(const NumT dist_upstream_mon,
			 const NumT time_upstream_mon,
			 const NumT dist_downstream_mon,
			 const NumT time_downstream_mon,
			 NumT & initial_velocity,
			 void *temp=NULL);

  /**
   * \brief This function is described in section 3.20.
   *
   * This function calculates the final velocity of the neutron for an
   * inverse geometry spectrometer according to the equation.
   * \f[
   * v=\frac{h}{m_n \lambda_f}
   * \f]
   * Where \f$v\f$ is the final velocity of the neutron, \f$h\f$ is
   * Planck's constant, \f$m_n\f$ is the mass of the neutron, and
   * \f$\lambda_f\f$ is the wavelength reflected by the analyzer
   * crystal.
   *
   * \param analyzer_wavelength (INPUT) is the wavelength reflected by
   * the analyzer crystal in units of Angstroms THERE SHOULD BE AN
   * UNCERTAINTY WITH THIS AS WELL
   * \param final_velocity (OUTPUT) is the final velocity of the
   * neutron in units of meter/micro-seconds THERE SHOULD BE AN
   * UNCERTAINTY WITH THIS AS WELL
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    final_velocity_igs(const NumT analyzer_wavelength,
		       NumT & final_velocity,
		       void *temp=NULL);
 

  /**
   * \brief This function is described in section 3.21.
   *
   * This function calculates the energy of a neutron given its
   * velocity according to the equation
   * \f[
   * E[i]=\frac{1}{2}m_n v[i]^2
         = 5.227\times 10^{-6} \left( \frac{v[i]}{m/\mu s} \right)^2 meV
   * \f]
   * Where \f$E[i]\f$ is the energy of the neutron, \f$m_n\f$ is the
   * mass of the neutron, and \f$v[i]\f$ is the velocity of the
   * netron.
   *
   * \param velocity (INPUT) is the velocity of the neutron in units
   * of meter/micro-seconds
   * \param velocity_err2 (INPUT) is the square of the uncertainty in
   * the velocity of the neutron
   * \param energy (OUTPUT) is the energy of the neutron in units of
   * meV
   * \param energy_err2 (OUTPUT) is the square of the uncertainty in
   * the energy
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    velocity_to_energy(std::vector<NumT> const & velocity,
		       std::vector<NumT> const & velocity_err2,
		       std::vector<NumT> & energy,
		       std::vector<NumT> & energy_err2,
		       void *temp=NULL);

  /**
   * \brief This function is described in section 3.22.
   *
   * This function calculates the energy of a neutron given its
   * wavelength according to the equation
   * \f[
   * E[i]=\frac{h^2}{2 m_n \lambda[i]^2}
   *     =\frac{81.83 Angstrom^2}{\lambda[i]^2} meV
   * \f]
   * Where \f$E\f$ is energy of the neutron, \f$h\f$ is Planck's
   * constant, \f$m_n\f$ is the mass of the neutron, and \f$lambda\f$
   * is the wavelength of the neutron.
   *
   * \param wavelength (INPUT) is the wavelength axis in units of
   * angstroms
   * \param wavelength_err2 (INPUT) is the square of the uncertainty
   * in the wavelength axis
   * \param energy (OUTPUT) is the energy of the neutron in units of
   * meV
   * \param energy_err2 (OUTPUT) is the square of the uncertainty in
   * the energy
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    wavelength_to_energy(std::vector<NumT> const & wavelength,
			 std::vector<NumT> const & wavelength_err2,
			 std::vector<NumT> & energy,
			 std::vector<NumT> & energy_err2,
			 void *temp=NULL);

  /**
   * \brief This function is described in section 3.23.
   *
   * This function calculates the scalar wavevector given the velocity
   * according to the equation
   * \f[
   * k[i]=\frac{m_n}{h}v[i]
   * \f]
   * Where \f$k[i]\f$ is the scalar wavevector, \f$m_n\f$ is the mass
   * of the neutron, \f$h\f$ is Planck's constant, and \f$v[i]\f$ is
   * the velocity of the neutron.
   *
   * \param velocity (INPUT) is the velocity of the neutron in units
   * of meter/micro-seconds
   * \param velocity_err2 (INPUT) is the square of the uncertainty in
   * the velocity of the neutron
   * \param wavevector (OUTPUT) is the scalar wavevector in units of
   * reciprocal Angstroms
   * \param wavevector_err2 (OUTPUT) is the square of the uncertainty
   * in the scalar wavevector
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    velocity_to_scalar_k(std::vector<NumT> const & velocity,
			 std::vector<NumT> const & velocity_err2,
			 std::vector<NumT> & wavevector,
			 std::vector<NumT> & wavevector_err2,
			 void *temp=NULL);

  /**
   * \brief This function is described in section 3.24.
   *
   * This function calculates the scalar wavevector given the
   * wavelength accroding to the equation
   * \f[
   * k[i]=\frac{2\pi}{\lambda[i]}
   * \f]
   * Where \f$k[i]\f$ is the scalar wavevector, and \f$\lambda\f$ is
   * the wavelength.
   *
   * \param wavelength (INPUT) is the wavelength axis in units of
   * angstroms
   * \param wavelength_err2 (INPUT) is the square of the uncertainty
   * in the wavelength axis
   * \param wavevector (OUTPUT) is the scalar wavevector in units of
   * reciprocal Angstroms
   * \param wavevector_err2 (OUTPUT) is the square of the uncertainty
   * in the scalar wavevector
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    wavelength_to_scalar_k(std::vector<NumT> const & wavelength,
			   std::vector<NumT> const & wavelength_err2,
			   std::vector<NumT> & wavevector,
			   std::vector<NumT> & wavevector_err2,
			   void *temp=NULL);

  /**
   * \brief This function is described in section 3.25.
   *
   * This function calculates the d-spacing given the wavelength
   * according to the equation
   * \f[
   * d[i]=\frac{\lambda[i]}{2\sin(polar)}
   * \f]
   * Where \f$d\f$ is the d-spacing, \f$\lambda[i]\f$ is the
   * wavelength, and \f$polar\f$ is the angle between the z-axis and
   * the scattered neutron.
   *
   * \param wavelength (INPUT) is the wavelength axis in units of
   * angstroms
   * \param wavelength_err2 (INPUT) is the square of the uncertainty
   * in the wavelength axis
   * \param polar (INPUT) is the polar angle in the equation above in
   * units of radians THERE SHOULD BE AN UNCERTAINTY WITH THIS AS WELL
   * \param d_spacing (OUTPUT) is the d-spacing axis in units of
   * Angstrom
   * \param d_spacing_err2 (OUTPUT) is the square of the uncertainty
   * in the d-spacing axis
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    wavelength_to_d_spacing(std::vector<NumT> const & wavelength,
			    std::vector<NumT> const & wavelength_err2,
			    const NumT polar,
			    std::vector<NumT> & d_spacing,
			    std::vector<NumT> & d_spacing_err2,
			    void *temp=NULL);

  /**
   * \brief This function is described in section 3.26.
   *
   * This function calculates the time offset for a direct geometry
   * spectrometer according to the equation
   * \f[
   * t_0=t-\frac{L}{v}
   * \f]
   * Where \f$t_0\f$ is the time offset, \f$t\f$ is the time observed
   * at the downstream monitor, \f$L\f$ is the total flight path for
   * the downstream monitor, and \f$v\f$ is the velocity of the
   * incident neutrons.
   *
   * \param dist_downstream_monitor (INPUT) is the total flight path
   * for the downstream monitor in units of meter/second THERE SHOULD
   * BE AN UNCERTAINTY WITH THIS AS WELL
   * \param time_downstream_monitor (INPUT) is the time observed at
   * the downstream monitor in units of micro-seconds THERE SHOULD BE
   * AN UNCERTAINTY WITH THIS AS WELL
   * \param initial_velocity (INPUT) is the velocity of the incident
   * neutrons in unites of meter/seconds THERE SHOULD BE AN
   * UNCERTAINTY WITH THIS AS WELL
   * \param time_offset (OUTPUT) is the time offset of the neutron
   * emitting from the source assuming the velocity supplied in units
   * of micro-seconds THERE SHOULD BE AN UNCERTAINTY WITH THIS AS WELL
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    time_offset_dgs(const NumT dist_downstream_monitor,
		    const NumT time_downstream_monitor,
		    const NumT initial_velocity,
		    NumT & time_offset,
		    void *temp=NULL);

  /**
   * \brief This function is described in section 3.27.
   *
   * This function calculates the final velocity of the neutron for a
   * direct geometry spectrometer according to the equation
   * \f[
   * v_f[i]=\frac{L_D}{t[i]-\frac{L_S}{v_i}-t_0}
   * \f]
   * Where \f$v_f[i]\f$ is the final velocity of the neutron,
   * \f$L_D\f$ is the distance from the sample to the detector,
   * \f$t[i]\f$ is the total time-of-flight, \f$L_S\f$ is the distance
   * from source to sample, \f$v_i\f$ is the initial velocity of the
   * neutron, and \f$t_0\f$ is the time-offset of the neutron.
   *
   * \param tof (INPUT) is the time-of-flight axis in units of
   * micro-seconds
   * \param tof_err2 (INPUT) is the square of the uncertainty in the
   * time-of-flight axis
   * \param initial_velocity (INPUT) is the initial velocity of the
   * neutron in units of meter/mirco-seconds THERE SHOULD BE AN
   * UNCERTAINTY WITH THIS AS WELL
   * \param time_offset (INPUT) is the time offset of the neutron
   * emitting from the source assuming the velocity supplied in units
   * of micro-seconds THERE SHOULD BE AN UNCERTAINTY WITH THIS AS WELL
   * \param dist_source_sample (INPUT) is the distance from source to
   * sample in units of meter THERE SHOULD BE AN UNCERTAINTY WITH THIS
   * AS WELL
   * \param dist_sample_detector (INPUT) is the distance from sample
   * to detector in units of meter THERE SHOULD BE AN UNCERTAINTY WITH
   * THIS AS WELL
   * \param final_velocity (OUTPUT) is the final velocity axis of the
   * neutron in units of meter/second
   * \param final_velocity_err2 (OUTPUT) is the square of the
   * uncertainty in the final velocity axis
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
 template <typename NumT>
   std::string
   tof_to_final_velocity_dgs(std::vector<NumT> const & tof,
			     std::vector<NumT> const & tof_err2,
			     const NumT initial_velocity,
			     const NumT time_offset,
			     const NumT dist_source_sample,
			     const NumT dist_sample_detector,
			     std::vector<NumT> & final_velocity,
			     std::vector<NumT> & final_velocity_err2,
			     void *temp=NULL);

  /**
   * \brief This function is described in section 3.28.
   *
   * This function calculates the initial velocity of an indirect
   * geometry spectromer according to the equation
   * \f[
   * v_i[i]=\frac{L_S}{t[i]-\frac{L_D}{v_f}-t_0}
   * \f]
   * Where \f$v_i[i]\f$ is the initial velocity of the neutron,
   * \f$L_S\f$ is the distance from the source to the sample,
   * \f$t[i]\f$ is the total time-of-flight, \f$L_D\f$ is the distance
   * from the sample to the detector, \f$v_f\f$ is the final velocity
   * of the neutron, and \f$t_0\f$ is the time-offset of the neutron.
   *
   * \param tof (INPUT) is the time-of-flight axis in units of
   * micro-seconds
   * \param tof_err2 (INPUT) is the square of the uncertainty in the
   * time-of-flight axis
   * \param final_velocity (INPUT) is the final velocity of the
   * neutron in units of meter/mirco-seconds THERE SHOULD BE AN
   * UNCERTAINTY WITH THIS AS WELL
   * \param time_offset (INPUT) is the time offset of the neutron
   * emitting from the source assuming the velocity supplied in units
   * of micro-seconds THERE SHOULD BE AN UNCERTAINTY WITH THIS AS WELL
   * \param dist_source_sample (INPUT) is the distance from source to
   * sample in units of meter THERE SHOULD BE AN UNCERTAINTY WITH THIS
   * AS WELL
   * \param dist_sample_detector (INPUT) is the distance from sample
   * to detector in units of meter THERE SHOULD BE AN UNCERTAINTY WITH
   * THIS AS WELL
   * \param initial_velocity (OUTPUT) is the initial velocity axis of
   * the neutron in units of meter/second
   * \param initial_velocity_err2 (OUTPUT) is the square of the
   * uncertainty in the initial velocity axis
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
 template <typename NumT>
   std::string
   tof_to_initial_velocity_igs(std::vector<NumT> const & tof,
			       std::vector<NumT> const & tof_err2,
			       const NumT final_velocity,
			       const NumT time_offset,
			       const NumT dist_source_sample,
			       const NumT dist_sample_detector,
			       std::vector<NumT> & initial_velocity,
			       std::vector<NumT> & initial_velocity_err2,
			       void *temp=NULL);

  /**
   * \brief This function is described in section 3.29.
   *
   * This function calculates the initial wavelength for an inverse
   * geometry spectromer according to the equation
   * \f[
   * \lambda_i[i]=\frac{h}{m_n L_S}
   *              \left(t[i]-\frac{m_n \lambda_f L_D}{h} -t_0 \right)
   * \f]
   * Where \f$\lambda_i[i]\f$ is the incident wavelength, \f$h\f$ is
   * Planck's constant, \f$m_n\f$ is the mass of the neutron,
   * \f$L_S\f$ is the distance from the source to the sample,
   * \f$t[i]\f$ is the total time-of-flight, \f$\lambda_f\f$ is the
   * final wavelength, \f$L_D\f$ is the distance from the sample to
   * the detector, and \f$t_0\f$ is the time offset.
   *
   * \param tof (INPUT) is the time-of-flight axis in units of
   * micro-seconds
   * \param tof_err2 (INPUT) is the square of the uncertainty in the
   * time-of-flight axis
   * \param final_wavelength (INPUT) is the final wavelength of the
   * neutron in units of Angstroms THERE SHOULD BE AN UNCERTAINTY WITH
   * THIS AS WELL
   * \param time_offset (INPUT) is the time offset of the neutron
   * emitting from the source assuming the velocity supplied in units
   * of micro-seconds THERE SHOULD BE AN UNCERTAINTY WITH THIS AS WELL
   * \param dist_source_sample (INPUT) is the distance from source to
   * sample in units of meter THERE SHOULD BE AN UNCERTAINTY WITH THIS
   * AS WELL
   * \param dist_sample_detector (INPUT) is the distance from sample
   * to detector in units of meter THERE SHOULD BE AN UNCERTAINTY WITH
   * THIS AS WELL
   * \param initial_wavelength (OUTPUT) is the initial wavelength axis
   * in units of Anstrom
   * \param initial_wavelength_err2 (OUTPUT) is the square of the
   * uncertainty of the initial wavelength axis
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
 template <typename NumT>
   std::string
   tof_to_initial_wavelength_igs(std::vector<NumT> const & tof,
				 std::vector<NumT> const & tof_err2,
				 const NumT final_wavelength,
				 const NumT time_offset,
				 const NumT dist_source_sample,
				 const NumT dist_sample_detector,
				 std::vector<NumT> & initial_wavelength,
				 std::vector<NumT> & initial_wavelength_err2,
				 void *temp=NULL);

  /**
   * \brief This function is described in section 3.30.
   *
   * This function calculates the energy transfer according to the
   * equation
   * \f[
   * \nu=\frac{E_i-E_f}{h}=\frac{E_i-E_f}{4.1357}\frac{THz}{meV}
   * \f]
   * Where \f$\nu\f$ is the energy transfer, \f$E_i\f$ is the incident
   * energy, and \f$E_f\f$ is the final energy.
   *
   * \param initial_energy (INPUT) is the incident energy axis in
   * units of meV
   * \param initial_energy_err2 (INPUT) is the square of the
   * uncertainty of the incident energy axis
   * \param final_energy (INPUT) is the final energy axis in units of
   * meV
   * \param final_energy_err2 (INPUT) is the square of the uncertainty
   * of the final energy axis
   * \param energy_transfer (OUTPUT) is the energy transfer axis in
   * units of THz
   * \param energy_transfer_err2 (OUTPUT) is the square of the
   * uncertainty in the energy transfer axis
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    energy_transfer(std::vector<NumT> const & initial_energy,
		    std::vector<NumT> const & initial_energy_err2,
		    std::vector<NumT> const & final_energy,
		    std::vector<NumT> const & final_energy_err2,
		    std::vector<NumT> & energy_transfer,
		    std::vector<NumT> & energy_transfer_err2,
		    void *temp=NULL);

  /**
   * \brief This function is described in section 3.31.
   *
   * This function calculates the angular frequency according to the
   * equation
   * \f[
   * \omega[i]=2\pi\nu[i] \times 10^{12}
   * \f]
   * Where \f$\omega[i]\f$ is the angular frequency, and \f$\nu[i]\f$
   * is the frequency.
   *
   * \param frequency (INPUT) is the frequency axis in units of THz
   * \param frequency_err2 (INPUT) is the square of the uncertainty in
   * the frequency axis
   * \param angular_frequency (OUTPUT) is the angular frequency axis
   * in units of rad/second
   * \param angular_frequency_err2 (OUTPUT) is the square of the
   * uncertainty in the angular frequency axis
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    frequency_to_angular_frequency(std::vector<NumT> const & frequency,
				   std::vector<NumT> const & frequency_err2,
				   std::vector<NumT> & angular_frequency,
				   std::vector<NumT> & angular_frequency_err2,
				   void *temp=NULL);

  /**
   * \brief This function is described in section 3.32.
   *
   * This function calculates the momentum transfrom from the incident
   * and scattered wavevectors according to the equations
   * \f[
   * Q_x=-k_f\cos(azimuthal)\sin(polar)
   * \f]
   * \f[
   * Q_y=-k_f\sin(azimuthal)\sin(polar)
   * \f]
   * \f[
   * Q_z=k_i-k_f\cos(polar)
   * \f]
   * Where \f$k_i\f$ is the incident wavevector, \f$k_f\f$ is the
   * scattered wavevector, \f$Q_x\f$ is the x-component of the
   * momentum transfer, \f$Q_y\f$ is the y-component of the momentum
   * transfer, \f$Q_z\f$ is the z-component of the momentum transfer,
   * \f$azimuthal\f$ is the angle between the x-axis and the scattered
   * neturon, and \f$polar\f$ is the angle between the z-axis and the
   * scattered neutron.
   *
   * \param initial_wavevector (INPUT) is the incident wavevector axis
   * in units of reciprocal Angstroms
   * \param initial_wavevector_err2 (INPUT) is the square of the
   * uncertainty of the incident wavevector axis
   * \param final_wavevector (INPUT) is the final wavevector axis in
   * units of reciprocal Angstroms
   * \param final_wavevector_err2 (INPUT) is the square of the
   * uncertainty of the final wavevector axis
   * \param azimuthal (INPUT) is the azimuthal angle in the equation
   * above in units of radians THERE SHOULD BE AN UNCERTAINTY WITH
   * THIS AS WELL.
   * \param polar (INPUT) is the polar angle in the equation above in
   * units of radians THERE SHOULD BE AN UNCERTAINTY WITH THIS AS
   * WELL.
   * \param Qx (OUTPUT) is the x-component of the momentum transfer,
   * \f$Q_x\f$, axis in units of reciprocal angstroms
   * \param Qx_err2 (OUTPUT) is the square of the uncertainty in the
   * x-component of the momentum transfer axis
   * \param Qy (OUTPUT) is the y-component of the momentum transfer,
   * \f$Q_y\f$, axis in units of reciprocal angstroms
   * \param Qy_err2 (OUTPUT) is the square of the uncertainty in the
   * y-component of the momentum transfer axis
   * \param Qz (OUTPUT) is the y-component of the momentum transfer,
   * \f$Q_y\f$, axis in units of reciprocal angstroms
   * \param Qz_err2 (OUTPUT) is the square of the uncertainty in the
   * y-component of the momentum transfer axis
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
   std::string
   init_scatt_wavevector_to_Q(std::vector<NumT> const & initial_wavevector,
			      std::vector<NumT> const & initial_wavevector_err2,
			      std::vector<NumT> const & final_wavevector,
			      std::vector<NumT> const & final_wavevector_err2,
			      const NumT azimuthal,
			      const NumT polar,
			      std::vector<NumT> & Qx,
			      std::vector<NumT> & Qx_err2,
			      std::vector<NumT> & Qy,
			      std::vector<NumT> & Qy_err2,
			      std::vector<NumT> & Qz,
			      std::vector<NumT> & Qz_err2,
			      void *temp=NULL);

  /**
   * \brief This function is described in section 3.33.
   *
   * This function calculates the scalar momentum transfer from the
   * incident and scattered wavevectors according to the equation
   * \f[
   * Q=\sqrt{k_i^2+k_f^2-2k_ik_f\cos(polar)}
   * \f]
   * Where \f$Q\f$ is the scalar momentum transfer, \f$k_i\f$ is the
   * incident wavevector, \f$k_f\f$ is the final wavevector, and
   * \f$polar\f$ is the angle between the z-axis and the scattered
   * neutron.
   *
   * \param initial_wavevector (INPUT) is the incident wavevector axis
   * in units of reciprocal Angstroms

   * \param initial_wavevector_err2 (INPUT) is the square of the
   * uncertainty of the incident wavevector axis

   * \param final_wavevector (INPUT) is the final wavevector axis in
   * units of reciprocal Angstroms

   * \param final_wavevector_err2 (INPUT) is the square of the
   * uncertainty of the final wavevector axis

   * \param polar (INPUT) is the polar angle in the equation above in
   * units of radians THERE SHOULD BE AN UNCERTAINTY WITH THIS AS
   * WELL.

   * \param Q (OUTPUT) is the scalar momentum transfer, Q, axis in
   * units of reciprocal angstroms

   * \param Q_err2 (OUTPUT) is the square of the uncertainty in the
   * scalar momentum transfer axis
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    init_scatt_wavevector_to_scalar_Q(std::vector<NumT> const & initial_wavevector,
				      std::vector<NumT> const & initial_wavevector_err2,
				      std::vector<NumT> const & final_wavevector,
				      std::vector<NumT> const & final_wavevector_err2,
				      const NumT polar,
				      std::vector<NumT> & Q,
				      std::vector<NumT> & Q_err2,
				      void *temp=NULL);
  
  /**
   * \brief This function is described in section 3.34.
   *
   * This function converts the time-of-flight to momentum
   * transfer. This is done in two steps. First by calculating the
   * sclar momentum transfer according to the equation
   * \f[
   * Q[i]=\frac{4\pi m_n L \sin(polar)}{h TOF[i]}
   * \f]
   * Where \f$Q[i]\f$ is the scalar momentum transfer, \f$m_n\f$ is
   * the mass of the neutron, \f$L\f$ is the total flight path,
   * \f$polar\f$ is the angle between the z-axis and the scattered
   * neutron, \f$h\f$ is Planck's constant, and \f$TOF[i]\f$ is the
   * time-of-flight.
   *
   * The three components of the momentum transfer are described by
   * the equations
   * \f[
   * Q_x=-Q\cos(azimuthal)\sin(polar)
   * \f]
   * \f[
   * Q_y=-Q\sin(azimuthal)\sin(polar)
   * \f]
   * \f[
   * Q_z=Q(1-\cos(polar))
   * \f]
   * Where \f$Q_x\f$ is the x-component of the momentum transfer,
   * \f$Q_y\f$ is the y-component of the momentum transfer, \f$Q_z\f$
   * is the z-component of the momentum transfer, \f$azimuthal\f$ is
   * the angle between the x-axis and the scattered neutron, and
   * \f$polar\f$ is the angle between the z-axis and the scattered
   * neutron.
   *
   * \param tof (INPUT) is the time-of-flight axis in units of
   * micro-seconds
   * \param tof_err2 (INPUT) is the square of the uncertainty in the
   * time-of-flight axis
   * \param pathlength (INPUT) is the total flight path of the neutron
   * in units of meter THERE SHOULD BE AN UNCERTAINTY WITH THIS AS
   * WELL.
   * \param azimuthal (INPUT) is the azimuthal angle in the equation
   * above in units of radians THERE SHOULD BE AN UNCERTAINTY WITH
   * THIS AS WELL.
   * \param polar (INPUT) is the polar angle in the equation above in units of
   * radians THERE SHOULD BE AN UNCERTAINTY WITH THIS AS WELL.
   * \param Qx (OUTPUT) is the x-component of the momentum transfer,
   * \f$Q_x\f$, axis in units of reciprocal angstroms
   * \param Qx_err2 (OUTPUT) is the square of the uncertainty in the
   * x-component of the momentum transfer axis
   * \param Qy (OUTPUT) is the y-component of the momentum transfer,
   * \f$Q_y\f$, axis in units of reciprocal angstroms
   * \param Qy_err2 (OUTPUT) is the square of the uncertainty in the
   * y-component of the momentum transfer axis
   * \param Qz (OUTPUT) is the z-component of the momentum transfer,
   * \f$Q_y\f$, axis in units of reciprocal angstroms
   * \param Qz_err2 (OUTPUT) is the square of the uncertainty in the
   * z-component of the momentum transfer axis
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    tof_to_Q(std::vector<NumT> const & tof,
	     std::vector<NumT> const & tof_err2,
	     const NumT pathlength,
	     const NumT azimuthal,
	     const NumT polar,
	     std::vector<NumT> & Qx,
	     std::vector<NumT> & Qx_err2,
	     std::vector<NumT> & Qy,
	     std::vector<NumT> & Qy_err2,
	     std::vector<NumT> & Qz,
	     std::vector<NumT> & Qz_err2,
	     void *temp=NULL);

  /**
   * \brief This function is described in section  3.39.
   *
   * This function converts the d-spacing to time-of-flight at a
   * focused detector position according to the equation
   * \f[
   * TOF[i]=\frac{4\pi m_n}{h} L_{focused} d[i] \sin(polar_{focused})
   * \f]
   * Where \f$TOF[i]\f$ is the time-of-flight, \f$m_n\f$ is the mass
   * of the neutron, \f$h\f$ is Planck's constant, \f$L_{focused}\f$
   * is the focused total flight path, \f$d[i]\f$ is the d-spacing,
   * and \f$polar_{focused}\f$ is the angle between the z-axis and the
   * focused scattered neutron.
   *
   * \param d_spacing (INPUT) is the d-spacing axis in units of
   * Angstrom
   * \param d_spacing_err2 (INPUT) is the square of the uncertainty in
   * the d-spacing axis
   * \param pathlength_focused (INPUT) is the total flight path of the
   * focused neutron in units of meter THERE SHOULD BE AN UNCERTAINTY
   * WITH THIS AS WELL.
   * \param polar_focused (INPUT) is the polar angle of the focused
   * neutron in the equation above in units of radians THERE SHOULD BE
   * AN UNCERTAINTY WITH THIS AS WELL.
   * \param tof (OUTPUT) is the time-of-flight axis in units of
   * micro-seconds
   * \param tof_err2 (OUTPUT) is the square of the uncertainty in the
   * time-of-flight axis
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    d_spacing_to_tof_focused_det(std::vector<NumT> const & d_spacing,
				 std::vector<NumT> const & d_spacing_err2,
				 const NumT pathlength_focused,
				 const NumT polar_focused,
				 std::vector<NumT> & tof,
				 std::vector<NumT> & tof_err2,
				 void *temp=NULL);
  

} // AxisManip

#endif // _CONVERSIONS_H
