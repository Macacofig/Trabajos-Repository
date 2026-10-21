using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using System.Data;//ADO .NET
using MySql.Data.MySqlClient;
using CRUDBasicoRazorPages.Models; //MySQL

namespace CRUDBasicoRazorPages.Pages
{
    public class ClientesModel : PageModel
    {
        private readonly IConfiguration configuration;
        public string Mensaje { get; set; }
        public List<Cliente> ListClientes { get; set; } = new List<Cliente>();
        public ClientesModel(IConfiguration configuration)
        {
            this.configuration = configuration;
        }

        public void OnGet()
        {
            Select();

        }

        void Select()
        {
            string connectionString = configuration.GetConnectionString("MySqlConnection")!;

            string query = @"SELECT id, ciNit, razonSocial, fechaRegistro 
                            FROM cliente 
                            WHERE estado=1 ORDER BY 3";

            try
            {
                using (MySqlConnection connection = new MySqlConnection(connectionString))                
                {
                    MySqlCommand command = new MySqlCommand(query, connection);
                    //command.CommandText = query;
                    //command.Connection = connection;

                    connection.Open();

                    //Si la conexión está abierta
                    //Se ejecuta la consulta SQL y el resultado pasa al DataAdapter
                    MySqlDataAdapter adapter = new MySqlDataAdapter(command);
                    DataTable tableClientes = new DataTable();

                    adapter.Fill(tableClientes);
                    foreach (DataRow row in tableClientes.Rows) 
                    {
                        Cliente cliente = new Cliente {
                            Id = Convert.ToInt16(row["id"]),
                            CiNit = row["ciNit"].ToString(),
                            RazonSocial = row["razonSocial"].ToString(),
                            FechaRegistro = Convert.ToDateTime(row["fechaRegistro"])

                        };
                    
                        ListClientes.Add(cliente);
                    }



                }
                
            }
            catch (Exception ex)
            {
                Mensaje = ex.Message;
            }
          
        
        }

    }
}
