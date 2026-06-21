import CreateNotes from "./CreateNotes";
import CreateTasks from "./CreateTasks";

export default function TasksNotesContainer()
{
    return (
        <div className="container">
            <CreateTasks />
            <CreateNotes />
        </div>
    );
}