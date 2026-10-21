using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EjercicioCleanCode
{
    internal class EmpresaControlVectores:Establecimiento
    {
        private const decimal PORCENTAJE_RECARGO_ANTIGUEDAD = 0.02m;

        public string TipoTrabajo { get; set; }
        public string DetalleEquiposFumigacion { get; set; }

        public EmpresaControlVectores(string nit, string razonSocial, char categoria, decimal arancelAnualBase, DateTime fechaRegistro)
            : base(nit, razonSocial, categoria, arancelAnualBase, fechaRegistro)
        {
        }
        public EmpresaControlVectores(string nit, string razonSocial, char categoria, decimal arancelAnualBase, DateTime fechaRegistro, string tipoTrabajo, string detalleEquiposFumigacion)
            : base(nit, razonSocial, categoria, arancelAnualBase, fechaRegistro)
        {
            TipoTrabajo = tipoTrabajo;
            DetalleEquiposFumigacion = detalleEquiposFumigacion;
        }

        public override decimal CalcularMontoTotalArancelAnual()
        {
            decimal recargoAntiguedad = ArancelAnualBase * (CalcularAntiguedadAnios() * PORCENTAJE_RECARGO_ANTIGUEDAD);
            return ArancelAnualBase + recargoAntiguedad;
        }
    }
}
