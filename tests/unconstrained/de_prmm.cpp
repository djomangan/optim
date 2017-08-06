//
// DE tests
//
// g++-mp-7 -O2 -Wall -std=c++11 -I/opt/local/include de_prmm.cpp -o de_prmm.test -L/opt/local/lib -loptim -framework Accelerate
// g++-mp-7 -O2 -Wall -std=c++11 -I./../../include de_prmm.cpp -o de_prmm.test -L./../.. -loptim -framework Accelerate
//

#include "optim.hpp"
#include "./../test_fns/test_fns.hpp"

int main()
{
    //
    // test 1
    arma::vec x_1 = arma::ones(2,1);

    bool success_1 = optim::de_prmm(x_1,unconstr_test_fn_1,nullptr);

    if (success_1) {
        std::cout << "de_prmm: test_1 completed successfully." << std::endl;
    } else {
        std::cout << "de_prmm: test_1 completed unsuccessfully." << std::endl;
    }

    arma::cout << "de_prmm: solution to test_1:\n" << x_1 << arma::endl;

    //
    // test 2

    arma::vec x_2 = arma::zeros(2,1);

    bool success_2 = optim::de_prmm(x_2,unconstr_test_fn_2,nullptr);

    if (success_2) {
        std::cout << "de_prmm: test_2 completed successfully." << std::endl;
    } else {
        std::cout << "de_prmm: test_2 completed unsuccessfully." << std::endl;
    }

    arma::cout << "de_prmm: solution to test_2:\n" << x_2 << arma::endl;

    //
    // test 3
    int test_3_dim = 5;
    arma::vec x_3 = arma::ones(test_3_dim,1);

    bool success_3 = optim::de_prmm(x_3,unconstr_test_fn_3,nullptr);

    if (success_3) {
        std::cout << "de_prmm: test_3 completed successfully." << std::endl;
    } else {
        std::cout << "de_prmm: test_3 completed unsuccessfully." << std::endl;
    }

    arma::cout << "de_prmm: solution to test_3:\n" << x_3 << arma::endl;

    //
    // test 4
    arma::vec x_4 = arma::ones(2,1);

    bool success_4 = optim::de_prmm(x_4,unconstr_test_fn_4,nullptr);

    if (success_4) {
        std::cout << "de_prmm: test_4 completed successfully." << std::endl;
    } else {
        std::cout << "de_prmm: test_4 completed unsuccessfully." << std::endl;
    }

    arma::cout << "de_prmm: solution to test_4:\n" << x_4 << arma::endl;

    //
    // test 6
    optim::optim_opt_settings opt_settings_6;

    opt_settings_6.de_lb = arma::zeros(2,1) - 2.0;
    opt_settings_6.de_ub = arma::zeros(2,1) + 2.0;
    opt_settings_6.de_n_pop = 200;

    unconstr_test_fn_6_data test_6_data;
    test_6_data.A = 10;

    arma::vec x_6 = arma::ones(2,1) + 1.0;

    bool success_6 = optim::de_prmm(x_6,unconstr_test_fn_6,&test_6_data,opt_settings_6);

    if (success_6) {
        std::cout << "de_prmm: test_6 completed successfully." << std::endl;
    } else {
        std::cout << "de_prmm: test_6 completed unsuccessfully." << std::endl;
    }

    arma::cout << "de_prmm: solution to test_6:\n" << x_6 << arma::endl;

    //
    // test 7
    arma::vec x_7 = arma::ones(2,1);

    bool success_7 = optim::de_prmm(x_7,unconstr_test_fn_7,nullptr);

    if (success_7) {
        std::cout << "de_prmm: test_7 completed successfully." << std::endl;
    } else {
        std::cout << "de_prmm: test_7 completed unsuccessfully." << std::endl;
    }

    arma::cout << "de_prmm: solution to test_7:\n" << x_7 << arma::endl;

    //
    // test 8
    arma::vec x_8 = arma::zeros(2,1);

    bool success_8 = optim::de_prmm(x_8,unconstr_test_fn_8,nullptr);

    if (success_8) {
        std::cout << "de_prmm: test_8 completed successfully." << std::endl;
    } else {
        std::cout << "de_prmm: test_8 completed unsuccessfully." << std::endl;
    }

    arma::cout << "de_prmm: solution to test_8:\n" << x_8 << arma::endl;

    //
    // test 9
    optim::optim_opt_settings opt_settings_9;
    
    opt_settings_9.de_lb = arma::zeros(2,1) - 2.0;
    opt_settings_9.de_ub = arma::zeros(2,1) + 2.0;

    arma::vec x_9 = arma::zeros(2,1);
    x_9(0) = -11.0;

    bool success_9 = optim::de_prmm(x_9,unconstr_test_fn_9,nullptr,opt_settings_9);

    if (success_9) {
        std::cout << "de_prmm: test_9 completed successfully." << std::endl;
    } else {
        std::cout << "de_prmm: test_9 completed unsuccessfully." << std::endl;
    }

    arma::cout << "de_prmm: solution to test_9:\n" << x_9 << arma::endl;

    //
    // for coverage

    optim::optim_opt_settings opt_settings;
    double val_out;

    optim::de_prmm(x_1,unconstr_test_fn_1,nullptr);
    optim::de_prmm(x_1,unconstr_test_fn_1,nullptr,opt_settings);
    optim::de_prmm(x_1,unconstr_test_fn_1,nullptr,val_out);
    optim::de_prmm(x_1,unconstr_test_fn_1,nullptr,val_out,opt_settings);

    x_7 = arma::ones(2,1) + 1.0;
    optim::de_prmm(x_7,unconstr_test_fn_7,nullptr,opt_settings);

    arma::cout << "de_prmm: solution to test_7:\n" << x_7 << arma::endl;

    return 0;
}