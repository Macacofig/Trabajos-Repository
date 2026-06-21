import {saludar} from "./Chatbot.js";

const nombreInput = document.getElementById("nombre");
const edadInput = document.getElementById("edad-input");
const form = document.getElementById("chat-form");
const div = document.getElementById("chat-output");

form.addEventListener("submit", (event) => {
    event.preventDefault();

    const nombre = nombreInput.value;
    const edad =  Number.parseInt(edadInput.value);
    const idioma = document.querySelector('input[name="idioma"]:checked');
    const genero = document.querySelector('input[name="genero"]:checked');
    div.innerHTML =  "<p>" + saludar(nombre, genero.value, edad,idioma.value) + "</p>";
});
