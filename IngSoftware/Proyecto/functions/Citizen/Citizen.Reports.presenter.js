import { ModelReport } from '../../Models/Report.js';
import { authService } from '../../services/AuthService.js';

if (!authService.checkAuth()) {
    throw new Error("No autenticado");
}

const currentUser = authService.getCurrentLoggedUser();
const citizenId = currentUser.getId();

// =========================
// ELEMENTOS
// =========================
const reportsContainer =
  document.getElementById("reportsContainer");

const dateFilter =
  document.getElementById("dateFilter");

const filterButton =
  document.getElementById("filterButton");

const clearButton =
  document.getElementById("clearButton");

// =========================
// DATA
// =========================
let reports = new ModelReport();

// =========================
// EVENTOS
// =========================
filterButton.addEventListener(
  "click",
  applyFilters
);

clearButton.addEventListener(
  "click",
  clearFilters
);

// =========================
// FILTRAR
// =========================
function applyFilters() {

  const filteredReports =
    reports.filterReports(
      {
        idCitizen: citizenId,
        date: dateFilter.value
      }
    );

  renderReports(filteredReports);

}

// =========================
// LIMPIAR FILTROS
// =========================
function clearFilters() {

  dateFilter.value = "";

  applyFilters();

}

// =========================
// RENDER
// =========================
function renderReports(reportsToRender) {

  reportsContainer.innerHTML = "";

  if (reportsToRender.length === 0) {

    reportsContainer.innerHTML = `
      <div class="empty-state">
        <h2>No hay reportes</h2>
        <p>No se encontraron incidencias.</p>
      </div>
    `;

    return;
  }

  reportsToRender.forEach(report => {

    const card =
      document.createElement("div");

    card.classList.add("report-card");

    card.innerHTML = `
      <div class="report-summary">

        <div class="report-info">

          <div class="info-block">
            <span class="label">
              ID Reporte
            </span>

            <span class="value">
              ${report.id}
            </span>
          </div>

          <div class="info-block">
            <span class="label">
              Ubicación
            </span>

            <span class="value">
              ${report.location}
            </span>
          </div>

          <div class="info-block">
            <span class="label">
              Fecha
            </span>

            <span class="value">
              ${formatDate(report.date)}
            </span>
          </div>

          <div class="info-block">
            <span class="label">
              Estado
            </span>

            <span class="
              status
              ${report.status === 'Completed'
                ? 'completed'
                : 'pending'}
            ">
              ${report.status}
            </span>
          </div>

        </div>

      </div>

      <div class="report-description">
        ${report.description}
      </div>
    `;

    card.addEventListener(
      "click",
      () => {
        card.classList.toggle(
          "expanded"
        );
      }
    );

    reportsContainer.appendChild(card);

  });

}

// =========================
// FECHA
// =========================
function formatDate(dateString) {

  const date =
    new Date(dateString);

  return date.toLocaleDateString(
    "es-ES"
  );

}

applyFilters();
