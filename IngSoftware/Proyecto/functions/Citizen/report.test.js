import { register_report  } from "./report.js";

describe("Reports", () => {
    
  it("It should register a report of a citizen ", () => {
    expect(register_report(1,"There is accumulated garbage", "caracoles")).toEqual("Report: Successfully registered");
  });
  it("It should show an error if description is empty", () => {
    expect(register_report(1,"", "caracoles")).toEqual("Description cannot be empty");
  });
  it("It should show an error if location is empty", () => {
    expect(register_report(1,"There is accumulated garbage", "")).toEqual("Location cannot be empty");
  });

});