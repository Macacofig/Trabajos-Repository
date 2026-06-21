import { authService } from '../services/AuthService.js';
import { emsaSidebar } from '../components/emsaSidebar.js';
import { citizenSidebar } from '../components/citizenSidebar.js';
/**
 * Inyecta el sidebar correspondiente y maneja su lógica visual
 * @param {string} type - 'emsa' o 'citizen'
 * @param {string} activeMenuId - ID del elemento del menú que debe estar resaltado
 */
export async function loadSidebar(type, activeMenuId) {
  const container = document.getElementById('sidebar-container');
  if (!container) return;

  const htmlText =
    type === 'emsa'
      ? emsaSidebar
      : citizenSidebar;

  container.innerHTML = htmlText;

  // Resaltar el botón activo en el menú
  const activeItem = document.getElementById(activeMenuId);

  if (activeItem) {
    activeItem.classList.add('active');
  }

  // Activar funcionalidades
  setupToggle();
  setupProfileRedirect(type);

  // Logout
  const logoutBtn = document.getElementById('menu-logout');

  if (logoutBtn) {
    logoutBtn.addEventListener('click', (e) => {
      e.preventDefault();
      authService.logout();
    });
  }

  // Mobile menu
  if (!document.querySelector('.mobile-header')) {

    const mobileHeader = document.createElement('div');

    mobileHeader.className = 'mobile-header';

    mobileHeader.innerHTML = `
      <button class="mobile-menu-toggle">☰</button>
      <span style="color: white; font-weight: bold; margin-left: 15px; font-size: 1.2rem;">
        Menú
      </span>
    `;

    document.body.insertBefore(
      mobileHeader,
      document.body.firstChild
    );

    mobileHeader
      .querySelector('.mobile-menu-toggle')
      .addEventListener('click', () => {

        const sidebar =
          document.getElementById('appSidebar');

        if (sidebar) {
          sidebar.classList.toggle('mobile-open');
        }
      });
  }
}

function setupToggle() {
  const sidebar = document.getElementById('appSidebar');
  const toggleBtn = document.getElementById('toggleSidebar');

  if (sidebar && toggleBtn) {
    toggleBtn.addEventListener('click', () => {
      // 1. Contraemos o expandimos el sidebar visualmente
      sidebar.classList.toggle('collapsed');

      // 2. Cambiamos el ícono de la flecha según el estado del colapso
      toggleBtn.textContent = sidebar.classList.contains('collapsed') ? "▶" : "◀";
    });
  }
}

function setupProfileRedirect(type) {
  // Buscamos el ítem del menú de perfil (si usas el ID menu-profile)
  const profileMenuBtn = document.getElementById('menu-user-profile') || document.getElementById('menu-profile');
  // También volvemos clickeable toda el área de la foto/nombre del usuario
  const userProfileArea = document.querySelector('.user-profile');

  const redirectToProfile = (e) => {
    // Evita interferir si el botón ya es un enlace (<a>) que sí funciona
    const link = e.target.closest('a');
    if (link && link.getAttribute('href') && link.getAttribute('href') !== '#') return;

    e.preventDefault();
    // REDIRECCIÓN DIRECTA: Cambiamos a la ruta real según el tipo
    const targetUrl = type === 'emsa' ? 'edit_profile_emsa.html' : 'edit_profile_citizen.html';
    window.location.href = targetUrl; 
  };

  if (profileMenuBtn) {
    profileMenuBtn.addEventListener('click', redirectToProfile);
  }
  if (userProfileArea) {
    userProfileArea.style.cursor = 'pointer';
    userProfileArea.addEventListener('click', redirectToProfile);
  }
}