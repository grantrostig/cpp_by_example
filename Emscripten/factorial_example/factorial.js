// Import the WebAssembly module
const WASM = import('./factorial.wasm');

async function calculateFactorial() {
  const number = document.getElementById('numberInput').value;
  const intNumber = parseInt(number);

  // Wait for the WebAssembly module to load
  const { factorial } = await WASM;

  // Call the C++ function from JavaScript
  const result = factorial(intNumber);

  // Display the result
  document.getElementById('result').textContent = `The factorial of ${number} is ${result}`;
}

