import { getServices, saveServicesToLocalStorage } from "../utils/localStorage.js";
import { ModelUser } from "../Models/User.js";

class AuthService {
    constructor() {
        this.userModel = new ModelUser();
        // Claves estándar en localStorage
        this.SESSION_KEY = "currentUserId";
        this.ROLE_KEY = "currentUserRole";
    }

    /**
     * Valida credenciales, guarda la sesión y retorna el usuario
     */
    login(email, password) {
        if (!email || !password) {
            return { success: false, message: "Email y contraseña requeridos" };
        }

        const users = this.userModel.getUsers();
        const user = users.find(u => u.email === email && u.password === password);

        if (!user) {
            return { success: false, message: "Credenciales incorrectas" };
        }

        // Guardar sesión centralizada
        saveServicesToLocalStorage(user.getId(), this.SESSION_KEY);
        saveServicesToLocalStorage(user.role, this.ROLE_KEY);

        return { success: true, user: user };
    }

    /**
     * Limpia la sesión actual
     */
    logout() {
        localStorage.removeItem(this.SESSION_KEY);
        localStorage.removeItem(this.ROLE_KEY);
        // Limpiar keys antiguas/heredadas por retrocompatibilidad
        localStorage.removeItem("citizen_id");
        window.location.href = "index.html";
    }

    /**
     * Obtiene el usuario actualmente logueado
     */
    getCurrentLoggedUser() {
        const userId = getServices(this.SESSION_KEY);
        // Si getServices retorna un array vacío u nulo, no hay usuario
        if (!userId || Array.isArray(userId)) return null; 

        const users = this.userModel.getUsers();
        return users.find(u => String(u.getId()) === String(userId));
    }

    /**
     * Protege rutas: redirige a index.html si no hay sesión
     */
    checkAuth() {
        const user = this.getCurrentLoggedUser();
        if (!user) {
            window.location.href = "index.html";
            return false;
        }
        return true;
    }
}

export const authService = new AuthService();
