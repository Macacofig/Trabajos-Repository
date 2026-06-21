"use client";
import { useState } from "react";
import { createNote } from "@/services/notesService";
import { getKey } from "@/services/aesKeyService";

export default function CreateNotes()
{
    const today = new Date().toISOString().split("T")[0];

    const [note, setNote] = useState({
        title: `Notas de Reunión ${today}`,
        type: "",
        textSp: "",
        textEn: "",
        Date: today,
    });

    async function handleSubmit()
    {
        try
        {
            const key = getKey();

            if (!key)
            {
                alert("AES key requerida");
                return;
            }

            await createNote(note, key);

            alert("Nota creada");

            setNote({
                title: `Notas de Reunión ${today}`,
                type: "",
                textSp: "",
                textEn: "",
                Date: today,
            });
        }
        catch
        {
            alert("Error al crear nota");
        }
    }
    return (
        <section className="panel">
            <h2>
                Notas de Reunión
                <small className="date"> {today}</small>
            </h2>

            <div className="panel-scroll">

                <input
                    className="input"
                    placeholder="Tipo"
                    value={note.type}
                    onChange={(e) =>
                        setNote({
                            ...note,
                            type: e.target.value,
                        })
                    }
                />

                <textarea
                    className="textarea"
                    placeholder="Texto en Español"
                    value={note.textSp}
                    onChange={(e) =>
                        setNote({
                            ...note,
                            textSp: e.target.value,
                        })
                    }
                />

                <textarea
                    className="textarea"
                    placeholder="Texto en Inglés"
                    value={note.textEn}
                    onChange={(e) =>
                        setNote({
                            ...note,
                            textEn: e.target.value,
                        })
                    }
                />
            </div>

            <button className="btn" onClick={handleSubmit}>
                Guardar Nota
            </button>
        </section>
    );
}