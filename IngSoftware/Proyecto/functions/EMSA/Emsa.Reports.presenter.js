import {
  getServices,
  saveServicesToLocalStorage
} from '../../utils/localStorage.js';

import {
  ModelReport
} from '../../Models/Report.js';

// =========================
// ELEMENTOS
// =========================
const reportsContainer =
  document.getElementById("reportsContainer");

const statusFilter =
  document.getElementById("statusFilter");

const dateFilter =
  document.getElementById("dateFilter");

const locationFilter =
  document.getElementById("locationFilter");

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

// Aplicar filtros manualmente
filterButton.addEventListener("click", applyFilters);

// Búsqueda dinámica
locationFilter.addEventListener("input", applyFilters);

// Limpiar filtros
clearButton.addEventListener("click", clearFilters);

// =========================
// FILTRAR
// =========================
function applyFilters() {

  const filteredReports = reports.filterReports(
    {

    status: statusFilter.value,

    date: dateFilter.value,

    location: locationFilter.value

  });

  renderReports(filteredReports);

}

// =========================
// LIMPIAR FILTROS
// =========================
function clearFilters() {

  statusFilter.value = "";

  dateFilter.value = "";

  locationFilter.value = "";

  renderReports(reports.getReports());

}

// =========================
// RENDER
// =========================
function renderReports(reportsToRender) {

  reportsContainer.innerHTML = "";

  // SIN REPORTES
  if (reportsToRender.length === 0) {

    reportsContainer.innerHTML = `
      <div class="empty-state">
        <h2>No hay reportes</h2>
        <p>No se encontraron incidencias.</p>
      </div>
    `;

    return;
  }

  // CARDS
  reportsToRender.forEach(report => {

    const card = document.createElement("div");

    card.classList.add("report-card");

    card.innerHTML = `
      <div class="report-summary">

        <div class="report-info">

          <div class="info-block">
            <span class="label">Ubicación</span>
            <span class="value">
              ${report.location}
            </span>
          </div>

          <div class="info-block">
            <span class="label">Ciudadano</span>
            <span class="value">
              ${report.idCitizen}
            </span>
          </div>

          <div class="info-block">
            <span class="label">Fecha</span>
            <span class="value">
              ${formatDate(report.date)}
            </span>
          </div>

          <div class="info-block">
            <span class="label">Estado</span>

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

        <button
          class="complete-btn"
          data-id="${report.id}"
        >
          ${
            report.status === "Completed"
            ? "Pendiente"
            : "Completar"
          }
        </button>

      </div>

      <div class="report-description">
        ${report.description}
      </div>
    `;

    // Expandir
    card.addEventListener("click", (e) => {

      if (
        e.target.classList.contains("complete-btn")
      ) return;

      card.classList.toggle("expanded");

    });

    reportsContainer.appendChild(card);

  });

  activateCompleteButtons();

}

// =========================
// TOGGLE STATUS
// =========================
function activateCompleteButtons() {

  const buttons =
    document.querySelectorAll(".complete-btn");

  buttons.forEach(button => {

    button.addEventListener("click", (e) => {

      e.stopPropagation();

      const reportId =
        Number(e.target.dataset.id);

      const reportToUpdate =
        reports.getReports().find(
          report => report.id === reportId
        );

      if (!reportToUpdate) return;

      // TOGGLE
      reportToUpdate.status =
        reportToUpdate.status === "Completed"
          ? "Pending"
          : "Completed";

      // GUARDAR
      reports.saveReports();

      // REAPLICAR FILTROS
      applyFilters();

    });

  });

}

// =========================
// FORMATO FECHA
// =========================
function formatDate(dateString) {

  const date = new Date(dateString);

  return date.toLocaleDateString("es-ES");

}

renderReports(reports.getReports());