using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Solucion
{
    internal class Empleado : ICalculoSalario
    {
        #region Propiedades
        public int Ci { get; set; }
        public string CiExt { get; set; }
        public string Nombres { get; set; }
        public string PrimerApllido { get; set; }
        public string SegundoApellido { get; set; }
        public DateTime FechaNacimiento { get; set; }
        public DateTime FechaIngreso { get; set; }
        public readonly ConfiguracionPago ConfiguracionPagoEmpleado;
        #endregion

        #region Constructores
        public Empleado()
        {
            ConfiguracionPagoEmpleado = new ConfiguracionPago();
        }

        public Empleado(
            int ci, 
            string ciExt,
            string nombres,
            string primerApllido,
            string segundoApellido,
            DateTime fechaNacimiento,
            DateTime fechaIngreso
        )
        {
            Ci = ci;
            CiExt = ciExt;
            Nombres = nombres;
            PrimerApllido = primerApllido;
            SegundoApellido = segundoApellido;
            FechaNacimiento = fechaNacimiento;
            FechaIngreso = fechaIngreso;
        }
        #endregion

        #region Implementacion Metodos Interfaz ICalculoSalario
        public virtual float CalculoLiquidoPagable()
        {
            return ConfiguracionPagoEmpleado.SalarioMensual;
        }
        #endregion

        public float CalculoHorasExtra()
        {
            return ConfiguracionPagoEmpleado.CantidadHorasExtra * ConfiguracionPagoEmpleado.CostoHorasExtra;
        }

    }
}
