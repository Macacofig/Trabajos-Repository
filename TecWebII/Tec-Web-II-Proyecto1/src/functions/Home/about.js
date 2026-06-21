
const reveals = document.querySelectorAll('.reveal');

function revealOnScroll() {
    const windowHeight = window.innerHeight;

    reveals.forEach(el => {
        const elementTop = el.getBoundingClientRect().top;

        if (elementTop < windowHeight - 100) {
            el.classList.add('active');
        }
    });
}

window.addEventListener('scroll', revealOnScroll);

const aboutBtn = document.getElementById('aboutBtn');

aboutBtn.addEventListener('click', (e) => {
    e.preventDefault();

    const section = document.querySelector('#features');

    section.scrollIntoView({
        behavior: 'smooth'
    });
});