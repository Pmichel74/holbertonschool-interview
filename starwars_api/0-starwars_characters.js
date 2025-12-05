#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

const apiUrl = `https://swapi-api.hbtn.io/api/films/${movieId}`;

request(apiUrl, (err, response, body) => {
  if (err) {
    console.error(err);
    return;
  }

  const filmData = JSON.parse(body);
  const characters = filmData.characters;

  const printCharacters = (index) => {
    if (index >= characters.length) return;

    request(characters[index], (err, res, body) => {
      if (err) {
        console.error(err);
        return;
      }

      const characterData = JSON.parse(body);
      console.log(characterData.name);
      printCharacters(index + 1);
    });
  };

  printCharacters(0);
});
