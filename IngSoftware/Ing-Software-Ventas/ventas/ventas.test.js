import {calcularTotal, calcularTotalImpuesto , calcularDescuentos, calcularCategoria, calcularPesoVolumetrico, calculoTipoCliente, calculobeneficio} from './ventas.js'

describe('Sistema de ventas', () => {
  it('Deberia mostrar 300 al ingresar cantidad = 100 y precio = 3', () => {
    expect(calcularTotal(100,3)).toEqual(300);
  });
  /*------IMPUESTOS------*/
  it('Deberia mostrar 4266 al ingresar cantidad = 400, precio = 100 y estado = UT', () => {
    expect(calcularTotalImpuesto(4000,'UT')).toEqual([4266,266]);
  });
  it('Deberia mostrar 8640 al ingresar  cantidad = 80, precio = 100 y estado = NV', () => {
    expect(calcularTotalImpuesto(8000,'NV')).toEqual([8640,640]);
  });
  it('Deberia mostrar 850 al ingresar cantidad = 10, precio = 80 y estado = TX', () => {
    expect(calcularTotalImpuesto(800,'TX')).toEqual([850,50]);
  });
  it('Deberia mostrar 4160 al ingresar cantidad = 40, precio = 100, estado = AL', () => {
    expect(calcularTotalImpuesto(4000,'AL')).toEqual([4160,160]);
  });
  it('Deberia mostrar 16237 al ingresar cantidad = 150, precio = 100, estado = CA', () => {
    expect(calcularTotalImpuesto(15000,'CA')).toEqual([16237.5,1237.5]);
  });
  /*-----DESCUENTOS-----*/
  it('Deberia mostrar total con un descuento del 3% totalingresado >= 1000 <= 2999', () => {
    expect(calcularDescuentos(100,15)).toEqual([1455,45]);
  });
  it('Deberia mostrar total con un descuento del 5% totalingresado >= 3000 <= 6999', () => {
    expect(calcularDescuentos(3000,2)).toEqual([5700,300]);
  });
  it('Deberia mostrar total con un descuento del 7% totalingresado >= 7000 <= 9999', () => {
    expect(calcularDescuentos(1000,7)).toEqual([6510,490]);
  });
  it('Deberia mostrar total con un descuento del 10% totalingresado >= 10000 <= 29999', () => {
    expect(calcularDescuentos(1000,10)).toEqual([9000,1000]);
  });
  it('Deberia mostrar total con un descuento del 15% totalingresado >= 30000', () => {
    expect(calcularDescuentos(2000,20)).toEqual([34000,6000]);
  });
  /*-----CATEGORIA-----*/
  it('Deberia mostrar total con un calculo de Aliento totalingresado', () => {
    expect(calcularCategoria(2000,'Alimentos')).toEqual([2040,0,40]);
  });
  it('Deberia mostrar total con un calculo de Bebidas alcoholicas totalingresado', () => {
    expect(calcularCategoria(2000,'Bebidas alcoholicas')).toEqual([1860,140,0]);
  });
  it('Deberia mostrar total con un calculo de Material de escritorio totalingresado', () => {
    expect(calcularCategoria(2000,'Material de escritorio')).toEqual([2030,0,30]);
  });
  it('Deberia mostrar total con un calculo de Muebles totalingresado', () => {
    expect(calcularCategoria(2000,'Muebles')).toEqual([1940,60,0]);
  });
  it('Deberia mostrar total con un calculo de Electronicos totalingresado', () => {
    expect(calcularCategoria(2000,'Electronicos')).toEqual([1939.2,80,19.2]);
  });
  it('Deberia mostrar total con un calculo de Vestimenta totalingresado', () => {
    expect(calcularCategoria(2000,'Vestimenta')).toEqual([1960,40,0]);
  });
  it('Deberia mostrar total con un calculo de Varios totalingresado', () => {
    expect(calcularCategoria(2000,'Varios')).toEqual([2000,0,0]);
  });

  /*-----PESO VOLUMETRICO-----*/
  it('Deberia mostrar total con un calculo con peso 0 a 10', () => {
      expect(calcularPesoVolumetrico(2000,20,8)).toEqual([2000,0]);
  });
  it('Deberia mostrar total con un calculo con peso 11 a 20', () => {
    expect(calcularPesoVolumetrico(2000,20,12)).toEqual([2070,70]);
  });
  it('Deberia mostrar total con un calculo con peso 21 a 40', () => {
    expect(calcularPesoVolumetrico(2000,20,21)).toEqual([2100,100]);
  });
  it('Deberia mostrar total con un calculo con peso 41 a 80', () => {
    expect(calcularPesoVolumetrico(2000,20,41)).toEqual([2120,120]);
  });
  it('Deberia mostrar total con un calculo con peso 81 a 100', () => {
    expect(calcularPesoVolumetrico(2000,20,81)).toEqual([2130,130]);
  });
  it('Deberia mostrar total con un calculo con peso 101 a 200', () => {
    expect(calcularPesoVolumetrico(2000,20,101)).toEqual([2160,160]);
  });
  it('Deberia mostrar total con un calculo con peso > 200', () => {
    expect(calcularPesoVolumetrico(2000,20,201)).toEqual([2180,180]);
  });

  /*-----TIPO de PERSONAS---*/
  it('Deberia mostrar total con un calculo con tipo normal', () => {
    expect(calculoTipoCliente(2000,'Normal')).toEqual([2000,0]);
  });
  it('Deberia mostrar total con un calculo con tipo recurrente', () => {
    expect(calculoTipoCliente(2000,'Recurrente')).toEqual([1990,10]);
  });
  it('Deberia mostrar total con un calculo con tipo antiguo recurrente', () => {
    expect(calculoTipoCliente(2000,'Antiguo Recurrente')).toEqual([1980,20]);
  });
  it('Deberia mostrar total con un calculo con tipo especial', () => {
    expect(calculoTipoCliente(2000,'Especial')).toEqual([1970,30]);
  });

  //mostrar beneficio
  it('Deberia mostrar total con calculo respecto a cliente recurrente, neto > 3000 y categoria alimentos', () => {
    expect(calculobeneficio(2500,'Recurrente',3100,'Alimentos')).toEqual([2400,100]);
  });
  it('Deberia mostrar total con calculo respecto a cliente especial, neto > 7000 y categoria electronicos', () => {
    expect(calculobeneficio(2500,'Especial',7100,'Electronicos')).toEqual([2300,200]);
  });
});