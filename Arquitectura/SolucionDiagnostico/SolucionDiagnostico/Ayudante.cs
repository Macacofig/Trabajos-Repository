using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SolucionDiagnostico
{
    internal class Ayudante:Empleado
    {
        public bool TieneConocimientoEnCocina { get; set; }

        public Ayudante()
        {
            
        }

        public Ayudante(int ci, string ciExt, string nombres, string primerApellido, string segundoApellido, DateTime fechaNacimiento, DateTime fechaIngreso,  bool tieneConocimientoEnCocina) 
            : base(ci, ciExt, nombres, primerApellido, segundoApellido, fechaNacimiento, fechaIngreso)
        {
            TieneConocimientoEnCocina = tieneConocimientoEnCocina;

        }

        public override float CalculoLiquidoPagable()
        {
            return base.CalculoLiquidoPagable() + CalculoHorasExtra();

        }


    }
}
