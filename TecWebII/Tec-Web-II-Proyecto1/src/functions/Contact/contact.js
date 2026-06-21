//comentaries of localStorage 
let listcomentaries = JSON.parse(localStorage.getItem("comentaries")) || [];


function saveComentaries() {
    localStorage.setItem("comentaries", JSON.stringify(listcomentaries));
}


function AddComentary(name, email, reason) {

    let user = listcomentaries.find(c => c.email === email);

    if (user) {
        // ya existe → agregar comentario
        user.comments.push({ name, reason });
    } else {
        // nuevo usuario
        listcomentaries.push({
            email,
            comments: [{ name, reason }]
        });
    }

    saveComentaries();
    loadComentaries();
}

function loadComentaries() {
    const container = document.querySelector(".comments-container");
    container.innerHTML = "";

    if (listcomentaries.length === 0) {
        container.innerHTML = `
            <p class="empty-msg">No hay comentarios aún</p>
        `;
        return;
    }

    listcomentaries.forEach(user => {
        const div = document.createElement("div");
        div.classList.add("comment-card");

        div.innerHTML = `
            <div class="comment-header">
                <h4>${user.email}</h4>
                <span class="arrow">▼</span>
            </div>

            <div class="comments-expansion">
                ${(user.comments || []).map(c => `
                    <div class="individual-comment">
                        <p><strong>${c.name}</strong></p>
                        <p>${c.reason}</p>
                    </div>
                `).join("")}
            </div>
        `;

        div.querySelector(".comment-header").addEventListener("click", () => {
            div.classList.toggle("is-expanded");
        });

        container.appendChild(div);
    });
}

function clearComentaries() {
    listcomentaries = [];
    localStorage.removeItem("comentaries");
    console.log("Comentarios eliminados");
}


document.addEventListener('DOMContentLoaded', () => {
    const backToTopBtn = document.getElementById('backToTop');

    window.addEventListener('scroll', () => {
        if (window.scrollY > 400) {
            backToTopBtn.classList.add('active');
        } else {
            backToTopBtn.classList.remove('active');
        }
    });

    // 2. Acción de volver arriba al hacer clic
    backToTopBtn.addEventListener('click', () => {
        window.scrollTo({
            top: 0,
            behavior: 'smooth' 
        });
    });
});
