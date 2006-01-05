/**
 * $Id$
 *
 * \file nessi/libinfo.hpp
 */
/** 
 * The purpose of this file is to add information to the main index page for 
 * the SNS Data Reduction Library documentation.
 *
 * \mainpage SNS Data Reduction Library 1.0.0alpha
 *
 * \section Rules of the Library
 *
 * To provide the greatest inter-language and inter-facility
 * operability, the data reduction library will be implemented as C++
 * functions. In addition, those functions will follow a set of rules
 * that will provide the application programmer with confidence that
 * the library is well-formed, does not affect outside systems and
 * does not maintain state. The rules are:
 *
 * # There will be no global/package variables.
 * # There will be no side effects.
 * # They will be thread safe.
 * # They will neither allocate nor de-allocate any persistent
 * resources. This allows for allocating (and de-allocating) temporary
 * memory for calculations.
 * # There will be at least one unit test for every function.
 * # The functions will need to be passed the arguments, space for the
 * results, and space for any temporary storage needed. To notify the
 * caller of how much memory is needed for temporary space, any
 * function that uses temporary space must have a related utility
 * function that returns information on the amount of temporary
 * storage needed. If the user passes in null pointers for the
 * temporary storage the function is intended to allocate and
 * de-allocate what is needed.
 * # The functions will return an integer status report with a helper
 * function that creates strings according to that value.
 *
 * \section Function Naming Conventions
 *
 */
