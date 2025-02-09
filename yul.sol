//SPDX-License-Identifier: MIT
pragma solidity ^0.8.26;

contract AssemblyYum {

function fastMulDiv (uint256 x, uint256 y, uint256 z) public pure returns (uint256 result) {
assembly {
    let product := mul(x, y )
    result := div(product, z)
}   
}
}