// Selección del contenedor
const track = document.querySelector('.features__track');

// 1. Crear y configurar botones
const btnLeft = document.createElement('button');
const btnRight = document.createElement('button');

btnLeft.innerHTML = '‹';
btnRight.innerHTML = '›';

btnLeft.classList.add('features__btn', 'left');
btnRight.classList.add('features__btn', 'right');

document.querySelector('.features').appendChild(btnLeft);
document.querySelector('.features').appendChild(btnRight);

// 2. Lógica de navegación CIRCULAR
btnRight.addEventListener('click', () => {
    const card = document.querySelector('.card');
    const cardWidth = card.offsetWidth + 40; // Ancho + gap (2.5rem aprox)
    
    // Calculamos cuánto scroll falta para llegar al final real
    const maxScroll = track.scrollWidth - track.clientWidth;

    // Si ya estamos en el final (o muy cerca por decimales)
    if (track.scrollLeft >= maxScroll - 5) {
        track.scrollTo({
            left: 0,
            behavior: 'smooth'
        });
    } else {
        track.scrollBy({
            left: cardWidth,
            behavior: 'smooth'
        });
    }
});

btnLeft.addEventListener('click', () => {
    const card = document.querySelector('.card');
    const cardWidth = card.offsetWidth + 40;

    // Si ya estamos al principio
    if (track.scrollLeft <= 5) {
        const maxScroll = track.scrollWidth - track.clientWidth;
        track.scrollTo({
            left: maxScroll,
            behavior: 'smooth'
        });
    } else {
        track.scrollBy({
            left: -cardWidth,
            behavior: 'smooth'
        });
    }
});

// AUTOPLAY
let autoPlay = setInterval(() => {
    btnRight.click();
}, 5000);

// Resetear autoplay si el usuario interactúa
const resetAutoplay = () => {
    clearInterval(autoPlay);
    autoPlay = setInterval(() => {
        btnRight.click();
    }, 5000);
};

btnRight.addEventListener('click', resetAutoplay);
btnLeft.addEventListener('click', resetAutoplay);

// Pausar cuando el mouse está encima
track.addEventListener('mouseenter', () => {
    clearInterval(autoPlay);
});

track.addEventListener('mouseleave', () => {
    autoPlay = setInterval(() => {
        btnRight.click();
    }, 5000);
});