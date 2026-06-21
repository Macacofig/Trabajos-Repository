const phones = document.querySelectorAll(".screenshots__slider .phone");
const dots = document.querySelectorAll(".screenshots__dots .dot");

function updateCarousel(centerIndex) {

    phones.forEach(phone => {
        phone.classList.remove("left", "center", "right");
    });

    const left = (centerIndex - 1 + phones.length) % phones.length;
    const right = (centerIndex + 1) % phones.length;

    phones[left].classList.add("left");
    phones[centerIndex].classList.add("center");
    phones[right].classList.add("right");

    dots.forEach(dot => dot.classList.remove("active"));
    dots[centerIndex].classList.add("active");
}

dots.forEach((dot, index) => {
    dot.addEventListener("click", () => {
        updateCarousel(index);
    });
});

// estado inicial
updateCarousel(1);