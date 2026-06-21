import {
    verify_update_user
} from "../../Models/User.js";

import { authService } from "../../services/AuthService.js";

// Proteger ruta
if (!authService.checkAuth()) {
    throw new Error("No autenticado");
}

const form =
    document.getElementById(
        "edit-profile-form"
    );

const messageBox =
    document.getElementById(
        "message-container"
    );

const successModal =
    document.getElementById(
        "success-modal"
    );

// ==========================================
// LOAD CURRENT USER
// ==========================================

loadCurrentUser();

// ==========================================
// UPDATE USER
// ==========================================

form.addEventListener(
    "submit",
    function(event) {

        event.preventDefault();

        clearErrors();

        const currentUser =
            authService.getCurrentLoggedUser();

        if (!currentUser) {

            renderMessage({

                success: false,

                message:
                    "Usuario no encontrado"

            });

            return;

        }

        const userData = {

            id:
                currentUser.getId(),

            name:
                document
                    .getElementById("username")
                    .value,

            email:
                document
                    .getElementById("email")
                    .value,

            password:
                document
                    .getElementById("password")
                    .value,

            role:
                currentUser.getRole()

        };

        // ==========================
        // VERIFY
        // ==========================

        const verifyResult =
            verify_update_user(
                userData,
                authService.userModel.getUsers()
            );

        if (
            !verifyResult.success
        ) {

            renderMessage(
                verifyResult
            );

            showFieldError(
                verifyResult.field
            );

            return;

        }

        // ==========================
        // UPDATE
        // ==========================

        const updateResult =
            authService.userModel.updateUser(
                userData
            );

        if (
            updateResult.success
        ) {

            successModal
                .classList
                .add("active");

        } else {

            renderMessage(
                updateResult
            );

        }

    }
);

// ==========================================
// CLOSE MODAL
// ==========================================

document
    .getElementById("accept-btn")
    .addEventListener(
        "click",
        function() {

            successModal
                .classList
                .remove("active");

        }
    );

successModal.addEventListener(
    "click",
    function(event) {

        if (
            event.target ===
            successModal
        ) {

            successModal
                .classList
                .remove("active");

        }

    }
);

// ==========================================
// LOAD USER DATA
// ==========================================

function loadCurrentUser() {

    const currentUser =
        authService.getCurrentLoggedUser();

    if (!currentUser) return;

    document
        .getElementById("username")
        .value =
        currentUser.getName();

    document
        .getElementById("email")
        .value =
        currentUser.getEmail();

    document
        .getElementById("password")
        .value =
        currentUser.getPassword();

}

// ==========================================
// RENDER MESSAGE
// ==========================================

function renderMessage(result) {

    messageBox.className =
        "message-box";

    if (!result.success) {

        messageBox
            .classList
            .add("error");

    } else {

        messageBox
            .classList
            .add("success");

    }

    messageBox.textContent =
        result.message;

}

// ==========================================
// FIELD ERROR
// ==========================================

function showFieldError(field) {

    const inputId = field === "name" ? "username" : field;

    const input =
        document.getElementById(
            inputId
        );

    if (input) {

        input.classList.add(
            "input-error"
        );

    }

}

// ==========================================
// CLEAR ERRORS
// ==========================================

function clearErrors() {

    const inputs =
        document.querySelectorAll(
            "input"
        );

    inputs.forEach(input => {

        input.classList.remove(
            "input-error"
        );

    });

}