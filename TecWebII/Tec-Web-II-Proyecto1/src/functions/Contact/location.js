document.addEventListener('DOMContentLoaded', () => {
    const locationCard = document.querySelector('.location-card');
    const mapBtn = document.querySelector('.btn-directions');

    // 1. Efecto de aparición 
    const observer = new IntersectionObserver((entries) => {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                entry.target.style.opacity = '1';
                entry.target.style.transform = 'translateY(0)';
            }
        });
    }, { threshold: 0.1 });

    if (locationCard) {
        // Estado inicial para la animación
        locationCard.style.opacity = '0';
        locationCard.style.transform = 'translateY(20px)';
        locationCard.style.transition = 'all 0.8s ease-out';
        observer.observe(locationCard);
    }

    // Link a una búsqueda de Google Maps
    if (mapBtn) {
        mapBtn.addEventListener('click', (e) => {
            e.preventDefault();
            const testUrl = "https://maps.google.com/?cid=1024818209598176881&g_mp=CiVnb29nbGUubWFwcy5wbGFjZXMudjEuUGxhY2VzLkdldFBsYWNl";
            window.open(testUrl, '_blank');
        });
    }
});