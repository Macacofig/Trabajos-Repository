import Link from "next/link";
export default function HomePage() 
{
    return (
    <main>
        <h1>Práctica de Web Tokens con Next.js</h1>
        <p>
        En esta práctica aprenderás a iniciar sesión, guardar un token,
        consumir una ruta protegida y cerrar sesión.
        </p>
        <ul>
            <li>Login con API pública</li>
            <li>Almacenamiento de token</li>
            <li>Consumo de ruta protegida</li>
            <li>Logout</li>
        </ul>
        <Link href="/login">Ir al login</Link>
        <br />

        <Link href="/dashboard">
            Ir al dashboard
        </Link>
    </main>
    );
}