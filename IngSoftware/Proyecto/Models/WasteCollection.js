import {
    saveServicesToLocalStorage,
    getServices
} from "../utils/localStorage.js";

class WasteCollection{
    constructor(
        day, 
        distrito, 
        zone, 
        schedule, 
        routes = [],
        status = "available"
    ){
        this.day = day;
        this.distrito = distrito;
        this.zone = zone;
        this.schedule = schedule;
        this.routes = routes;
        this.status = status;
    }

    getDay() {
        return this.day;
    }
    getDistrito() {
        return this.distrito;
    }
    getZone() {
        return this.zone;
    }
    getSchedule() {
        return this.schedule;
    }
    getRoutes() {
        return this.routes;
    }
    getStatus() {
        return this.status;
    }
    toJSON() {
        return {
            day: this.day,
            distrito: this.distrito,
            zone: this.zone,
            schedule: this.schedule,
            routes: this.routes,
            status: this.status
        };
    }
}

class ModelWasteCollection {

    constructor() {
        this.wasteCollections = [];
        this.loadWasteCollections();
    }
    loadWasteCollections() {
        const wasteCollectionsData = getServices('wasteCollections');
        this.wasteCollections = wasteCollectionsData.map(w => new WasteCollection(
            w.day,
            w.distrito,
            w.zone,
            w.schedule,
            w.routes || [],
            w.status || "available"
        ));
    }
    getWasteCollections() {
        return this.wasteCollections;
    }
    addWasteCollection(wasteCollection) {
        this.wasteCollections.push(wasteCollection);
        this.saveWasteCollections();
    }
    saveWasteCollections() {
        const wasteCollectionsJSON = this.wasteCollections.map(w => w.toJSON());
        saveServicesToLocalStorage(wasteCollectionsJSON, 'wasteCollections');
    }

    updateWasteCollection(index, updatedWasteCollection) {

        this.wasteCollections[index] = updatedWasteCollection;

        this.saveWasteCollections();

    }

    deleteWasteCollection(index) {

        this.wasteCollections.splice(index, 1);

        this.saveWasteCollections();

    }
}

function isDuplicateWasteCollections(WasteCollection, WasteCollectionsList) {
    return WasteCollectionsList.some(w =>
        w.day === WasteCollection.day &&
        w.distrito === WasteCollection.distrito &&
        w.zone === WasteCollection.zone &&
        w.schedule === WasteCollection.schedule
    );
}

function verify_WasteCollection(WasteCollection, WasteCollectionsList = [], currentList = []) 
{

  if (!WasteCollection.day) return {field: "day",message: "Selecciona un día"};

  if (!WasteCollection.distrito) return {field: "district",message: "Selecciona un distrito"};

  if (!WasteCollection.zone) return {field: "zone",message: "Selecciona una zona"};

  if (!WasteCollection.schedule) return {field: "schedule",message: "Selecciona un horario"};

  if (!WasteCollection.routes ||WasteCollection.routes.length === 0) return {field: "rutas",message: "Debes agregar al menos una ruta"};

  if (isDuplicateWasteCollections(WasteCollection, WasteCollectionsList)) return {field: "general",message:"El servicio ya existe"};

  if (isDuplicateWasteCollections(WasteCollection, currentList)) return {field: "general",message:"El servicio de recoleccion ya existe"};
    
  return {success: true};
}

function filter_Wastecollections(wasteCollections,{distrito = "", zone = "", day = "", search = ""} = {}) 
{
    return wasteCollections.filter(wasteCollection => {

        const matchesDistrito = !distrito || wasteCollection.distrito === distrito;

        const matchesZone = !zone || wasteCollection.zone === zone;

        const matchesDay = !day || wasteCollection.day.toLowerCase().includes(day.toLowerCase());

        const matchesSearch = !search || wasteCollection.routes.some(route => route.toLowerCase().includes(search.toLowerCase()));

        return ( matchesDistrito && matchesZone && matchesDay && matchesSearch);
    });
}

export { WasteCollection, ModelWasteCollection, verify_WasteCollection, filter_Wastecollections };