import { getServices } from "../../utils/localStorage.js";
import { filter_Wastecollections } from "../../Models/WasteCollection.js";
import { select_collection_point, filter_by_route } from "../EMSA/Service.js";

document.addEventListener("DOMContentLoaded", () => {

    const btnBuscar = document.querySelector(".search-btn");
    const gridCards = document.getElementById("grid-cards");

    const selectDistrito = document.getElementById("filter-distrito");
    const selectZona = document.getElementById("filter-zona");
    const selectDia = document.getElementById("filter-dia");
    const inputRuta = document.getElementById("filter-ruta");
    const checkEstricto = document.getElementById("filter-estricto");

    const confirmationBox = document.getElementById("confirmation-message");
    const confirmationText = document.getElementById("confirmation-text");
    const confirmBtn = document.getElementById("confirm-btn");
    const cancelBtn = document.getElementById("cancel-btn");

    let selectedPoint = null;

    const Zones_by_district = {
        "2": ["Barrio Policial", "Colquiri", "Ticti Norte"],
        "6": ["Alto Cochabamba"],
        "7": ["Villa Venezuela"],
        "8": ["Ushpa Ushpa", "Las Rocas", "San Andrés", "Nueva Vera Cruz"],
        "9": ["Aguas Calientes", "San Antonio", "Villa Paraíso", "21 de Septiembre", "Pucara"],
        "15": ["Arrumani Agrario", "J.V. Copacabana"]
    };

    // ===== ZONAS DINÁMICAS =====
    selectZona.disabled = true;

    selectDistrito.addEventListener("change", function () {
        const distrito = this.value;
        selectZona.innerHTML = '<option value="">Seleccionar</option>';
        selectZona.disabled = !distrito;
        if (Zones_by_district[distrito]) {
            Zones_by_district[distrito].forEach(zona => {
                const option = document.createElement("option");
                option.value = zona;
                option.textContent = zona;
                selectZona.appendChild(option);
            });
        }
        filterServices();
    });


    // ===== COLORES POR DÍA =====
    function getColorByDay(day) {
        day = day.toLowerCase();
        if (day === "lunes" || day === "martes") return "bg-green";
        if (day === "miercoles" || day === "miércoles" || day === "jueves") return "bg-orange";
        if (day === "viernes" || day === "sabado" || day === "sábado" || day === "domingo") return "bg-red";
        return "";
    }

    // ===== CREAR CARD =====
    function createCard(service) {
        const article = document.createElement("article");
        article.className = `card ${getColorByDay(service.day)}`;

        article.innerHTML = `
            <div class="card-status ${service.status}">
                ${service.status === "available" ? "Disponible" : "No disponible"}
            </div>
            <p><strong>Distrito:</strong> ${service.distrito}</p>
            <p><strong>Zona:</strong> ${service.zone}</p>
            <p><strong>Día:</strong> ${capitalize(service.day)}</p>
            <p><strong>Hora:</strong> ${service.schedule}</p>
            <p><strong>Rutas:</strong> ${service.routes.join(", ")}</p>
        `;

        article.addEventListener("click", () => {
            document.querySelectorAll(".card").forEach(c => c.classList.remove("selected"));
            article.classList.add("selected");
            selectedPoint = {
                distrito: service.distrito,
                zone: service.zone,
                day: service.day,
                schedule: service.schedule,
                listaRutas: service.routes.join(", ")
            };
            confirmationText.textContent =
                `¿Confirmas: Zona ${service.zone}, ${capitalize(service.day)} a las ${service.schedule}?`;
            confirmationBox.style.display = "block";
        });

        return article;
    }

    // ===== CAPITALIZAR TEXTO =====
    function capitalize(text) {
        return text.charAt(0).toUpperCase() + text.slice(1);
    }

    // ===== RENDER =====
    function renderServices(services) {
        gridCards.innerHTML = "";
        if (services.length === 0) {
            gridCards.innerHTML = `
                <article class="card bg-orange">
                    <p><strong>🔍 No se encontraron resultados</strong></p>
                    <p>Prueba con otros filtros</p>
                </article>
            `;
            return;
        }
        services.forEach(service => {
            gridCards.appendChild(createCard(service));
        });
    }

    // ===== FILTRO =====
    function filterServices() {
        const distrito = selectDistrito.value;
        const zona = selectZona.value;
        const dia = selectDia.value;
        const rutaInput = inputRuta.value.trim();
        const estricto = checkEstricto.checked;

        let services = getServices('wasteCollections');

        services = filter_Wastecollections(services, { distrito, zone: zona, day: dia });

        if (rutaInput) {
            const routes = rutaInput.split(",").map(r => r.trim()).filter(r => r !== "");
            services = filter_by_route(services, routes, estricto);
        }

        renderServices(services);
    }

    // ===== EVENTOS =====
    btnBuscar.addEventListener("click", filterServices);
    
    // filtros automáticos (UX pro)
    selectZona.addEventListener("change", filterServices);
    selectDia.addEventListener("change", filterServices);
    inputRuta.addEventListener("input", filterServices);
    checkEstricto.addEventListener("change", filterServices);

    confirmBtn.addEventListener("click", () => {
        const result = select_collection_point(selectedPoint);
        if (result.success) {
            confirmationBox.style.display = "none";
            confirmationText.textContent = "";
            alert(result.message);
            document.querySelectorAll(".card").forEach(c => c.classList.remove("selected"));
            selectedPoint = null;
        }
    });

    cancelBtn.addEventListener("click", () => {
        confirmationBox.style.display = "none";
        confirmationText.textContent = "";
        document.querySelectorAll(".card").forEach(c => c.classList.remove("selected"));
        selectedPoint = null;
    });

    // ===== CARGA INICIAL =====
    renderServices(getServices('wasteCollections'));

    // ===== MAPA - MODAL =====
    const mapContainer = document.getElementById("map-container");
    const modal = document.getElementById("map-modal");
    const closeModal = document.getElementById("close-modal");

    mapContainer.addEventListener("click", () => {
        modal.style.display = "flex";
        requestAnimationFrame(() => modal.classList.add("show"));
    });

    closeModal.addEventListener("click", closeMapModal);
    modal.addEventListener("click", (e) => {
        if (e.target === modal) closeMapModal();
    });

    function closeMapModal() {
        modal.classList.remove("show");
        setTimeout(() => modal.style.display = "none", 300);
    }
});
