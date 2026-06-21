function validateForm(name, email, reason) {
    let isValid = true;

    // limpiar errores previos
    document.querySelectorAll(".error-msg").forEach(e => e.remove());

    // NAME
    if (name.length < 3) {
        showError("name", "El nombre debe tener al menos 3 caracteres");
        isValid = false;
    }

    // EMAIL
    if (!email.includes("@") || email.length < 5) {
        showError("email", "Introduce un email válido");
        isValid = false;
    }

    // MENSAJE
    if (reason.length < 5) {
        showError("reason", "El mensaje es demasiado corto");
        isValid = false;
    }

    return isValid;
}

function showError(inputId, message) {
    const input = document.getElementById(inputId);

    const error = document.createElement("span");
    error.classList.add("error-msg");
    error.textContent = message;

    input.parentElement.appendChild(error);
}

document.addEventListener("DOMContentLoaded", () => {

    const contactForm = document.getElementById("contact-form");
    const nameInput = document.getElementById("name");
    const emailInput = document.getElementById("email");
    const reasonInput = document.getElementById("reason");

    contactForm.addEventListener("submit", (event) => {
        event.preventDefault();

        const name = nameInput.value.trim();
        const email = emailInput.value.trim();
        const reason = reasonInput.value.trim();

        if (!validateForm(name, email, reason)) return;

        AddComentary(name, email, reason);
        event.target.reset();
    });

    loadComentaries();
});