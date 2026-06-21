export const emsaSidebar = `
<aside class="sidebar emsa-theme expanded" id="appSidebar">
  <button id="toggleSidebar" class="toggle-btn">◀</button>

  <div class="sidebar-inner">
    <div class="user-profile">
      <img src="https://ui-avatars.com/api/?name=EMSA+Admin&background=fff&color=FE8330" alt="Admin" class="avatar">
      <div class="user-info">
        <span class="user-role">ADMINISTRADOR</span>
        <span class="user-name">Equipo Operativo</span>
      </div>
    </div>

    <nav class="sidebar-menu">
      <span class="menu-label">EMSA OPERACIONES</span>

      <ul>
        <li class="menu-item" id="menu-emsa-services">
          <a href="emsa_WasteCollections.html">
            <span class="icon">📋</span>
            <span class="text">Services List</span>
          </a>
        </li>

        <li class="menu-item" id="menu-emsa-register">
          <a href="emsa_register_WasteCollection.html">
            <span class="icon">📝</span>
            <span class="text">Register New</span>
          </a>
        </li>

        <li class="menu-item" id="menu-emsa-reports">
          <a href="emsa_reports.html">
            <span class="icon">🚨</span>
            <span class="text">Gestión Reportes</span>
          </a>
        </li>

        <li class="menu-item" id="menu-user-profile">
          <a href="edit_profile_emsa.html">
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