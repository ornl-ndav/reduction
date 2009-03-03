#
#                     SNS Common Libraries
#           A part of the SNS Analysis Software Suite.
#
#                  Spallation Neutron Source
#          Oak Ridge National Laboratory, Oak Ridge TN.
#
#
#                             NOTICE
#
# For this software and its associated documentation, permission is granted
# to reproduce, prepare derivative works, and distribute copies to the public
# for any purpose and without fee.
#
# This material was prepared as an account of work sponsored by an agency of
# the United States Government.  Neither the United States Government nor the
# United States Department of Energy, nor any of their employees, makes any
# warranty, express or implied, or assumes any legal liability or
# responsibility for the accuracy, completeness, or usefulness of any
# information, apparatus, product, or process disclosed, or represents that
# its use would not infringe privately owned rights.
#
#

# $Id$

##
# \file bindings/axis_manip.py

"""
   This module gives the NessiList access to the various physical axis
   conversions that are useful for time-on-flight neutron scattering which
   are found in the C++ axis_manip library. All of the bases functions are
   written in reference to SNS 107030214-TD0001-R00, \"Data Reduction Library
   Software Requirements and Specifications\".

   Once a function is called, according to the type of the NessiList calling
   it, the module redirectes the call to the right function
"""

import nessi_list
import axis_manip_bind
import vpair_bind

from scl_defs import VERSION as __version__

##
# \namespace axis_manip
#
# \brief Python abstraction layer for access to AxisManip library functions
#
# This module gives the NessiList access to the various physical axis
# conversions that are useful for time-on-flight neutron scattering. All of
# the bases functions are written in reference to SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# Once a function is called, according to the type of the NessiList calling
# it,the module redirectes the call to the right function
#
# For example, when calling the function \f$energy\_transfer\f$ with 4
# NessiList of type <i>float</i>, the module redirects the call to the
# function \f$energy\_transfer\_f\f$.
#

##
# \defgroup d_spacing_to_tof_focused_det \
# axis_manip::d_spacing_to_tof_focused_det
# \{

##
# \brief This function is described in section  3.39.
#
# This function converts the d-spacing to time-of-flight at a
# focused detector position according to the equation
# \f[
# TOF[i]=\frac{2\ m_n}{h} L_{focused} d[i] \sin(polar_{focused}/2)
# \f]
# Where \f$TOF[i]\f$ is the time-of-flight, \f$m_n\f$ is the mass
# of the neutron, \f$h\f$ is Planck's constant, \f$L_{focused}\f$
# is the focused total flight path, \f$d[i]\f$ is the d-spacing,
# and \f$polar_{focused}\f$ is the angle between the z-axis and the
# focused scattered neutron. The uncertainty is calculated using
# the assumption of uncorrelated uncertainties.
#
# \f[
# \sigma^2_{TOF}[i] = \left(\frac{m_n}{h}\right)^2 \times 
# \left((2 d[i] \sin(polar_{focused}/2))^2 \sigma^2_{L_{focused}} + 
# (2 L_{focused} \sin(polar_{focused}/2))^2 \sigma^2_d[i] + 
# (L_{focused} d[i] \cos(polar_{focused}/2))^2 \sigma^2_{polar_{focused}}
# \right)
# \f]
#
# \param d_spacing (INPUT) is the d-spacing axis in units of
# Angstrom
# \param d_spacing_err2 (INPUT) is the square of the uncertainty in
# the d-spacing axis
# \param pathlength_focused (INPUT) is the total flight path of the
# focused neutron in units of meter
# \param pathlength_focused_err2 (INPUT) is the square of the
# uncertainty in pathlength_focused
# \param polar_focused (INPUT) is the polar angle of the focused
# neutron in the equation above in units of radians
# \param polar_focused_err2 (INPUT) is the square of the
# uncertainty in polar_focused
#
# \return
# - The time-of-flight axis in units of micro-seconds
# - The square of the uncertainty in the time-of-flight axis
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the lists are not
# recognized types

def d_spacing_to_tof_focused_det(d_spacing, d_spacing_err2,
                                 pathlength_focused,
                                 pathlength_focused_err2,
                                 polar_focused,
                                 polar_focused_err2):

    """
    This function converts the d-spacing to time-of-flight at a
    focused detector position according to the equation
    
    TOF[i] = 2 m_n L_focused d[i] sin(polar_focused / 2) / h
 
    Where TOF[i] is the time-of-flight, m_n is the mass of the neutron,
    h is Planck's constant, L_focused is the focused total flight path,
    d[i] is the d-spacing, and polar_focused is the angle between the
    z-axis and the focused scattered neutron. The uncertainty is
    calculated using the assumption of uncorrelated uncertainties.

    TOF_err2[i] = (m_n / h)^2 x ((2 d[i] sin(polar_focused / 2))^2 x
    L_focused_err2 + (2 L_focused sin(polar_focused / 2))^2 x d_err2[i] + 
    (L_focused d[i] cos(polar_focused / 2))^2 x polar_focused_err2)

    
    Parameters:
    __________
    
    -> d_spacing is the d-spacing axis in units of Angstrom
    -> d_spacing_err2 is the square of the uncertainty in the d-spacing axis
    -> pathlength_focused is the total flight path of the focused neutron
    in units of meter
    -> pathlength_focused_err2 is the square of the uncertainty in
    pathlength_focused
    -> polar_focused is the polar angle of the focused neutron in the
    equation above in units of radians
    -> polar_focused_err2 is the square of the uncertainty in polar_focused
    
    Returns - 2 NessiLists:
    ________________________

    <- The time-of-flight axis in units of micro-seconds
    <- The square of the uncertainty in the time-of-flight axis
    
    Exceptions:
    __________
    
    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the lists are not recognized types
    """

    try:
        if d_spacing.__type__ != d_spacing_err2.__type__:
            raise TypeError("D-Spacing and D-Spacing Err2 arrays are not " \
                            +"the same type")

        if (d_spacing.__type__ == nessi_list.NessiList.DOUBLE):
            tof = nessi_list.NessiList(len(d_spacing))
            tof_err2 = nessi_list.NessiList(len(d_spacing))
            axis_manip_bind.d_spacing_to_tof_focused_det_d(\
                d_spacing.__array__,\
                d_spacing_err2.__array__,\
                float(pathlength_focused),\
                float(pathlength_focused_err2),\
                float(polar_focused),\
                float(polar_focused_err2),\
                tof.__array__,\
                tof_err2.__array__)

        else:
            raise TypeError("Unknown primative type %s" \
                            % str(d_spacing.__type__))

        return (tof, tof_err2)

    except AttributeError:
        tof_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.d_spacing_to_tof_focused_det_ss_d(\
            float(d_spacing),\
            float(d_spacing_err2),\
            float(pathlength_focused),\
            float(pathlength_focused_err2),\
            float(polar_focused),\
            float(polar_focused_err2),\
            tof_ss)
        return (tof_ss.val, tof_ss.val_err2)

##
# \}

##
# \defgroup energy_to_wavelength axis_manip::energy_to_wavelength
# \{
#

##
# \brief This function is described in section 3.51.
#
# This function calculates the wavelength of a neutron given its
# energy according to the equation
# \f[
# \lambda[i]=\sqrt{\frac{h^2}{2 m_n E[i]}}
# \f]
# where \f$\lambda[i]\f$ is the wavelength of the neutron, \f$h\f$ is 
# Planck's constant, \f$m_n\f$ is the mass of the neutron and \f$E[i]\f$ is 
# energy of the neutron.
#
# Assuming that the uncertainties are uncorrelated, the uncertainty
# in the wavelength is defined by
# \f[
# \sigma^2_{\lambda}[i]=\left(\frac{\lambda[i]}{2E[i]}\right)^2\sigma^2_E[i]
# \f]
# where \f$\sigma_{\lambda}[i]\f$ is the uncertainty in the wavelength axis 
# and \f$\sigma_E[i]\f$ is the uncertainty in the energy.
#
# \param energy (INPUT) is the energy of the neutron in units of meV
# \param energy_err2 (INPUT) is the square of the uncertainty in the energy
# axis
#
# \return 
# - The wavelength axis in units of Angstroms
# - The square of the uncertainty in the wavelength axis
#
# \exception IndexError is thrown if the arrays are not of compatible sizes
# \exception TypeError is thrown if any of the lists are not recognized types
#

def energy_to_wavelength(energy, energy_err2):
    
    """
    ---------------------------------------------------------------------------

    This function calculates the wavelength of a neutron given its
    energy according to the equation:

    lambda[i] = sqrt((h^2)/(2.m_n.E[i]))

    where lambda is the wavelength of the neutron, h is Planck's constant,
    m_n is the mass of the neutron and E is the energy of the neutron.

    Assuming that the uncertainties are uncorrelated, the uncertainty in the
    wavelength is defined by:

    lambda_err2[i]^2 = (lambda[i]/2.E[i])^2.E_err2[i]^2

    where lambda_err2 is the uncertainty in the wavelength axis and E_err2 is
    the uncertainty in the energy.

    Parameters:
    __________
    -> energy is the energy axis in units of Angstroms
    -> energy_err2 is the square of the uncertainty in the energy
       axis

    Returns 2 NessiLists:
    ______________________
    <- the wavelength of the neutron in units of Angstroms
    <- the square of the uncertainty in the wavelength

    Exceptions:
    __________
    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types

    """
    try:
        if energy.__type__ != energy_err2.__type__:
            raise TypeError("Energy and Energy Err2 arrays are not " \
                            +"the same type")

        if (energy.__type__ == nessi_list.NessiList.DOUBLE):
            wavelength = nessi_list.NessiList(len(energy))
            wavelength_err2 = nessi_list.NessiList(len(energy))
            axis_manip_bind.energy_to_wavelength_d(energy.__array__, \
                                                   energy_err2.__array__,\
                                                   wavelength.__array__,\
                                                   wavelength_err2.__array__)
        else:
            raise TypeError("Unknown primitive type %s" % \
                            str(energy.__type__))

        return (wavelength, wavelength_err2)

    except AttributeError:
        wavelength_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.energy_to_wavelength_ss_d(\
      float(energy),\
      float(energy_err2),\
      wavelength_ss)
        return (wavelength_ss.val, wavelength_ss.val_err2)

##
# \}

##
# \defgroup energy_transfer axis_manip::energy_transfer
# \{

##
# \brief This function calculates the energy transfer and its uncertainty.
#
# This function is described  in section 3.30 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function calculates the energy transfer according to the equation
# \f[
# \nu[i]=\frac{E_i[i]-E_f[i]}{h}=\frac{E_i[i]-E_f[i]}{4.1357}\frac{THz}{meV}
# \f]
# Where \f$\nu\f$ is the energy transfer, \f$E_i\f$ is the incident
# energy, and \f$E_f\f$ is the final energy.
# Using the assumption of uncorrelated uncertainties, the square of
# the uncertainty of the energy transfer is given by
# \f[
# \sigma^2_\nu [i]=\frac{\sigma^2_{E_i}[i] +\sigma^2_{E_f}[i]}{h^2}
# \f]
# Where \f$\sigma_{E_i} \f$ is the uncertainty of the incident
# energy axis, and \f$\sigma_{E_f} \f$ is the uncertainty of the
# final energy axis.
#
# \param initial_energy (INPUT) is the incident energy axis in units of meV
# \param initial_energy_err2 (INPUT) is the square of the uncertainty of the
# incident energy axis
# \param final_energy (INPUT) is the final energy axis in units of meV
# \param final_energy_err2 (INPUT) is the square of the uncertainty of the
# final energy axis
# \return
# - The energy transfer axis in units of THz.
# - The square of the uncertainty in the energy tranfser axis.
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the lists are not
# recognized types

def energy_transfer(initial_energy, initial_energy_err2, 
                    final_energy, final_energy_err2):
    """
    ---------------------------------------------------------------------------

    This function calculates the energy transfer according to the equation:

    nu[i]=(E_i - E_f)/h = (E_i - E_f)/4.1357 * THz/meV

    where, nu is the energy transfer, E_i is the incident energy, E_f is
    the final energy.

    Using the assumption of uncorrelated uncertainties, the square of the
    uncertainty of the energy transfer is given by:

    nu_err2[i]^2 = (E_i_err2[i]^2 + E_f_err2[i]^2)/h^2

    where E_i_err2 is the uncertainty of the incident energy axis, and
    E_f_err2 is the uncertainty of the final energy axis.

    Parameters:
    __________

    -> initial_energy is the incident energy axis in units of meV
    -> initial_energy_err2 is the square of the uncertainty of the incident
       energy axis
    -> final_energy is the final energy axis in units of meV
    -> final_energy_err2 is the square of the uncertainty of the final energy
       axis

    Returns - 2 NessiLists:
    ________________________

    <- the energy transfer axis in units of THz
    <- the square of the uncertainty in the energy transfer axis

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the lists are not
       recognized types
    """

    try:
        if initial_energy.__type__ != final_energy.__type__:
            raise TypeError("Initial Energy and Final Energy array types " \
                            +"are not the same.")

        if initial_energy.__type__ != initial_energy_err2.__type__:
            raise TypeError("Initial Energy and Initial Energy Err2 array " \
                            +"types are not the same.")

        if (initial_energy.__type__ == nessi_list.NessiList.DOUBLE):
            e_transfer = nessi_list.NessiList(len(initial_energy))
            e_transfer_err2 = nessi_list.NessiList(len(initial_energy))
            axis_manip_bind.energy_transfer_d(\
                            initial_energy.__array__,\
                            initial_energy_err2.__array__,\
                            final_energy.__array__,\
                            final_energy_err2.__array__,\
                            e_transfer.__array__,\
                            e_transfer_err2.__array__)
        else:
            raise TypeError("Unknown primitive type %s" % \
                            str(initial_energy.__type__))

        return (e_transfer, e_transfer_err2)

    except AttributeError:
        try:
            initial_energy.__type__
            array = initial_energy
            array_err2 = initial_energy_err2
            scalar = final_energy
            scalar_err2 = final_energy_err2
            
            if(array.__type__ == array.DOUBLE):
                e_transfer = nessi_list.NessiList(len(array))
                e_transfer_err2 = nessi_list.NessiList(len(array))
                axis_manip_bind.energy_transfer_d(\
                        array.__array__,\
                        array_err2.__array__,\
                        float(scalar),\
                        float(scalar_err2),\
                        e_transfer.__array__,\
                        e_transfer_err2.__array__)
                
            else:
                raise TypeError("Unknown primative type %s" \
                                % str(array.__type__))

            return (e_transfer, e_transfer_err2)

        except AttributeError:
            try:
                final_energy.__type__
                array = final_energy
                array_err2 = final_energy_err2
                scalar = initial_energy
                scalar_err2 = initial_energy_err2
                
                if (array.__type__ == nessi_list.NessiList.DOUBLE):
                    e_transfer = nessi_list.NessiList(len(array))
                    e_transfer_err2 = nessi_list.NessiList(len(array))
                    axis_manip_bind.energy_transfer_d(\
                        float(scalar),\
                        float(scalar_err2),\
                        array.__array__,\
                        array_err2.__array__,\
                        e_transfer.__array__,\
                        e_transfer_err2.__array__)
                else:
                    raise TypeError("Unknown primative type %s" \
                                    % str(array.__type__))

                return (e_transfer, e_transfer_err2)

            except AttributeError:
                e_transfer_ss = vpair_bind.DoubleVPair()
                axis_manip_bind.energy_transfer_ss_d(\
                    float(initial_energy), \
                    float(initial_energy_err2),\
                    float(final_energy),\
                    float(final_energy_err2),\
                    e_transfer_ss)
                
                return (e_transfer_ss.val, e_transfer_ss.val_err2)
##
# \}


##
# \defgroup frequency_to_angular_frequency \
# axis_manip::frequency_to_angular_frequency
# \{

##
# \brief This function is described in section 3.31.
#
# This function calculates the angular frequency according to the equation
# \f[
# \omega[i] = 2\pi\nu[i] \times 10^{12}
# \f]
# Where \f$\omega[i]\f$ is the angular frequency, and \f$\nu[i]\f$
# is the frequency. The uncertainty is calculated using the
# assumption of uncorrelated uncertainties.
#
# \f[
# \sigma^2_{\omega}[i] = 4 \pi^2 \times 10^{24} \sigma^2_{\nu}[i]
# \f]
#
# \param frequency (INPUT) is the frequency axis in units of THz
# \param frequency_err2 (INPUT) is the square of the uncertainty in
# the frequency axis
#
# \return
# -The angular_frequency is the angular frequency axis in units of rad/second
# -The angular_frequency_err2 is the square of the uncertainty in the angular
# frequency axis
#
# \exception IndexError is thrown if the arrays are not of compatible sizes
# \exception TypeError is thrown if any of the lists are not recognized types
   
def frequency_to_angular_frequency(frequency, frequency_err2):

    """
    This function takes a histogram data set that has the principle axis in
    units of THz and converts it to rad/second according to the equation

    omega[i] = 2 * pi * nu[i] * 10^12

    where omega is the angular frequency in units of rad/second, nu is the
    frequency in units of THz.
    Assuming that the uncertainties are uncorrelated, the square of the
    uncertainty of the angular frequency axis is given by

    sigma^2_omega[i] = 4 * pi^2 * 10^24 * sigma^2_nu[i]

    Parameters:
    ----------
    -> frequency is the frequency axis in unit of THz
    -> frequency_err2 is the square of the uncertainty of the frequency axis

    Returns - 2 NessiLists:
    ----------------------
    <- the angular_frequency axis in units of rad/second
    <- the square of the uncertainty of the angular frequency axis

    Exceptions:
    ----------
    <- IndexError is thrown if the arrays are not of compatible  sizes
    <- TypeError is thrown if any of the lists are not recognized types

    """

    try:
        if frequency.__type__ != frequency_err2.__type__:
            raise TypeError("Frequency and Frequency Err2 arrays are not " \
                            +"the same type")

        if (frequency.__type__ == nessi_list.NessiList.DOUBLE):
            omega = nessi_list.NessiList(len(frequency))
            omega_err2 = nessi_list.NessiList(len(frequency))
            axis_manip_bind.frequency_to_angular_frequency_d(\
                frequency.__array__,\
                frequency_err2.__array__,\
                omega.__array__,\
                omega_err2.__array__)

        else:
            raise TypeError("Unknown primative type %s" \
                            % str(frequency.__type__))

        return (omega, omega_err2)

    except AttributeError:
        omega_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.frequency_to_angular_frequency_ss_d(\
            float(frequency),\
            float(frequency_err2),\
            omega_ss)
        return (omega_ss.val, omega_ss.val_err2)

##
# \}

##
# \defgroup frequency_to_energy axis_manip::frequency_to_energy
# \{

##
# \brief This function converts the frequency to energy and its uncertainty.
#
# This function is described  in section 3.47 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function takes a histogram data set that has the principle axis
# in units of THz and converts it to meV according to the equation
# \f[
# E[i]=h\nu[i]
# \f]
# where \f$E\f$ is the energy in units of meV, \f$\nu\f$ is the frequency
# in units
# of THz, and \f$h\f$ is Planck's constant.
# Assuming that the uncertainties are uncorrelated, the square of the
# uncertainty of the energy axis is given by
# \f[
# \sigma^2_E[i]=h^2\sigma^2_{\nu}[i]
# \f]
#
# \param frequency (INPUT) is the frequency axis in unit of THz
# \param frequency_err2 (INPUT) is the square of the uncertainty of the
#        frequency axis
#
# \return
# - the energy axis in units of meV
# - the square of the uncertainty of the energy axis
#
# \exception IndexError is thrown if the arrays are not of compatible  sizes
# \exception TypeError is thrown if any of the lists are not recognized types

def frequency_to_energy(frequency, frequency_err2):

    """
    This function takes a histogram data set that has the principle axis in
    units of THz and converts it to meV according to the equation

    E[i] = h * nu[i]

    where E is the energy in units of meV, nu is the frequency in units of
    THz, and h is Planck's constant.
    Assuming that the uncertainties are uncorrelated, the square of the
    uncertainty of the energy axis is given by

    sigma^2_E[i] = h^2 * sigma^2_nu[i]

    Parameters:
    ----------
    -> frequency is the frequency axis in unit of THz
    -> frequency_err2 is the square of the uncertainty of the frequency axis

    Returns - 2 NessiLists:
    ----------------------
    <- the energy axis in units of meV
    <- the square of the uncertainty of the energy axis

    Exceptions:
    ----------
    <- IndexError is thrown if the arrays are not of compatible  sizes
    <- TypeError is thrown if any of the lists are not recognized types

    """

    try:
        if frequency.__type__ != frequency_err2.__type__:
            raise TypeError("Frequency and Frequency Err2 arrays are not " \
                            +"the same type")

        if (frequency.__type__ == nessi_list.NessiList.DOUBLE):
            E = nessi_list.NessiList(len(frequency))
            E_err2 = nessi_list.NessiList(len(frequency))
            axis_manip_bind.frequency_to_energy_d(\
                frequency.__array__,\
                frequency_err2.__array__,\
                E.__array__,\
                E_err2.__array__)

        else:
            raise TypeError("Unknown primative type %s" \
                            % str(frequency.__type__))

        return (E, E_err2)

    except AttributeError:
        E_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.frequency_to_energy_ss_d(\
            float(frequency),\
            float(frequency_err2),\
            E_ss)
        return (E_ss.val, E_ss.val_err2)

