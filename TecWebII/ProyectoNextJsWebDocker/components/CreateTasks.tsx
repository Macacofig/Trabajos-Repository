"use client";

import { useState } from "react";
import { createTask } from "@/services/tasksService";
import { getKey } from "@/services/aesKeyService";

export default function CreateTasks()
{
    const today = new Date().toISOString().split("T")[0];

    const [task, setTask] = useState({
        title: "",
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

            await createTask({
                ...task,
                importance: "new",
            }, key);

            alert("Tarea creada");

            setTask({
                title: "",
                textSp: "",
                textEn: "",
                Date: today,
            });
        }
        catch
        {
            alert("Error al crear tarea");
        }
    } // ← ESTE TE FALTABA

    return (
        <section className="panel">
            <h2>Crear Tareas</h2>

            <div className="panel-scroll">

                <div className="task-header">
                    <input
                        className="input task-title"
                        placeholder="Título"
                        value={task.title}
                        onChange={(e) =>
                            setTask({
                                ...task,
                                title: e.target.value,
                            })
                        }
                    />

                    <input
                        type="date"
                        className="input task-date"
                        value={task.Date}
                        onChange={(e) =>
                            setTask({
                                ...task,
                                Date: e.target.value,
                            })
                        }
                    />
                </div>

                <textarea
                    className="textarea"
                    placeholder="Texto en Español"
                    value={task.textSp}
                    onChange={(e) =>
                        setTask({
                            ...task,
                            textSp: e.target.value,
                        })
                    }
                />

                <textarea
                    className="textarea"
                    placeholder="Texto en Inglés"
                    value={task.textEn}
                    onChange={(e) =>
                        setTask({
                            ...task,
                            textEn: e.target.value,
                        })
                    }
                />
            </div>

            <button className="btn" onClick={handleSubmit}>
                Guardar Tarea
            </button>
        </section>
    );
}