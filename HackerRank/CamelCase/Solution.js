/*
EXERCÍCIO SIMPLES DE LÓGICA DE PROGRAMAÇÃO EM JS
*/

'use strict';

const fs = require('fs');

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

function camelcase(s) {
    let contador = 1;

    for(let i = 0; i<s.length; i++){
        if(s[i] === s[i].toUpperCase()){
            contador++;
        }
    }

    return contador;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const s = readLine();

    const result = camelcase(s);

    ws.write(result + '\n');

    ws.end();
}