##
# \}

##
# \defgroup init_scatt_wavevector_to_Q \
# axis_manip::init_scatt_wavevector_to_Q
# \{

##
# \brief This function is described in section 3.32 of the
# SNS 107030214-TD0001-R00, "Data Reduciton Library Software
# Requirements and Specifications".
#
# This function calculates the momentum transfer from the
# incident and scattered wavevectors according to the equation
# \f[
# Q_x[i]=-k_f[i]\cos(azimuthal)\sin(polar)
# \f]
# \f[
# Q_y[i]=-k_f[i]\sin(azimuthal)\sin(polar)
# \f]
# \f[
# Q_z[i]=k_i[i]-k_f[i]\cos(polar)
# \f]
# Where \f$k_i\f$ is the incident wavevector, \f$k_f\f$ is the
# scattered wavevector, \f$Q_x\f$ is the x-component of the
# momentum transfer, \f$Q_y\f$ is the y-component of the momentum
# transfer, \f$Q_z\f$ is the z-component of the momentum transfer,
# \f$azimuthal\f$ is the angle between the x-axis and the scattered
# neutron, and \f$polar\f$ is the angle between the z-axis and the
# scattered neutron. The uncertainty is calculated using assumption
# of uncorrelated uncertainties.
#
# \f[
# \sigma^2_{Q_x}[i] = (\cos(azimuthal) \sin(polar))^2 \sigma^2_{k_f}[i] + 
# k^2_f[i] \times ((\sin(azimuthal) \sin(polar))^2 \sigma^2_{azimuthal} + 
# (\cos(azimuthal) \cos(polar))^2 \sigma^2_{polar})
# \f]
# \f[
# \sigma^2_{Q_y}[i] = (\sin(azimuthal) \sin(polar))^2 \sigma^2_{k_f}[i] + 
# k^2_f[i] \times ((\cos(azimuthal) \sin(polar))^2 \sigma^2_{azimuthal} + 
# (\sin(azimuthal) \cos(polar))^2 \sigma^2_{polar})
# \f]
# \f[
# \sigma^2_{Q_z}[i] = \sigma^2_{k_i}[i] + \cos^2(polar)\sigma^2_{k_f}[i] + 
# k^2_f[i] \sin^2(polar) \sigma^2_{polar}
# \f]
#
# \param initial_wavevector (INPUT) is the incident wavevector axis in units
# of reciprocal Angstroms
# \param initial_wavevector_err2 (INPUT) is the square of the uncertainty of
# the incident wavevector axis
# \param final_wavevector (INPUT) is the final wavevector axis in units of
# reciprocal Angstroms
# \param final_wavevector_err2 (INPUT) is the square of the uncertainty of the
# final wavevector axis
# \param azimuthal (INPUT) is the azimuthal angle in the equation
# above in units of radians
# \param azimuthal_err2 (INPUT) is the square of the uncertainty in
# azumuthal
# \param polar (INPUT) is the polar angle in the equation above in units of
# radians
# \param polar_err2 (INPUT) is the square of the uncertainty in polar angle
#
# \return
# - Qx is the x-component of the momentum transfer axis in units of
# reciprocal angstroms
# - Qx_err2 is the square of the uncertainty in the x-component of the
# momentum transfer axis
# - Qy is the y-component of the momentum transfer axis in units of
# reciprocal angstroms
# - Qy_err2 is the square of the uncertainty in the y-component of the
# momentum transfer axis
# - Qz is the y-component of the momentum transfer axis in units of
# reciprocal angstroms
# - Qz_err2 is the square of the uncertainty in the y-component of the
# momentum transfer axis
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def init_scatt_wavevector_to_Q(initial_wavevector,
                               initial_wavevector_err2,
                               final_wavevector,
                               final_wavevector_err2,
                               azimuthal,
                               azimuthal_err2,
                               polar,
                               polar_err2):

    """
    This function calculates the momentum transfer from the
    incident and scattered wavevectors according to the equation
    
    Q_x = -k_f * cos(azimuthal) * sin(polar)
   
    Q_y = -k_f  * sin(azimuthal) * sin(polar)
   
    Q_z = k_i - k_f * cos(polar)
   
    Where k_i is the incident wavevector, k_f is the scattered wavevector,
    Q_x is the x-component of the momentum transfer, Q_y is the y-component
    of the momentum transfer, Q_z is the z-component of the momentum transfer,
    azimuthal is the angle between the x-axis and the scattered neutron, and
    polar is the angle between the z-axis and the scattered neutron. The
    uncertainty is calculated using assumption of uncorrelated uncertainties.

    Q_x_err2[i] = (cos(azimuthal) sin(polar))^2 final_wavevector_err2[i] + 
    final_wavevector^2[i] x ((sin(azimuthal) sin(polar))^2 azimuthal_err2 + 
    (cos(azimuthal) cos(polar))^2 polar_err2)

    Q_y_err2[i] = (sin(azimuthal) sin(polar))^2 final_wavevector_err2[i] + 
    final_wavevector^2[i] x ((cos(azimuthal) sin(polar))^2 azimuthal_err2 + 
    (sin(azimuthal) cos(polar))^2 polar_err2)

    Q_z[i] = initial_wavevector_err2[i] +
    cos^2(polar) final_wavevector_err2[i] + final_wavevector^2[i] sin^2(polar)
    polar_err2


    Parameters:
    __________
    
    -> initial_wavevector is the incident wavevector axis in units
    of reciprocal Angstroms
    -> initial_wavevector_err2 is the square of the uncertainty of
    the incident wavevector axis
    -> final_wavevector is the final wavevector axis in units of
    reciprocal Angstroms
    -> final_wavevector_err2 is the square of the uncertainty of the
    final wavevector axis
    -> azimuthal is the azimuthal angle in the equation
    above in units of radians
    -> azimuthal_err2 is the square of the uncertainty in
    azumuthal
    -> polar is the polar angle in the equation above in units of
    radians
    -> polar_err2 is the square of the uncertainty in polar angle

    Returns - 2 NessiLists:
    ________________________

    <- Qx is the x-component of the momentum transfer axis in units of
    reciprocal angstroms
    <- Qx_err2 is the square of the uncertainty in the x-component of the
    momentum transfer axis
    <- Qy is the y-component of the momentum transfer axis in units of
    reciprocal angstroms
    <- Qy_err2 is the square of the uncertainty in the y-component of the
    momentum transfer axis
    <- Qz is the y-component of the momentum transfer axis in units of
    reciprocal angstroms
    <- Qz_err2 is the square of the uncertainty in the y-component of the
    momentum transfer axis

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible
    sizes
    <- TypeError is thrown if any of the arrays are not recognized types
    """    

    try:
        if initial_wavevector.__type__ != final_wavevector.__type__:
            raise TypeError("Initial Wavevector and Scattered Wavevector " \
                            +"array types are not the same.")
        
        if initial_wavevector.__type__ != initial_wavevector_err2.__type__:
            raise TypeError("Initial Wavevector and Initial Wavevector Err2 " \
                            +"array types are not the same.")
        
        if final_wavevector.__type__ != final_wavevector_err2.__type__:
            raise TypeError("Scattered Wavevector and Scattere Wavevector " \
                            +"Err2 array types are not the same.")
        
        if (initial_wavevector.__type__ == nessi_list.NessiList.DOUBLE):
            Qx = nessi_list.NessiList(len(initial_wavevector))
            Qx_err2 = nessi_list.NessiList(len(initial_wavevector))
            Qy = nessi_list.NessiList(len(initial_wavevector))
            Qy_err2 = nessi_list.NessiList(len(initial_wavevector))
            Qz = nessi_list.NessiList(len(initial_wavevector))
            Qz_err2 = nessi_list.NessiList(len(initial_wavevector))
            axis_manip_bind.init_scatt_wavevector_to_Q_d(\
                initial_wavevector.__array__,\
                initial_wavevector_err2.__array__,\
                final_wavevector.__array__,\
                final_wavevector_err2.__array__,\
                float(azimuthal),\
                float(azimuthal_err2),\
                float(polar), \
                float(polar_err2),\
                Qx.__array__, Qx_err2.__array__,\
                Qy.__array__, Qy_err2.__array__,\
                Qz.__array__, Qz_err2.__array__)
        else:
            raise TypeError("Unknown primitive type %s" % \
                            str(initial_wavevector.__type__))
        
        return (Qx, Qx_err2, Qy, Qy_err2, Qz, Qz_err2)

    except AttributeError:
        try:
            initial_wavevector.__type__
            array = initial_wavevector
            array_err2 = initial_wavevector_err2
            scalar = final_wavevector
            scalar_err2 = final_wavevector_err2
            
            if(array.__type__ == array.DOUBLE):
                Qx = nessi_list.NessiList(len(array))
                Qx_err2 = nessi_list.NessiList(len(array))
                Qy = nessi_list.NessiList(len(array))
                Qy_err2 = nessi_list.NessiList(len(array))
                Qz = nessi_list.NessiList(len(array))
                Qz_err2 = nessi_list.NessiList(len(array))
                axis_manip_bind.init_scatt_wavevector_to_Q_d(\
                array.__array__,\
                array_err2.__array__,\
                float(scalar),\
                float(scalar_err2),\
                float(azimuthal),\
                float(azimuthal_err2),\
                float(polar), \
                float(polar_err2),\
                Qx.__array__, Qx_err2.__array__,\
                Qy.__array__, Qy_err2.__array__,\
                Qz.__array__, Qz_err2.__array__)
                
            else:
                raise TypeError("Unknown primative type %s" \
                                % str(array.__type__))
        
            return (Qx, Qx_err2, Qy, Qy_err2, Qz, Qz_err2)
    
        except AttributeError:
            try:
                final_wavevector.__type__
                array = final_wavevector
                array_err2 = final_wavevector_err2
                scalar = initial_wavevector
                scalar_err2 = initial_wavevector_err2
                
                if (array.__type__ == nessi_list.NessiList.DOUBLE):
                    Qx = nessi_list.NessiList(len(array))
                    Qx_err2 = nessi_list.NessiList(len(array))
                    Qy = nessi_list.NessiList(len(array))
                    Qy_err2 = nessi_list.NessiList(len(array))
                    Qz = nessi_list.NessiList(len(array))
                    Qz_err2 = nessi_list.NessiList(len(array))
                    axis_manip_bind.init_scatt_wavevector_to_Q_d(\
                    float(scalar),\
                    float(scalar_err2),\
                    array.__array__,\
                    array_err2.__array__,\
                    float(azimuthal),\
                    float(azimuthal_err2),\
                    float(polar),\
                    float(polar_err2),\
                    Qx.__array__, Qx_err2.__array__,\
                    Qy.__array__, Qy_err2.__array__,\
                    Qz.__array__, Qz_err2.__array__)
                    
                else:
                    raise TypeError("Unknown primative type %s" \
                                    % str(array.__type__))

                return (Qx, Qx_err2, Qy, Qy_err2, Qz, Qz_err2)
            
            except AttributeError:
                init_scatt_wavevector_to_Qx_ss = vpair_bind.DoubleVPair()
                init_scatt_wavevector_to_Qy_ss = vpair_bind.DoubleVPair()
                init_scatt_wavevector_to_Qz_ss = vpair_bind.DoubleVPair()
                axis_manip_bind.init_scatt_wavevector_to_Q_ss_d(\
                float(initial_wavevector),\
                float(initial_wavevector_err2),\
                float(final_wavevector),\
                float(final_wavevector_err2),\
                float(azimuthal),\
                float(azimuthal_err2),\
                float(polar),\
                float(polar_err2),\
                init_scatt_wavevector_to_Qx_ss,\
                init_scatt_wavevector_to_Qy_ss,\
                init_scatt_wavevector_to_Qz_ss)
                
                return init_scatt_wavevector_to_Qx_ss.val, \
                       init_scatt_wavevector_to_Qx_ss.val_err2, \
                       init_scatt_wavevector_to_Qy_ss.val, \
                       init_scatt_wavevector_to_Qy_ss.val_err2, \
                       init_scatt_wavevector_to_Qz_ss.val, \
                       init_scatt_wavevector_to_Qz_ss.val_err2
            
##
# \}

##
# \defgroup init_scatt_wavevector_to_scalar_Q \
# axis_manip::init_scatt_wavevector_to_scalar_Q
# \{

##
# \brief This function calculates the scalar momentum transfer from the
# incident and scattered wavevectors.
#
# This function is described in section 3.33 of the SNS 107030214-TD0001-R00,
# "Data Reduciton Library Software Requirements and Specifications".
#
# This function calculates the scalar momentum transfer from the
# incident and scattered wavevectors according to the equation
# \f[
# Q[i]=\sqrt{k_i^2[i]+k_f^2[i]-2k_i[i]k_f[i]\cos(\theta)}
# \f]
# Where \f$Q\f$ is the scalar momentum transfer, \f$k_i\f$ is the
# incident wavevector, \f$k_f\f$ is the final wavevector, and
# \f$\theta\f$ is the angle between the z-axis and the scattered
# neutron.
#
# Using the assumption that the uncertainties are uncorrelated,
# the square of the uncertainty of the scalar momentum transfer
# is given by
# \f[
# \sigma^2_Q[i]=\frac{1}{Q^2}((k_i[i]-k_f[i]
# cos(\theta))^2\sigma^2_{k_i}[i]+(k_f[i]-k_i[i]
# cos(\theta))^2\sigma^2_{k_f}[i]+
# (k_i[i]k_f[i]sin(\theta))^2\sigma^2_{\theta})
# \f]
# where \f$\sigma_Q\f$ is the uncertainty of the scalar momentum
# transfer, \f$\sigma_{k_i}\f$ is the uncertainty of the incident
# wavevector, \f$\sigma_{k_f}\f$ is the uncertainty of the final
# wavevector, and \f$\sigma_{\theta}\f$ is the uncertainty of the angle
# between the z-axis and the scattered neutron.
#
# \param initial_wavevector (INPUT) is the incident wavevector axis in units
# of reciprocal Angstroms
# \param initial_wavevector_err2 (INPUT) is the square of the uncertainty of
# the incident wavevector axis
# \param final_wavevector (INPUT) is the final wavevector axis in units of
# reciprocal Angstroms
# \param final_wavevector_err2 (INPUT) is the square of the uncertainty of the
# final wavevector axis
# \param polar (INPUT) is the polar angle in the equation above in units of
# radians
# \param polar_err2 (INPUT) is the square of the uncertainty in polar angle
# \return
# - The scalar momentum transfer Q axis in units of reciprocal Angstroms
# - The square of the uncertainty in the scalar momentum transfer axis
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def init_scatt_wavevector_to_scalar_Q(initial_wavevector,
                                      initial_wavevector_err2,
                                      final_wavevector,
                                      final_wavevector_err2,
                                      polar, polar_err2):

    """
    ---------------------------------------------------------------------------

    This function calculates the scalar momentum transfer from the incident
    and scattered wavevectors according to the equation:

    Q[i] = sqrt{k_i[i]^2 + k_f[i]^2 - 2.k_i[i].k_f[i].cos(theta)}

    Where Q is the scalar momentum transfer, k_i is the incident wavevector,
    k_f is the final wavevector, and theta is the angle between the z-axis and
    the scattered neutron.

    Using the assumption that the uncertainties are uncorrelated, the square of
    of the uncertainty of the scalar momentum transfer is given by:

    Q_err2[i]^2 = 1/Q^2{(k_i[i]^2-k_f[i]^2.cos(theta))^2.k_i_err2[i]^2 +
                  (k_f[i]-k_i.cos(theta))^2.k_f_err2[i]^2 +
                  (k_i[i].k_f[i].sin(theta))^2.theta_err2^2

    where Q_err2[i] it the uncertainty of the scalar momentum transfer,
    k_i_err2 is the uncertainty of the incident wavevector, k_f_err2 is the
    uncertainty of the final wavevector, and theta_err2 is the
    uncertainty of the angle between the z-axis and the scattered neutron

    Parameters:
    __________

    -> initial_wavevector is the incident wavevector axis in units of
       reciprocal Angstroms
    -> initial_wavevector_err2 is the square of the uncertainty of the incident
       wavevector axis
    -> final_wavevector is the final wavevector axis in units of reciprocal
       Angstroms
    -> final_wavevector_err2 is the square of the uncertainty of the final
       wavevector axis
    -> polar is the polar angle in units of radians
    -> polar_err2 is the square of the uncertainty in polar

    Returns - 2 NessiLists:
    ________________________

    <- the scalar momentum transfer axis in units of reciprocal Angstroms
    <- the square of the uncertainty in the scalar momentum transfer axis

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types
    """

    try:
        if initial_wavevector.__type__ != final_wavevector.__type__:
            raise TypeError("Initial Wavevector and Scattered Wavevector " \
                            +"array types are not the same.")

        if initial_wavevector.__type__ != initial_wavevector_err2.__type__:
            raise TypeError("Initial Wavevector and Initial Wavevector Err2 " \
                            +"array types are not the same.")

        if (initial_wavevector.__type__ == nessi_list.NessiList.DOUBLE):
            Q = nessi_list.NessiList(len(initial_wavevector))
            Q_err2 = nessi_list.NessiList(len(initial_wavevector))
            axis_manip_bind.init_scatt_wavevector_to_scalar_Q_d(\
                                       initial_wavevector.__array__,\
                                       initial_wavevector_err2.__array__,\
                                       final_wavevector.__array__,\
                                       final_wavevector_err2.__array__,\
                                       float(polar), \
                                       float(polar_err2),\
                                       Q.__array__, Q_err2.__array__)
        else:
            raise TypeError("Unknown primitive type %s" % \
                            str(initial_wavevector.__type__))

        return (Q, Q_err2)

    except AttributeError:
        try:
            initial_wavevector.__type__
            array = initial_wavevector
            array_err2 = initial_wavevector_err2
            scalar = final_wavevector
            scalar_err2 = final_wavevector_err2
            
            if(array.__type__ == array.DOUBLE):
                Q = nessi_list.NessiList(len(array))
                Q_err2 = nessi_list.NessiList(len(array))
                axis_manip_bind.init_scatt_wavevector_to_scalar_Q_d(\
                                       array.__array__,\
                                       array_err2.__array__,\
                                       float(scalar),\
                                       float(scalar_err2),\
                                       float(polar), \
                                       float(polar_err2),\
                                       Q.__array__, Q_err2.__array__)

            else:
                raise TypeError("Unknown primative type %s" \
                                % str(array.__type__))

            return (Q, Q_err2)

        except AttributeError:
            try:
                final_wavevector.__type__
                array = final_wavevector
                array_err2 = final_wavevector_err2
                scalar = initial_wavevector
                scalar_err2 = initial_wavevector_err2
                
                if (array.__type__ == nessi_list.NessiList.DOUBLE):
                    Q = nessi_list.NessiList(len(array))
                    Q_err2 = nessi_list.NessiList(len(array))
                    axis_manip_bind.init_scatt_wavevector_to_scalar_Q_d(\
                                       float(scalar),\
                                       float(scalar_err2),\
                                       array.__array__,\
                                       array_err2.__array__,\
                                       float(polar), \
                                       float(polar_err2),\
                                       Q.__array__, Q_err2.__array__)
                    
                else:
                    raise TypeError("Unknown primative type %s" \
                                    % str(array.__type__))

                return (Q, Q_err2)
            
            except AttributeError:
                init_scatt_wavevector_to_scalar_Q_ss = vpair_bind.DoubleVPair()
                axis_manip_bind.init_scatt_wavevector_to_scalar_Q_ss_d(\
        float(initial_wavevector),\
        float(initial_wavevector_err2),\
        float(final_wavevector),\
        float(final_wavevector_err2),\
        float(polar),\
        float(polar_err2),\
        init_scatt_wavevector_to_scalar_Q_ss)
                
                return init_scatt_wavevector_to_scalar_Q_ss.val, \
                       init_scatt_wavevector_to_scalar_Q_ss.val_err2
            
##
# \}

##
# \defgroup initial_velocity_dgs axis_manip::initial_velocity_dgs
# \{

