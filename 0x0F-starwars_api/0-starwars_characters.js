#!/usr/bin/node
const request = require('request');
const IdReference = process.argv[2];
const url = `https://swapi.dev/api/films/${IdReference}/`;

request(url, async function (error, resp, body) {
  if (error) {
    console.log(error);
  } else {
    const characters = JSON.parse(body).characters;
    for (const ct of characters) {
      const res = await new Promise((resolve, reject) => {
        request(ct, (error, res, html) => {
          if (error) {
            reject(error);
          } else {
            resolve(JSON.parse(html).name);
          }
        });
      });
      console.log(res);
    }
  }
});
