const boton = document.getElementById("boton");
const titulo = document.getElementById("titulo");
const nombre = document.getElementById("nombre");
const mensaje = document.getElementById("mensaje");

boton.addEventListener("click", function(){

    let valor = nombre.value;

    // mostrar nombre
    mensaje.textContent = "Hola " + valor;

    // cambiar titulo
    titulo.textContent = "Bienvenido " + valor;

    // cambiar color
    titulo.style.color = "purple";
});