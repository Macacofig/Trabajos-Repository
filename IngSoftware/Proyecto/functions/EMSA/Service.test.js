import {register_day, register_district_zone, register_schedule, 
        register_Route, getServices, clearServices,
        select_collection_point, filter_by_route} from "./Service.js";

describe("Service", () => {
    
  it("It should register a day of service", () => {
    expect(register_day("monday")).toEqual("Day: Successfully registered");
  });


  it("It should register day with district and zone", () => {
    expect(register_district_zone("monday", "9", "Pucara")).toEqual("Day,District,Zone: Successfully registered");
  });

  it("It should register day with district, zone and schedule", () => {
    expect(register_schedule("monday", "9", "Pucara", "8:00-12:00")).toEqual("Day,District,Zone,Schedule: Successfully registered");
  });

  it("Debería devolver éxito al recibir datos", () => {
    expect(register_Route("Lunes", "Pucara", "Zona 1", "08:00-12:00", "caracoles")).toEqual({ success: true });
  });
  it("Debería devolver que ya existe ", () => {
    register_Route("Lunes", "Pucara", "Zona 1", "08:00-12:00", "caracoles");
    expect(register_Route("Lunes", "Pucara", "Zona 1", "08:00-12:00", "caracoles")).toEqual({ field: "general", message: "El servicio ya existe" });
  });
  it("Debería devolver que error por campos vacíos", () => {
  expect(register_Route("", "Pucara", "Zona 1", "08:00-12:00", "caracoles")).toEqual({ field: "day", message: "Selecciona un día" });
  });
  it("error cuando distrito vacío", () => {
    expect(register_Route("Lunes", "", "Zona 1", "08:00-12:00", "ruta"))
    .toEqual({ field: "district", message: "Selecciona un distrito" });
  });

  it("error cuando zona vacía", () => {
    expect(register_Route("Lunes", "9", "", "08:00-12:00", "ruta"))
    .toEqual({ field: "zone", message: "Selecciona una zona" });
  });

  it("error cuando horario vacío", () => {
    expect(register_Route("Lunes", "9", "Zona 1", "", "ruta"))
    .toEqual({ field: "schedule", message: "Selecciona un horario" });
  });

  it("error cuando rutas vacías", () => {
    expect(register_Route("Lunes", "9", "Zona 1", "08:00-12:00", ""))
    .toEqual({ field: "rutas", message: "Debes agregar al menos una ruta" });
  });
  it("Debería devolver la lista de servicios", () => {
    register_Route("Lunes", "Pucara", "Zona 1", "08:00-12:00", "caracoles");
    expect(getServices()).toEqual([
      {
        day: "Lunes",
        distrito: "Pucara",
        zone: "Zona 1",
        schedule: "08:00-12:00",
        listaRutas: "caracoles"
      }
    ]);
  });
  it("Debería devolver la lista de servicios", () => {
    clearServices();
    register_Route("Lunes", "9", "Zona 1", "08:00-12:00", "caracoles");
    register_Route("Martes", "2", "Zona 2", "09:00-12:00", "caracoles, tortugas");
    expect(getServices()).toEqual([
      {
        day: "Lunes",
        distrito: "9",
        zone: "Zona 1",
        schedule: "08:00-12:00",
        listaRutas: "caracoles"
      },
      {
        day: "Martes",
        distrito: "2",
        zone: "Zona 2",
        schedule: "09:00-12:00",
        listaRutas: "caracoles, tortugas"
      }
    ]);
  });

  it("should return error when day is empty", () => {
  expect(register_day("")).toEqual("Day is empty");
  });

  it("should return error when district or zone is empty", () => {
  expect(register_district_zone("monday", "", "Pucara")).toEqual("Day, District or Zone is empty");
  });

  it("should return error when schedule is empty", () => {
  expect(register_schedule("monday", "9", "Pucara", "")).toEqual("Day, District, Zone or Schedule is empty");
  });

  it("selecciona punto valido", () => {
  const point = {
    distrito: "9", zone: "Pucara",
    day: "lunes", schedule: "08:00",
    listaRutas: "Ruta Norte"
  };
  expect(select_collection_point(point)).toEqual({
    success: true,
    message: "Punto de recolección seleccionado correctamente"
  });
});

it("filtra por una ruta", () => {
  clearServices();
  register_Route("Lunes", "2", "Barrio Policial", "08:00", "CALA CALA");
  register_Route("Martes", "6", "Alto Cochabamba", "09:00", "Circunvalacion");
  expect(filter_by_route(getServices(), ["CALA CALA"])).toHaveLength(1);
});

it("filtra por varias rutas con al menos una", () => {
  clearServices();
  register_Route("Lunes", "2", "Barrio Policial", "08:00", "CALA CALA");
  register_Route("Martes", "6", "Alto Cochabamba", "09:00", "Circunvalacion");
  register_Route("Miercoles", "7", "Villa Venezuela", "10:00", "Av.Pando");
  expect(filter_by_route(getServices(), ["CALA CALA", "Circunvalacion"])).toHaveLength(2);
});

it("filtra de forma estricta por todas las rutas", () => {
  clearServices();
  register_Route("Lunes", "2", "Barrio Policial", "08:00", "CALA CALA, Circunvalacion");
  register_Route("Martes", "6", "Alto Cochabamba", "09:00", "Circunvalacion");
  expect(filter_by_route(getServices(), ["CALA CALA", "Circunvalacion"], true)).toHaveLength(1);
});

});
