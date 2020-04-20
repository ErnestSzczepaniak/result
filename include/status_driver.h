#ifndef _status_driver_h
#define _status_driver_h

/**
 * @file	status_driver.h
 * @author	en2
 * @date	20-04-2020
 * @brief	
 * @details	
**/

#include "status.h"

namespace status::driver
{

status_class(Driver, Open_error);
status_class(Driver, Close_error);
status_class(Driver, Write_error);
status_class(Driver, Read_error);
status_class(Driver, Timeout);
status_class(Driver, Failure);
status_class(Driver, Busy);
status_class(Driver, Bad_configuration);
status_class(Driver, Restart_needed);
status_class(Driver, Not_present);
status_class(Driver, Not_responding);
status_class(Driver, Hardware_fault);

}; /* namespace: error::driver */

#endif /* define: error_driver_h */