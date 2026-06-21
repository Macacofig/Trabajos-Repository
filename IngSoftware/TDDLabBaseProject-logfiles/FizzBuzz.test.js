import { fizzBuzz } from '../src/FizBuzz.js';

describe('FizzBuzz', () => {
  it('deberia retornar "" si el numero es 0', () => {
    expect(fizzBuzz(0)).toEqual("");
  });
  it('deberia retornar "" si el numero es negativo', () => {
    expect(fizzBuzz(-1)).toEqual("");
  });
  it('deberia retornar "1" si el numero es 1', () => {
    expect(fizzBuzz(1)).toEqual("1");
  });
  it('deberia retornar "1 2" si el numero es 2', () => {
    expect(fizzBuzz(2)).toEqual("1 2");
  });
  it('deberia retornar "1 2 fizz" si el numero es 3', () => {
    expect(fizzBuzz(3)).toEqual("1 2 fizz");
  });
  it('deberia retornar "1 2 fizz 4 buzz" si el numero es 5', () => {
    expect(fizzBuzz(5)).toEqual("1 2 fizz 4 buzz");
  });
  it('deberia retornar "1 2 fizz 4 buzz fizz " si el numero es 6', () => {
    expect(fizzBuzz(6)).toEqual("1 2 fizz 4 buzz fizz");
  });
  it('deberia retornar "1 2 fizz 4 buzz fizz 7 8 fizz buzz" si el numero es 10', () => {
    expect(fizzBuzz(10)).toEqual("1 2 fizz 4 buzz fizz 7 8 fizz buzz");
  });
  it('deberia retornar "1 2 fizz 4 buzz fizz 7 8 fizz buzz 11 fizz 13 14 fizzbuzz" si el numero es 15', () => {
    expect(fizzBuzz(15)).toEqual("1 2 fizz 4 buzz fizz 7 8 fizz buzz 11 fizz 13 14 fizzbuzz");
  });
});