function saludar(nombre, genero, edad, idioma) {
    const [saludo, hora] = horaActual(idioma);
    const distin = Genero(genero,edad,idioma);
    const t = textos[idioma];
    return `${saludo} ${distin} ${nombre}, ${t.sonLas} ${hora}`;
}

function horaActual(idioma) {
    const fecha = new Date();
    const horaFormateada = fecha.toLocaleTimeString();
    const t = textos[idioma];
    let text1;
    let text2;
    if (fecha.getHours() < 12) {
        text1 = t.buenosDias; 
    } else if (fecha.getHours() < 18) {
        text1 = t.buenasTardes; 
    } else {
        text1 = t.buenasNoches; 
    }
    text2 = `${horaFormateada}`;

    return [text1, text2];
}

function Genero(genero, edad, idioma) 
{
    let distin;
    const t = textos[idioma];
    if (edad > 30)
    {
        if (genero === "masculino") 
        {
            distin = t.senor;
        } else if (genero === "femenino") 
        {
            distin = t.senora;
        }
    }
    else
    {
        if (genero === "masculino") 
        {
            distin = t.joven;
        } else if (genero === "femenino") 
        {
            distin = t.senorita;
        }
    }
    
    return distin;
}
export {saludar};



const textos = {
    es: {
        buenosDias: "Buenos días",
        buenasTardes: "Buenas tardes",
        buenasNoches: "Buenas noches",
        senor: "Señor",
        senora: "Señora",
        joven: "Joven",
        senorita: "Señorita",
        sonLas: "son las"
    },
    en: {
        buenosDias: "Good morning",
        buenasTardes: "Good afternoon",
        buenasNoches: "Good evening",
        senor: "Mr.",
        senora: "Mrs.",
        joven: "Young man",
        senorita: "Miss",
        sonLas: "it's"
    }
};