namespace ProyectoDemo.Models
{
    public class Cliente
    {
        public short Id { get; set; }
        public string CiNit { get; set; }
        public string RazonSocial { get; set; }
        public byte Estado { get; set; }
        public DateTime FechaRegistro { get; set; }
        public DateTime FechaUltimaActualizacion { get; set; }
        public  short IdUsuario { get; set; }
    }
}
