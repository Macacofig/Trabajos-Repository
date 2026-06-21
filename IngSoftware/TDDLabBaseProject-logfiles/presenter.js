import {sumar, multiplicar} from "./Operadores.js";

const first = document.querySelector("#primer-numero");
const second = document.querySelector("#segundo-numero");
const form1 = document.querySelector("#sumar-form");
const div = document.querySelector("#resultado-div");

form1.addEventListener("submit", (event) => {
  event.preventDefault();

  const firstNumber = Number.parseInt(first.value);
  const secondNumber = Number.parseInt(second.value);

  div.innerHTML = "<p>" + sumar(firstNumber, secondNumber) + "</p>";
});

const firstM = document.querySelector("#primer-numero-m");
const secondM = document.querySelector("#segundo-numero-m");
const form2 = document.querySelector("#multiplicar-form");

form2.addEventListener("submit", (event) => {
  event.preventDefault();

  const first2 = Number.parseInt(firstM.value);
  const second2 = Number.parseInt(secondM.value);
  div.innerHTML = "<p>" + multiplicar(first2, second2) + "</p>";
});
