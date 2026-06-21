import { API_URL } from "@/lib/api";
import { Task } from "@/types/task";

export async function createTask(task: Partial<Task>, key: string)
{
    const response = await fetch(`${API_URL}/tasks/create`,
    {
        method: "POST",
        headers:
        {
            "Content-Type": "application/json",
        },
        body: JSON.stringify({
            task,
            key,
        }),
    });

    if (!response.ok)
    {
        throw new Error("Error creating task");
    }

    return response.json();
}