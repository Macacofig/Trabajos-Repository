using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SolucionDiagnostico
{
    internal class Chef:Empleado
    {
        public string Especialidad { get; set; }

        public Chef()
        {
            
        }

        public Chef(int ci, string ciExt, string nombres, string primerApellido, string segundoApellido, DateTime fechaNacimiento, DateTime fechaIngreso,  string especialidad) 
            : base(ci, ciExt, nombres, primerApellido, segundoApellido, fechaNacimiento, fechaIngreso)
        {
            Especialidad = especialidad;
        }

        
        public override float CalculoLiquidoPagable()
        {
            return base.CalculoLiquidoPagable() + CalculoHorasExtra(); 
            
        }
    }
}
