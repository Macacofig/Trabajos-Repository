import { API_URL } from "@/lib/api";
import { Note } from "@/types/note";

export async function createNote(note: Partial<Note>, key: string)
{
    const response = await fetch(`${API_URL}/notes/register`,
    {
        method: "POST",
        headers:
        {
            "Content-Type": "application/json",
        },
        body: JSON.stringify({
            note,
            key,
        }),
    });

    if (!response.ok)
    {
        throw new Error("Error creating note");
    }

    return response.json();
}