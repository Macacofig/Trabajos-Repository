"use client";
import { useEffect, useState } from "react";
import { useRouter } from "next/navigation";
import { getAuthUser } from "@/services/authService";
import { AuthUser } from "@/types/auth";
export default function ProfilePage() 
{
    const router = useRouter();
    const [user, setUser] = useState<AuthUser | null>(null);
    const [loading, setLoading] = useState(true);
    useEffect(() => {
        async function loadUser() 
        {
            const token = localStorage.getItem("accessToken");
            if (!token) 
            {
                router.push("/login");
                return;
            }
            try {
                const data = await getAuthUser(token);
                setUser(data);
            } catch {
                localStorage.removeItem("accessToken");
                localStorage.removeItem("refreshToken");
                router.push("/login");
            } finally {
                setLoading(false);
            }
        }
        loadUser();
    }, [router]);

    function logout() 
    {
        localStorage.removeItem("accessToken");
        localStorage.removeItem("refreshToken");
        router.push("/login");
    }
    if (loading) 
    {
        return <p>Cargando perfil...</p>;
    }
    if (!user) 
    {
        return <p>No se encontró información del usuario.</p>;
    }
    return (
    <main>
        <h1>Perfil del usuario autenticado</h1>
        <img src={user.image} alt={user.firstName} width={100} />
        <p>
            <strong>ID:</strong> {user.id}
        </p>
        <p>
            <strong>Nombre:</strong> {user.firstName} {user.lastName}
        </p>
        <p>
            <strong>Usuario:</strong> {user.username}
        </p>
        <p>
            <strong>Email:</strong> {user.email}
        </p>
        <p>
            <strong>Género:</strong> {user.gender}
        </p>
        <button onClick={logout}>
            Cerrar sesión
        </button>
    </main>
    );
}