##
# \brief This function calculates the initial velocity of the neutron
# for a direct geometry spectrometer according to the equation
# \f[
# v=\frac{L_d-L_u}{t_d-t_u}
# \f]
# Where \f$v\f$ is the initial velocity, \f$L\_d\f$ is the distance
# to the downstream monitor, \f$L\_u\f$ is the distance to the
# upstream monitor, \f$t\_d\f$ is the time-of-flight to reach the
# downstream monitor, and \f$t\_u\f$ is the time-of-flight to reach
# the upstream monitor. The uncertainty is calculated using the
# assumption of uncorrelated uncertainties.
# 
# \f[
# \sigma^2_v = \frac{\sigma^2_{dist\_downstream\_mon} +
#                    \sigma^2_{dist\_upstream\_mon}}
#                      {(t_d - t_u)^2}
# \f]
#
# \param dist_upstream_mon (INPUT) is the distance to the upstream
# monitor in units of meters
# \param dist_upstream_mon_err2 (INPUT) is the square of the
# uncertainty in dist_upstream_mon
# \param time_upstream_mon (INPUT) is the time-of-flight to reach
# the upstream monitor in units of micro-seconds
# \param time_upstream_mon_err2 (INPUT) is the square of the
# uncertainty in time_upstream_mon
# \param dist_downstream_mon (INPUT) is the distance to the
# downstream monitor in units of meters
# \param dist_downstream_mon_err2 (INPUT) is the square of the
# uncertainty in dist_downstream_mon
# \param time_downstream_mon (INPUT) is the time-of-flight to reach
# the downstream monitor in units of micro-seconds
# \param time_downstream_mon_err2 (INPUT) is the square of the
# uncertainty in time_downstream_mon
#
# \return
# - The initial_velocity is the initial velocity of the
# neutron in units of meter/mirco-seconds
# - The initial_velocity_err2 is the square of the
# uncertainty in initial_velocity
#
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def initial_velocity_dgs(dist_upstream_mon,
                         dist_upstream_mon_err2,
                         time_upstream_mon,
                         time_upstream_mon_err2,
                         dist_downstream_mon,
                         dist_downstream_mon_err2,
                         time_downstream_mon,
                         time_downstream_mon_err2):

    """
    This function calculates the initial velocity of the neutron
    for a direct geometry spectrometer according to the equation
    
    v[i] = (L_d-L_u) / (t_d-t_u)
    
    Where v is the initial velocity, L_d is the distance to the
    downstream monitor, L_u is the distance to the upstream
    monitor, t_d is the time-of-flight to reach the downstream monitor,
    and t_u is the time-of-flight to reach the upstream monitor. The
    uncertainty is calculated using the assumption of uncorrelated
    uncertainties.

    v_err2[i] = (dist_downstream_mon_err2 + dist_upstream_mon_err2) /
             (time_downstream_mon - time_upstream_mon)^2

    Parameters:
    __________
    
     -> dist_upstream_mon is the distance to the upstream
    monitor in units of meters
     -> dist_upstream_mon_err2 is the square of the
    uncertainty in dist_upstream_mon
     -> time_upstream_mon is the time-of-flight to reach
    the upstream monitor in units of micro-seconds
     -> time_upstream_mon_err2 is the square of the
    uncertainty in time_upstream_mon
     -> dist_downstream_mon is the distance to the
    downstream monitor in units of meters
    -> dist_downstream_mon_err2 is the square of the
    uncertainty in dist_downstream_mon
    -> time_downstream_mon is the time-of-flight to reach
    the downstream monitor in units of micro-seconds
     -> time_downstream_mon_err2 is the square of the
    uncertainty in time_downstream_mon
   
    Returns - 2 NessiLists:
    ________________________
    <- The initial_velocity is the initial velocity of the
    neutron in units of meter/mirco-seconds
    <- The initial_velocity_err2 is the square of the
    uncertainty in initial_velocity
    
    Exceptions:
    __________

    <- TypeError is thrown if any of the arrays are not
    recognized types

    """

    initial_velocity_dgs_ss = vpair_bind.DoubleVPair()
    axis_manip_bind.initial_velocity_dgs_ss_d(\
        float(dist_upstream_mon),\
        float(dist_upstream_mon_err2),\
        float(time_upstream_mon),\
        float(time_upstream_mon_err2),\
        float(dist_downstream_mon),\
        float(dist_downstream_mon_err2),\
        float(time_downstream_mon),\
        float(time_downstream_mon_err2),\
        initial_velocity_dgs_ss)
    return (initial_velocity_dgs_ss.val, initial_velocity_dgs_ss.val_err2)
                             
##
# \}

##
# \defgroup rebin_2D_quad_to_rectlin axis_manip::rebin_2D_quad_to_rectlin
# \{
#

##
# \brief This function rebins quadrilateral bins to a rectilinear grid
#
# This function is described in section 3.61 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function rebins a set of two-dimensional quadrilateral bins from a 
# given input spectrum onto a given rectilinear grid. The best way to 
# illustrate the functionality is with an example.
#
# We start with a set of five quadrilateral bins with the same number of 
# counts in each bin. The array of quadrilateral bins, shaded in gray, are 
# shown in the following picture on the rectilinear grid to which they will 
# be rebinned. 
#
# <IMG SRC="../images/Rebin_2D_Quad_To_Rectlin_OrigHist.png">
#
# After the rebinning process, the distribution of counts, fractional area 
# and bin contribution are shown in the following picture. The top line in 
# each grid bin represents the total counts placed from the original 
# quadrilateral bins. The second line in each grid bin is the summed 
# fractional area for that grid box as determined from the overlap of the 
# original quadrilateral bins. The bottom line is the contribution of the 
# data to the final grid where 1 means the input array contributed at least 
# once and 0 means no contribution.
#
# <IMG SRC="../images/Rebin_2D_Quad_To_Rectlin_RebinHist.png">
#
# \param axis_in_x1 (INPUT) is the x-coordinate of the 1st corner of the 
# initial data axis
# \param axis_in_y1 (INPUT) is the y-coordinate of the 1st corner of the 
# initial data axis
# \param axis_in_x2 (INPUT) is the x-coordinate of the 2nd corner of the 
# initial data axis
# \param axis_in_y2 (INPUT) is the y-coordinate of the 2nd corner of the 
# initial data axis
# \param axis_in_x3 (INPUT) is the x-coordinate of the 3rd corner of the 
# initial data axis
# \param axis_in_y3 (INPUT) is the y-coordinate of the 3rd corner of the 
# initial data axis
# \param axis_in_x4 (INPUT) is the x-coordinate of the 4th corner of the 
# initial data axis
# \param axis_in_y4 (INPUT) is the y-coordinate of the 4th corner of the 
# initial data axis
# \param input (INPUT) is the data associated with the initial axis
# \param input_err2 (INPUT) is the square of the uncertainty associated
# with the data
# \param axis_out_1 (INPUT) is the 1st (x-coordinate) target axis for 
# rebinning
# \param axis_out_2 (INPUT) is the 2nd (y-coordinate) target axis for 
# rebinning
#
# \return
# - The rebinned data according to the target axis
# - The square of the uncertainty associated with the rebinned data
# - The fractional area accumulated during rebinning
# - The contribution of the data to the final grid (0 or 1 for each bin)
#
# \exception IndexError is raised if the arrays are not of compatible sizes
# \exception TypeError is raised if any of the arrays are not recognized types
#
def rebin_2D_quad_to_rectlin(axis_in_x1, axis_in_y1, axis_in_x2, axis_in_y2,
                             axis_in_x3, axis_in_y3, axis_in_x4, axis_in_y4,
                             input, input_err2, axis_out_1, axis_out_2):
    """
    This function rebins a set of two-dimensional quadrilateral bins from a 
    given input spectrum onto a given rectilinear grid. The best way to 
    illustrate the functionality is with an example.
    
    We start with a set of five quadrilateral bins with the same number of 
    counts in each bin. The array of quadrilateral bins, with the counts
    inside, are shown in the following picture on the rectilinear grid to
    which they will be rebinned. 

                       4  ________________________________
                         |       |       |       |       |
                         |       |       |       |       |
                         |       |       |       |       |
                         |       |       |       | /     |
                         |       |       |       |/|     |
                         |       |       |       / |     |
                         |       |       |      /  |     |
                         |       |       |     / 10|     |
                       3 |_______|_______|____/|+-1/_____|
                         |       |       |   / |  /      |
                         |       |       |  /  | /       |
                         |       |       | / 10|/|       |
                         |       |       |/|+-1/ |       |
                         |       |       / |  /  |       |
                         |       |      /  | /   |       |
                         |       |     / 10|/    |       |
                       2 |_______|____/|+-1/_____|_______|
                         |       |   / |  /      |       |
                         |       |  /  | /       |       |
                         |       | / 10|/|       |       |
                         |       |/|+-1/ |       |       |
                         |       / |  /  |       |       |
                         |      /  | /   |       |       |
                         |     / 10|/    |       |       |
                         |     |+-1/     |       |       |
                       1 |_____|  /______|_______|_______|
                         |     | /       |       |       |
                         |     |/|       |       |       |
                         |     / |       |       |       |
                         |       |       |       |       |
                         |       |       |       |       |
                         |       |       |       |       |
                         |       |       |       |       |
                         |       |       |       |       |
                       0 |_______|_______|_______|_______|
                                 
                         0       1       2       3       4

    After the rebinning process, the distribution of counts, fractional area 
    and bin contribution are shown in the following picture. The top line in 
    each grid bin represents the total counts placed from the original 
    quadrilateral bins. The second line in each grid bin is the summed 
    fractional area for that grid box as determined from the overlap of the 
    original quadrilateral bins. The bottom line is the contribution of the 
    data to the final grid where 1 means the input array contributed at least 
    once and 0 means no contribution.

        4 -------------------------------------------------------------
          |              |              |              |              |
          |       0      |       0      |    1.25+-    |    1.25+-    |
          |              |              | 0.009765625  |   0.015625   |
          |              |              |              |              |
          |       0      |       0      |    0.125     |    0.125     |
          |              |              |              |              |
          |       0      |       0      |       1      |       1      |
          |              |              |              |              |
        3 -------------------------------------------------------------
          |              |              |              |              |
          |       0      |    1.25+-    |    3.75+-    |       0      |
          |              | 0.009765625  | 0.064453125  |              |
          |              |              |              |              |
          |       0      |    0.125     |    0.375     |       0      |
          |              |              |              |              |
          |       0      |       1      |       1      |       0      |
          |              |              |              |              |
        2 -------------------------------------------------------------
          |              |              |              |              |
          |   0.9375+-   |    3.75+-    |       0      |       0      |
          | 0.0087890625 | 0.064453125  |              |              |
          |              |              |              |              |
          |   0.09375    |    0.375     |       0      |       0      |
          |              |              |              |              |
          |       1      |       1      |       0      |       0      |
          |              |              |              |              |
        1 -------------------------------------------------------------
          |              |              |              |              |
          |   0.3125+-   |       0      |       0      |       0      |
          | 0.0009765625 |              |              |              |
          |              |              |              |              |
          |   0.03125    |       0      |       0      |       0      |
          |              |              |              |              |
          |       1      |       0      |       0      |       0      |
          |              |              |              |              |
        0 -------------------------------------------------------------        
          0              1              2              3              4

    Parameters:
    ----------
    -> axis_in_x1 is the x-coordinate of the 1st corner of the initial data
    axis
    -> axis_in_y1 is the y-coordinate of the 1st corner of the initial data
    axis
    -> axis_in_x2 is the x-coordinate of the 2nd corner of the initial data
    axis
    -> axis_in_y2 is the y-coordinate of the 2nd corner of the initial data
    axis
    -> axis_in_x3 is the x-coordinate of the 3rd corner of the initial data
    axis
    -> axis_in_y3 is the y-coordinate of the 3rd corner of the initial data
    axis
    -> axis_in_x4 is the x-coordinate of the 4th corner of the initial data
    axis
    -> axis_in_y4 is the y-coordinate of the 4th corner of the initial data
    axis
    -> input is the data associated with the initial axis
    -> input_err2 is the square of the uncertainty associated with the data
    -> axis_out_1 is the 1st (x-coordinate) target axis for rebinning
    -> axis_out_2 is the 2nd (y-coordinate) target axis for rebinning
    
    Returns:
    -------
    <- The rebinned data according to the target axis
    <- The square of the uncertainty associated with the rebinned data
    <- The fractional area accumulated during rebinning
    <- The contribution of the data to the final grid (0 or 1 for each bin)

    Exceptions:
    ----------
    -> IndexError is raised if the arrays are not of compatible sizes
    -> TypeError is raised if any of the arrays are not recognized types
    """
    if axis_in_x1.__type__ != axis_in_y1.__type__:
        raise TypeError("X and Y Axis for 1st Corner are not the same type.")

    if axis_in_x2.__type__ != axis_in_y2.__type__:
        raise TypeError("X and Y Axis for 2nd Corner are not the same type.")

    if axis_in_x3.__type__ != axis_in_y3.__type__:
        raise TypeError("X and Y Axis for 3rd Corner are not the same type.")

    if axis_in_x4.__type__ != axis_in_y4.__type__:
        raise TypeError("X and Y Axis for 4th Corner are not the same type.")

    if axis_in_x1.__type__ != axis_in_x2.__type__:
        raise TypeError("X Axes for 1st and 2nd Corner are not the same type.")

    if axis_in_x1.__type__ != axis_in_x3.__type__:
        raise TypeError("X Axes for 1st and 3rd Corner are not the same type.")

    if axis_in_x1.__type__ != axis_in_x4.__type__:
        raise TypeError("X Axes for 1st and 4th Corner are not the same type.")

    if axis_in_x1.__type__ != input.__type__:
        raise TypeError("Input Axis 1 and Input Data are not the same type.")

    if axis_in_x1.__type__ != axis_out_1.__type__:
        raise TypeError("X Axis for 1st Corner and Output Axis 1 are not the "\
                        +"same type.")

    if axis_out_1.__type__ != axis_out_2.__type__:
        raise TypeError("Output Axis 1 and Output Axis 2 are not the same " \
                        +"type.")

    if input.__type__ != input_err2.__type__:
        raise TypeError("Input Data and Input Data Err2 are not the same " \
                        +"type.")

    if (axis_in_x1.__type__ == nessi_list.NessiList.DOUBLE):
        orig_bin_x = nessi_list.NessiList(4)
        orig_bin_y = nessi_list.NessiList(4)
        rebin_bin_x = nessi_list.NessiList(4)
        rebin_bin_y = nessi_list.NessiList(4)
        frac_bin_x = nessi_list.NessiList(8)
        frac_bin_y = nessi_list.NessiList(8)

        output = nessi_list.NessiList((len(axis_out_1)-1) * \
                                      (len(axis_out_2)-1))
        output_err2 = nessi_list.NessiList((len(axis_out_1)-1) * \
                                           (len(axis_out_2)-1))
        frac_area = nessi_list.NessiList((len(axis_out_1)-1) * \
                                         (len(axis_out_2)-1))
        bin_count = nessi_list.NessiList((len(axis_out_1)-1) * \
                                         (len(axis_out_2)-1))
        
        axis_manip_bind.rebin_2D_quad_to_rectlin_d(axis_in_x1.__array__,
                                                   axis_in_y1.__array__,
                                                   axis_in_x2.__array__,
                                                   axis_in_y2.__array__,
                                                   axis_in_x3.__array__,
                                                   axis_in_y3.__array__,
                                                   axis_in_x4.__array__,
                                                   axis_in_y4.__array__,
                                                   input.__array__,
                                                   input_err2.__array__,
                                                   axis_out_1.__array__,
                                                   axis_out_2.__array__,
                                                   orig_bin_x.__array__,
                                                   orig_bin_y.__array__,
                                                   rebin_bin_x.__array__,
                                                   rebin_bin_y.__array__,
                                                   frac_bin_x.__array__,
                                                   frac_bin_y.__array__,
                                                   output.__array__,
                                                   output_err2.__array__,
                                                   frac_area.__array__,
                                                   bin_count.__array__)
    else:
        raise TypeError("Unknown primitive type %s" % str(input.__type__))

    return (output, output_err2, frac_area, bin_count)                    

##
# \}

##
# \defgroup rebin_axis_1D axis_manip::rebin_axis_1D
# \{

