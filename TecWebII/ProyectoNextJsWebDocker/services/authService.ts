import { AuthUser, LoginRequest, LoginResponse } from "@/types/auth";

const API_URL = "https://dummyjson.com/auth";

export async function login(data: LoginRequest): Promise<LoginResponse> 
{
    const response = await fetch(`${API_URL}/login`, 
    {
        method: "POST",
        headers: {
        "Content-Type": "application/json",
        },
        body: JSON.stringify({
            username: data.username,
            password: data.password,
            expiresInMins: 30,
        }),
    });
    if (!response.ok) 
    {
        throw new Error("Credenciales incorrectas");
    }
    return response.json();
}
export async function getAuthUser(token: string): Promise<AuthUser> 
{
    const response = await fetch(`${API_URL}/me`, 
    {
        method: "GET",
        headers: {
        Authorization: `Bearer ${token}`,
        },
    });
    if (!response.ok) 
    {
        throw new Error("Token inválido o expirado");
    }
    return response.json();
}