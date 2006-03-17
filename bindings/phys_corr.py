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
# \file bindings/phys_corr.py
#

"""
   This module gives NessiList access to the various correction routines
   provided by the C++ phys_corr library. These functions are written in
   reference to SNS 107030214-TD0001-R00, \"Data Reduction Library Software
   Requirements and Specifications.\"

   Once a function is called, according to the type of the NessiLists calling
   it, the module redirects the call to the right function.
"""

##
# \namespace phys_corr
#
# \brief This Python abstraction layer module contains the various corrections
#        that require a model of the data.
#
# This module gives NessiList access to the various correction routines
# provided by the <i>phys_corr</i> library. These functions are written in
# reference to SNS 107030214-TD0001-R00, "Data Reduction Library Software
# Requirements and Specifications."
#
# Once a function is called, according to the type of the NessiLists calling
# it, the module redirects the call to the right function.
