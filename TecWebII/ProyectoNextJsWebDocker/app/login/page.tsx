"use client";
import { FormEvent, useState } from "react";
import { useRouter } from "next/navigation";
import { login } from "@/services/authService";
export default function LoginPage() 
{
    const router = useRouter();
    const [username, setUsername] = useState("emilys");
    const [password, setPassword] = useState("emilyspass");
    const [error, setError] = useState("");
    const [loading, setLoading] = useState(false);
    async function handleSubmit(event: FormEvent<HTMLFormElement>) 
    {
        event.preventDefault();
        setError("");
        setLoading(true);
        try {
            const data = await login({
            username,
            password,
        });
            localStorage.setItem("accessToken", data.accessToken);
            localStorage.setItem("refreshToken", data.refreshToken);
            router.push("/profile");
        } catch {
            setError("Usuario o contraseña incorrectos");
        } finally {
            setLoading(false);
        }
    }

    return (
    <main>
        <h1>Iniciar sesión</h1>
        <p>
            Usa las credenciales de prueba de DummyJSON:
        </p>
        <p>
            <strong>Usuario:</strong> emilys
        </p>
        <p>
            <strong>Contraseña:</strong> emilyspass
        </p>
        <form onSubmit={handleSubmit}>
        <div>
        <label htmlFor="username">Usuario</label>
        <input
        id="username"
        type="text"
        value={username}
        onChange={(event) => setUsername(event.target.value)}
        />
        </div>
        <div>
        <label htmlFor="password">Contraseña</label>
        <input
        id="password"
        type="password"
        value={password}
        onChange={(event) => setPassword(event.target.value)}
        />
        </div>
        <button type="submit" disabled={loading}>
        {loading ? "Ingresando..." : "Ingresar"}
        </button>
        </form>
        {error && <p>{error}</p>}
        
    </main>
    );
}