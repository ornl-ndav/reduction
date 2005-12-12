// vector.i - SWIG interface
//
// $Id$
//
%module vector
%include "std_vector.i"

namespace std {
	%template(IntVector) vector<int>;
	%template(DoubleVector) vector<double>;
	%template(FloatVector) vector<float>;
	%template(UnsignedIntVector) vector<unsigned>;
}
