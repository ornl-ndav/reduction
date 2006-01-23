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

/**
 * $Id$
 *
 * \file nessi/libinfo.hpp
 */
/**
 * The purpose of this file is to add information to the main index page for
 * the SNS Data Reduction Library documentation.
 *
 * \mainpage SNS Common Libraries 1.0.0alpha
 *
 * \section rules Rules of the Library
 *
 * To provide the greatest inter-language and inter-facility
 * operability, the data reduction library will be implemented as C++
 * functions. In addition, those functions will follow a set of rules
 * that will provide the application programmer with confidence that
 * the library is well-formed, does not affect outside systems and
 * does not maintain state. The rules are:
 *
 * -# There will be no global/package variables.
 * -# There will be no side effects.
 * -# They will be thread safe.
 * -# They will neither allocate nor de-allocate any persistent
 * resources. This allows for allocating (and de-allocating) temporary
 * memory for calculations.
 * -# There will be at least one smoke test for every function.
 * -# Functions will create no heap memory. The functions will need to
 * be passed the arguments, space for the results, and space for any
 * temporary storage needed. To notify the caller of how much memory
 * is needed for temporary space, any function that uses temporary
 * space may have a related utility function that returns information
 * on the amount of temporary storage needed. If the user passes in
 * null pointers for the temporary storage the function is intended to
 * allocate and de-allocate what is needed.
 * -# The functions will return an integer status report with a helper
 * function that creates strings according to that value.
 *
 * \section template_types Template Types
 *
 * In various sections of the library the user will encounter the
 * template types:
 * - \p NumT - Any numeric type
 * - \p T - Any type that vector supports
 *
 * \section naming_convention Function Naming Conventions
 *
 * To make the library easier to navigate without documentation there
 * are some naming conventions that were created.
 *
 * \arg _ncerr This extension denotes that the function calculations
 * the uncertainties assuming non-correlated errors
 *
 * \section definitions Definitions
 *
 * \subsection definitions-histogram Histogram
 *
 * Some functions in the library assume that the information supplied
 * is a histogram. A histogram is defined as a list of bin boundaries
 * and a weight contained with within the boundaries. In practical
 * terms this means that the independant variable array has one more
 * value than the function array.
 *
 * The other requirement of histograms is that thier independent axis
 * is monotonically increasing. Note that this does require that the
 * bins are of equal size.
 *
 * \section library_coords Library Coordinate System
 *
 * \image html Coordinates.jpg 
 * \image latex Coordinates.eps "Library Coordinate System" width=10cm
 *
 * The figure shown above shows the coordinate system assumed by the SNS 
 * Common Libraries. This system was chosen to coincide with the coordinate 
 * system chosen for NeXus.
 */
