"use client";

import { useEffect, useState } from "react";
import {
    getKey,
    setKey,
    clearKey,
} from "@/services/aesKeyService";

export default function AesKeyPanel()
{
    const [inputKey, setInputKey] = useState("");
    const [savedKey, setSavedKey] = useState("");

    useEffect(() =>
    {
        const currentKey = getKey();

        if (currentKey)
        {
            setSavedKey(currentKey);
        }

    }, []);

    function handleSave()
    {
        if (!inputKey.trim())
        {
            alert("Ingresa una clave AES");
            return;
        }

        setKey(inputKey);

        setSavedKey(inputKey);

        setInputKey("");

        alert("Clave AES guardada");
    }

    function handleClear()
    {
        clearKey();

        setSavedKey("");

        alert("Clave eliminada");
    }

    return (
        <section className="key-panel">

            <h2>Clave AES</h2>

            <input
                className="input"
                placeholder="Ingresa clave AES"
                value={inputKey}
                onChange={(e) =>
                    setInputKey(e.target.value)
                }
            />

            <div className="key-buttons">

                <button
                    className="btn"
                    onClick={handleSave}
                >
                    Guardar clave
                </button>

                <button
                    className="btn danger-btn"
                    onClick={handleClear}
                >
                    Eliminar clave
                </button>

            </div>

            <p>
                <strong>Estado:</strong>{" "}
                {savedKey
                    ? "Clave configurada"
                    : "Sin clave"}
            </p>

            {savedKey && (
                <p>
                    <strong>Preview:</strong>{" "}
                    {savedKey.substring(0, 12)}...
                </p>
            )}

        </section>
    );
}