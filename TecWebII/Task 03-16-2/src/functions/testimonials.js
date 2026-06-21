// TESTIMONIALS
const testimonialCards = document.querySelectorAll(".testimonial-card");
const toggleBtn = document.querySelector(".link-all");

let expanded = false;

// estado inicial
testimonialCards.forEach((card, index) => {
    if (index !== 0) {
        card.style.display = "none";
    }
});

toggleBtn.addEventListener("click", (e) => {
    e.preventDefault();

    expanded = !expanded;

    testimonialCards.forEach((card, index) => {
        if (index !== 0) {

            if (expanded) {
                card.style.display = "block";

                setTimeout(() => {
                    card.classList.remove("hidden");
                }, 50 + index * 120);

            } else {
                card.classList.add("hidden");

                setTimeout(() => {
                    card.style.display = "none";
                }, 300);
            }
        }
    });

    toggleBtn.textContent = expanded ? "Show Less ❮" : "See All ❯";
});