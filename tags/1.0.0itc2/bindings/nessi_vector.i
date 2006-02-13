// nessi_vector.i - SWIG interface
//
// $Id$
//
%module nessi_vector_bind
%{
#include "nessi.hpp"
%}

%include "std_vector.i"
%include "nessi.hpp"

namespace std {
	%template(IntVector) vector<int>;
	%template(DoubleVector) vector<double>;
	%template(FloatVector) vector<float>;
	%template(UnsignedIntVector) vector<unsigned>;
}

namespace Nessi {
	%template(IntNessiVector) Vector<int>;
	%template(DoubleNessiVector) Vector<double>;
	%template(FloatNessiVector) Vector<float>;
	%template(UnsignedIntNessiVector) Vector<unsigned>;
}