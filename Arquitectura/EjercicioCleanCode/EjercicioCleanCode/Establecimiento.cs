using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EjercicioCleanCode
{
    internal abstract class Establecimiento:CalculoArranqueAnual
    {
        public string Nit { get; set; }
        public string RazonSocial { get; set; }
        public char Categoria { get; set; } // TODO : Se puede cambiar a ENUM
        public decimal ArancelAnualBaseBS { get; set; }
        public DateTime FechaRegistro { get; set; }

        public Establecimiento()
        {
        }
        public Establecimiento(string nit, string razonSocial, char categoria, decimal arancelAnualBase, DateTime fechaRegistro)
        {
            Nit = nit;
            RazonSocial = razonSocial;
            Categoria = categoria;
            ArancelAnualBaseBS = arancelAnualBase;
            FechaRegistro = fechaRegistro;
        }

        public int CalcularAntiguedadAnios()
        {
            return DateTime.Now.Year - FechaRegistro.Year;
        }
        public abstract decimal CalcularMontoTotalArancelAnual();

        public decimal CalcularPorcentajeArranqueAnual()
        {
            return ArancelAnualBaseBS * Porcentaje;
        }

    }
}
