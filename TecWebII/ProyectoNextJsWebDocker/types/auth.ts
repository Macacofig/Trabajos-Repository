export interface LoginRequest // Datos enviados al servidor para iniciar sesión
{
    username: string;
    password: string;
}

export interface LoginResponse // Datos recibidos del servidor después de iniciar sesión exitosamente
{
    id: number;
    username: string;
    email: string;
    firstName: string;
    lastName: string;
    gender: string;
    image: string;
    accessToken: string; // Dato importante
    refreshToken: string; // Dato importante
}

export interface AuthUser // Informacion del usuario autenticado
{
    id: number;
    username: string;
    email: string;
    firstName: string;
    lastName: string;
    gender: string;
    image: string;
}