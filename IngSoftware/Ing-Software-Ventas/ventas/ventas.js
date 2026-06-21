function calcularTotal(cantidad, precio)
{
    return Number((cantidad * precio).toFixed(2));
}

function calcularTotalImpuesto(total, estado)
{
    const estados = {'UT': 6.65/100, 'NV': 8/100, "TX": 6.25/100, "AL": 4/100, "CA": 8.25/100}
    let porcentajeimpuesto;
    porcentajeimpuesto = estados[estado]
    /*
    if(estado === 'UT')
    {
      porcentajeimpuesto = estados['UT']
    }
    if(estado === 'NV')
    {
      porcentajeimpuesto = estados['NV']
    }
    if(estado === 'TX')
    {
      porcentajeimpuesto = estados['TX']
    }
    if(estado === 'AL')
    {
      porcentajeimpuesto = estados['AL']
    }
    if(estado === "CA")
    {
      porcentajeimpuesto = estados['CA']
    }
    */
    let calc = total * porcentajeimpuesto
    let totalconimpuesto = total + calc;
    return [Number((totalconimpuesto).toFixed(2)),Number((calc).toFixed(2))] ;
}

function calcularDescuentos(cantidad, precio) {
  const total = cantidad * precio;
  let descuento = 0;

  if (total >= 1000 && total <= 2999) {
    descuento = 0.03;
  }

  if(total >= 3000 && total <= 6999) {
    descuento = 0.05;
  }

  if(total >= 7000 && total <= 9999) {
    descuento = 0.07;
  }

  if(total >= 10000 && total <= 29999) {
    descuento = 0.10;
  }

  if(total >= 30000) {
    descuento = 0.15;
  }

  const montoDescuento = total * descuento;
  return [Number((total-montoDescuento).toFixed(2)),Number((montoDescuento).toFixed(2))];
}

function calcularCategoria(total,categoria)
{
  const categorias = {
    'Alimentos':{'descuento': 0,'impuesto': 2/100}, 
    'Bebidas alcoholicas': {'descuento': 7/100,'impuesto': 0},
    'Material de escritorio': {'descuento': 0,'impuesto': 1.5/100},
    'Muebles': {'descuento': 3/100,'impuesto': 0},
    'Electronicos': {'descuento': 4/100,'impuesto': 1/100},
    'Vestimenta': {'descuento': 2/100,'impuesto': 0},
    'Varios': {'descuento': 0,'impuesto': 0},
  }
  let descuentoAplicar;
  let impuestoAplicar;
  let totalcompleto;
  /*
  if(categoria === 'Alimentos')
  {
    descuentoAplicar = total * categorias['Alimentos']['descuento'];
    totalcompleto = total - descuentoAplicar;
    impuestoAplicar = totalcompleto * categorias['Alimentos']['impuesto'];
    totalcompleto = totalcompleto + impuestoAplicar;
  }
  if(categoria === 'Bebidas alcoholicas')
  {
    descuentoAplicar = total * categorias['Bebidas alcoholicas']['descuento'];
    totalcompleto = total - descuentoAplicar;
    impuestoAplicar = totalcompleto * categorias['Bebidas alcoholicas']['impuesto'];
    totalcompleto = totalcompleto + impuestoAplicar;
  }
  if(categoria === 'Material de escritorio')
  {
    descuentoAplicar = total * categorias['Material de escritorio']['descuento'];
    totalcompleto = total - descuentoAplicar;
    impuestoAplicar = totalcompleto * categorias['Material de escritorio']['impuesto'];
    totalcompleto = totalcompleto + impuestoAplicar;
  }
  if(categoria === 'Muebles')
  {
    descuentoAplicar = total * categorias['Muebles']['descuento'];
    totalcompleto = total - descuentoAplicar;
    impuestoAplicar = totalcompleto * categorias['Muebles']['impuesto'];
    totalcompleto = totalcompleto + impuestoAplicar;
  }
  if(categoria === 'Electronicos')
  {
    descuentoAplicar = total * categorias['Electronicos']['descuento'];
    totalcompleto = total - descuentoAplicar;
    impuestoAplicar = totalcompleto * categorias['Electronicos']['impuesto'];
    totalcompleto = totalcompleto + impuestoAplicar;
  }
  if(categoria === 'Vestimenta')
  {
    descuentoAplicar = total * categorias['Vestimenta']['descuento'];
    totalcompleto = total - descuentoAplicar;
    impuestoAplicar = totalcompleto * categorias['Vestimenta']['impuesto'];
    totalcompleto = totalcompleto + impuestoAplicar;
  }
  if(categoria === 'Varios')
  {
    descuentoAplicar = total * categorias['Varios']['descuento'];
    totalcompleto = total - descuentoAplicar;
    impuestoAplicar = totalcompleto * categorias['Varios']['impuesto'];
    totalcompleto = totalcompleto + impuestoAplicar;
  } 
  */
  descuentoAplicar = total * categorias[categoria]['descuento'];
  totalcompleto = total - descuentoAplicar;
  impuestoAplicar = totalcompleto * categorias[categoria]['impuesto'];
  totalcompleto = totalcompleto + impuestoAplicar;

  return [Number((totalcompleto).toFixed(2)),Number((descuentoAplicar).toFixed(2)),Number((impuestoAplicar).toFixed(2))];
}

function calcularPesoVolumetrico(total,cantidad,peso)
{
  let totalpeso;
  let agregado;
  if(peso >= 0 && peso <= 10)
  {
    agregado = 0 * cantidad;
    totalpeso = total + agregado;
  }
  if(peso >= 11 && peso <= 20)
  {
    agregado = 3.5 * cantidad;
    totalpeso = total + agregado;
  }
  if(peso >= 21 && peso <= 40)
  {
    agregado = 5 * cantidad;
    totalpeso = total + agregado;
  }
  if(peso >= 41 && peso <= 80)
  {
    agregado = 6 * cantidad;
    totalpeso = total + agregado;
  }
  if(peso >= 81 && peso <= 100)
  {
    agregado = 6.5 * cantidad;
    totalpeso = total + agregado;
  }
  if(peso >= 101 && peso <= 200)
  {
    agregado = 8 * cantidad;
    totalpeso = total + agregado;
  }
  if(peso > 200)
  {
    agregado = 9 * cantidad;
    totalpeso = total + agregado;
  }
  return [Number((totalpeso).toFixed(2)),Number((agregado).toFixed(2))];
}

function calculoTipoCliente(total,tipo)
{
  const tipos = {'Normal': 0, 'Recurrente': 0.5/100, 'Antiguo Recurrente': 1/100, 'Especial': 1.5/100};
  
  let descuentotipo = total * tipos[tipo];
  return [Number((total - descuentotipo).toFixed(2)),Number((descuentotipo).toFixed(2))];
}

function calculobeneficio(total,cliente,neto,categoria)
{
  let totalbeneficio = total;
  let beneficio = 0;
  if(cliente === 'Recurrente' && neto > 3000 && categoria === 'Alimentos')
  {
    beneficio = 100;
    totalbeneficio = total - beneficio;
  }
  if(cliente === 'Especial' && neto > 7000 && categoria === 'Electronicos')
  {
    beneficio = 200;
    totalbeneficio = total - beneficio;
  }
  return [Number((totalbeneficio).toFixed(2)),(beneficio)]
}

export {calcularTotal, calcularTotalImpuesto, calcularDescuentos, calcularCategoria, calcularPesoVolumetrico, calculoTipoCliente, calculobeneficio};