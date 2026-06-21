import {
    User,
    ModelUser,
    verify_user
} from "../../Models/User.js";

const form =
    document.getElementById(
        "registerForm"
    );

const roleSelect =
    document.getElementById(
        "role"
    );

const keyContainer =
    document.getElementById(
        "keyContainer"
    );

const messageBox =
    document.getElementById(
        "messageBox"
    );

const modelUser =
    new ModelUser();

// ==================================================
// SHOW / HIDE KEY
// ==================================================

roleSelect.addEventListener(
    "change",
    () => {

        if (
            roleSelect.value === "emsa"
        ) {

            keyContainer
                .classList
                .remove("hidden");

        } else {

            keyContainer
                .classList
                .add("hidden");

        }

    }
);

// ==================================================
// REGISTER USER
// ==================================================

form.addEventListener(
    "submit",
    function(event) {

        event.preventDefault();

        clearErrors();

        const userData = {


            name:
                document
                    .getElementById("name")
                    .value.trim(),

            email:
                document
                    .getElementById("email")
                    .value.trim(),

            password:
                document
                    .getElementById("password")
                    .value.trim(),

            role:
                document
                    .getElementById("role")
                    .value,

            key:
                document
                    .getElementById("key")
                    .value

        };

        // ==========================
        // VERIFY USER
        // ==========================

        const verifyResult =
            verify_user(
                userData,
                modelUser.getUsers()
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
        // CREATE USER
        // ==========================

        const registrationResult =
            modelUser.addUser(
                userData.name,
                userData.email,
                userData.password,
                userData.role
            );

        renderMessage(
            registrationResult
        );

        form.reset();

        keyContainer
            .classList
            .add("hidden");

    }
);

// ==================================================
// RENDER MESSAGE
// ==================================================

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

// ==================================================
// FIELD ERROR
// ==================================================

function showFieldError(field) {

    if (
        field === "general"
    ) return;

    const input =
        document.getElementById(
            field
        );

    if (input) {

        input.classList.add(
            "input-error"
        );

    }

}

// ==================================================
// CLEAR ERRORS
// ==================================================

function clearErrors() {

    const inputs =
        document.querySelectorAll(
            "input, select"
        );

    inputs.forEach(input => {

        input.classList.remove(
            "input-error"
        );

    });

}