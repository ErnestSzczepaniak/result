#ifndef _status_argument_h
#define _status_argument_h

/**
 * @file	status_argument.h
 * @author	en2
 * @date	20-04-2020
 * @brief	
 * @details	
**/

#include "status.h"

namespace status::argument
{

status_class(Argument, Size_mismatch);
status_class(Argument, Type_mismatch);
status_class(Argument, Address_unaligned);
status_class(Argument, Address_empty);
status_class(Argument, Out_of_range);

}; /* namespace: status::argument */

#endif /* define: status_argument_h */