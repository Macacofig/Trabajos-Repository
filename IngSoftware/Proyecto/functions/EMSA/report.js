const reports = [
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
  },
  {
    idCitizen: "30991",
    description: "Transformador emitiendo chispas.",
    location: "Queru Queru",
    date: "2026-05-08",
    status: "Pending"
  },
];

function filter_reports(status) {
  return reports.filter(report => report.status === status);
}

function filter_reports2(status, date) 
{
    if (status != "" && date != "")
    {
        return reports.filter(report => report.status === status && report.date >= date);
    }
    if (status == "") 
    {
        return reports.filter(report => report.date >= date);
    }
    if (date == "")
    {
        return reports.filter(report => report.status === status);
    }
}

function filter_reports3(status, date, location)
{
    if (status != "" && date != "" && location != "")
    {
        return reports.filter(report => report.status === status && report.date >= date && report.location === location);
    }
    if (status != "" && location != "")
    {
        return reports.filter(report => report.status === status && report.location === location );
    }
    if (date != "" && location != "")
    {
        return reports.filter(report => report.date >= date && report.location === location );
    }
    if (status == "")
    {
        return reports.filter(report => report.location === location);
    }
}

export { filter_reports, filter_reports2, filter_reports3 };