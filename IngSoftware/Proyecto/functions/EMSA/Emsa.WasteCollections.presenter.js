

import {ModelWasteCollection, WasteCollection, filter_Wastecollections } from "../../Models/WasteCollection.js";

const model = new ModelWasteCollection();

const gridCards = document.getElementById("grid-cards");

const btnBuscar = document.querySelector(".search-btn");

const selectDistrito = document.getElementById("filter-distrito");
const selectZona = document.getElementById("filter-zona");
const selectDia = document.getElementById("filter-dia");

const searchInput = document.getElementById("search-input");
const clearFiltersBtn = document.getElementById("clear-filters");

/* MODALS */

const editModal = document.getElementById("edit-modal");
const deleteModal = document.getElementById("delete-modal");

const editDistrito = document.getElementById("edit-distrito");
const editZona = document.getElementById("edit-zona");
const editDia = document.getElementById("edit-dia");
const editHorario = document.getElementById("edit-horario");
const editStatus = document.getElementById("edit-status");
const editRutas = document.getElementById("edit-rutas");

const saveEdit = document.getElementById("save-edit");

const cancelEdit = document.getElementById("cancel-edit");

const cancelDelete = document.getElementById("cancel-delete");

const confirmDelete = document.getElementById("confirm-delete");



let currentEditIndex = null;
let currentDeleteIndex = null;

const Zones_by_district = {
    "2": ["Barrio Policial", "Colquiri", "Ticti Norte"],
    "6": ["Alto Cochabamba"],
    "7": ["Villa Venezuela"],
    "8": ["Ushpa Ushpa", "Las Rocas", "San Andrés", "Nueva Vera Cruz"],
    "9": ["Aguas Calientes", "San Antonio", "Villa Paraíso", "21 de Septiembre", "Pucara"],
    "15": ["Arrumani Agrario", "J.V. Copacabana"]
};

/* ZONAS */

selectZona.disabled = true;

selectDistrito.addEventListener("change", function () {

    const distrito = this.value;

    selectZona.innerHTML = '<option value="">Zona</option>';

    selectZona.disabled = !distrito;

    if (Zones_by_district[distrito]) {

        Zones_by_district[distrito].forEach(zona => {

            const option = document.createElement("option");

            option.value = zona;
            option.textContent = zona;

            selectZona.appendChild(option);

        });

    }

});

/* RENDER */

function createCard(service, index) {

    const article = document.createElement("article");

    article.className = "card";

    article.innerHTML = `

        <div class="
            card-status
            ${service.status}
        ">
            ${
                service.status === "available"
                    ? "Disponible"
                    : "No disponible"
            }
        </div>

        <p><strong>Distrito:</strong> ${service.distrito}</p>

        <p><strong>Zona:</strong> ${service.zone}</p>

        <p><strong>Día:</strong> ${service.day}</p>

        <p><strong>Hora:</strong> ${service.schedule}</p>

        <p>
            <strong>Rutas:</strong>
            ${service.routes.join(", ")}
        </p>

        <div class="actions">

            <button class="btn-edit">
                Edit
            </button>

            <button class="btn-delete">
                Delete
            </button>

        </div>
    `;

    article
        .querySelector(".btn-edit")
        .addEventListener(
            "click",
            () => openEditModal(index)
        );

    article
        .querySelector(".btn-delete")
        .addEventListener(
            "click",
            () => openDeleteModal(index)
        );

    return article;
}

function renderServices(services) {

    gridCards.innerHTML = "";

    if (services.length === 0) {

        gridCards.innerHTML = `
            <div class="empty-message">
                <h3>No services found</h3>
            </div>
        `;

        return;
    }

    services.forEach((service, index) => {

        const card = createCard(service, index);

        gridCards.appendChild(card);

    });

}

/* FILTER */

function filterServices() {

    const distrito = selectDistrito.value;
    const zona = selectZona.value;
    const dia = selectDia.value;
    const search = searchInput.value.toLowerCase();

    const filtered = filter_Wastecollections(model.getWasteCollections(), { distrito, zone: zona, day: dia, search });
    renderServices(filtered);

}

function clearFilters() {

    selectDistrito.value = "";
    selectZona.value = "";
    selectDia.value = "";
    searchInput.value = "";

    selectZona.disabled = true;
    
    selectZona.innerHTML = '<option value="">Zona</option>';

    renderServices(
        model.getWasteCollections()
    );

}

btnBuscar.addEventListener("click", filterServices);

searchInput.addEventListener(
    "input",
    filterServices
);

selectDistrito.addEventListener(
    "change",
    filterServices
);

selectZona.addEventListener(
    "change",
    filterServices
);

selectDia.addEventListener(
    "change",
    filterServices
);

clearFiltersBtn.addEventListener(
    "click",
    clearFilters
);

/* EDIT MODAL */

function openEditModal(index) {

    const wasteCollections = model.getWasteCollections();

    const service = wasteCollections[index];

    currentEditIndex = index;

    editDistrito.value = service.distrito;
    /* LOAD ZONES */

    editZona.innerHTML = '<option value="">Zona</option>';

    if (Zones_by_district[service.distrito]) {

        Zones_by_district[service.distrito].forEach(zona => {

            const option = document.createElement("option");

            option.value = zona;
            option.textContent = zona;

            editZona.appendChild(option);

        });

    }

    /* SET VALUES */

    editDistrito.value = service.distrito;
    editZona.value = service.zone;
    editDia.value = service.day;
    editHorario.value = service.schedule;
    editStatus.value = service.status || "available";

    editRutas.value = (service.routes || []).join(", ");

    editModal.classList.add("active");

}

function closeEditModal() {
    editModal.classList.remove("active");
}

saveEdit.addEventListener("click", () => {

    const updatedService =
        new WasteCollection(

            editDia.value,

            editDistrito.value,

            editZona.value,

            editHorario.value,

            editRutas.value
                .split(",")
                .map(r => r.trim())
                .filter(r => r !== ""),

            editStatus.value

        );

    model.updateWasteCollection(
        currentEditIndex,
        updatedService
    );

    renderServices(
        model.getWasteCollections()
    );

    closeEditModal();

});

cancelEdit.addEventListener("click", closeEditModal);

/* DELETE MODAL */

function openDeleteModal(index) {

    currentDeleteIndex = index;

    deleteModal.classList.add("active");

}

function closeDeleteModal() {

    deleteModal.classList.remove("active");

}

confirmDelete.addEventListener("click", () => {

    model.deleteWasteCollection(currentDeleteIndex);

    renderServices(
        model.getWasteCollections()
    );

    closeDeleteModal();

});

cancelDelete.addEventListener("click", closeDeleteModal);

/* INITIAL */

renderServices(model.getWasteCollections());

/* =========================
   EDIT MODAL ZONAS
========================= */

editDistrito.addEventListener("change", function () {

    const distrito = this.value;

    editZona.innerHTML = '<option value="">Zona</option>';

    if (Zones_by_district[distrito]) {

        Zones_by_district[distrito].forEach(zona => {

            const option = document.createElement("option");

            option.value = zona;
            option.textContent = zona;

            editZona.appendChild(option);

        });

    }

});

