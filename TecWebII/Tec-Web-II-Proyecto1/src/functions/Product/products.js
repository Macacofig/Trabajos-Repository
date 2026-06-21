document.addEventListener('DOMContentLoaded', () => {
    // Selección de elementos
    const chips = document.querySelectorAll('.chip');
    const track = document.getElementById('carouselTrack');
    const modal = document.getElementById('product-modal');
    const cards = document.querySelectorAll('.product-card');
    
    // Elementos internos del modal
    const modalTitle = document.getElementById('modal-titulo');
    const modalDetail = document.getElementById('modal-detalle');
    const modalPrice = document.getElementById('modal-precio');
    const modalImg = document.getElementById('modal-img');
    const modalCat = document.getElementById('modal-categoria'); // Corregido el ID

    //BUSCAR
    let found = false;
    const errorMsg = document.getElementById("search-error");
    const searchInput = document.getElementById("search-input");
    const categories = document.querySelectorAll(".category-view");

    searchInput.addEventListener("keydown", (e) => {
        searchInput.addEventListener("input", () => {
            errorMsg.classList.remove("active");
        });
        if (e.key !== "Enter") return;

        e.preventDefault(); // evitar submit o comportamientos raros

        const value = searchInput.value.toLowerCase().trim();
        errorMsg.classList.remove("active");
        errorMsg.textContent = "";
        if (!value) return;

        found = false;

        categories.forEach((category, index) => {
            const cards = category.querySelectorAll(".product-card");

            cards.forEach(card => {
                const title = card.querySelector("h3").innerText.toLowerCase();

                if (title.includes(value) && !found) {
                    found = true;

                    // mover carrusel
                    track.style.transform = `translateX(-${index * 25}%)`;

                    // actualizar chips
                    chips.forEach(c => c.classList.remove("active"));
                    chips[index].classList.add("active");

                    // abrir modal
                    openModal(card);
                }
            });
        });

        if (!found) {
            errorMsg.textContent = "No se encontró ningún producto";
            errorMsg.classList.add("active");
        }
        // limpiar input SIEMPRE después de Enter
        searchInput.value = "";
    });
    /**
     * LÓGICA DEL CARRUSEL
     */
    chips.forEach(chip => {
        chip.addEventListener('click', () => {
            chips.forEach(c => c.classList.remove('active'));
            chip.classList.add('active');

            const index = chip.getAttribute('data-index');
            track.style.transform = `translateX(-${index * 25}%)`;
        });
    });

    /**
     * LÓGICA DEL MODAL
     */
    const openModal = (card) => {
        // Extraer datos de la card
        const title = card.querySelector('h3').innerText;
        const detail = card.getAttribute('data-detail');
        const price = card.getAttribute('data-price');
        const category = card.getAttribute('data-cat') || "General";
        const imgSrc = card.querySelector('img').src;

        // Inyectar datos
        if(modalTitle) modalTitle.innerText = title;
        if(modalDetail) modalDetail.innerText = detail;
        if(modalPrice) modalPrice.innerText = price;
        if(modalImg) modalImg.src = imgSrc;
        if(modalCat) modalCat.innerText = category;

        // ACTIVAR MODAL (Usando la clase .active que tienes en tu SCSS)
        modal.classList.add('active');
        document.body.style.overflow = 'hidden';
    };

    const closeModal = () => {
        modal.classList.remove('active');
        document.body.style.overflow = 'auto';
    };

    // Eventos de las tarjetas
    cards.forEach(card => {
        card.addEventListener('click', (e) => {
            e.preventDefault();
            openModal(card);
        });
    });

    // Eventos de cierre
    const closeBtn = document.querySelector('.modal-close');
    const overlay = document.querySelector('.modal-overlay');

    if (closeBtn) closeBtn.addEventListener('click', closeModal);
    if (overlay) overlay.addEventListener('click', closeModal);

    document.addEventListener('keydown', (e) => {
        if (e.key === 'Escape' && modal.classList.contains('active')) {
            closeModal();
        }
    });
});

document.addEventListener('DOMContentLoaded', () => {
    const backToTopBtn = document.getElementById('backToTop');

    // 1. Mostrar/Ocultar el botón según el scroll
    window.addEventListener('scroll', () => {
        if (window.scrollY > 400) {
            backToTopBtn.classList.add('active');
        } else {
            backToTopBtn.classList.remove('active');
        }
    });

    // 2. Acción de volver arriba al hacer clic
    backToTopBtn.addEventListener('click', () => {
        window.scrollTo({
            top: 0,
            behavior: 'smooth' 
        });
    });
});

const toast = document.getElementById("toast");

// función para mostrar mensaje
function showToast() {
    toast.classList.add("show");

    setTimeout(() => {
        toast.classList.remove("show");
    }, 2000); // dura 2 segundos
}

document.querySelectorAll(".btn-add").forEach(button => {
    button.addEventListener("click", () => {
        showToast();
    });
});