using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using MySql.Data.MySqlClient;
using System.Data;

namespace ProyectoDemo.Pages
{
    public class ClientesModel : PageModel
    {
        private readonly IConfiguration configuration;
        public string Mensaje { get; set; }


        public DataTable table { get; set; } = new DataTable();
        public ClientesModel(IConfiguration configuration)
        {
            this.configuration = configuration;
        }
        public void OnGet()
        {
            Select();
        }
        public void Select()
        {
            string connectionString = configuration.GetConnectionString("MySqlConnection");
            string query = @"SELECT id, ciNit, razonSocial, fechaRegistro 
                             FROM cliente 
                             WHERE estado=1 ORDER BY 3";
            try
            {
                using (MySqlConnection connection = new MySqlConnection(connectionString))
                {
                    MySqlCommand command = new MySqlCommand(query,connection);
                    //command.CommandText = query;
                    //command.Connection = connection;
                    connection.Open();
                    MySqlDataAdapter adapter = new MySqlDataAdapter(command);
                    adapter.Fill(table);
                    Mensaje = "Lograste Conectarte";
                }               
            }
            catch (Exception ex)
            {
                Mensaje = ex.Message;
            }
        }
    }
}
