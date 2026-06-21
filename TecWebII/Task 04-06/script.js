// function calcularTotal(precio, cantidad, descuento) {
// return precio * cantidad - descuento;
// }
// let total1 = calcularTotal(10, 2, 5);
// let total2 = calcularTotal("10", 2, 5);
// let total3 = calcularTotal(10, "2", "5");
// console.log("Total 1:", total1);
// console.log("Total 2:", total2);
// console.log("Total 3:", total3);

// function saludar(usuario) {
// return "Hola " + usuario.nombre.toUpperCase();
// }
// let user1 = { nombre: "Juan" };
// let user2 = { name: "Maria" };
// console.log(saludar(user1));
// console.log(saludar(user2));

// function calcularTotal(precio, cantidad, descuento) {
// if (typeof precio !== "number") throw new Error("Precio inválido");
// if (typeof cantidad !== "number") throw new Error("Cantidad inválida");
// if (typeof descuento !== "number") throw new Error("Descuento inválido");
// return precio * cantidad - descuento;
// }
// let total1 = calcularTotal(10, 2, 5);
// console.log("Total 1:", total1);
// let total2 = calcularTotal("10", 2, 5);
// console.log("Total 2:", total2);
// let total3 = calcularTotal(10, "2", "5");
// console.log("Total 3:", total3);

function saludar(usuario) {
    if (!usuario.nombre) throw new Error("El usuario debe tener un nombre");
    if (typeof usuario.nombre !== "string") throw new Error("El usuario debe tener un nombre válido");
    return "Hola " + usuario.nombre.toUpperCase();
    }

let user1 = { nombre: "Juan" };
let user2 = { name: "Maria" };
console.log(saludar(user1));
console.log(saludar(user2));