##
# \brief This function rebin data and its associated errors from one axis to
# another given axis.
#
# This function is described in section 3.12 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function rebins data and its associated errors from one axis to
# another given axis. This function uses fractional overlap of bins to
# perform the rebinning process. The function also assumes that the data
# is represented by a histogram model.
#
# To show the effects of rebinning, an example will now be discussed. We
# start with a histogram containing 3 bins, which runs from 0 to 3 on its
# x-axis. So, the histogram looks like:
#
# <CENTER>
# <TABLE>
# <TR>
# <TH>X-Axis Value</TH>
# <TH>Counts</TH>
# <TH>\f$\sigma^2\f$</TH>
# </TR>
# <TR ALIGN="CENTER"><TD>0</TD><TD>10</TD><TD>1</TD></TR>
# <TR ALIGN="CENTER"><TD>1</TD><TD>20</TD><TD>4</TD></TR>
# <TR ALIGN="CENTER"><TD>2</TD><TD>30</TD><TD>9</TD></TR>
# <TR ALIGN="CENTER"><TD>3</TD><TD>  </TD><TD> </TD></TR>
# </TABLE>
# </CENTER>
#
# Notice that the final x-axis value is not associated with a count value.
# This is a property of the histogram data model. Our new histogram has the
# same x-axis range [0,3], but it only has two bins. The result of the
# rebinned histogram is shown in the table below.
# <CENTER>
# <TABLE>
# <TR>
# <TH>X-Axis Value</TH>
# <TH>Counts</TH>
# <TH>\f$\sigma^2\f$</TH>
# </TR>
# <TR ALIGN="CENTER"><TD>0</TD><TD>20</TD><TD>2</TD></TR>
# <TR ALIGN="CENTER"><TD>1.5</TD><TD>40</TD><TD>10</TD></TR>
# <TR ALIGN="CENTER"><TD>3</TD><TD>  </TD><TD> </TD></TR>
# </TABLE>
# </CENTER>
#
# The new bin boundary (1.5) lies in the middle of the second bin in the
# original histogram. That means that its contents will be evenly split
# into the new bins. So,
# \f[
# Bin_1^{new} = Bin_1^{old} + 0.5 \times Bin_2^{old}
# \f]
# \f[
# Bin_2^{new} = Bin_3^{old} + 0.5 \times Bin_2^{old}
# \f]
# and
# \f[
# \sigma^2_{Bin_1^{new}} = \sigma^2_{Bin_1^{old}} + (0.5)^2 \times
# \sigma^2_{Bin_2^{old}}
# \f]
# \f[
# \sigma^2_{Bin_2^{new}} = \sigma^2_{Bin_3^{old}} + (0.5)^2 \times
# \sigma^2_{Bin_2^{old}}
# \f]
#
# This can be seen in the results presented in the above table. Now, we will
# reverse the process. The original histogram is the rebinned histogram
# with two bins used previously and the new rebinned histogram will have
# the same number of bins (3) as the previously used original histogram.
# One can see that we have the following distribution of bin contents:
#
# \f[
# Bin_1^{new} = \frac{2}{3} \times Bin_1^{old}
# \f]
# \f[
# Bin_2^{new} = \frac{1}{3} \times Bin_1^{old} + \frac{1}{3} \times
# Bin_2^{old}
# \f]
# \f[
# Bin_3^{new} = \frac{2}{3} \times Bin_3^{old}
# \f]
# and
# \f[
# \sigma^2_{Bin_1^{new}} = (\frac{2}{3})^2 \times \sigma^2_{Bin_1^{old}}
# \f]
# \f[
# \sigma^2_{Bin_2^{new}} = (\frac{1}{3})^2 \times \sigma^2_{Bin_1^{old}} +
# (\frac{1}{3})^2 \times \sigma^2_{Bin_2^{old}}
# \f]
# \f[
# \sigma^2_{Bin_3^{new}} = (\frac{2}{3})^2 \times \sigma^2_{Bin_3^{old}}
# \f]
#
# The results of this operation are shown in the following table:
#
# <CENTER>
# <TABLE>
# <TR>
# <TH>X-Axis Value</TH>
# <TH>Counts</TH>
# <TH>\f$\sigma^2\f$</TH>
# </TR>
# <TR ALIGN="CENTER"><TD>0</TD><TD>13.33333</TD><TD>0.88888</TD></TR>
# <TR ALIGN="CENTER"><TD>1</TD><TD>20</TD><TD>1.33333</TD></TR>
# <TR ALIGN="CENTER"><TD>2</TD><TD>26.66666</TD><TD>4.44444</TD></TR>
# <TR ALIGN="CENTER"><TD>3</TD><TD>  </TD><TD> </TD></TR>
# </TABLE>
# </CENTER>
#
# As one can see, these values are different from the first table shown in
# this example. This is due to the loss of information when performing a
# rebin on data. Therefore, rebin your data thoughtfully and carefully!
#
# This function was provided by Paul Kienzle (NIST) and is based on an
# OpenGenie routine.
#
# \param axis_in (INPUT) is the initial data axis
# \param data_in (INPUT) is the data associated with the initial axis
# \param data_in_err2 (INPUT) is the square of the uncertainty associated
# with the data
# \param axis_out (INPUT) is the target axis for rebinning
# \return
# - The rebinned data according to the target axis
# - The uncertainty associated with the rebinned data
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def rebin_axis_1D(axis_in, data_in, data_in_err2, axis_out):

    """
    ---------------------------------------------------------------------------

    This function rebins data and its associated errors from one axis to
    another given axis. This function uses fractional overlap of bins to
    perform the rebinning process. The function also assumes that the data
    is represented by a histogram model.

    To show the effects of rebinning, an example will now be discussed. We
    start with a histogram containing 3 bins, which runs from 0 to 3 on its
    x-axis. So, the histogram looks like:

               X-axis Value   |  Counts   |   sigma^2
               _______________|___________|___________
                     0        |    10     |     1
                     1        |    20     |     4
                     2        |    30     |     9
                     3

    Notice that the final x-axis value is not associated with a count value.
    This is a property of the histogram data model.
    Our new histogram has the same x-axis range [0,3], but it only has two
    bins. The result of the rebinned histrogram is shown in the table below.

               X-axis Value   |  Counts   |   sigma^2
               _______________|___________|___________
                     0        |    20     |     2
                    1.5       |    40     |     10
                     3

    The new bin boundary (1.5) lies in the middle of the second bin in the
    original histogram. That means that its contents will be envly split into
    the new bins. So,

          Bin_1_new = Bin_1_old + 0.5.Bin_2_old
          Bin_2_new = Bin_3_old + 0.5.Bin_2_old
    and
          (Bin_1_new_err2)^2 = (Bin_1_old_err2)^2 + (0.5)^2.(Bin_2_old_err2)^2
          (Bin_2_new_err2)^2 = (Bin_3_old_err2)^2 + (0.5)^2.(Bin_2_old_err2)^2

    This can be seen in the results presented in the above table. Now, we will
    reverse the process. The original histogram is the rebinned histogram with
    the two bins used previously and the new rebinned histogram will have the
    same number of bins (3) as the previously used original histogram. One
    can see that we have the following distribution of bins contents:

          Bin_1_new = 2/3.Bin_1_old
          Bin_2_new = 1/3.Bin_1_old + 1/3.Bin_2_old
          Bin_3_new = 2/3.Bin_3_old
    and
          (Bin_1_new_err2)^2 = (2/3)^2.(Bin_1_old_err2)^2
          (Bin_2_new_err2)^2 = (1/3)^2.(Bin_1_old_err2)^2 +
                               (1/3)^2.(Bin_2_old_err2)^2
          (Bin_3_new_err2)^2 = (2/3)^2.(Bin_3_old_err2)^2

    The result of this operation are shown in the following table:

               X-axis Value   |  Counts   |   sigma^2
               _______________|___________|___________
                     0        | 13.33333  |  0.88888
                     1        |    20     |  1.33333
                     2        | 26.66666  |  4.44444
                     3

    As one can see, these values are different from the first table
    shown in this example. This is due to the loss of information when
    performing a rebin on data. Therefore, rebin your data thoughtfully and
    carefully!

    Parameters:
    __________

    -> axis_in is the initial data axis
    -> data_in is the data associated with the initial axis
    -> data_in_err2 is the square of the uncertainty associated with the data
    -> axis_out is the target axis for rebinning

    Returns - two NessiLists:
    __________________________

    <- the rebinned data according to the target axis
    <- the square of the uncertainty associated with the rebinned data

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types

    """

    if axis_in.__type__ != data_in.__type__:
        raise TypeError("Input Axis and Input Data are not the same type.")

    if axis_in.__type__ != axis_out.__type__:
        raise TypeError("Input Axis and Output Axis are not the same type.")

    if data_in.__type__ != data_in_err2.__type__:
        raise TypeError("Input Data and Input Data Err2 are not the same " \
                        +"type.")

    if (axis_in.__type__ == nessi_list.NessiList.DOUBLE):
        output = nessi_list.NessiList(len(axis_out)-1)
        output_err2 = nessi_list.NessiList(len(axis_out)-1)
        axis_manip_bind.rebin_axis_1D_d(axis_in.__array__,
                                        data_in.__array__,
                                        data_in_err2.__array__,
                                        axis_out.__array__,
                                        output.__array__,
                                        output_err2.__array__)
    else:
        raise TypeError("Unknown primitive type %s" % str(data_in.__type__))

    return (output, output_err2)

##
# \}

##
# \defgroup rebin_axis_1D_frac axis_manip::rebin_axis_1D_frac
# \{

##
# \brief This function rebins data and its associated errors from one axis to
# another given axis.
#
# This function is described in section 3.62 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function rebins data and its associated errors from one axis to
# another given axis. This function uses fractional overlap of bins to
# perform the rebinning process. The function also assumes that the data
# is represented by a histogram model. The fractional overlap is tracked 
# separately. When processing the data, if either the input value or its 
# associated error is <em>nan</em> or <em>inf</em>, the bin is ignored and 
# the fraction is not added. <b>NOTE</b>: The data and fractional overlap
# arrays must be divided by a separate function. This function does not
# do that in order to allow investigation of the information.
#
# For each bin in the output array, the input data, squared uncertainty and 
# fractional area are determined in the following manner:
#
# \f[
# data_{out}[k] = \sum_j data_{in}[j] \times \Delta_{jk}
# \f]
# \f[
# \sigma_{out}^2[k] = \sum_j \sigma_{in}^2[j] \times \Delta_{jk}^2
# \f]
# \f[
# f[k] = \sum_j \Delta_{jk}
# \f] 
# 
# where \f$k\f$ is the current bin in the output and \f$j\f$ are the bins 
# in the input which have overlap with \f$k\f$. The variable 
# \f$\Delta_{jk}\f$ is given by
#
# \f[
# \Delta_{jk} = min(axis_{out}[k+1], axis_{in}[j+1]) - 
# max(axis_{out}[k], axis_{in}[j])
# \f]
#
# \param axis_in (INPUT) is the initial data axis
# \param data_in (INPUT) is the data associated with the initial axis
# \param data_in_err2 (INPUT) is the square of the uncertainty associated
# with the data
# \param axis_out (INPUT) is the target axis for rebinning
# \return
# - The rebinned data according to the target axis
# - The uncertainty associated with the rebinned data
# - The fractional area associated with rebinning the data to the target axis
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def rebin_axis_1D_frac(axis_in, data_in, data_in_err2, axis_out):
    """
    This function rebins data and its associated errors from one axis to
    another given axis. This function uses fractional overlap of bins to
    perform the rebinning process. The function also assumes that the data
    is represented by a histogram model. The fractional overlap is tracked 
    separately. When processing the data, if either the input value or its 
    associated error is nan or inf, the bin is ignored and the fraction is not
    added. NOTE: The data and fractional overlap arrays must be divided by a
    separate function. This function does not do that in order to allow
    investigation of the information.

    For each bin in the output array, the input data, squared uncertainty and 
    fractional area are determined in the following manner:

    data_{out}[k] = sum_j data_{in}[j] x Delta_{jk}
    sigma_{out}^2[k] = sum_j sigma_{in}^2[j] x (Delta_{jk})^2
    f[k] = sum_j Delta_{jk}

    where k is the current bin in the output and j are the bins in the input
    which have overlap with k. The variable Delta_{jk} is given by

    Delta_{jk} = min(axis_{out}[k+1], axis_{in}[j+1]) -
                 max(axis_{out}[k], axis_{in}[j])

    Parameters:
    __________

    -> axis_in is the initial data axis
    -> data_in is the data associated with the initial axis
    -> data_in_err2 is the square of the uncertainty associated with the data
    -> axis_out is the target axis for rebinning

    Returns - two NessiLists:
    __________________________

    <- the rebinned data according to the target axis
    <- the square of the uncertainty associated with the rebinned data
    <- the fractional area associated with rebinning the data to the target
       axis

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types
    """
    if axis_in.__type__ != data_in.__type__:
        raise TypeError("Input Axis and Input Data are not the same type.")

    if axis_in.__type__ != axis_out.__type__:
        raise TypeError("Input Axis and Output Axis are not the same type.")

    if data_in.__type__ != data_in_err2.__type__:
        raise TypeError("Input Data and Input Data Err2 are not the same " \
                        +"type.")

    if (axis_in.__type__ == nessi_list.NessiList.DOUBLE):
        output = nessi_list.NessiList(len(axis_out)-1)
        output_err2 = nessi_list.NessiList(len(axis_out)-1)
        frac_area = nessi_list.NessiList(len(axis_out)-1)
        axis_manip_bind.rebin_axis_1D_frac_d(axis_in.__array__,
                                             data_in.__array__,
                                             data_in_err2.__array__,
                                             axis_out.__array__,
                                             output.__array__,
                                             output_err2.__array__,
                                             frac_area.__array__)

        return (output, output_err2, frac_area)
    else:
        raise TypeError("Unknown primitive type %s" % str(data_in.__type__))

##
# \}

##
# \defgroup rebin_axis_2D axis_manip::rebin_axis_2D
# \{

##
# \brief This function rebin data and its associated errors from two axes to
#        two different axes.
#
# This function is described in section 3.13 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function rebins data and its associated errors from two axes to
# two different axes. This function uses fractional overlap of bins to
# perform the rebinning process. The function also assumes that the data
# is represented by a histogram model. The fractional overlap is performed
# on one axis at a time with the second declared axis going first.
#
# To show the effects of rebinning, an example will now be discussed. We
# start with a histogram containing 9 bins, which runs from 0 to 3 on its
# x and y axes. So, the histogram looks like:
#
# <CENTER>
# <TABLE>
# <TR>
# <TH>X-Axis Value</TH>
# <TH>Y-Axis Value</TH>
# <TH>Counts</TH>
# <TH>\f$\sigma^2\f$</TH>
# </TR>
# <TR ALIGN="CENTER"><TD>0</TD><TD>0</TD><TD>10</TD><TD>1</TD></TR>
# <TR ALIGN="CENTER"><TD>0</TD><TD>1</TD><TD>20</TD><TD>4</TD></TR>
# <TR ALIGN="CENTER"><TD>0</TD><TD>2</TD><TD>30</TD><TD>9</TD></TR>
# <TR ALIGN="CENTER"><TD>0</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
# <TR ALIGN="CENTER"><TD>1</TD><TD>0</TD><TD>10</TD><TD>1</TD></TR>
# <TR ALIGN="CENTER"><TD>1</TD><TD>1</TD><TD>20</TD><TD>4</TD></TR>
# <TR ALIGN="CENTER"><TD>1</TD><TD>2</TD><TD>30</TD><TD>9</TD></TR>
# <TR ALIGN="CENTER"><TD>1</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
# <TR ALIGN="CENTER"><TD>2</TD><TD>0</TD><TD>10</TD><TD>1</TD></TR>
# <TR ALIGN="CENTER"><TD>2</TD><TD>1</TD><TD>20</TD><TD>4</TD></TR>
# <TR ALIGN="CENTER"><TD>2</TD><TD>2</TD><TD>30</TD><TD>9</TD></TR>
# <TR ALIGN="CENTER"><TD>2</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
# <TR ALIGN="CENTER"><TD>3</TD><TD>  </TD><TD> </TD></TR>
# </TABLE>
# </CENTER>
#
# Our new histogram is still [0,3] on both the x and y axes, but now both
# axes are two bins. The result of the rebinned histogram is shown in the
# table below.
#
# <CENTER>
# <TABLE>
# <TR>
# <TH>X-Axis Value</TH>
# <TH>Y-Axis Value</TH>
# <TH>Counts</TH>
# <TH>\f$\sigma^2\f$</TH>
# </TR>
# <TR ALIGN="CENTER"><TD>0</TD><TD>0</TD><TD>30</TD><TD>2.5</TD></TR>
# <TR ALIGN="CENTER"><TD>0</TD><TD>1.5</TD><TD>60</TD><TD>12.5</TD></TR>
# <TR ALIGN="CENTER"><TD>0</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
# <TR ALIGN="CENTER"><TD>1.5</TD><TD>0</TD><TD>30</TD><TD>2.5</TD></TR>
# <TR ALIGN="CENTER"><TD>1.5</TD><TD>1.5</TD><TD>60</TD><TD>12.5</TD></TR>
# <TR ALIGN="CENTER"><TD>1.5</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
# <TR ALIGN="CENTER"><TD>3</TD><TD> </TD><TD> </TD><TD> </TD></TR>
# </TABLE>
# </CENTER>
#
# The algorithm relies on the constructs used in the 1D rebinning algorithm
# to perform the calculations.
#
# Now, we reverse the process starting with the newly rebinned histogram
# with four total bins and revert back to the original axes layout in the
# histogram with nine bins. The results of the rebinning are shown in the
# table below.
#
# <CENTER>
# <TABLE>
# <TR>
# <TH>X-Axis Value</TH>
# <TH>Y-Axis Value</TH>
# <TH>Counts</TH>
# <TH>\f$\sigma^2\f$</TH>
# </TR>
# <TR ALIGN="CENTER"><TD>0</TD><TD>0</TD><TD>13.33333</TD><TD>0.49383</TD></TR>
# <TR ALIGN="CENTER"><TD>0</TD><TD>1</TD><TD>20</TD><TD>0.74074</TD></TR>
# <TR ALIGN="CENTER"><TD>0</TD><TD>2</TD><TD>26.66666</TD><TD>2.46914</TD></TR>
# <TR ALIGN="CENTER"><TD>0</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
# <TR ALIGN="CENTER"><TD>1</TD><TD>0</TD><TD>13.33333</TD><TD>0.49383</TD></TR>
# <TR ALIGN="CENTER"><TD>1</TD><TD>1</TD><TD>20</TD><TD>0.74074</TD></TR>
# <TR ALIGN="CENTER"><TD>1</TD><TD>2</TD><TD>26.66666</TD><TD>2.46914</TD></TR>
# <TR ALIGN="CENTER"><TD>1</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
# <TR ALIGN="CENTER"><TD>2</TD><TD>0</TD><TD>13.33333</TD><TD>0.49383</TD></TR>
# <TR ALIGN="CENTER"><TD>2</TD><TD>1</TD><TD>20</TD><TD>0.74074</TD></TR>
# <TR ALIGN="CENTER"><TD>2</TD><TD>2</TD><TD>26.66666</TD><TD>2.46914</TD></TR>
# <TR ALIGN="CENTER"><TD>2</TD><TD>3</TD><TD> </TD><TD> </TD></TR>
# <TR ALIGN="CENTER"><TD>3</TD><TD>  </TD><TD> </TD></TR>
# </TABLE>
# </CENTER>
#
# As one can see, these values are different from the first table shown in
# this example. This is due to the loss of information when performing a
# rebin on data. Therefore, rebin your data thoughtfully and carefully!
#
# \param axis_in_1 (INPUT) is the 1st initial data axis
# \param axis_in_2 (INPUT) is the 2nd initial data axis
# \param data_in (INPUT) is the data associated with the initial axis
# \param data_in_err2 (INPUT) is the square of the uncertainty associated
# with the data
# \param axis_out_1 (INPUT) is the 1st target axis for rebinning
# \param axis_out_2 (INPUT) is the 2nd target axis for rebinning
#
# \return
# - The rebinned data according to the target axis
# - The uncertainty associated with the rebinned  data
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def rebin_axis_2D(axis_in_1, axis_in_2, data_in, data_in_err2,
                  axis_out_1, axis_out_2):
    """
    ---------------------------------------------------------------------------
    This function rebins data and its associated errors from two axes to
    two different axes. This function uses fractional overlap of bins to
    perform the rebinning process. The function also assumes that the data
    is represented by a histogram model. The fractional overlap is performed
    on one axis at a time with the second declared axis going first.

    To show the effects of rebinning, an example will now be discussed. We
    start with a histogram containing 9 bins, which runs from 0 to 3 on its
    x and y axes. So, the histogram looks like:

             X-axis Value  | Y-axis Value  |  Counts   |  sigma^2
             ______________|_______________|___________|___________
                   0       |       0       |    10     |     1
                   0       |       1       |    20     |     4
                   0       |       2       |    30     |     9
                   0       |       3       |           |
                   1       |       0       |    10     |     1
                   1       |       1       |    20     |     4
                   1       |       2       |    30     |     9
                   1       |       3       |           |
                   2       |       0       |    10     |     1
                   2       |       1       |    20     |     4
                   2       |       2       |    30     |     9
                   2       |       3       |           |
                   3

    Our new histogram is still [0,3] on both the x and y axes, but now both
    axes are two bins. The result of the rebinned histogram is shown in the
    table below.

             X-axis Value  | Y-axis Value  |  Counts   |  sigma^2
             ______________|_______________|___________|___________
                   0       |       0       |    30     |    2.5
                   0       |      1.5      |    60     |   12.5
                   0       |       3       |           |
                  1.5      |       0       |    30     |    2.5
                  1.5      |      1.5      |    60     |   12.5
                  1.5      |       3       |           |
                   3

    The algorithm relies on the constructs used in the 1D rebinning algorithm
    to perform the calculations.

    Now, we reverse the process starting with the newly rebinned histogram
    with four total bins and revert back to the original axes layout in the
    histogram with nine bins. The results of the rebinning are shown in the
    table below.

             X-axis Value  | Y-axis Value  |  Counts   |  sigma^2
             ______________|_______________|___________|___________
                   0       |       0       |  13.33333 |  0.49383
                   0       |       1       |     20    |  0.74074
                   0       |       2       |  26.66666 |  2.46914
                   0       |       3       |           |
                   1       |       0       |  13.33333 |  0.49383
                   1       |       1       |     20    |  0.74074
                   1       |       2       |  26.66666 |  2.46914
                   1       |       3       |           |
                   2       |       0       |  13.33333 |  0.49383
                   2       |       1       |     20    |  0.74074
                   2       |       2       |  26.66666 |  2.46914
                   2       |       3       |           |
                   3

    As one can see, these values are different from the first table shown in
    this example. This is due to the loss of information when performing a
    rebin on data. Therefore, rebin your data thoughtfully and carefully!

    Parameters:
    __________

    -> axis_in_1 is the 1st initial data axis
    -> axis_in_2 is the 2nd initial data axis
    -> data_in is the data associated with the initial axis
    -> data_in_err2 is the square of the uncertainty associated with the data
    -> axis_out_1 is the 1st target axis for rebinning
    -> axis_out_2 is the 2nd target axis for rebinning

    Returns - two NessiLists:
    __________________________

    <- the rebinned data according to the target axis
    <- the square of the uncertainty associated with the rebinned data

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types

    """

    if axis_in_1.__type__ != axis_in_2.__type__:
        raise TypeError("Input Axis 1 and Input Axis 2 are not the same type.")

    if axis_in_1.__type__ != data_in.__type__:
        raise TypeError("Input Axis 1 and Input Data are not the same type.")

    if axis_in_1.__type__ != axis_out_1.__type__:
        raise TypeError("Input Axis 1 and Output Axis 1 are not the same " \
                        +"type.")

    if axis_out_1.__type__ != axis_out_2.__type__:
        raise TypeError("Output Axis 1 and Output Axis 2 are not the same " \
                        +"type.")

    if data_in.__type__ != data_in_err2.__type__:
        raise TypeError("Input Data and Input Data Err2 are not the same " \
                        +"type.")

    if (axis_in_1.__type__ == nessi_list.NessiList.DOUBLE):
        output = nessi_list.NessiList((len(axis_out_1)-1) * \
                                      (len(axis_out_2)-1))
        output_err2 = nessi_list.NessiList((len(axis_out_1)-1) * \
                                           (len(axis_out_2)-1))
        axis_manip_bind.rebin_axis_2D_d(axis_in_1.__array__,
                                        axis_in_2.__array__,
                                        data_in.__array__,
                                        data_in_err2.__array__,
                                        axis_out_1.__array__,
                                        axis_out_2.__array__,
                                        output.__array__,
                                        output_err2.__array__)
    else:
        raise TypeError("Unknown primitive type %s" % str(data_in.__type__))

    return (output, output_err2)

##
# \}

##
# \defgroup rebin_diagonal axis_manip::rebin_diagonal
# \{

