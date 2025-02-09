#include <iostream>
#include <vector>
#include <random>
#include <omp.h> //inclusão do paralelismo (OPENMP)

using namespace std;

const int timesteps = 10000; //testamento de perfomance dos codigos em sol
const double mu =0.01;
const double sigma = 0.05;

int main() {

    vector<double>prices(timesteps);
    prices[0] = 1.0;

    random_device rd;
    mt19937 gen(rd());
    normal_distribution<double> dist(mu , sigma);

    #pragma omp parallel for //paralelismo  
    for (int i = 1; i < timesteps; i++) {
        prices[i] = prices[i-1] * (1.0 + dist(gen));
    }

    cout << "Preço final simulacao: " << prices[timesteps - 1] << endl;
    return 0;
}
