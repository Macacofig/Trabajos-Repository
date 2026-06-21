import { useState } from 'react'
import './App.css'
import React from 'react';

function App() {
  const [name, setName] = React.useState("");
  const [role, setRole] = React.useState("user");
  const [message, setMessage] = React.useState("");
  const handleSubmit = () => {
  localStorage.setItem("userName", name);
  localStorage.setItem("role", role);
  if (role === "admin") {
  setMessage("Bienvenido administrador " + name);
  } else {
  setMessage("Hola " + name);
  }
  };
  return (
  <div>
  <h1>{message}</h1>
  <input
  placeholder="Nombre"
  onChange={(e) => setName(e.target.value)}
  />
  <select onChange={(e) => setRole(e.target.value)}>
  <option value="user">Usuario</option>
  <option value="admin">Administrador</option>
  </select>
  <button onClick={handleSubmit}>Ingresar</button>
  </div>
  );
}

export default App
