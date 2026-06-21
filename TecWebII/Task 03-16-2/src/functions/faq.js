const faqItems = document.querySelectorAll(".faq__item");

faqItems.forEach(item => {
    const icon = item.querySelector(".plus-icon");

    item.addEventListener("click", () => {

        const isActive = item.classList.contains("active");

        // cerrar todos (opcional tipo acordeón)
        faqItems.forEach(i => {
            i.classList.remove("active");
            i.querySelector(".plus-icon").textContent = "+";
        });

        if (!isActive) {
            item.classList.add("active");
            icon.textContent = "-";
        }
    });
});