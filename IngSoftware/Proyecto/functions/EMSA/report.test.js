import { filter_reports, filter_reports2, filter_reports3 } from "./report.js";

describe("Reports", () => {
    
  it("It should filter reports by status ", () => {
    expect(filter_reports("Pending")).toEqual([{
    idCitizen: "30991",
    description: "Transformador emitiendo chispas.",
    location: "Queru Queru",
    date: "2026-05-08",
    status: "Pending"
    }]);
  });
  it("It should filter reports by status and date ", () => {
    expect(filter_reports2("","2026-05-09")).toEqual([  
    {
        idCitizen: "10234",
        description: "Poste inclinado con riesgo de caída.",
        location: "Zona Norte - Avenida América",
        date: "2026-05-10",
        status: "Completed"
    },
    {
        idCitizen: "20458",
        description: "Cable eléctrico caído sobre la vereda.",
        location: "Zona Sur - Calle Bolívar",
        date: "2026-05-09",
        status: "Completed"
    }
    ]);
  });
    it("It should filter reports by status and date ", () => {
    expect(filter_reports2("Completed","")).toEqual([  
    {
        idCitizen: "10234",
        description: "Poste inclinado con riesgo de caída.",
        location: "Zona Norte - Avenida América",
        date: "2026-05-10",
        status: "Completed"
    },
    {
        idCitizen: "20458",
        description: "Cable eléctrico caído sobre la vereda.",
        location: "Zona Sur - Calle Bolívar",
        date: "2026-05-09",
        status: "Completed"
    }
    ]);
  });

  it("It should filter reports by status and date ", () => {
    expect(filter_reports2("Completed", "2026-05-09")).toEqual([    
    {
        idCitizen: "10234",
        description: "Poste inclinado con riesgo de caída.",
        location: "Zona Norte - Avenida América",
        date: "2026-05-10",
        status: "Completed"
    },
    {
        idCitizen: "20458",
        description: "Cable eléctrico caído sobre la vereda.",
        location: "Zona Sur - Calle Bolívar",
        date: "2026-05-09",
        status: "Completed"
    }]);
  });

  it("It should filter reports by status, date and location ", () => {
    expect(filter_reports3("", "", "Zona Norte - Avenida América")).toEqual([
    {
        idCitizen: "10234",
        description: "Poste inclinado con riesgo de caída.",
        location: "Zona Norte - Avenida América",
        date: "2026-05-10",
        status: "Completed"
    }
    ]);
  });
  it("It should filter reports by status, date and location ", () => {
    expect(filter_reports3("Completed", "", "Zona Norte - Avenida América")).toEqual([
    {
        idCitizen: "10234",
        description: "Poste inclinado con riesgo de caída.",
        location: "Zona Norte - Avenida América",
        date: "2026-05-10",
        status: "Completed"
    }
    ]);
  });
  it("It should filter reports by status, date and location ", () => {
    expect(filter_reports3("", "2026-05-10", "Zona Norte - Avenida América")).toEqual([
    {
        idCitizen: "10234",
        description: "Poste inclinado con riesgo de caída.",
        location: "Zona Norte - Avenida América",
        date: "2026-05-10",
        status: "Completed"
    }
    ]);
  });
  it("It should filter reports by status, date and location ", () => {
    expect(filter_reports3("Completed", "2026-05-10", "Zona Norte - Avenida América")).toEqual([
    {
        idCitizen: "10234",
        description: "Poste inclinado con riesgo de caída.",
        location: "Zona Norte - Avenida América",
        date: "2026-05-10",
        status: "Completed"
    }    
    ]);
  });
}); 