##
# \brief This function rebins data and its associated errors from two axes to
#        two different axes.
#
# This function is described in section 3.53 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function rebins a two-dimensional spectrum that is diagonal in 
# terms of the number of elements in the axes that make up the spectrum. 
# The best way to illustrate the functionality is with an example.
#
# We start with a histogram containing 16 bins, which runs from 0 to 4 on 
# its x and y axes, but with values only along the diagonal of the 
# histogram. So, the histogram looks like:
#
# <IMG SRC="../images/Rebin_Diagonal_OrigHist.png">
#
# Our new histogram is still [0,4] on both the x and y axes, but now the x 
# axis is three bins and the y axis is two bins. The result of the 
# rebinned histogram is shown in the table below.
# 
# <IMG SRC="../images/Rebin_Diagonal_RebinHist.png">
#
# \param axis_in_1 (INPUT) is the 1st initial data axis
# \param axis_in_2 (INPUT) is the 2nd initial data axis
# \param data_in (INPUT) is the data associated with the initial axis
# \param data_in_err2 (INPUT) is the square of the uncertainty associated
# with the data
# \param axis_out_1 (INPUT) is the 1st target axis for rebinning
# \param axis_out_2 (INPUT) is the 2nd target axis for rebinning
#
# \return
# - The rebinned data according to the target axis
# - The uncertainty associated with the rebinned data
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def rebin_diagonal(axis_in_1, axis_in_2, data_in, data_in_err2,
                   axis_out_1, axis_out_2):
    """
    ---------------------------------------------------------------------------
    This function rebins a two-dimensional spectrum that is diagonal in 
    terms of the number of elements in the axes that make up the spectrum. 
    The best way to illustrate the functionality is with an example.
    
    We start with a histogram containing 16 bins, which runs from 0 to 4 on 
    its x and y axes, but with values only along the diagonal of the 
    histogram. So, the histogram looks like:

                4 -----------------------------------------
                  |         |         |         |         |
                  |         |         |         |  10+-1  |
                  |         |         |         |         |
                3 -----------------------------------------
                  |         |         |         |         |
                  |         |         |  10+-1  |         |
                  |         |         |         |         |
                2 -----------------------------------------
                  |         |         |         |         |
                  |         |  10+-1  |         |         |
                  |         |         |         |         |
                1 -----------------------------------------
                  |         |         |         |         |
                  |  10+-1  |         |         |         |
                  |         |         |         |         |
                0 -----------------------------------------
                  0         1         2         3         4

    Our new histogram is still [0,4] on both the x and y axes, but now the x 
    axis is three bins and the y axis is two bins. The result of the 
    rebinned histogram is shown in the table below.
    
              4 ----------------------------------------------
                |              |              |              |
                |      0       | 6.666+-0.444 | 13.333+-1.111|
                |              |              |              |
              2 ----------------------------------------------
                |              |              |              |
                | 13.333+-1.111| 6.666+-0.444 |      0       |
                |              |              |              |
              0 ----------------------------------------------
                0            1.333          2.666            4

    Parameters:
    __________

    -> axis_in_1 is the 1st initial data axis
    -> axis_in_2 is the 2nd initial data axis
    -> data_in is the data associated with the initial axis
    -> data_in_err2 is the square of the uncertainty associated with the data
    -> axis_out_1 is the 1st target axis for rebinning
    -> axis_out_2 is the 2nd target axis for rebinning

    Returns - two NessiLists:
    __________________________

    <- the rebinned data according to the target axis
    <- the square of the uncertainty associated with the rebinned data

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types

    """

    if axis_in_1.__type__ != axis_in_2.__type__:
        raise TypeError("Input Axis 1 and Input Axis 2 are not the same type.")

    if axis_in_1.__type__ != data_in.__type__:
        raise TypeError("Input Axis 1 and Input Data are not the same type.")

    if axis_in_1.__type__ != axis_out_1.__type__:
        raise TypeError("Input Axis 1 and Output Axis 1 are not the same " \
                        +"type.")

    if axis_out_1.__type__ != axis_out_2.__type__:
        raise TypeError("Output Axis 1 and Output Axis 2 are not the same " \
                        +"type.")

    if data_in.__type__ != data_in_err2.__type__:
        raise TypeError("Input Data and Input Data Err2 are not the same " \
                        +"type.")

    if (axis_in_1.__type__ == nessi_list.NessiList.DOUBLE):
        output = nessi_list.NessiList((len(axis_out_1)-1) * \
                                      (len(axis_out_2)-1))
        output_err2 = nessi_list.NessiList((len(axis_out_1)-1) * \
                                           (len(axis_out_2)-1))
        axis_manip_bind.rebin_diagonal_d(axis_in_1.__array__,
                                         axis_in_2.__array__,
                                         data_in.__array__,
                                         data_in_err2.__array__,
                                         axis_out_1.__array__,
                                         axis_out_2.__array__,
                                         output.__array__,
                                         output_err2.__array__)
    else:
        raise TypeError("Unknown primitive type %s" % str(data_in.__type__))

    return (output, output_err2)

##
# \}


##
# \defgroup reverse_array_cp axis_manip::reverse_array_cp
# \{

##
# \brief This function will reorder a NessiList so the last element of the
# supplied NessiList is the first element of the result NessiList
#
# This function is described in section 3.11 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function will reorder a NessiList so the last element of the
# supplied NessiList is the first element of the result NessiList.
#
# \param data_in (INPUT) is the NessiList to be reversed
#
# \return
# - The reversed NessiList
#
# \exception TypeError is thrown if the array is not a recognized type

def reverse_array_cp(data_in):

    """
    ---------------------------------------------------------------------------

    This function will reorder an NessiList so the last element of the
    supplied NessiList is the first element of the result NessiList.

    Parameter:
    _________

    -> data_in is the NessiList to be reversed

    Return - 1 NessiList:
    ______________________

    <- the reversed NessiList

    Exception:
    _________

    <- TypeError is thrown if the array is not a recognized type

    """

    try:
        output = nessi_list.NessiList(len(data_in), type=data_in.__type__)
    except AttributeError:
        raise TypeError("Function must be supplied a NessiList")

    if (data_in.__type__ == nessi_list.NessiList.DOUBLE):
        output = nessi_list.NessiList(len(data_in))
        axis_manip_bind.reverse_array_cp_d(data_in.__array__, output.__array__)

    elif (data_in.__type__ == nessi_list.NessiList.INT):
        output = nessi_list.NessiList(len(data_in),
                                      type=nessi_list.NessiList.INT)
        axis_manip_bind.reverse_array_cp_i(data_in.__array__, output.__array__)

    else:
        raise TypeError("Unknown primitive type %s" % str(data_in.__type__))

    return output

##
# \}


##
# \defgroup reverse_array_nc axis_manip::reverse_array_nc
# \{

##
# \brief This function will reorder a NessiList so the last element of the
# NessiList is the first element of the supplied NessiList.
#
# This function is not described but is based on section 3.11 of the SNS
# 107030214-TD0001-R00, "Data Reduction Library Software Requirements and
# Specifications".
#
# This function will reorder a NessiList so the last element of the
# supplied NessiList is the first element of the supplied NessiList. This
# NessiList reversal is done in place on the supplied NessiList
# (i.e. no copy).
#
# \param data_in (INPUT/OUTPUT) is the NessiList to be reversed. It also is the
# place holder for the reversed NessiList.
#
# \return reference to the input array
#
# \exception TypeError is thrown if the array is not a recognized
# type

def reverse_array_nc(data_in):

    """
    ---------------------------------------------------------------------------

    This function will reorder a NessiList so the last element of the
    supplied NessiList is the first element of the resulting array.
    This NessiList reversal is done in place of the supplied NessiList.

    Parameter:
    ________________

    -> data_in is the NessiList to be reversed. It is also the place holder
       for the reversed NessiList.

    Return - one NessiList:
    ______________________

    <- reference to the data_in array

    Exception:
    _________

    <- TypeError is thrown if the array is not a recognized type

    """

    if (data_in.__type__ == nessi_list.NessiList.DOUBLE):
        axis_manip_bind.reverse_array_nc_d(data_in.__array__)

    elif (data_in.__type__ == nessi_list.NessiList.INT):
        axis_manip_bind.reverse_array_nc_i(data_in.__array__)

    else:
        raise TypeError("Unknown primitive type %s" % str(data_in.__type__))

    return data_in

##
#\}


##
# \defgroup time_offset_dgs axis_manip::time_offset_dgs
# \{

##
# \brief This function is described in section 3.26.
#
# This function calculates the time offset for a direct geometry
# spectrometer according to the equation
# \f[
# t_0 = t - \frac{L}{v}
# \f]
# Where \f$t_0\f$ is the time offset, \f$t\f$ is the time observed
# at the downstream monitor, \f$L\f$ is the total flight path for
# the downstream monitor, and \f$v\f$ is the velocity of the
# incident neutrons. The uncertainty is calculated using the
# assumption of uncorrelated uncertainties.
#
# \f[
# \sigma^2_{t_0} = \sigma^2_t + \left(\frac{1}{v}\right)^2 \sigma^2_L + 
# \left(\frac{L}{v^2}\right)^2 \sigma^2_v
# \f]
#
# \param dist_downstream_monitor (INPUT) is the total flight path
# for the downstream monitor in units of meter
# \param dist_downstream_monitor_err2 (INPUT) is the square of the
# uncertainty in dist_downstream_monitor
# \param time_downstream_monitor (INPUT) is the time observed at
# the downstream monitor in units of micro-seconds
# \param time_downstream_monitor_err2 (INPUT) is the square of the
# uncertainty in time_downstream_monitor
# \param initial_velocity (INPUT) is the velocity of the incident
# neutrons in unites of meter/micro-seconds
# \param initial_velocity_err2 (INPUT) is the square of the
# uncertainty in initial_velocity
#
# \return
# - The time_offset is the time offset of the neutron
# emitting from the source assuming the velocity supplied in units
# of micro-seconds
# - The time_offset_err2 is the square of the uncertainty
# in time_offset
#
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def time_offset_dgs(dist_downstream_monitor,
                    dist_downstream_monitor_err2,
                    time_downstream_monitor,
                    time_downstream_monitor_err2,
                    initial_velocity,
                    initial_velocity_err2):

    """
    This function calculates the time offset for a direct geometry
    spectrometer according to the equation
    
    t_0 = t - (L / v)
    
    Where t_0 is the time offset, t is the time observed
    at the downstream monitor, L is the total flight path for
    the downstream monitor, and v is the velocity of the
    incident neutrons. The uncertainty is calculated using the
    assumption of uncorrelated uncertainties.

    t_0_err2 = t_err2 + (1 / v)^2 L_err2 + (L / v^2)^2 v_err2

    Parameters:
    __________
    
    -> dist_downstream_monitor is the distance to the downstream monitor
    in units of meters
    -> dist_downstream_monitor_err2 is the square of the uncertainty in
    dist_downstream_monitor
    -> time_downstream_monitor is the time-of-flight to reach the
    downstream monitor in units of micro-seconds
    -> time_downstream_monitor_err2 is the square of the uncertainty in
    time_downstream_monitor
    -> initial_velocity is the velocity of the incident neutrons in
    unites of meter/micro-seconds
    -> initial_velocity_err2 is the square of the uncertainty in
    initial_velocity
   
    Returns - 2 NessiLists:
    ________________________
    <- The time_offset is the time offset of the neutron emitting from
    the source assuming the velocity supplied in units of micro-seconds
    <- The time_offset_err2 is the square of the uncertainty in
    time_offset
    
    Exceptions:
    __________

    <- TypeError is thrown if any of the arrays are not
    recognized types

    """

    time_offset_dgs_ss = vpair_bind.DoubleVPair()
    axis_manip_bind.time_offset_dgs_ss_d(\
        float(dist_downstream_monitor),\
        float(dist_downstream_monitor_err2),\
        float(time_downstream_monitor),\
        float(time_downstream_monitor_err2),\
        float(initial_velocity),\
        float(initial_velocity_err2),\
        time_offset_dgs_ss)
    return (time_offset_dgs_ss.val, time_offset_dgs_ss.val_err2)
                             
##
# \}

##
# \defgroup tof_to_final_velocity_dgs axis_manip::tof_to_final_velocity_dgs
# \{
   
##
# \brief This function is described in section 3.27 of the
# SNS 107030214-TD0001-R00, "Data Reduction Library Software Requirements
# and Specifications".
#
# This function calculates the final velocity of the neutron for a
# direct geometry spectrometer according to the equation
# \f[
# v_f[i]=\frac{L_D}{t[i]-\frac{L_S}{v_i}-t_0}
# \f]
# Where \f$v_f[i]\f$ is the final velocity of the neutron,
# \f$L_D\f$ is the distance from the sample to the detector,
# \f$t[i]\f$ is the total time-of-flight, \f$L_S\f$ is the distance
# from source to sample, \f$v_i\f$ is the initial velocity of the
# neutron, and \f$t_0\f$ is the time-offset of the neutron. The uncertainty
# is calculated using the assumption of uncorrelated uncertainties.
#
# \f[ 
# \sigma^2_{v_f[i]}[i] =
# \frac{\sigma^2_{L_D}}{(t[i]-\frac{L_S}{v_i}-t_0)^2} +
# \frac{L_D^2 \sigma^2_t}{(t[i]-\frac{L_S}{v_i}-t_0)^4} +
# \frac{L^2_D \sigma^2_{L_S}}{v^2_i (t[i]-\frac{L_S}{v_i}-t_0)^4} +
# \frac{L^2_S L^2_D \sigma^2_{v_i}}{v^4_i (t[i]-\frac{L_S}{v_i}-t_0)^4}
# + \frac{L^2_D \sigma^2_{t_0}}{(t[i]-\frac{L_S}{v_i}-t_0)^4}
# \f]
#
# \param tof (INPUT) is the time-of-flight axis in units of
# micro-seconds
# \param tof_err2 (INPUT) is the square of the uncertainty in the
# time-of-flight axis
# \param initial_velocity (INPUT) is the initial velocity of the
# neutron in units of meter/seconds
# \param initial_velocity_err2 (INPUT) is the square of the
# uncertainty in initial_velocity
# \param time_offset (INPUT) is the time offset of the neutron
# emitting from the source assuming the velocity supplied in units
# of micro-seconds
# \param time_offset_err2 (INPUT) is the square of the uncertainty
# in time_offset
# \param dist_source_sample (INPUT) is the distance from source to
# sample in units of meter
# \param dist_source_sample_err2 (INPUT) is the square of the
# uncertainty in dist_source_sample
# \param dist_sample_detector (INPUT) is the distance from sample
# to detector in units of meter
# \param dist_sample_detector_err2 (INPUT) is the square of the
# uncertainty in dist_sample_detector
#
# \return
# - The final_velocity is the final velocity axis of the
# neutron in units of meter/second
# - The final_velocity_err2 is the square of the
# uncertainty in the final velocity axis
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def tof_to_final_velocity_dgs(tof,
                              tof_err2,
                              initial_velocity,
                              initial_velocity_err2,
                              time_offset,
                              time_offset_err2,
                              dist_source_sample,
                              dist_source_sample_err2,
                              dist_sample_detector,
                              dist_sample_detector_err2):

    """
    This function calculates the final velocity of the neutron for a
    direct geometry spectrometer according to the equation:

    v_f[i] = L_D / (t[i]-(L_S/v_i)-t_0)
    
    Where v_f[i] is the final velocity of the neutron, L_D is the distance
    from the sample to the detector, t[i] is the total time-of-flight,
    L_S is the distance from source to sample, v_i is the initial velocity
    of the neutron, and t_0 is the time-offset of the neutron. The uncertainty
    is calculated using the assumption of uncorrelated uncertainties. The
    uncertainty is calculated using the assumption of uncorrelated uncertainties
    v_f_err2[i] = (L_D_err2)/(t[i]-(L_S/v_i)-t_0)^2 +
    ((L_D)^2 * t_err2 / ((t[i]-(L_S/v_i)-t_0)^4)) +
    ((L_D)^2 * L_S_err2)/((v_i)^2 * (t[i]-(L_S/v_i)-t_0)^4) +
    ((L_S)^2 * (L_D)^2 * v_i_err2)/((v_i)^4 * (t[i]-(L_S/v_i)-t_0)^4) +
    ((L_D)^2 * t_0_err2)/(t[i]-(L_S/v_i)-t_0)^4
    
    Parameters:
    __________

    -> tof is the time-of-flight axis in units of micro-seconds
    -> tof_err2 is the square of the uncertainty in the time-of-flight axis
    -> initial_velocity is the initial velocity of the neutron in units of
       meter/seconds
    -> initial_velocity_err2 is the square of the uncertainty in initial_velocity  
    -> time_offset is the time offset of the neutron emitting from the source
       assuming the velocity supplied in units of micro-seconds
    -> time_offset_err2 is the square of the uncertainty in time_offset
    -> dist_source_sample is the distance from source to sample in units of
       meter
    -> dist_source_sample_err2 is the square of the uncertainty in
       dist_source_sample
    -> dist_sample_detector is the distance from sample to detector in units
       of meter
    -> dist_sample_detector_err2 is the square of the uncertainty in
       dist_sample_detector

    Returns - 2 NessiLists:
    ________________________

    <- the final_velocity axis in units of meter/second
    <- the square of the uncertainty of the final_velocity axis

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types

    """
    try:
        if tof.__type__ != tof_err2.__type__:
            raise TypeError("Tof and Tof Err2 arrays are not the same type.")

        if (tof.__type__ == nessi_list.NessiList.DOUBLE):
            final_velocity = nessi_list.NessiList(len(tof))
            final_velocity_err2 = nessi_list.NessiList(len(tof))
            axis_manip_bind.tof_to_final_velocity_dgs_d(\
                tof.__array__,\
                tof_err2.__array__,\
                float(initial_velocity),\
                float(initial_velocity_err2),\
                float(time_offset),\
                float(time_offset_err2),\
                float(dist_source_sample),\
                float(dist_source_sample_err2),\
                float(dist_sample_detector),\
                float(dist_sample_detector_err2),\
                final_velocity.__array__, \
                final_velocity_err2.__array__)

        else:
            raise TypeError("Unknown primitive type %s" % str(tof.__type__))

        return (final_velocity, final_velocity_err2)

    except AttributeError:
        final_velocity_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.tof_to_final_velocity_dgs_ss_d(\
            float(tof),\
            float(tof_err2),\
            float(initial_velocity),\
            float(initial_velocity_err2),\
            float(time_offset),\
            float(time_offset_err2),\
            float(dist_source_sample),\
            float(dist_source_sample_err2),\
            float(dist_sample_detector),\
            float(dist_sample_detector_err2),\
            final_velocity_ss)
        return (final_velocity_ss.val, final_velocity_ss.val_err2)

##
# \}

##
# \defgroup tof_to_initial_wavelength_igs \
# axis_manip::tof_to_initial_wavelength_igs
# \{

