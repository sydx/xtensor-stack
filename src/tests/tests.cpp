#include <iostream>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

#include <xtensor-blas/xlinalg.hpp>

void test_xtensor()
{
    xt::xarray<double> arr1
      {{1.0, 2.0, 3.0},
       {2.0, 5.0, 7.0},
       {2.0, 5.0, 7.0}};

    xt::xarray<double> arr2
      {5.0, 6.0, 7.0};

    xt::xarray<double> res = xt::view(arr1, 1) + arr2;

    std::cout << res << std::endl;
}

void test_xtensor_blas()
{
    xt::xarray<double> arr
      {{1.0, -0.5},
       {-0.5, 2.0}};
    auto chol = xt::linalg::cholesky(arr);

    std::cout << chol << std::endl;
}

int main()
{
    std::cout << "Testing the xtensor-blas stack" << std::endl;

    std::cout << "xtensor" << std::endl;
    test_xtensor();

    std::cout << "xtensor-blas" << std::endl;
    test_xtensor_blas();
}
