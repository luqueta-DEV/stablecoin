#include <iostream>
#include <cpprest/http_client.h> //acessa Apis
#include <web3cpp/web3.h>  //Web C++ SDK (maquina virtual que compila o codigo)

using namespace std;
using namespace web;

string contractAddress = "0x..";
double priceThreshold = 1.02;

void checkArbitrage() {
    http_client client (U("http://api.exchange.com/price"));
    auto response = client.requesr(methods::GET).ger();
    double externalPrice = stod(response.extract_string().get());

    Web3 web3;
    web3.setProvider ("http://127.0.0.1:8545"); //conectando uma rede de nós local
    
    if (extenalPrice > contractPrice * pricesThreshold) {
        cout << "Oportinidade de arbitragem! Comprando SSC..." << end1;
         web3.eth.sendTransaction(contractAddress, "buySSC()", "0.5");  // Compra 0.5 ETH de SSC
    } else {
        cout << "Sem oportunidades de arbitragem." << endl;
    }
}
    