##
# \brief This function calculates the initial wavelength for an inverse
# geometry spectrometer
#
# This function is described in section 3.29 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function calculates the initial wavelength for an inverse
# geometry spectrometer according to the equation
# \f[
# \lambda_i[i]=\frac{h}{m_n L_S}
#              \left(t[i]-\frac{m_n \lambda_f L_D}{h} -t_0 \right)
# \f]
# Where \f$\lambda_i[i]\f$ is the incident wavelength, \f$h\f$ is
# Planck's constant, \f$m_n\f$ is the mass of the neutron,
# \f$L_S\f$ is the distance from the source to the sample,
# \f$t[i]\f$ is the total time-of-flight, \f$\lambda_f\f$ is the
# final wavelength, \f$L_D\f$ is the distance from the sample to
# the detector, and \f$t_0\f$ is the time offset.
#
# Assuming that the uncertainties are uncorrelated, the square of
# the uncertainty of the initial wavelength for an inverse geometry
# spectromer is defined by
# \f[
# \sigma^2_{\lambda_i}[i]=
# \left(\frac{\lambda_i[i]}{L_S}\right)^2*\sigma^2_{L_S}
# + \left(\frac{h}{m_n*L_S}\right)^2(\sigma^2_t+\sigma^2_{t_0})+
# \left(\frac{\lambda_f}{L_S}\right)^2\sigma^2_{L_D}
# + \left(\frac{L_D}{L_S}\right)^2\sigma^2_{\lambda_f}
# \f]
#
# where \f$\sigma_{\lambda_i}\f$ is the uncertainty of the initial
# wavelength axis, \f$\sigma_{L_S}\f$ is the uncertainty of the
# distance from the source to the sample, \f$\sigma_t\f$ is the
# uncertainty of the time-of-flight, \f$\sigma_{t_0}\f$ is the
# uncertainty of the time-offset, \f$\sigma_{L_D}\f$ is the
# uncertainty of the distance from the sample to the detector, and
# \f$\sigma_{\lambda_f}\f$ the uncertainty of the final wavelength.
#
# \param tof (INPUT) is the time-of-flight axis in units of
# micro-seconds
# \param tof_err2 (INPUT) is the square of the uncertainty in the
# time-of-flight axis
# \param final_wavelength (INPUT) is the final wavelength of the
# neutron in units of Angstroms
# \param final_wavelength_err2 (INPUT) is the square of the
# uncertainty in final_wavelength
# \param time_offset (INPUT) is the time offset of the neutron
# emitting from the source assuming the velocity supplied in units
# of micro-seconds
# \param time_offset_err2 (INPUT) is the square of the uncertainty
# in time_offset
# \param dist_source_sample (INPUT) is the distance from source to
# sample in units of meter
# \param dist_source_sample_err2 (INPUT) is the square of the
# uncertainty in dist_source_sample
# \param dist_sample_detector (INPUT) is the distance from sample
# to detector in units of meter
# \param dist_sample_detector_err2 (INPUT) is the square of the
# uncertainty in dist_sample_detector
#
# \return
# - The initial wavelength axis in units of Angstrom
# - The square of the uncertainty of the initial wavelength axis
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def tof_to_initial_wavelength_igs(tof,
                                  tof_err2,
                                  final_wavelength,
                                  final_wavelength_err2,
                                  time_offset,
                                  time_offset_err2,
                                  dist_source_sample,
                                  dist_source_sample_err2,
                                  dist_sample_detector,
                                  dist_sample_detector_err2):

    """
    ---------------------------------------------------------------------------

    This function calculates the initial wavelength for an inverse geometry
    spectrometer according to the equation:

    lambda_i[i] = {h/(m_n.L_s)}{t[i] - (m_n.lambda.L_d)/h - t_0}

    where lambda is the incident wavelength, h is Planck's constant,
    m_n is the mass of the neutron, L_s is the distance from the source to
    the sample, t[i] is the total time-of-flight, lambda is the final
    wavelength, L_d is the distance from the sample to the detector, and
    t_0 is the time offset.

    Assuming that the uncertainties are uncorrelated, the square of the
    uncertainty of the initial wavelength for an inverse geometry spectromter
    is defined by

    lambda_i_err2[i]^2 = (lambda_i[i]/L_s)^2.L_s_err2^2 +
                         {h/(m_n.L_s)}^2.(t_err2^2 + t_0_err2^2) +
                         (lambda_f/L_s)^2.L_d_err2^2 +
                         (L_d/L_s)^2.lambda_f_err2^2

    where lambda_i_err2 is the uncertainty of the initial wavelength axis,
    L_s_err2 is the uncertainty of the distance from the source to the sample,
    t_err2 is the uncertainty of the time-of-flight, t_0_err2 is the
    uncertainty of the time-offset, L_d_err2 is the uncertainty of the
    distance from the sample to the detector, and lambda_f_err2 is the
    uncertainty of the final wavelength.

    Parameters:
    __________

    -> tof is the time-of-flight axis in units of micro-seconds
    -> tof_err2 is the square of the uncertainty in the time-of-flight axis
    -> final_wavelength is the final wavelength of the neutron in units of
       Angstroms
    -> final_wavelength_err2 is the square of the uncertainty in
       final_wavelength
    -> time_offset is the time offset of the neutron emitting from the source
       assuming the velocity supplied in units of micro-seconds
    -> time_offset_err2 is the square of the uncertainty in time_offset
    -> dist_source_sample is the distance from source to sample in units of
       meter
    -> dist_source_sample_err2 is the square of the uncertainty in
       dist_source_sample
    -> dist_sample_detector is the distance from sample to detector in units
       of meter
    -> dist_sample_detector_err2 is the square of the uncertainty in
       dist_sample_detector

    Returns - 2 NessiLists:
    ________________________

    <- the initial wavelength axis in units of Angstroms
    <- the square of the uncertainty of the initial wavelength axis

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types

    """
    try:
        if tof.__type__ != tof_err2.__type__:
            raise TypeError("Tof and Tof Err2 arrays are not the same type.")

        if (tof.__type__ == nessi_list.NessiList.DOUBLE):
            initial_wavelength = nessi_list.NessiList(len(tof))
            initial_wavelength_err2 = nessi_list.NessiList(len(tof))
            axis_manip_bind.tof_to_initial_wavelength_igs_d(\
                    tof.__array__,\
                    tof_err2.__array__,\
                    float(final_wavelength),\
                    float(final_wavelength_err2),\
                    float(time_offset),\
                    float(time_offset_err2),\
                    float(dist_source_sample),\
                    float(dist_source_sample_err2),\
                    float(dist_sample_detector),\
                    float(dist_sample_detector_err2),\
                    initial_wavelength.__array__, \
                    initial_wavelength_err2.__array__)

        else:
            raise TypeError("Unknown primitive type %s" % str(tof.__type__))

        return (initial_wavelength, initial_wavelength_err2)

    except AttributeError:
        initial_wavelength_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.tof_to_initial_wavelength_igs_ss_d(\
      float(tof),\
      float(tof_err2),\
      float(final_wavelength),\
      float(final_wavelength_err2),\
      float(time_offset),\
      float(time_offset_err2),\
      float(dist_source_sample),\
      float(dist_source_sample_err2),\
      float(dist_sample_detector),\
      float(dist_sample_detector_err2),\
      initial_wavelength_ss)
        return (initial_wavelength_ss.val, initial_wavelength_ss.val_err2)

##
# \}

##
# \defgroup tof_to_initial_wavelength_igs_lin_time_zero \
# axis_manip::tof_to_initial_wavelength_igs_lin_time_zero
# \{

##
# \brief This function calculates the initial wavelength for an inverse
# geometry spectrometer
#
# This function is described in section 3.48 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function calculates the initial wavelength for an inverse
# geometry spectrometer according to the equation
# \f[
# \lambda_i[i]=\frac{1}{\frac{m_n}{h} L_S + t_{0,slope}}
#              \left(t[i]-\frac{m_n \lambda_f L_D}{h} - t_{0,offset} \right)
# \f]
# Where \f$\lambda_i[i]\f$ is the incident wavelength, \f$h\f$ is
# Planck's constant, \f$m_n\f$ is the mass of the neutron,
# \f$L_S\f$ is the distance from the source to the sample,
# \f$t[i]\f$ is the total time-of-flight, \f$\lambda_f\f$ is the
# final wavelength, \f$L_D\f$ is the distance from the sample to
# the detector, and \f$t_{0,offset}\f$ is the time zero offset and
# \f$t_{0,slope}\f$ is the time zero slope determined from a linear fit to
# data of time zero versus initial wavelength.
#
# Assuming that the uncertainties are uncorrelated, the square of
# the uncertainty of the initial wavelength for an inverse geometry
# spectromer is defined by
# \f[
# \sigma^2_{\lambda_i}[i]=
# \left(\frac{1}{\frac{m_n}{h}L_S + t_{0,slope}}\right)^2*\left(
# \left(\lambda_i[i]\right)^2*\left(\left(\frac{m_n}{h}\right)^2
# \sigma^2_{L_S}+ \sigma^2_{t_{0,slope}}\right)+(\sigma^2_t[i]+
# \sigma^2_{t_{0,offset}})+ \left(\frac{m_n}{h}\right)^2\left(\left(
# \lambda_f\right)^2\sigma^2_{L_D} + \left({L_D}\right)^2
# \sigma^2_{\lambda_f}\right)\right)
# \f]
#
# where \f$\sigma_{\lambda_i}\f$ is the uncertainty of the initial
# wavelength axis, \f$\sigma_{L_S}\f$ is the uncertainty of the
# distance from the source to the sample, \f$\sigma_t\f$ is the
# uncertainty of the time-of-flight, \f$\sigma_{t_{0,offset}}\f$ is the
# uncertainty of the time-zero-offset, \f$\sigma_{t_{0,slope}}\f$ is the
# uncertainty of the time-zero-slope, \f$\sigma_{L_D}\f$ is the
# uncertainty of the distance from the sample to the detector, and
# \f$\sigma_{\lambda_f}\f$ the uncertainty of the final wavelength.
#
# \param tof (INPUT) is the time-of-flight axis in units of
# micro-seconds
# \param tof_err2 (INPUT) is the square of the uncertainty in the
# time-of-flight axis
# \param final_wavelength (INPUT) is the final wavelength of the
# neutron in units of Angstroms
# \param final_wavelength_err2 (INPUT) is the square of the
# uncertainty in final_wavelength
# \param time_0_slope (INPUT) is the slope parameter of a linear fit of 
# time zero versus initial wavelength
# \param time_0_slope_err2 (INPUT) is the square of the uncertainty
# in time_0_slope
# \param time_0_offset (INPUT) is the offset parameter of a linear fit of 
# time zero versus initial wavelength
# \param time_0_offset_err2 (INPUT) is the square of the uncertainty
# in time_0_offset
# \param dist_source_sample (INPUT) is the distance from source to
# sample in units of meter
# \param dist_source_sample_err2 (INPUT) is the square of the
# uncertainty in dist_source_sample
# \param dist_sample_detector (INPUT) is the distance from sample
# to detector in units of meter
# \param dist_sample_detector_err2 (INPUT) is the square of the
# uncertainty in dist_sample_detector
#
# \return
# - The initial wavelength axis in units of Angstrom
# - The square of the uncertainty of the initial wavelength axis
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def tof_to_initial_wavelength_igs_lin_time_zero(tof,
                                                tof_err2,
                                                final_wavelength,
                                                final_wavelength_err2,
                                                time_0_slope,
                                                time_0_slope_err2,
                                                time_0_offset,
                                                time_0_offset_err2,
                                                dist_source_sample,
                                                dist_source_sample_err2,
                                                dist_sample_detector,
                                                dist_sample_detector_err2):

    """
    ---------------------------------------------------------------------------

    This function calculates the initial wavelength for an inverse geometry
    spectrometer according to the equation:

    lambda_i[i] = (1/(m_n/h).L_S + t_0_slope) * (t[i] - (m_n lambda_f L_D)/h -
                  t_0_offset)

    where lambda_i is the incident wavelength, h is Planck's constant,
    m_n is the mass of the neutron, L_S is the distance from the source to
    the sample, t[i] is the total time-of-flight, lambda_f is the final
    wavelength, L_D is the distance from the sample to the detector, and
    t_0_offset is the time zero offset and t_0_slope is the time zero slope
    determined from a linear fit to data of time zero versus initial
    wavelength.

    Assuming that the uncertainties are uncorrelated, the square of the
    uncertainty of the initial wavelength for an inverse geometry spectromter
    is defined by

    lambda_i_err[i]^2 = (1/((m_n/h)L_S + t_0_slope))^2 * (lambda_i[i]^2 *
                        ((m_n/h)^2*L_S_err^2+t_0_slope_err^2) + t_err[i]^2 +
                        t_0_offset_err^2 + (m_n/h)^2 * (lambda_f^2*L_D_err^2 + 
                        L_D^2*lambda_f_err^2))


    where lambda_i_err is the uncertainty of the initial wavelength axis,
    L_S_err is the uncertainty of the distance from the source to the sample,
    t_err is the uncertainty of the time-of-flight, t_0_offset_err is the
    uncertainty of the time-zero-offset, t_0_slope_err is the uncertainty of
    the time-zero-slope, L_D_err is the uncertainty of the distance from the
    sample to the detector, and lambda_f_err2 is the uncertainty of the final
    wavelength.

    Parameters:
    __________

    -> tof is the time-of-flight axis in units of micro-seconds
    -> tof_err2 is the square of the uncertainty in the time-of-flight axis
    -> final_wavelength is the final wavelength of the neutron in units of
       Angstroms
    -> final_wavelength_err2 is the square of the uncertainty in
       final_wavelength
    -> time_0_slope is the slope parameter of a linear fit of time zero versus
       initial wavelength
    -> time_0_slope_err2 is the square of the uncertainty in time_0_slope
    -> time_0_offset is the offset parameter of a linear fit of time zero
       versus initial wavelength
    -> time_0_offset_err2 is the square of the uncertainty in time_0_offset
    -> dist_source_sample is the distance from source to sample in units of
       meter
    -> dist_source_sample_err2 is the square of the uncertainty in
       dist_source_sample
    -> dist_sample_detector is the distance from sample to detector in units
       of meter
    -> dist_sample_detector_err2 is the square of the uncertainty in
       dist_sample_detector

    Returns - 2 NessiLists:
    ________________________

    <- the initial wavelength axis in units of Angstroms
    <- the square of the uncertainty of the initial wavelength axis

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types

    """
    try:
        if tof.__type__ != tof_err2.__type__:
            raise TypeError("Tof and Tof Err2 arrays are not the same type.")

        if (tof.__type__ == nessi_list.NessiList.DOUBLE):
            initial_wavelength = nessi_list.NessiList(len(tof))
            initial_wavelength_err2 = nessi_list.NessiList(len(tof))
            axis_manip_bind.tof_to_initial_wavelength_igs_lin_time_zero_d(\
                    tof.__array__,\
                    tof_err2.__array__,\
                    float(final_wavelength),\
                    float(final_wavelength_err2),\
                    float(time_0_slope),\
                    float(time_0_slope_err2),\
                    float(time_0_offset),\
                    float(time_0_offset_err2),\
                    float(dist_source_sample),\
                    float(dist_source_sample_err2),\
                    float(dist_sample_detector),\
                    float(dist_sample_detector_err2),\
                    initial_wavelength.__array__, \
                    initial_wavelength_err2.__array__)

        else:
            raise TypeError("Unknown primitive type %s" % str(tof.__type__))

        return (initial_wavelength, initial_wavelength_err2)

    except AttributeError:
        initial_wavelength_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.tof_to_initial_wavelength_igs_lin_time_zero_ss_d(\
      float(tof),\
      float(tof_err2),\
      float(final_wavelength),\
      float(final_wavelength_err2),\
      float(time_0_slope),\
      float(time_0_slope_err2),\
      float(time_0_offset),\
      float(time_0_offset_err2),\
      float(dist_source_sample),\
      float(dist_source_sample_err2),\
      float(dist_sample_detector),\
      float(dist_sample_detector_err2),\
      initial_wavelength_ss)
        return (initial_wavelength_ss.val, initial_wavelength_ss.val_err2)

##
# \}

##
# \defgroup tof_to_scalar_Q axis_manip::tof_to_scalar_Q
# \{

##
# \brief This function is described in section 3.17.
#
# This function converts time-of-flight to scalar momentum transfer
# according to the equation
# \f[
# Q[i]=\frac{4\pi m_n L \sin(polar/2)}{h TOF[i]}
# \f]
# Where \f$Q[i]\f$ is the scalar momentum transfer, \f$m_n\f$ is
# the mass of the neutron, \f$L\f$ is the total flight path of the
# neutron, \f$polar\f$ is the angle between the positive z-axis and
# the direction of the scattered neutron, \f$h\f$ is Planck's
# constant, and \f$TOF[i]\f$ is the time-of-flight. The uncertainty
# is calculated using the assumption of uncorrelated uncertainties.
#
# \f[
# \sigma^2_Q[i]=\left(\frac{4\pi m_n}{hTOF[i]}\right)^2
# \left(sin^2(polar/2)\sigma^2_L+
# \frac{L^2cos^2(polar/2)}{4}\sigma^2_{polar}+
# \left(\frac{Lsin(polar/2)}{TOF[i]}\right)^2\sigma^2_{TOF}[i]\right)
# \f]
#
# where \f$\sigma_Q\f$ is the uncertainty in the momentum transfer,
# \f$\sigma_L\f$ is the uncertainty in the total flight path of the neutron
# \f$\sigma_{polar}\f$ is the uncertainty in the angle between the positive
# z-axis and the direction of the scattered neutron and \f$\sigma_{TOF}\f$
# is the uncertainty in the time-of-flight.
#
# \param tof (INPUT) is the time-of-flight axis in units of
# micro-seconds
# \param tof_err2 (INPUT) is the square of the uncertainty in the
# time-of-flight axis
# \param pathlength (INPUT) is the total flight path of the neutron
# in units of meter
# \param pathlength_err2 (INPUT) is the square of the uncertainty
# in pathlength
# \param polar (INPUT) is the polar angle in the equation above in
# units of radians
# \param polar_err2 (INPUT) is the square of the uncertainty in
# polar
# /return
# - The scalar momentum transfer, Q, in units of reciprocal Angstroms
# - The square of the uncertainty in the scalar momentum transfer axis
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def tof_to_scalar_Q(tof, tof_err2,
                    pathlength, pathlength_err2,
                    polar, polar_err2):
    
    """
    ---------------------------------------------------------------------------

    This function converts the time-of-flight to scalar momentum transfer
    according to the equation:
        
    Q[i] = (4.PI.m_n.L.sin(polar/2))/(h.TOF[i])
    
    where PI is the Pi constant, m_n is the mass of the neutron,
    polar is the angle between the positive z-axis and the direction
    of the scattered neutron, h is Planck's constant and TOF is the
    time-of-flight. 
    
    Assuming that the uncertainties are uncorrelated, the square of the
    uncertainty of the wavelength axis is given by:
    
    Q_err2[i]^2 = ({4.PI.m_n}/{h.TOF[i]})^2.[sin(polar/2)^2.L_err2 +
                  (L.cos(polar/2)/2)^2.polar_err2 +
                  ({L.sin(polar/2)}/{TOF[i]})^2.TOF_err2]
    
    where Q_err2 is the uncertainty in the momentum transfer, L_err2 is
    the uncertainty in the pathlength, polar_err2 is the uncertainty in the
    angle between the positive z-axis and the direction of the scattered
    neutron and TOF_err2 is the uncertainty in the time-of-flight axis.
    
    Parameters:
    __________
    
    -> tof is the time-of-flight axis in units of micro-seconds
    -> tof_err2 is the square of the uncertainty in the time-of-flight axis
    -> pathlength is the total flight path of the neutron in units of meter
    -> pathlength_err2 is the square of the uncertainty in pathlength
    -> polar is the angle between the positive z-axis and the direction of the
             scattered neutron
    -> polar_err2 is the uncertainty in the polar angle
        
    Returns - 2 NessiLists:
    ________________________

    <- the scalar momentum transfer, Q, in units of reciprocal Angstroms
    <- the square of the uncertainty in the scalar momentum transfer axis

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types

    """

    try:
        if tof.__type__ != tof_err2.__type__:
            raise TypeError("Tof and Tof Err2 arrays are not the same type.")

        if (tof.__type__ == nessi_list.NessiList.DOUBLE):

            Q = nessi_list.NessiList(len(tof))
            Q_err2 = nessi_list.NessiList(len(tof))
            axis_manip_bind.tof_to_scalar_Q_d(tof.__array__,
                                              tof_err2.__array__,
                                              float(pathlength),
                                              float(pathlength_err2),
                                              float(polar),
                                              float(polar_err2),
                                              Q.__array__,
                                              Q_err2.__array__)
            
        else:
            raise TypeError("Unknown primitive type %s" % str(tof.__type__))
        
        return (Q, Q_err2)
    
    except AttributeError:
        
        Q_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.tof_to_scalar_Q_ss_d(\
      float(tof),\
      float(tof_err2),\
      float(pathlength),\
      float(pathlength_err2),\
      float(polar),\
      float(polar_err2),\
      Q_ss)
        return (Q_ss.val, Q_ss.val_err2)
    
##
# \}

##
# \defgroup tof_to_wavelength axis_manip::tof_to_wavelength
# \{

