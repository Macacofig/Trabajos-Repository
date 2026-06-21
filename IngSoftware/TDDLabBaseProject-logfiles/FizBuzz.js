function obtenerValor(n) {
    if (n % 3 === 0 && n % 5 === 0) {
        return "fizzbuzz";
    }

    if (n % 3 === 0) {
        return "fizz";
    }

    if (n % 5 === 0) {
        return "buzz";
    }

    return n.toString();
}

function fizzBuzz(n) {
    if (n <= 0) {
        return "";
    }

    if (n === 1) {
        return "1";
    }

    return fizzBuzz(n - 1) + " " + obtenerValor(n);
}

export { fizzBuzz };