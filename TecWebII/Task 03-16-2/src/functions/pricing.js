const cards = document.querySelectorAll(".pricing .card");
const buttons = document.querySelectorAll(".pricing .card .btn");

buttons.forEach((btn, index) => {
    btn.addEventListener("click", () => {

        // quitar destacado a todas
        cards.forEach(card => {
            card.classList.remove("card--featured");
        });

        // agregar destacado a la tarjeta clickeada
        cards[index].classList.add("card--featured");

    });
});