##
# \brief This function converts the time-of-fligth to wavelength
#
# This function is described in section 3.15 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function converts the time-of-flight to wavelength according
# to the equation
# \f[
# \lambda[i]=\frac{h TOF[i]}{m_n L}
# \f]
# Where \f$\lambda[i]\f$ is the wavelength, \f$h\f$ is Planck's
# constant, \f$TOF[i]\f$ is the time-of-flight, \f$m_n\f$ is the
# mass of the neutron, and \f$L\f$ is the total flight path of the
# neutron.
#
# Assuming that the uncertainties are uncorrelated, the square of the
# uncertainty of the wavelength axis is given by
#
# \f[
# \sigma^2_{\lambda}[i]=\left(\frac{h}{m_n L}\right)^2\sigma^2_{TOF}[i]+
# \left(\frac{\lambda[i]}{L}\right)^2\sigma^2_L
# \f]
# where \f$\sigma_{\lambda}\f$ is the uncertainty in the wavelength axis,
# \f$\sigma_{TOF}\f$ is the uncertainty in the time of flight axis, and
# \f$\sigma_L\f$ is the uncertainty in the pathlength.
#
# \param tof (INPUT) is the time-of-flight axis in units of
# micro-seconds
# \param tof_err2 (INPUT) is the square of the uncertainty in the
# time-of-flight axis
# \param pathlength (INPUT) is the total flight path of the neutron
# in units of meter
# \param pathlength_err2 (INPUT) is the square of the uncertainty
# in pathlength
#
# \return
# - The wavelength axis in units of Angstroms
# - The square of the uncertainty in the wavelength axis
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def tof_to_wavelength(tof, tof_err2, pathlength, pathlength_err2):

    """
    ---------------------------------------------------------------------------

    This function converts the time-of-flight to wavelength according
    to the equation:

    lambda[i] = (h.TOF[i])/(m_n.L)

    where lambda is the wavelength, h is Planck's constant, TOF
    is the time-of-flight, m_n is the mass of the neutron, and
    L is the total flight path of the neutron.

    Assuming that the uncertainties are uncorrelated, the square of the
    uncertainty of the wavelength axis is given by:

    lambda_err2[i]^2 = {h/(m_n.L)}^2.TOF_err2^2 +
                       (lambda/L)^2.L_err2^2

    where lambda_err2 is the uncertainty in the wavelength axis,
    TOF_err2 is the uncertainty in the time of flight axis, and
    L_err2 is the uncertainty in the pathlength.

    Parameters:
    __________

    -> tof is the time-of-flight axis in units of micro-seconds
    -> tof_err2 is the square of the uncertainty in the time-of-flight axis
    -> pathlength is the total flight path of the neutron in units of meter
    -> pathlength_err2 is the square of the uncertainty in pathlength

    Returns - 2 NessiLists:
    ________________________

    <- the wavelength axis in units of Angstroms
    <- the square of the uncertainty in the wavelength axis

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types

    """

    try:
        if tof.__type__ != tof_err2.__type__:
            raise TypeError("Tof and Tof Err2 arrays are not the same type.")

        if (tof.__type__ == nessi_list.NessiList.DOUBLE):

            wavelength = nessi_list.NessiList(len(tof))
            wavelength_err2 = nessi_list.NessiList(len(tof))
            axis_manip_bind.tof_to_wavelength_d(tof.__array__,
                                                tof_err2.__array__,
                                                float(pathlength),
                                                float(pathlength_err2),
                                                wavelength.__array__,
                                                wavelength_err2.__array__)

        else:
            raise TypeError("Unknown primitive type %s" % str(tof.__type__))

        return (wavelength, wavelength_err2)

    except AttributeError:
        wavelength_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.tof_to_wavelength_ss_d(\
      float(tof),\
      float(tof_err2),\
      float(pathlength),\
      float(pathlength_err2),\
      wavelength_ss)
        return (wavelength_ss.val, wavelength_ss.val_err2)

##
# \}

##
# \defgroup tof_to_wavelength_lin_time_zero axis_manip::tof_to_wavelength_lin_time_zero
# \{
#

##
# \brief This function converts the time-of-flight to wavelength
#
# This function is described in section 3.50 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function converts the time-of-flight to wavelength according
# to the equation
#
# \f[
# \lambda[i]=\frac{TOF[i] - t_{0,offset}}{\frac{m_n L}{h} + t_{0,slope}}
# \f]
#
# where \f$\lambda[i]\f$ is the wavelength, \f$h\f$ is Planck's
# constant, \f$TOF[i]\f$ is the time-of-flight, \f$m_n\f$ is the
# mass of the neutron, \f$L\f$ is the total flight path of the neutron. 
# \f$t_{0,offset}\f$ is the time zero offset and \f$t_{0,slope}\f$ is the 
# time zero slope determined from a linear fit to data of time zero versus 
# wavelength.
#
# Assuming that the uncertainties are uncorrelated, the square of the
# uncertainty of the wavelength axis is given by
#
# \f[
# \sigma^2_{\lambda}[i]=\left(\frac{1}{\frac{m_n L}{h} + 
# t_{0,slope}}\right)^2 \times \left(\sigma^2_{TOF}[i] + 
# \sigma^2_{t_{0,offset}} + \lambda[i]^2 \left(\left(
# \frac{m_n}{h}\right)^2\sigma^2_L + 
# \sigma^2_{t_{0,slope}}\right)\right)
# \f]
#
# where \f$\sigma_{\lambda}\f$ is the uncertainty in the wavelength axis,
# \f$\sigma_{TOF}\f$ is the uncertainty in the time of flight axis, 
# \f$\sigma_L\f$ is the uncertainty in the pathlength and 
# \f$\sigma_{t_{0,offset}}\f$ is the uncertainty of the time-zero-offset, 
# \f$\sigma_{t_{0,slope}}\f$ is the uncertainty of the time-zero-slope.
#
# \param tof (INPUT) is the time-of-flight axis in units of
# micro-seconds
# \param tof_err2 (INPUT) is the square of the uncertainty in the
# time-of-flight axis
# \param pathlength (INPUT) is the total flight path of the neutron
# in units of meter
# \param pathlength_err2 (INPUT) is the square of the uncertainty
# in pathlength
# \param time_0_slope (INPUT) is the slope parameter of a linear fit of 
# time zero versus wavelength
# \param time_0_slope_err2 (INPUT) is the square of the uncertainty
# in time_0_slope
# \param time_0_offset (INPUT) is the offset parameter of a linear fit of 
# time zero versus wavelength
# \param time_0_offset_err2 (INPUT) is the square of the uncertainty
# in time_0_offset
#
# \return 
# - The wavelength axis in units of Angstroms
# - The square of the uncertainty in the wavelength axis
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def tof_to_wavelength_lin_time_zero(tof, tof_err2,
                                    pathlength,
                                    pathlength_err2,
                                    time_0_slope,
                                    time_0_slope_err2,
                                    time_0_offset,
                                    time_0_offset_err2):

    """
    This function converts the time-of-flight to wavelength according to the
    equation

    lambda[i]= (TOF[i] - t_{0,offset})/((m_n L)/h + t_{0,slope})

    where lambda[i] is the wavelength, h is Planck's constant, TOF[i] is the
    time-of-flight, m_n is the mass of the neutron, L is the total flight path
    of the neutron, t_{0,offset} is the time zero offset and t_{0,slope} is
    the time zero slope determined from a linear fit to data of time zero
    versus wavelength.

    Assuming that the uncertainties are uncorrelated, the square of the
    uncertainty of the wavelength axis is given by

    sigma^2_{lambda}[i]=(1 / ((m_n L)/h + t_{0,slope}))^2 *
    (sigma^2_{TOF}[i] + sigma^2_{t_{0,offset}} + lambda[i]^2 *
    (((m_n/h)^2 sigma^2_L + sigma^2_{t_{0,slope}}))

    where sigma_{\lambda} is the uncertainty in the wavelength axis,
    sigma_{TOF} is the uncertainty in the time of flight axis, sigma_L is the
    uncertainty in the pathlength and sigma_{t_{0,offset}} is the uncertainty
    of the time-zero-offset, sigma_{t_{0,slope}} is the uncertainty of the
    time-zero-slope.

    Parameters:
    ----------
    -> tof (INPUT) is the time-of-flight axis in units of micro-seconds
    -> tof_err2 (INPUT) is the square of the uncertainty in the time-of-flight
    axis
    -> pathlength (INPUT) is the total flight path of the neutron in units of
    meter
    -> pathlength_err2 (INPUT) is the square of the uncertainty in pathlength
    -> time_0_slope (INPUT) is the slope parameter of a linear fit of time
    zero versus wavelength
    -> time_0_slope_err2 (INPUT) is the square of the uncertainty in
    time_0_slope
    -> time_0_offset (INPUT) is the offset parameter of a linear fit of time
    zero versus wavelength
    -> time_0_offset_err2 (INPUT) is the square of the uncertainty in
    time_0_offset

    Returns:
    -------
    <- The wavelength axis in units of Angstroms
    <- The square of the uncertainty in the wavelength axis

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types
    """

    try:
        if tof.__type__ != tof_err2.__type__:
            raise TypeError("Tof and Tof Err2 arrays are not the same type.")

        if (tof.__type__ == nessi_list.NessiList.DOUBLE):

            wavelength = nessi_list.NessiList(len(tof))
            wavelength_err2 = nessi_list.NessiList(len(tof))
            axis_manip_bind.tof_to_wavelength_lin_time_zero_d(\
                tof.__array__,\
                tof_err2.__array__,\
                float(pathlength),\
                float(pathlength_err2),
                float(time_0_slope),\
                float(time_0_slope_err2),\
                float(time_0_offset),\
                float(time_0_offset_err2),\
                wavelength.__array__,\
                wavelength_err2.__array__)

        else:
            raise TypeError("Unknown primitive type %s" % str(tof.__type__))

        return (wavelength, wavelength_err2)

    except AttributeError:
        wavelength_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.tof_to_wavelength_lin_time_zero_ss_d(\
      float(tof),\
      float(tof_err2),\
      float(pathlength),\
      float(pathlength_err2),\
      float(time_0_slope),\
      float(time_0_slope_err2),\
      float(time_0_offset),\
      float(time_0_offset_err2),\
      wavelength_ss)
        return (wavelength_ss.val, wavelength_ss.val_err2)

##
# \}

##
# \defgroup velocity_to_energy axis_manip::velocity_to_energy
# \{

##
# \brief This function is described in section 3.21.
#
# This function calculates the energy of a neutron given its velocity
# according to the equation
# \f[
# E[i]=\frac{1}{2}m_n v[i]^2 =
# 5.227\times 10^{-6} \left( \frac{v[i]}{m/\mu s} \right)^2 meV
# \f]
# Where \f$E[i]\f$ is the energy of the neutron, \f$m_n\f$ is the mass of the
# neutron, and \f$v[i]\f$ is the velocity of the neutron. The uncertainty is
# calculated using the assumption of uncorrelated uncertainties.
#
# \f[
# \sigma^2_E[i] = (m_n v[i])^2 \sigma^2_v[i]
# \f]
#
# \param velocity (INPUT) is the velocity of the neutron in units of
# meter/micro-seconds
# \param velocity_err2 (INPUT) is the square of the uncertainty in the
# velocity of the neutron
#
# \return
# - The energy is the energy of the neutron in units of meV
# - The energy_err2 is the square of the uncertainty in the energy
#
# \exception IndexError is thrown if the arrays are not of compatible  sizes
# \exception TypeError is thrown if any of the lists are not recognized types

def velocity_to_energy(velocity, velocity_err2):

    """
    This function takes a histogram data set that has the principle axis in
    units of meter/micro-seconds and converts it to meV according to the
    equation

    E[i] = m_n v[i]^2 / 2 = 5.227* 10^-6 * v[i]^2
    
    Where E is the energy of the neutron, m_n is the mass of the neutron, and
    v is the velocity of the neutron. 
    Assuming that the uncertainties are uncorrelated, the square of the
    uncertainty of the energy axis is given by

    E_err2[i] = m_n^2 * velocity[i]^2 * velocity_err2[i]

    Parameters:
    ----------
    -> velocity is the velocity of the neutron in units of meter/micro-seconds
    -> velocity_err2 is the square of the uncertainty in the velocity of the
       neutron
   
    Returns - 2 NessiLists:
    ----------------------
    <- the energy of the neutron in units of meV
    <- the square of the uncertainty in the energy 

    Exceptions:
    ----------
    <- IndexError is thrown if the arrays are not of compatible  sizes
    <- TypeError is thrown if any of the lists are not recognized types

    """

    try:
        if velocity.__type__ != velocity_err2.__type__:
            raise TypeError("Velocity and Velocity Err2 arrays are not " \
                            +"the same type")

        if (velocity.__type__ == nessi_list.NessiList.DOUBLE):
            E = nessi_list.NessiList(len(velocity))
            E_err2 = nessi_list.NessiList(len(velocity))
            axis_manip_bind.velocity_to_energy_d(\
                velocity.__array__,\
                velocity_err2.__array__,\
                E.__array__,\
                E_err2.__array__)

        else:
            raise TypeError("Unknown primative type %s" \
                            % str(velocity.__type__))

        return (E, E_err2)

    except AttributeError:
        E_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.velocity_to_energy_ss_d(\
            float(velocity),\
            float(velocity_err2),\
            E_ss)
        return (E_ss.val, E_ss.val_err2)

##
# \}

##
# \defgroup velocity_to_scalar_k axis_manip::velocity_to_scalar_k
# \{

##
# \brief This function is described in section 3.23.
#
# This function calculates the scalar wavevector given the velocity
# according to the equation
# \f[
# k[i]=\frac{m_n}{\hbar}v[i]
# \f]
# Where \f$k[i]\f$ is the scalar wavevector, \f$m_n\f$ is the mass
# of the neutron, \f$\hbar\f$ is Planck's constant divided by \f$2\pi\f$,
# and \f$v[i]\f$ is
# the velocity of the neutron. The uncertainty is calculated using
# the assumption of uncorrelated uncertainties.
#
# \f[
# \sigma^2_k[i] = \frac{m^2_n \sigma^2_{v}[i]}{\hbar^2}
# \f]
#
# \param velocity (INPUT) is the velocity of the neutron in units
# of meter/micro-seconds
# \param velocity_err2 (INPUT) is the square of the uncertainty in
# the velocity of the neutron
#
# \return
# - The wavevector is the scalar wavevector in units of reciprocal Angstroms
# - The wavevector_err2 is the square of the uncertainty in the scalar
#   wavevector
#
# \exception IndexError is thrown if the arrays are not of compatible sizes
# \exception TypeError is thrown if any of the arrays are not recognized types

def velocity_to_scalar_k(velocity, velocity_err2):

    """
    This function calculates the scalar wavevector given the velocity
    according to the equation:

    k[i] = m_n * v[i] / hbar

    where k[i] is the scalar wavevector, m_n is the mass of the neutron,
    v[i] is the velocity of the neutron, and hbar is Planck's constant divide
    by 2pi.

    Assuming that the uncertainties are uncorrelated, the uncertainty
    in the scalar wavevector is given by:

    k_err2[i]^2 = (m_n / hbar)^2 * v_err2[i]^2

    where k_err2 is the uncertainty in the scalar wavevector, and
    v_err2 is the uncertainty in the velocity of the neutron.

    Parameters:
    __________

    -> velocity is the velocity of the neutron in units of
       meter/micro-seconds
    -> velocity_err2 is the square of the uncertainty in the velocity

    Returns 2 NessiLists:
    ______________________

    <- the scalar wavevector in units of reciprocal Angstroms
    <- the square of the uncertainty in the scalar wavevector

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types

    """

    try:
        if velocity.__type__ != velocity_err2.__type__:
            raise TypeError("Velocity and Velocity Err2 arrays are not " \
                            +"the same type")

        if (velocity.__type__ == nessi_list.NessiList.DOUBLE):
            wavevector = nessi_list.NessiList(len(velocity))
            wavevector_err2 = nessi_list.NessiList(len(velocity))
            axis_manip_bind.velocity_to_scalar_k_d(\
                velocity.__array__,\
                velocity_err2.__array__,\
                wavevector.__array__,\
                wavevector_err2.__array__)

        else:
            raise TypeError("Unknown primative type %s" \
                            % str(velocity.__type__))

        return (wavevector, wavevector_err2)

    except AttributeError:
        wavevector_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.velocity_to_scalar_k_ss_d(\
            float(velocity),\
            float(velocity_err2),\
            wavevector_ss)
        return (wavevector_ss.val, wavevector_ss.val_err2)

##
# \}

##
# \defgroup velocity_to_wavelength axis_manip::velocity_to_wavelength
# \{
#

##
# \brief This function calculates wavelength from velocity
#
# This function is described in section 3.58 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function converts velocity to wavelength according to the equation
# \f[
# \lambda[i] = \frac{h}{m_n v[i]}
# \f]
# Where \f$v[i]\f$ is the velocity, \f$h\f$ is Planck's constant, \f$m_n\f$ 
# is the mass of the neutron, and \f$\lambda[i]\f$ is the wavelength. The 
# uncertainty is calculated using the assumption of uncorrelated 
# uncertainties.
#
# Assuming that the uncertainties are uncorrelated, the square of the 
# uncertainty in velocity is given by
# \f[
# \sigma^2_{\lambda}[i] = \left(\frac{\lambda[i]}{v[i]}\right)^2 
# \sigma^2_v[i]
# \f]
# where \f$\sigma^2_v[i]\f$ is the uncertainty in the velocity axis and 
# \f$\sigma^2_{\lambda}[i]\f$ is the uncertainty in the wavelength axis.
#
# \param velocity (INPUT) is the velocity axis in units of meter/micro-seconds
# \param velocity_err2 (INPUT) is the square of the uncertainty in the 
# velocity axis
#
# \return
# - The wavelength axis in units of Angstroms
# - The square of the uncertainty in the wavelength axis
#
# \exception IndexError is thrown if the arrays are not of compatible sizes
# \exception TypeError is thrown if any of the lists are not recognized types
#

def velocity_to_wavelength(velocity, velocity_err2):
    """
    This function converts velocity to wavelength according to the equation

    lambda[i] = h / (m_n v[i])

    where v[i] is the velocity, h is Planck's constant, m_n is the mass of the
    neutron, and lambda[i] is the wavelength. The uncertainty is calculated
    using the assumption of uncorrelated uncertainties.

    Assuming that the uncertainties are uncorrelated, the square of the 
    uncertainty in velocity is given by

    sigma^2_lambda[i] = (lambda[i] / v[i])^2 * sigma^2_v[i]

    where sigma^2_v[i] is the uncertainty in the velocity axis and
    sigma^2_lambda[i] is the uncertainty in the wavelength axis.

    Parameters:
    ----------
    
    -> velocity is the velocity axis in units of meter/micro-seconds
    -> velocity_err2 is the square of the uncertainty in the velocity axis

    Returns - 2 NessiLists:
    ----------------------
    
    <- The wavelength axis in units of Angstroms
    <- The square of the uncertainty in the wavelength axis

    Exceptions:
    ----------
    
    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the lists are not recognized types

    """
    try:
        if velocity.__type__ != velocity_err2.__type__:
            raise TypeError("Velocity and Velocity Err2 arrays are "\
                            +"not the same type.")

        if velocity.__type__ == nessi_list.NessiList.DOUBLE:

            wavelength = nessi_list.NessiList(len(velocity))
            wavelength_err2 = nessi_list.NessiList(len(velocity))
            axis_manip_bind.velocity_to_wavelength_d(velocity.__array__,
                                                     velocity_err2.__array__,
                                                     wavelength.__array__,
                                                     wavelength_err2.__array__)

        else:
            raise TypeError("Unknown primitive type %s" \
                            % str(velocity.__type__))

        return (wavelength, wavelength_err2)

    except AttributeError:
        wavelength_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.velocity_to_wavelength_ss_d(float(velocity),
                                                    float(velocity_err2),
                                                    wavelength_ss)
        return (wavelength_ss.val, wavelength_ss.val_err2)

##
#\}

##
# \defgroup wavelength_to_d_spacing axis_manip::wavelength_to_d_spacing
# \{

##
# \brief This function is described in section 3.25.
#
# This function calculates the d-spacing given the wavelength according
# to the equation
# \f[
# d[i]=\frac{\lambda[i]}{2\sin(polar/2)}
# \f]
# Where \f$d\f$ is the d-spacing, \f$\lambda[i]\f$ is the wavelength,
# and \f$polar\f$ is the angle between the positive z-axis and
# the direction of the scattered neutron.
#
# Assuming that the uncertainties are uncorrelated, the square of the
# uncertainty of the energy axis is given by
#
# \f[
# \sigma^2_d[i] = \left(\frac{1}{2 \sin(polar/2)}\right)^2 
# \sigma^2_{\lambda}[i] + \left(\frac{\lambda[i] 
# \cot(polar/2)}{4 \sin(polar/2)}\right)^2 \sigma^2_{polar}
# \f]
#
# \param wavelength (INPUT) is the wavelength axis in units of
# Angstroms
# \param wavelength_err2 (INPUT) is the square of the uncertainty
# in the wavelength axis
# \param polar (INPUT) is the polar angle in the equation above in
# units of radians
# \param polar_err2 (INPUT) is the square of the uncertainty in polar
#
# \return
# - The d is the d-spacing axis in units of Angstrom
# - The d_err2 is the square of the uncertainty
# in the d-spacing axis
#
# \exception IndexError is thrown if the arrays are not of compatible  sizes
# \exception TypeError is thrown if any of the lists are not recognized types

