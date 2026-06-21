let list_Services= [];

function register_day(day)
{
    if(day!=="")
    {
        return "Day: Successfully registered"
    }
    return "Day is empty";
}
function register_district_zone(day, distrito, zone)
{
    if(day!=="" && distrito !== "" && zone !== "")
    {
        return "Day,District,Zone: Successfully registered"
    }
    return "Day, District or Zone is empty";
}

function register_schedule(day, distrito, zone, schedule)
{
    if(day!=="" && distrito !== "" && zone !== "" && schedule !== "")
    {
        return "Day,District,Zone,Schedule: Successfully registered"
    }
    return "Day, District, Zone or Schedule is empty";
}

function register_Route(day, distrito, zone, schedule, listaRutas) {
  
  if (!day) return { field: "day", message: "Selecciona un día" };

  if (!distrito) return { field: "district", message: "Selecciona un distrito" };

  if (!zone) return { field: "zone", message: "Selecciona una zona" };

  if (!schedule) return { field: "schedule", message: "Selecciona un horario" };

  if (!listaRutas || listaRutas.trim() === "") {
    return { field: "rutas", message: "Debes agregar al menos una ruta" };
  }

  // Verificar duplicados
  if (list_Services.length > 0 &&
    list_Services.some(
      service =>
        service.day === day &&
        service.distrito === distrito &&
        service.zone === zone &&
        service.schedule === schedule
    )
  ) {
    return { field: "general", message: "El servicio ya existe" };
  }

  // Guardar
  list_Services.push({
    day,
    distrito,
    zone,
    schedule,
    listaRutas
  });

  return { success: true };
}

function getServices() {
    return list_Services;
}

function clearServices() {
    list_Services = [];
}

function select_collection_point(point) {
  if (!point || !point.distrito || !point.zone || !point.day || !point.schedule) {
    return { success: false, message: "Punto de recolección inválido" };
  }
  return { success: true, message: "Punto de recolección seleccionado correctamente" };
}

function filter_by_route(services, routes, strict = false) {
  if (!routes || routes.length === 0) return services;
  return services.filter(service => {
    const serviceRoutes = service.listaRutas
      ? service.listaRutas.toLowerCase()
      : (service.routes || []).join(", ").toLowerCase();
    if (strict) {
      return routes.every(route => serviceRoutes.includes(route.toLowerCase()));
    } else {
      return routes.some(route => serviceRoutes.includes(route.toLowerCase()));
    }
  });
}

export { register_day, register_district_zone, register_schedule, 
         register_Route, getServices, clearServices, 
         select_collection_point, filter_by_route };