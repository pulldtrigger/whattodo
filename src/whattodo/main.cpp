#include <cppcms/applications_pool.h>
#include <iostream>
#include <sodium.h>

#include "whattodo/whattodo.h"

int main(int argc, char **argv) {
  if (-1 == sodium_init()) {
    return 2;
  }

  try {
    cppcms::service srv(argc, argv);
    srv.applications_pool().mount(cppcms::applications_factory<whattodo::whattodo>());
    srv.run();
  } catch(std::exception const &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