def wavelength_to_d_spacing(wavelength, wavelength_err2, polar, polar_err2):

    """
    This function converts the wavelength to scalar momentum transfer
    according to the equation

    d[i] = lambda[i] / (2 * sin(polar / 2))

    Where d[i] is the d-spacing axis, lambda[i] is the wavelength,
    and polar is the angle between the positive z-axis and the direction of
    the scattered neutron.

    Using the assumption of uncorrelated uncertainties, the square of the
    uncertainty of the scalar momentum transfer is given by

    d_err2[i] = lambda_err2[i] / (2 * sin(polar / 2))^2 +
    polar_err2 * ((lambda[i] * cot(polar / 2)) / (4 * sin(polar / 2)))^2

    Parameters:
    ----------
    -> wavelength is the wavelength axis in units of Angstroms
    -> wavelength_err2 is the square of the uncertainty in the wavelength axis
    -> polar is the polar angle in the equation above in units of radians
    -> polar_err2 is the square of the uncertainty in polar

    Returns - 2 NessiLists:
    ----------------------
    <- The d[i] is in units of Angstroms
    <- The square of the uncertainty in the d_spacing axis

    Exceptions:
    ----------
    <- IndexError is thrown if the arrays are not of compatible  sizes
    <- TypeError is thrown if any of the lists are not recognized types

    """

    try:
        if wavelength.__type__ != wavelength_err2.__type__:
            raise TypeError("Wavelength and Wavelength Err2 arrays are not " \
                            +"the same type")

        if (wavelength.__type__ == nessi_list.NessiList.DOUBLE):
            d_spacing = nessi_list.NessiList(len(wavelength))
            d_spacing_err2 = nessi_list.NessiList(len(wavelength))
            axis_manip_bind.wavelength_to_d_spacing_d(\
                wavelength.__array__,\
                wavelength_err2.__array__,\
                float(polar),\
                float(polar_err2),\
                d_spacing.__array__,\
                d_spacing_err2.__array__)

        else:
            raise TypeError("Unknown primative type %s" \
                            % str(wavelength.__type__))

        return (d_spacing, d_spacing_err2)

    except AttributeError:
        d_spacing_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.wavelength_to_d_spacing_ss_d(\
            float(wavelength),\
            float(wavelength_err2),\
            float(polar),\
            float(polar_err2),\
            d_spacing_ss)
        return (d_spacing_ss.val, d_spacing_ss.val_err2)

##
# \}

##
# \defgroup wavelength_to_energy axis_manip::wavelength_to_energy
# \{

##
# \brief This function calculates the energy of a neutron given its wavelength
#
# This function is described in section 3.22 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function calculates the energy of a neutron given its
# wavelength according to the equation
# \f[
# E[i]=\frac{h^2}{2 m_n \lambda[i]^2}
#     =\frac{81.83 Angstrom^2}{\lambda[i]^2} meV
# \f]
# Where \f$E\f$ is energy of the neutron, \f$h\f$ is Planck's
# constant, \f$m_n\f$ is the mass of the neutron, and \f$lambda\f$
# is the wavelength of the neutron.
#
# Assuming that the uncertainty are uncorrelated, the uncertainty
# in the energy is defined by
# \f[
# \sigma^2_E[i]=\left(\frac{2E}{\lambda}\right)^2\sigma^2_{\lambda}[i]
# \f]
# where \f$\sigma_E\f$ is the uncertainty in the energy, and
# \f$\sigma_{\lambda}\f$ is the uncertainty in the wavelength axis.
#
# \param wavelength (INPUT) is the wavelength axis in units of
# angstroms
# \param wavelength_err2 (INPUT) is the square of the uncertainty
# in the wavelength axis
#
# \return
# - The energy of the neutron in units of meV
# - The square of the uncertainty in the energy
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def wavelength_to_energy(wavelength, wavelength_err2):

    """
    ---------------------------------------------------------------------------

    This function calculates the energy of a neutron given its
    wavelength according to the equation:

    E[i] = (h^2)/(2.m_n.lambda[i]^2)
         = (81.83 Angstroms^2)/(lambda[i]^2) meV

    where E is the energy of the neutron, h is Planck's constant,
    m_n is the mass of the neutron, and lambda is the wavelength of
    the neutron.

    Assuming that the uncertainties are uncorrelated, the uncertainty in the
    energy is defined by:

    E_err2[i]^2 = (2.E/lambda)^2.lambda_err2[i]^2

    where E_err2 is the uncertainty in the energy, and
    lambda_err2 is the uncertainty in the wavelength axis.

    Parameters:
    __________

    -> wavelength is the wavelength axis in units of Angstroms
    -> wavelength_err2 is the square of the uncertainty in the wavelength
       axis

    Returns 2 NessiLists:
    ______________________

    <- the energy of the neutron in units of meV
    <- the square of the uncertainty in the energy

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types

    """
    try:
        if wavelength.__type__ != wavelength_err2.__type__:
            raise TypeError("Wavelength and Wavelength Err2 arrays are not " \
                            +"the same type")

        if (wavelength.__type__ == nessi_list.NessiList.DOUBLE):
            energy = nessi_list.NessiList(len(wavelength))
            energy_err2 = nessi_list.NessiList(len(wavelength))
            axis_manip_bind.wavelength_to_energy_d(wavelength.__array__, \
                                                   wavelength_err2.__array__,\
                                                   energy.__array__,\
                                                   energy_err2.__array__)
        else:
            raise TypeError("Unknown primitive type %s" % \
                            str(wavelength.__type__))

        return (energy, energy_err2)

    except AttributeError:
        energy_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.wavelength_to_energy_ss_d(\
      float(wavelength),\
      float(wavelength_err2),\
      energy_ss)
        return (energy_ss.val, energy_ss.val_err2)

##
# \}


##
# \defgroup wavelength_to_scalar_k axis_manip::wavelength_to_scalar_k
# \{

##
# \brief This function calculates the scalar wavevector given the wavelength
#
# This function is described in section 3.24 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function calculates the scalar wavevector given the
# wavelength according to the equation
# \f[
# k[i]=\frac{2\pi}{\lambda[i]}
# \f]
# Where \f$k[i]\f$ is the scalar wavevector, and \f$\lambda\f$ is
# the wavelength.
#
# Assuming that the uncertainties are uncorrelated, the uncertainty
# in the scalar wavevector is given by
# \f[
# \sigma^2_k[i]=\left(\frac{k[i]}{\lambda}\right)^2\sigma^2_{\lambda}[i]
# \f]
# where \f$\sigma_k\f$ is the uncertainty in the scalar wavevector, and
# \f$\sigma_{\lambda}\f$ is the uncertainty in the wavelength axis.
#
# \param wavelength (INPUT) is the wavelength axis in units of
# Angstroms
# \param wavelength_err2 (INPUT) is the square of the uncertainty
# in the wavelength axis
#
# \return
# - The scalar wavevector in units of reciprocal Angstroms
# - The square of the uncertainty in the scalar wavevector
#
# \exception IndexError is thrown if the arrays are not of compatible
# sizes
# \exception TypeError is thrown if any of the arrays are not
# recognized types

def wavelength_to_scalar_k(wavelength, wavelength_err2):

    """
    ---------------------------------------------------------------------------

    This function calculates the scalar wavevector given the
    wavelength according to the equation:

    k[i] = (2.Pi)/(lambda[i])

    where k[i] is the scalar wavevector, and lambda is the wavelength.

    assuming that the uncertainties are uncorrelated, the uncertainty
    in the scalar wavevector is given by:

    k_err2[i]^2 = (k[i]/lambda)^2.lambda_err2[i]^2

    where k_err2 is the uncertainty in the scalar wavevector, and
    lambda_err2 is the uncertainty in the wavelength axis.

    Parameters:
    __________

    -> wavelength is the wavelength axis in units of Angstroms
    -> wavelength_err2 is the square of the uncertainty in the wavelength_axis

    Returns 2 NessiLists:
    ______________________

    <- the scalar wavevector in units of reciprocal Angstroms
    <- the square of the uncertainty in the scalar wavevector

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types

    """

    try:
        if wavelength.__type__ != wavelength_err2.__type__:
            raise TypeError("Wavelength and Wavelength Err2 arrays are not " \
                            +"the same type")

        if (wavelength.__type__ == nessi_list.NessiList.DOUBLE):
            wavevector = nessi_list.NessiList(len(wavelength))
            wavevector_err2 = nessi_list.NessiList(len(wavelength))
            axis_manip_bind.wavelength_to_scalar_k_d(\
                    wavelength.__array__,\
                    wavelength_err2.__array__,\
                    wavevector.__array__,\
                    wavevector_err2.__array__)

        else:
            raise TypeError("Unknown primative type %s" \
                            % str(wavelength.__type__))

        return (wavevector, wavevector_err2)

    except AttributeError:
        wavevector_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.wavelength_to_scalar_k_ss_d(\
      float(wavelength),\
      float(wavelength_err2),\
      wavevector_ss)
        return (wavevector_ss.val, wavevector_ss.val_err2)

##
# \}


##
# \defgroup wavelength_to_scalar_Q axis_manip::wavelength_to_scalar_Q
# \{

##
# \brief This function calculates the scalar momentum transfer from wavelength
#
# This function is described in section 3.18 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function converts the wavelength to scalar momentum transfer
# according to the equation
# \f[
# Q[i]=\frac{4\pi}{\lambda[i]}\sin(polar/2)
# \f]
# Where \f$Q[i]\f$ is the scalar momentum transfer, \f$\lambda[i]\f$
# is the wavelength, and \f$polar\f$ is the angle between the
# positive z-axis and the direction of the scattered neutron.
#
# Using the assumption of uncorrelated uncertainties, the square of the
# uncertainty of the scalar momentum transfer is given by
# \f[
# \sigma^2_Q[i]=\left(\frac{4\pi}{\lambda[i]}\right)^2
# \left(\frac{cos(polar/2)^2}{4}\sigma_{polar}^2+\left(\frac{sin(polar/2)}
# {\lambda[i]}\right)^2\sigma^2_\lambda[i]\right)
# \f]
#
# \param wavelength (INPUT) is the wavelength axis in units of
# angstroms
# \param wavelength_err2 (INPUT) is the square of the uncertainty in the
 # wavelength axis
# \param polar (INPUT) is the polar angle in the equation above in
# units of radians
# \param polar_err2 (INPUT) is the square of the uncertainty in
# polar
#
# \return
# - The scalar momentum transfer, Q, axis in units of reciprocal angstroms
# - The square of the uncertainty in the scalar momentum transfer axis
#
# \exception IndexError is thrown if the arrays are not of compatible  sizes
# \exception TypeError is thrown if any of the lists are not recognized types

def wavelength_to_scalar_Q(wavelength, wavelength_err2, polar, polar_err2):

    """
    This function converts the wavelength to scalar momentum transfer
    according to the equation

    Q[i] = 4 pi / lambda[i] * sin(polar/2)

    Where Q[i] is the scalar momentum transfer, lambda[i] is the wavelength,
    and polar is the angle between the positive z-axis and the direction of
    the scattered neutron.

    Using the assumption of uncorrelated uncertainties, the square of the
    uncertainty of the scalar momentum transfer is given by

    sigma^2_Q[i] = (4 pi / lambda[i])^2 * ((cos(polar/2) / 2)^2 *
    sigma_polar^2) + ((sin(polar/2) / lambda[i])^2 * sigma^2_lambda[i])

    Parameters:
    ----------
    -> wavelength is the wavelength axis in units of angstroms
    -> wavelength_err2 is the square of the uncertainty in the wavelength axis
    -> polar is the polar angle in the equation above in units of radians
    -> polar_err2 is the square of the uncertainty in polar

    Returns - 2 NessiLists:
    ----------------------
    <- The scalar momentum transfer, Q, axis in units of reciprocal angstroms
    <- The square of the uncertainty in the scalar momentum transfer axis

    Exceptions:
    ----------
    <- IndexError is thrown if the arrays are not of compatible  sizes
    <- TypeError is thrown if any of the lists are not recognized types

    """

    try:
        if wavelength.__type__ != wavelength_err2.__type__:
            raise TypeError("Wavelength and Wavelength Err2 arrays are not " \
                            +"the same type")

        if (wavelength.__type__ == nessi_list.NessiList.DOUBLE):
            Q = nessi_list.NessiList(len(wavelength))
            Q_err2 = nessi_list.NessiList(len(wavelength))
            axis_manip_bind.wavelength_to_scalar_Q_d(\
                    wavelength.__array__,\
                    wavelength_err2.__array__,\
                    float(polar),\
                    float(polar_err2),\
                    Q.__array__,\
                    Q_err2.__array__)

        else:
            raise TypeError("Unknown primative type %s" \
                            % str(wavelength.__type__))

        return (Q, Q_err2)

    except AttributeError:
        Q_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.wavelength_to_scalar_Q_ss_d(\
      float(wavelength),\
      float(wavelength_err2),\
      float(polar),\
      float(polar_err2),\
      Q_ss)
        return (Q_ss.val, Q_ss.val_err2)

##
# \}

##
# \defgroup wavelength_to_tof axis_manip::wavelength_to_tof
# \{
#
   
##
# \brief This function calculates time-of-flight from wavelength
#
# This function is described in section 3.16 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function converts the wavelength to time-of-flight according
# to the equation
# \f[
# TOF[i]=\frac{m_n L \lambda[i]}{h}
# \f]
# Where \f$TOF[i]\f$ is the time-of-flight, \f$m_n\f$ is the mass
# of the neutron, \f$L\f$ is the total flight path of the neutron,
# \f$\lambda[i]\f$ is the wavelength, and \f$h\f$ is Planck's
# constant. The uncertainty is calculated using the assumption of
# uncorrelated uncertainties.
#
# Assuming that the uncertainties are uncorrelated, the square of the 
# uncertainty in time-of-flight is given by
# \f[
# \sigma^2_{TOF}[i]=\left(\frac{m_n \lambda[i]}{h}\right)^2\sigma^2_L +
# \left(\frac{m_n L}{h}\right)^2\sigma^2_{\lambda}[i]
# \f]
# where \f$\sigma_{TOF}[i]\f$ is the uncertainty in the time of flight 
# axis, \f$\sigma_{\lambda}[i]\f$ is the uncertainty in the wavelength 
# axis and \f$\sigma_L\f$ is the uncertainty in the pathlength.
#
# \param wavelength (INPUT) is the wavelength axis in units of
# angstroms
# \param wavelength_err2 (INPUT) is the square of the uncertainty
# in the wavelength axis
# \param pathlength (INPUT) is the total flight path of the neutron
# in units of meter
# \param pathlength_err2 (INPUT) is the square of the uncertainty
# in pathlength
#
# \return
# - The time-of-flight axis in units of micro-seconds
# - The square of the uncertainty in the time-of-flight axis
#
# \exception IndexError is thrown if the arrays are not of compatible  sizes
# \exception TypeError is thrown if any of the lists are not recognized types
#

def wavelength_to_tof(wavelength, wavelength_err2, pathlength,
                      pathlength_err2):
    """
    This function converts the wavelength to time-of-flight according to the
    equation

    TOF[i] = (m_n L lambda[i]) / h

    Where TOF[i] is the time-of-flight, m_n is the mass of the neutron, L is
    the total flight path of the neutron, lambda[i] is the wavelength, and h is
    Planck's constant. The uncertainty is calculated using the assumption of
    uncorrelated uncertainties.

    Assuming that the uncertainties are uncorrelated, the square of the 
    uncertainty in time-of-flight is given by

    sigma^2_TOF[i] = ((m_n lambda[i])/h)^2 sigma^2_L + ((m_n L)/h)^2 *
    sigma^2_lambda[i]
    
    where sigma_TOF[i] is the uncertainty in the time of flight axis,
    sigma_lambda[i] is the uncertainty in the wavelength axis and sigma_L is
    the uncertainty in the pathlength.
    
    Parameters:
    __________

    -> wavelength is the wavelength axis in units of Angstroms
    -> wavelength_err2 is the square of the uncertainty in the wavelength axis
    -> pathlength is the total flight path of the neutron in units of meter
    -> pathlength_err2 is the square of the uncertainty in pathlength

    Returns - 2 NessiLists:
    ________________________

    <- the time-of-flight axis in units of micro-seconds
    <- the square of the uncertainty in the time-of-flight axis

    Exceptions:
    __________

    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the arrays are not recognized
       types
    """
    
    try:
        if wavelength.__type__ != wavelength_err2.__type__:
            raise TypeError("Wavelength and Wavelength Err2 arrays are "\
                            +"not the same type.")

        if wavelength.__type__ == nessi_list.NessiList.DOUBLE:

            tof = nessi_list.NessiList(len(wavelength))
            tof_err2 = nessi_list.NessiList(len(wavelength))
            axis_manip_bind.wavelength_to_tof_d(wavelength.__array__,
                                                wavelength_err2.__array__,
                                                float(pathlength),
                                                float(pathlength_err2),
                                                tof.__array__,
                                                tof_err2.__array__)

        else:
            raise TypeError("Unknown primitive type %s" \
                            % str(wavelength.__type__))

        return (tof, tof_err2)

    except AttributeError:
        tof_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.wavelength_to_tof_ss_d(float(wavelength),
                                               float(wavelength_err2),
                                               float(pathlength),
                                               float(pathlength_err2),
                                               tof_ss)
        return (tof_ss.val, tof_ss.val_err2)

##
#\}

##
# \defgroup wavelength_to_velocity axis_manip::wavelength_to_velocity
# \{
#

##
# \brief This function calculates velocity from wavelength
#
# This function is described in section 3.20 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function converts wavelength to velocity according to the equation
# \f[
# v[i]=\frac{h}{m_n \lambda[i]}
# \f]
# Where \f$v[i]\f$ is the velocity, \f$h\f$ is Planck's constant, \f$m_n\f$ 
# is the mass of the neutron, and \f$\lambda[i]\f$ is the wavelength. The 
# uncertainty is calculated using the assumption of uncorrelated 
# uncertainties.
#
# Assuming that the uncertainties are uncorrelated, the square of the 
# uncertainty in velocity is given by
# \f[
# \sigma^2_v[i] = \left(\frac{v[i]}{\lambda[i]}\right)^2 
# \sigma^2_{\lambda}[i]
# \f]
# where \f$\sigma^2_v[i]\f$ is the uncertainty in the velocity axis and 
# \f$\sigma^2_{\lambda}[i]\f$ is the uncertainty in the wavelength axis.
#
# \param wavelength (INPUT) is the wavelength axis in units of Angstroms
# \param wavelength_err2 (INPUT) is the square of the uncertainty in the 
# wavelength axis
#
# \return
# - The velocity axis in units of meter/micro-seconds
# - The square of the uncertainty in the velocity axis
#
# \exception IndexError is thrown if the arrays are not of compatible sizes
# \exception TypeError is thrown if any of the lists are not recognized types
#

def wavelength_to_velocity(wavelength, wavelength_err2):
    """
    This function converts wavelength to velocity according to the equation

    v[i] = h / (m_n lambda[i])

    where v[i] is the velocity, h is Planck's constant, m_n is the mass of the
    neutron, and lambda[i] is the wavelength. The uncertainty is calculated
    using the assumption of uncorrelated uncertainties.

    Assuming that the uncertainties are uncorrelated, the square of the 
    uncertainty in velocity is given by

    sigma^2_v[i] = (v[i] / lambda[i])^2 * sigma^2_lambda[i]

    where sigma^2_v[i] is the uncertainty in the velocity axis and
    sigma^2_lambda[i] is the uncertainty in the wavelength axis.

    Parameters:
    ----------
    
    -> wavelength is the wavelength axis in units of Angstroms
    -> wavelength_err2 is the square of the uncertainty in the wavelength axis

    Returns - 2 NessiLists:
    ----------------------
    
    <- The velocity axis in units of meter/micro-seconds
    <- The square of the uncertainty in the velocity axis

    Exceptions:
    ----------
    
    <- IndexError is thrown if the arrays are not of compatible sizes
    <- TypeError is thrown if any of the lists are not recognized types

    """
    try:
        if wavelength.__type__ != wavelength_err2.__type__:
            raise TypeError("Wavelength and Wavelength Err2 arrays are "\
                            +"not the same type.")

        if wavelength.__type__ == nessi_list.NessiList.DOUBLE:

            velocity = nessi_list.NessiList(len(wavelength))
            velocity_err2 = nessi_list.NessiList(len(wavelength))
            axis_manip_bind.wavelength_to_velocity_d(wavelength.__array__,
                                                     wavelength_err2.__array__,
                                                     velocity.__array__,
                                                     velocity_err2.__array__)

        else:
            raise TypeError("Unknown primitive type %s" \
                            % str(wavelength.__type__))

        return (velocity, velocity_err2)

    except AttributeError:
        velocity_ss = vpair_bind.DoubleVPair()
        axis_manip_bind.wavelength_to_velocity_ss_d(float(wavelength),
                                                    float(wavelength_err2),
                                                    velocity_ss)
        return (velocity_ss.val, velocity_ss.val_err2)

##
#\}
