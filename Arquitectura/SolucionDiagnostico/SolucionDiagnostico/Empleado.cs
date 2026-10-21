using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SolucionDiagnostico
{
    internal abstract class Empleado:ICalculoSalario
    {
        #region Propiedades de la Clase
        public int Ci { get; set; }
        public string CiExt { get; set; }
        public string Nombres { get; set; }
        public string PrimerApellido { get; set; }
        public string SegundoApellido { get; set; }
        public DateTime FechaNacimiento { get; set; }
        public DateTime FechaIngreso { get; set; }

        private readonly ConfiguracionPago configuracionPago;


        #endregion

        #region Constructores
        public Empleado()
        {
            configuracionPago = new ConfiguracionPago();
        }

        public Empleado(int ci, string ciExt, string nombres, string primerApellido, string segundoApellido, DateTime fechaNacimiento, DateTime fechaIngreso)
        {
            Ci = ci;
            CiExt = ciExt;
            Nombres = nombres;
            PrimerApellido = primerApellido;
            SegundoApellido = segundoApellido;
            FechaNacimiento = fechaNacimiento;
            FechaIngreso = fechaIngreso;
            
        }

        public Empleado(string nombres, string primerApellido, string segundoApellido)
        {
            Nombres = nombres;
            PrimerApellido = primerApellido;
            SegundoApellido = segundoApellido;
        }



        #endregion

        #region Métodos/Funciones
        public virtual float CalculoLiquidoPagable()
        {
            return configuracionPago.SalarioBaseMensual;
        }

        public float CalculoHorasExtra()
        {
            return configuracionPago.CantidadHorasExtra * configuracionPago.CostoHoraExtra;
        }

        #endregion

    }
}
