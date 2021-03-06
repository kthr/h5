#include <H5Cpp.h>
#include <Rcpp.h>

#ifndef __Helpers_h__
#define __Helpers_h__
enum DTYPE { T_DOUBLE, T_INTEGER, T_LOGICAL, T_CHARACTER, T_VLEN_FLOAT,
	T_VLEN_DOUBLE, T_VLEN_INTEGER, T_VLEN_LOGICAL};
// Dataset functions
H5::DataType GetDataType(const DTYPE datatype, int size);
DTYPE GetTypechar(const H5::DataType &dtype);
DTYPE GetTypechar(char typechar);
char GetTypechar(DTYPE typechar);
void *ConvertBuffer(const SEXP &mat, DTYPE datatype, int stsize);
H5S_seloper_t GetOperator(std::string opstring);
SEXP AllocateRData(DTYPE tchar, Rcpp::NumericVector count);

SEXP ReadRData(DTYPE tchar, SEXP data,
			Rcpp::XPtr<H5::DataSet> dataset,
			Rcpp::XPtr<H5::DataSpace> memspace,
			Rcpp::XPtr<H5::DataSpace> dataspace);

SEXP ReadRDataAttribute(DTYPE tchar, SEXP data,
		Rcpp::XPtr<H5::Attribute> attribute);

#endif // __Dataset_h__

