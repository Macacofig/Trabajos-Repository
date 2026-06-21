import { WasteCollection,ModelWasteCollection, verify_WasteCollection } from "../../Models/WasteCollection.js";
import { getServices } from "../../utils/localStorage.js";
//Data elements
const Day_input = document.getElementById("daySelect"); // DAY INPUT
const District_input = document.getElementById("distrito"); // DISTRICT INPUT
const Zone_input = document.getElementById("zona"); // ZONE INPUT
const Schedule_input = document.getElementById("schedule"); // SCHEDULE INPUT
//form
const form = document.getElementById("formulario");

//Data zones
const Zones_by_district = {
  "2": ["Barrio Policial", "Colquiri", "Ticti Norte"],
  "6": ["Alto Cochabamba"],
  "7": ["Villa Venezuela"],
  "8": ["Ushpa Ushpa", "Las Rocas", "San Andrés", "Nueva Vera Cruz"],
  "9": ["Aguas Calientes", "San Antonio", "Villa Paraíso", "21 de Septiembre", "Pucara"],
  "15": ["Arrumani Agrario", "J.V. Copacabana"]
};

// Logic for zone and district select
/*****************************************************************/
/*****************************************************************/
// Turn off zona select until district is selected
Zone_input.disabled = true;

District_input.addEventListener("change", function() {
  const distrito = this.value;

  // Clear zones
  Zone_input.innerHTML = '<option value="">Selecciona zona</option>';

  // activar o desactivar
  Zone_input.disabled = !distrito;

  if (Zones_by_district[distrito]) {
    Zones_by_district[distrito].forEach(zona => {
      const option = document.createElement("option");
      option.value = zona;
      option.textContent = zona;
      Zone_input.appendChild(option);
    });
  }
});
/*****************************************************************/
/*****************************************************************/
// error messages
/*****************************************************************/
/*****************************************************************/
function clearErrors() {
  document.querySelectorAll(".error").forEach(e => e.textContent = "");
}

const formMessage = document.getElementById("form-message");

function showFormMessage(message, type = "error") {
  formMessage.textContent = message;
  formMessage.className = `form-message ${type}`;

  // desaparecer después de 3 segundos
  setTimeout(() => {
    formMessage.textContent = "";
    formMessage.className = "form-message";
  }, 3000);
}

/*****************************************************************/
/*****************************************************************/

// Form submission logic
/*****************************************************************/
/*****************************************************************/

const lista = document.getElementById("lista-registros");
const clearBtn = document.getElementById("clearBtn");
const guardarTodoBtn = document.getElementById("guardarTodo");

// Routes elements
const inputRuta = document.getElementById("inputRuta");
const addRutaBtn = document.getElementById("addRuta");
const listaRutas = document.getElementById("lista-rutas");

// Array for storing records in memory
let registros = [];
let rutas = [];

// CLEAR
clearBtn.addEventListener("click", () => {
  form.reset();
  rutas = [];
  renderRutas();
});

// =======================
// RUTAS
// =======================

// AGREGAR
addRutaBtn.addEventListener("click", () => {
  const nombre = inputRuta.value.trim();
  if (!nombre) return;

  rutas.push(nombre);
  inputRuta.value = "";
  renderRutas();
});

// RENDER RUTAS
function renderRutas() {
  listaRutas.innerHTML = "";

  rutas.forEach((ruta, index) => {
    const li = document.createElement("li");
    li.className = "ruta-item";
    li.draggable = true;

    li.innerHTML = `
      ${ruta}
      <button data-index="${index}">x</button>
    `;

    // ELIMINAR
    li.querySelector("button").onclick = () => {
      rutas.splice(index, 1);
      renderRutas();
    };

    // DRAG
    li.addEventListener("dragstart", () => {
      li.classList.add("dragging");
    });

    li.addEventListener("dragend", () => {
      li.classList.remove("dragging");
    });

    listaRutas.appendChild(li);
  });
}

// DRAG LOGIC
listaRutas.addEventListener("dragover", (e) => {
  e.preventDefault();
  const dragging = document.querySelector(".dragging");
  const afterElement = getDragAfterElement(listaRutas, e.clientY);

  if (afterElement == null) {
    listaRutas.appendChild(dragging);
  } else {
    listaRutas.insertBefore(dragging, afterElement);
  }

  updateArrayFromDOM();
});

function getDragAfterElement(container, y) {
  const elements = [...container.querySelectorAll(".ruta-item:not(.dragging)")];

  return elements.reduce((closest, child) => {
    const box = child.getBoundingClientRect();
    const offset = y - box.top - box.height / 2;
    if (offset < 0 && offset > closest.offset) {
      return { offset: offset, element: child };
    } else {
      return closest;
    }
  }, { offset: Number.NEGATIVE_INFINITY }).element;
}

// ACTUALIZAR ARRAY SEGUN ORDEN
function updateArrayFromDOM() {
  rutas = [...listaRutas.children].map(li => li.firstChild.textContent.trim());
}

// =======================
// FORM → SOLO PREPARA DATA
// =======================

form.addEventListener("submit", (e) => {
  e.preventDefault();

  clearErrors();

  const wastecollection = new WasteCollection(
    Day_input.value,
    District_input.value,
    Zone_input.value,
    Schedule_input.value,
    [...rutas],
    "available"
  );

  const validation = verify_WasteCollection(
    wastecollection,
    getServices("wasteCollections") || [],
    registros
  );

  if (!validation.success) {

    if (validation.field === "general") {
      showFormMessage(validation.message, "error");
      return;
    }

    const errorElement = document.getElementById(`error-${validation.field}`);
    
    if (errorElement) {
      errorElement.textContent = validation.message;
    }
    return;
  }

  registros.push(wastecollection);

  showFormMessage("Servicio registrado correctamente", "success");

  form.reset();
  rutas = [];
  renderRutas();
  renderRegistros();
});

// =======================
// RENDER FINAL (DERECHA)
// =======================

function renderRegistros() {
  lista.innerHTML = "";

  registros.forEach(service  => {
    const div = document.createElement("div");
    div.className = "registro-card";

    div.innerHTML = `
      <p><b>${service.day}</b></p>
      <p>Distrito: ${service.distrito}</p>
      <p>Zona: ${service.zone}</p>
      <p>Hora: ${service.schedule}</p>
      <p>Rutas: ${service.routes.join(", ")}</p>
    `;

    lista.appendChild(div);
  });
}

/*****************************************************************/
/*****************************************************************/

// SAVE ALL LOGIC IN BACKEND
/*****************************************************************/
/*****************************************************************/
guardarTodoBtn.addEventListener("click", () => {
  if (registros.length === 0) {
    showFormMessage("No hay registros para guardar", "error");
    return;
  }

   const model = new ModelWasteCollection();

  registros.forEach(wastecollection  => { model.addWasteCollection(wastecollection); });
  registros = []; 
  renderRegistros();
  showFormMessage("Todos los servicios han sido guardados", "success");
});

/*****************************************************************/
/*****************************************************************/

// =======================================================
// LÓGICA ESTÉTICA DEL SIDEBAR AÑADIDA (Sin tocar funcionalidad)
// =======================================================
document.addEventListener('DOMContentLoaded', () => {
    const sidebar = document.getElementById('appSidebar');
    const toggleBtn = document.getElementById('toggleSidebar');

    if(sidebar && toggleBtn) {
        toggleBtn.addEventListener('click', () => {
            // Alternar la clase 'collapsed'
            sidebar.classList.toggle('collapsed');
        });
    }
});