/*
EXERCÍCIO SIMPLES DE LÓGICA DE PROGRAMAÇÃO EM JS
*/

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');

    main();
});

function readLine() {
    return inputString[currentLine++];
}

function plusMinus(arr) {
    let contadorPositivo = 0, contadorNegativo = 0, contadorZeros = 0;

    const total = arr.length;

    for(let i = 0; i<total; i++){
        if(arr[i]<0){
            contadorNegativo++;
        } else if (arr[i]>0){
            contadorPositivo++;
        } else {
            contadorZeros++;
        }
    }

    // Exibindo as proporções com 6 casas decimais
    console.log((contadorPositivo / total).toFixed(6));
    console.log((contadorNegativo / total).toFixed(6));
    console.log((contadorZeros / total).toFixed(6));
}

function main() {
    const n = parseInt(readLine().trim(), 10);

    const arr = readLine().replace(/\s+$/g, '').split(' ').map(arrTemp => parseInt(arrTemp, 10));

    plusMinus(arr);
}
