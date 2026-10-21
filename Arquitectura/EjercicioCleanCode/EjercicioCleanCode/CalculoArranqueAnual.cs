using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EjercicioCleanCode
{
    internal abstract class CalculoArranqueAnual
    {
        public abstract decimal Porcentaje { get; set; }
        public abstract decimal CalcularPorcentajeArranqueAnual();
    }
}
