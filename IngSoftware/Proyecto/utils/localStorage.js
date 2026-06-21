function saveServicesToLocalStorage(list_Services, key) {
    localStorage.setItem(key, JSON.stringify(list_Services));
}

function getServices(key) {
    // Load existing services from localStorage
    let list_Services = JSON.parse(localStorage.getItem(key)) || [];
    return list_Services;
}

export { saveServicesToLocalStorage, getServices };