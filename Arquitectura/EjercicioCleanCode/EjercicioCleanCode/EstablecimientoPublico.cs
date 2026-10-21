using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EjercicioCleanCode
{
    internal class EstablecimientoPublico: Establecimiento
    {
        public string NumeroAutorizacionFuncionamiento { get; set; }
        public string ServiciosAlimentacionBrindados { get; set; }
        public override decimal Porcentaje { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }

        public EstablecimientoPublico(string nit, string razonSocial, char categoria, decimal arancelAnualBaseBS, DateTime fechaRegistro)
            : base(nit, razonSocial, categoria, arancelAnualBaseBS,fechaRegistro)
        {
        }

        public EstablecimientoPublico(string nit, string razonSocial, char categoria, decimal arancelAnualBaseBS, DateTime fechaRegistro, string numAutorizacion, string serviciosAlimentacion)
            : base(nit, razonSocial, categoria, arancelAnualBaseBS, fechaRegistro)
        {
            NumeroAutorizacionFuncionamiento = numAutorizacion;
            ServiciosAlimentacionBrindados = serviciosAlimentacion;
        }

        public override decimal CalcularMontoTotalArancelAnual()
        {
            return ArancelAnualBase + recargoAntiguedad;
        }

        public override decimal CalcularPorcentajeArrnqueAnual()
        {
            throw new NotImplementedException();
        }
    }
}
