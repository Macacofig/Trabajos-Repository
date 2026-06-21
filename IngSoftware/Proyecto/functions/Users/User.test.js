import { register_user } from "./User.js";
import { login_user } from "../../Models/User.js";

const usuariosBasura = [
  { id: 1, email: "ale@gmail.com", password: "1234", role: "citizen", getId: () => 1 },
  { id: 2, email: "admin@emsa.com", password: "admin123", role: "emsa", getId: () => 2 }
];


describe("Users", () => {
    
  it("It should show a registered user", () => {
    expect(register_user("nataly","nramirezmachicado@gmail.com","password","citizen")).toEqual("User Successfully registered");
  });
  it("It should show an error if name is empty", () => {
    expect(register_user("","nramirezmachicado@gmail.com","password", "citizen")).toEqual("The name field is required");
  });
  it("It should show an error if email is empty", () => {
    expect(register_user("nataly","", "password", "citizen")).toEqual("The email field is required");
  });
  it("It should show an error if role is empty", () => {
    expect(register_user("nataly","nramirezmachicado@gmail.com", "password", "")).toEqual("The role field is required");
  });
  it("It should show an error if password is empty", () => {
    expect(register_user("nataly","nramirezmachicado@gmail.com", "", "citizen")).toEqual("The password field is required");
  });
  it("It should show an error if any field is empty", () => {    
    expect(register_user("","","","")).toEqual("The all field is required");
  });

  it("login falla si email vacio", () => {
    expect(login_user("", "1234", usuariosBasura)).toEqual({
      success: false,
      message: "Email y contraseña requeridos"
    });
  });

  it("login falla si password vacio", () => {
    expect(login_user("ale@gmail.com", "", usuariosBasura)).toEqual({
      success: false,
      message: "Email y contraseña requeridos"
    });
  });

  it("login falla si usuario no existe", () => {
    expect(login_user("noexiste@gmail.com", "1234", usuariosBasura)).toEqual({
      success: false,
      message: "Credenciales incorrectas"
    });
  });

  it("login exitoso ciudadano", () => {
    expect(login_user("ale@gmail.com", "1234", usuariosBasura)).toEqual({
      success: true, role: "citizen", id: 1
    });
  });

  it("login exitoso admin", () => {
    expect(login_user("admin@emsa.com", "admin123", usuariosBasura)).toEqual({
      success: true, role: "emsa", id: 2
    });
  });

});