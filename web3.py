import numpy as np
import matplotlib.pyplot as plt
from web3 import Web3


initial_price = 1.0
mu = 0.01  
sigma = 0.05  
timesteps = 100


prices = [initial_price]
for _ in range(timesteps):
    random_shock = np.random.normal(loc=mu, scale=sigma)
    new_price = prices[-1] * (1 + random_shock)
    prices.append(new_price)


plt.plot(prices)
plt.xlabel("Tempo")
plt.ylabel("Preço da StableCoin (ETH)")
plt.title("Simulação de Mercado com Modelo Estocástico")
plt.show()


w3 = Web3(Web3.HTTPProvider("http://127.0.0.1:8545"))
contract_address = "0x.."
abi = [...]  
contract = w3.eth.contract(address=contract_address, abi=abi)


current_price = contract.functions.price().call()
print(f"Preço atual no contrato: {current_price / 1e18} ETH")

external_market_price = prices[-1] * 1e18  
arbitrage_message = contract.functions.arbitrageOpportunity(int(external_market_price)).call()
print("Oportunidade de arbitragem:", arbitrage_message)






