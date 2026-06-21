import { authService } from "../../services/AuthService.js";

document.addEventListener("DOMContentLoaded", () => {
    const emailInput = document.getElementById("email");
    const passwordInput = document.getElementById("password");
    const loginBtn = document.getElementById("login-btn");
    const errorMsg = document.getElementById("error-msg");

    // Usuarios de prueba si no hay ninguno registrado
    if (authService.userModel.getUsers().length === 0) {
        authService.userModel.addUser("Ciudadano", "ciudadano@gmail.com", "1234", "citizen");
        authService.userModel.addUser("Admin", "admin@emsa.com", "admin123", "emsa");
    }

    loginBtn.addEventListener("click", () => {
        const email = emailInput.value.trim();
        const password = passwordInput.value.trim();

        const result = authService.login(email, password);
        console.log("Intento de login:", { email, password, result });

        if (!result.success) {
            errorMsg.textContent = result.message;
            errorMsg.style.display = "block";
            return;
        }

        errorMsg.style.display = "none";

        if (result.user.role === "citizen") {
            window.location.href = "edit_profile_citizen.html";
        } else if (result.user.role === "emsa") {
            window.location.href = "edit_profile_emsa.html";
        } else {
            alert("Error: Rol desconocido '" + result.user.role + "'");
        }
    });
});