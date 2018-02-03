/*################################################################################
  ##
  ##   Copyright (C) 2016-2018 Keith O'Hara
  ##
  ##   This file is part of the OptimLib C++ library.
  ##
  ##   OptimLib is free software: you can redistribute it and/or modify
  ##   it under the terms of the GNU General Public License as published by
  ##   the Free Software Foundation, either version 2 of the License, or
  ##   (at your option) any later version.
  ##
  ##   OptimLib is distributed in the hope that it will be useful,
  ##   but WITHOUT ANY WARRANTY; without even the implied warranty of
  ##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ##   GNU General Public License for more details.
  ##
  ################################################################################*/

/*
 * Newton tests
 */

#include "optim.hpp"
#include "./../test_fns/test_fns.hpp"

int main()
{
    std::cout << "\n     ***** Begin Newton tests. *****     \n" << std::endl;

    //
    // test 3

    int test_3_dim = 5;
    arma::vec x_3 = arma::ones(test_3_dim,1);

    bool success_3 = optim::newton(x_3,unconstr_test_fn_3_whess,nullptr);

    if (success_3) {
        std::cout << "\nnewton: test_3 completed successfully." << std::endl;
    } else {
        std::cout << "\nnewton: test_3 completed unsuccessfully." << std::endl;
    }

    std::cout << "Distance from the actual solution to test_3:\n" \
              << arma::norm(x_3 - unconstr_test_sols::test_3(test_3_dim)) << std::endl;

    //

    std::cout << "\n     ***** End Newton tests. *****     \n" << std::endl;

    return 0;
}
