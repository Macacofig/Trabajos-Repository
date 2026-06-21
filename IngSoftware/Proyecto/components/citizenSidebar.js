export const citizenSidebar = `
<aside class="sidebar citizen-theme expanded" id="appSidebar">
  <button id="toggleSidebar" class="toggle-btn">◀</button>

  <div class="sidebar-inner">

    <div class="user-profile">
      <img
        src="https://ui-avatars.com/api/?name=Citizen&background=222&color=fff"
        alt="Usuario"
        class="avatar"
      >

      <div class="user-info">
        <span class="user-role">CIUDADANO</span>
        <span class="user-name">Usuario Local</span>
      </div>
    </div>

    <nav class="sidebar-menu">

      <span class="menu-label">MIS ACCESOS</span>

      <ul>

        <li class="menu-item" id="menu-citizen-home">
          <a href="citizen_WasteCollections.html">
            <span class="icon">🗺️</span>
            <span class="text">Rutas y Horarios</span>
          </a>
        </li>

        <li class="menu-item" id="menu-citizen-create">
          <a href="citizen_create_report.html">
            <span class="icon">🚨</span>
            <span class="text">Reportar Incidencia</span>
          </a>
        </li>

        <li class="menu-item" id="menu-citizen-reports">
          <a href="citizen_reports.html">
            <span class="icon">📂</span>
            <span class="text">Mis Reportes</span>
          </a>
        </li>

        <li class="menu-item" id="menu-user-profile">
          <a href="edit_profile_citizen.html">
            <span class="icon">👤</span>
            <span class="text">Editar Perfil</span>
          </a>
        </li>

        <li class="menu-item logout-item" id="menu-logout">
          <a href="#">
            <span class="icon">🚪</span>
            <span class="text">Cerrar Sesión</span>
          </a>
        </li>

      </ul>

    </nav>

  </div>
</aside>
`;