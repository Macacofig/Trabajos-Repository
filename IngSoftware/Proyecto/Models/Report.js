import {
    getServices,
    saveServicesToLocalStorage
} from "../utils/localStorage.js";

class Report {

    constructor(
        id,
        idCitizen,
        description,
        location,
        date,
        status
    ) {
        this.id = id;
        this.idCitizen = idCitizen;
        this.description = description;
        this.location = location;
        this.date = date;
        this.status = status;
    }

    getId() {
        return this.id;
    }

    getIdCitizen() {
        return this.idCitizen;
    }

    getDescription() {
        return this.description;
    }

    getLocation() {
        return this.location;
    }

    getDate() {
        return this.date;
    }

    getStatus() {
        return this.status;
    }

    toJSON() {
        return {
            id: this.id,
            idCitizen: this.idCitizen,
            description: this.description,
            location: this.location,
            date: this.date,
            status: this.status
        };
    }
}

class ModelReport {

    constructor() {
        this.reports = [];
        this.loadReports();
    }

    loadReports() {

        const reportsData =
            getServices("reports") || [];

        this.reports = reportsData.map(
            report =>
                new Report(
                    report.id,
                    report.idCitizen,
                    report.description,
                    report.location,
                    new Date(report.date),
                    report.status
                )
        );
    }

    saveReports() {

        const reportsJSON =
            this.reports.map(
                report => report.toJSON()
            );

        saveServicesToLocalStorage(
            reportsJSON,
            "reports"
        );
    }

    addReport(
        idCitizen,
        description,
        location
    ) {

        const newReport =
            new Report(
                this.generateReportId(),
                idCitizen,
                description,
                location,
                new Date(),
                "Pending"
            );

        this.reports.push(newReport);

        this.saveReports();
        return {
            message: "Report successfully registered",
            success: true
        };
    }

    generateReportId() {

        if (this.reports.length === 0) {
            return 1;
        }

        const ids = this.reports
            .map(report => report.getId())
            .sort((a, b) => a - b);

        return ids[ids.length - 1] + 1;
    }

    getReports() {
        return this.reports;
    }

    filterReports({
        status = "",
        date = "",
        location = "",
        idCitizen = ""
    } = {}) {

        return this.reports.filter(
            report => {

                const matchesStatus =
                    !status ||
                    report.getStatus() === status;

                const reportDate =
                    report
                        .getDate()
                        .toISOString()
                        .split("T")[0];

                const matchesDate =
                    !date ||
                    reportDate >= date;

                const matchesLocation =
                    !location ||
                    report
                        .getLocation()
                        .toLowerCase()
                        .includes(
                            location.toLowerCase()
                        );

                const matchesIdCitizen =
                    !idCitizen ||
                    report.getIdCitizen() == idCitizen;

                return (
                    matchesStatus &&
                    matchesDate &&
                    matchesLocation &&
                    matchesIdCitizen
                );
            }
        );
    }
}

function verify_report(
    description,
    location
) {

    if(description === "") {
        return {
            message:
                "Description cannot be empty",
            success: false
        };
    }

    if(location === "") {
        return {
            message:
                "Location cannot be empty",
            success: false
        };
    }

    return {
        message:
            "Report successfully registered",
        success: true
    };
}

export {
    Report,
    ModelReport,
    verify_report
};