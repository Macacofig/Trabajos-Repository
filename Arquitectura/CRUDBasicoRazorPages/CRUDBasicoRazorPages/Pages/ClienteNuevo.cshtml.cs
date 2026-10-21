using CRUDBasicoRazorPages.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using MySql.Data.MySqlClient;

namespace CRUDBasicoRazorPages.Pages
{
    public class ClienteNuevoModel : PageModel
    {
        [BindProperty]
        public Cliente ClienteEntity { get; set; } = new Cliente();

        private readonly IConfiguration configuration;
        public ClienteNuevoModel(IConfiguration configuration)
        {
            this.configuration = configuration;
        }

        public void OnGet()
        {            
        }

        public IActionResult OnPost() {
            string query = @"INSERT INTO cliente (ciNit, razonSocial, idUsuario)
                             VALUES(@ciNit,@razonSocial,1)";
            string connectionString = configuration.GetConnectionString("MySqlConnection")!;
            //1. Mantenibilidad - Codificación Compleja
            //2. Manejo de Caracteres Especiales
            //3. Inyeccion SQL
            
            //USO DE PARAMETROS


            try
            {
                using (MySqlConnection connection = new MySqlConnection(connectionString))
                using (MySqlCommand command = new MySqlCommand(query, connection))
                {
                    command.Parameters.AddWithValue("@ciNit",ClienteEntity.CiNit);
                    command.Parameters.AddWithValue("@razonSocial", ClienteEntity.RazonSocial);
                    connection.Open();
                    //Insert, Update, Delete
                    command.ExecuteNonQuery();

                }

            }
            catch
            {

                throw;
            }



            return RedirectToPage("Clientes");
        }


    }
}
