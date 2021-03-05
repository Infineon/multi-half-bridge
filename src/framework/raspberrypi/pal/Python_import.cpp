/**-------------------------------------------------------------------------------------------------------------------------------
* Imports python - time module and generates delay for specified measurement_time
* @param measurement_time : Required delay time in sec
* @return Status of operation
* @retval 1: Successful
* @retval 0: Operation failed
*/
#include <pybind11/embed.h>
#include "Python_import.hpp"

bool delay(uint16_t measurement_time){
	auto mod = pybind11::module::import("Python_modules");	
	bool ret_status = mod.attr("Delay_py")(measurement_time).cast<bool>();
	return ret_status;
} 
