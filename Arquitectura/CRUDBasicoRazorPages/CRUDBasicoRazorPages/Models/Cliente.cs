namespace CRUDBasicoRazorPages.Models
{
    public class Cliente
    {
        public short Id { get; set; }
        public string CiNit { get; set; }
        public string RazonSocial { get; set; }
        public byte Estado { get; set; }
        public DateTime FechaRegistro { get; set; }
        public DateTime UltimaActualizacion { get; set; }
        public short IdUsuario { get; set; }



    }
}
