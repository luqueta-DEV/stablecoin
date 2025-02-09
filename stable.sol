// SPDX-License-Identifier: MIT
pragma solidity ^0.8.26;

import "@openzeppelin/contracts/token/ERC20/ERC20.sol";
import "@openzeppelin/contracts/access/Ownable.sol";

contract stables is ERC-20, Ownable {

uint256 public reserveETH;
uint256 public price;
uint256 public volatility = 5;
uint256 public drift = 1;

}
construtor() ERC20("simulatedStableCoin", "SSC") {
price = 1 ether;

} 

function deposity() external payable {
require(msg.value > 0, "precisa enviar ETHER");
uint256 MintAmount = (msg.value * 1 ether) / price;
_mint(msg.sender, MintAmount);
reserveETH += msg.value;

}

function deposit() external payable {

require(msg.value > 0, "precisa enviar o ether");
uint256 mintAmount = msg.value * 1 ether) / price;
_mint(msg.sender, mintAmount);
reserveETH += msg.value;	

 
function withdraw(unit256 amount) external {
require(balanceOf(msg.sender) >= amount "valor insuficiente");
uint256 ethAmount = (amount * price) / 1 ether;
require(reserveETH >= ethAmount, "Reserva insuficiente");

_burn(msg.sender, amount);
reserveETH -= ethAmount;
payable(msg.sender).transfer(ethAmount);

}

function updateprice() external onlyOwner



