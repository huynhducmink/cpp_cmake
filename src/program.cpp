#include <iostream>
#include "program.h"
#include "module_1.h"
#include "module_2.h"
#include "lib1.h"
#include "lib2.h"

void start_program(){
  std::cout << "Program has started" << std::endl;
  hdm_module_1::hello_modulee_1();
  hdm_module_2::hello_modul_2();
  std::cout << "Sum of 1 and 2 from lib1: " << hdm_lib1::sum_int(1,2) << std::endl;
  std::cout << "Diff of 1 and 2 from lib2: " << hdm_lib2::minus_int(1,2) << std::endl;
}