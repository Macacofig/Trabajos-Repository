// "use client";

// import { useEffect, useState } from "react";
// import { useRouter } from "next/navigation";

// export default function DashboardPage() 
// {
//     const router = useRouter();

//     const [authenticated, setAuthenticated] = useState(false);
//     const [tokenPreview, setTokenPreview] = useState("");

//     useEffect(() => 
//     {
//         const token = localStorage.getItem("accessToken");

//         if (!token) 
//         {
//             router.push("/login");
//             return;
//         }

//         setAuthenticated(true);

//         const shortToken =
//             token.substring(0, 20) + "...";

//         setTokenPreview(shortToken);

//     }, [router]);

//     function logout() 
//     {
//         localStorage.removeItem("accessToken");
//         localStorage.removeItem("refreshToken");

//         router.push("/login");
//     }

//     return (
//         <main>
//             <h1>Dashboard</h1>

//             <p>
//                 <strong>Estado:</strong>{" "}
//                 {authenticated ? "Autenticado" : "No autenticado"}
//             </p>

//             <p>
//                 <strong>Token:</strong>{" "}
//                 {tokenPreview}
//             </p>

//             <button onClick={logout}>
//                 Cerrar sesión
//             </button>
//         </main>
//     );
// }

import AesKeyPanel from "@/components/AesKeyPanel";
import TasksNotesContainer from "@/components/TasksNotesContainer";

export default function DashboardPage()
{
    return (
        <main>

            <AesKeyPanel />

            <TasksNotesContainer />

        </main>
    );
}